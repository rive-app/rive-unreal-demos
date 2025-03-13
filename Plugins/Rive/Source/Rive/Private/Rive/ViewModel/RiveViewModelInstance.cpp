#include "Rive/ViewModel/RiveViewModelInstance.h"
#include "Rive/ViewModel/RiveViewModelInstanceNumber.h"
#include "Rive/ViewModel/RiveViewModelInstanceString.h"
#include "Rive/ViewModel/RiveViewModelInstanceTrigger.h"
#include "Rive/ViewModel/RiveViewModelInstanceBoolean.h"
#include "Rive/ViewModel/RiveViewModelInstanceColor.h"
#include "Rive/ViewModel/RiveViewModelInstanceEnum.h"
#include "Rive/ViewModel/RiveViewModelPropertyResolver.h"
#include "Logs/RiveLog.h"

THIRD_PARTY_INCLUDES_START
#include "rive/viewmodel/runtime/viewmodel_instance_runtime.hpp"
THIRD_PARTY_INCLUDES_END

using namespace rive;

void URiveViewModelInstance::Initialize(
    rive::ViewModelInstanceRuntime* InViewModelInstance,
    URiveViewModelInstance* InRoot)
{
    ViewModelInstancePtr = InViewModelInstance;
    Root = InRoot == nullptr ? this : InRoot;
}

void URiveViewModelInstance::BeginDestroy()
{
    // Only delete the root pointer, others are handled by
    // the wrapped class.
    if (Root == this)
    {
        ClearCallbacks();

        if (ViewModelInstancePtr)
        {
            delete ViewModelInstancePtr;
            ViewModelInstancePtr = nullptr;
        }
    }

    Properties.Empty();

    Super::BeginDestroy();
}

void URiveViewModelInstance::AddCallbackProperty(
    URiveViewModelInstanceValue* Property)
{
    if (Root != this)
    {
        Root->AddCallbackProperty(Property);
    }
    else
    {
        CallbackProperties.AddUnique(Property);
    }
}

void URiveViewModelInstance::RemoveCallbackProperty(
    URiveViewModelInstanceValue* Property)
{
    if (Root != this)
    {
        Root->RemoveCallbackProperty(Property);
    }
    else
    {
        CallbackProperties.Remove(Property);
    }
}

void URiveViewModelInstance::HandleCallbacks()
{
    // Always handle callbacks from the root instance.
    if (Root != this)
    {
        Root->HandleCallbacks();
    }
    else
    {
        for (TWeakObjectPtr<URiveViewModelInstanceValue> WeakProperty :
             CallbackProperties)
        {
            if (WeakProperty.IsValid())
            {
                URiveViewModelInstanceValue* Property = WeakProperty.Get();
                if (Property)
                {
                    Property->HandleCallbacks();
                }
            }
        }
    }
}

void URiveViewModelInstance::ClearCallbacks()
{
    if (Root != this)
    {
        Root->ClearCallbacks();
    }
    else
    {
        for (TWeakObjectPtr<URiveViewModelInstanceValue> WeakProperty :
             CallbackProperties)
        {
            if (WeakProperty.IsValid())
            {
                URiveViewModelInstanceValue* Property = WeakProperty.Get();
                if (Property)
                {
                    RemoveCallbackProperty(Property);
                }
            }
        }
    }
}

int32 URiveViewModelInstance::GetPropertyCount() const
{
    return ViewModelInstancePtr
               ? static_cast<int32>(ViewModelInstancePtr->propertyCount())
               : 0;
}

template <typename T>
T* URiveViewModelInstance::GetProperty(const FString& PropertyName)
{
    static_assert(TIsDerivedFrom<T, IRiveViewModelPropertyInterface>::Value,
                  "T must implement IRiveViewModelPropertyInterface!");

    FString Key = PropertyName + T::GetSuffix();

    if (UObject** Property = Properties.Find(Key))
    {
        return Cast<T>(*Property);
    }

    if (ViewModelInstancePtr)
    {
        using PropertyType = typename PropertyTypeResolver<T>::Type;

        PropertyType Property = nullptr;

        if constexpr (std::is_same_v<T, URiveViewModelInstanceBoolean>)
        {
            Property = ViewModelInstancePtr->propertyBoolean(
                TCHAR_TO_UTF8(*PropertyName));
        }
        else if constexpr (std::is_same_v<T, URiveViewModelInstanceColor>)
        {
            Property = ViewModelInstancePtr->propertyColor(
                TCHAR_TO_UTF8(*PropertyName));
        }
        else if constexpr (std::is_same_v<T, URiveViewModelInstanceEnum>)
        {
            Property = ViewModelInstancePtr->propertyEnum(
                TCHAR_TO_UTF8(*PropertyName));
        }
        else if constexpr (std::is_same_v<T, URiveViewModelInstanceNumber>)
        {
            Property = ViewModelInstancePtr->propertyNumber(
                TCHAR_TO_UTF8(*PropertyName));
        }
        else if constexpr (std::is_same_v<T, URiveViewModelInstanceString>)
        {
            Property = ViewModelInstancePtr->propertyString(
                TCHAR_TO_UTF8(*PropertyName));
        }
        else if constexpr (std::is_same_v<T, URiveViewModelInstanceTrigger>)
        {
            Property = ViewModelInstancePtr->propertyTrigger(
                TCHAR_TO_UTF8(*PropertyName));
        }
        else if constexpr (std::is_same_v<T, URiveViewModelInstance>)
        {
            Property = ViewModelInstancePtr->propertyViewModel(
                TCHAR_TO_UTF8(*PropertyName));
        }

        if (Property)
        {
            T* PropertyInstance = NewObject<T>(this);
            PropertyInstance->Initialize(Property, Root);
            Properties.Add(Key, PropertyInstance);
            return PropertyInstance;
        }
    }

    UE_LOG(LogRive,
           Warning,
           TEXT("Failed to retrieve "
                "property with name '%s'."),
           *Key);

    return nullptr;
}

URiveViewModelInstanceBoolean* URiveViewModelInstance::GetBooleanProperty(
    const FString& PropertyName)
{
    return GetProperty<URiveViewModelInstanceBoolean>(PropertyName);
}

void URiveViewModelInstance::SetBooleanPropertyValue(
    const FString& PropertyName,
    const bool Value)
{
    URiveViewModelInstanceBoolean* BooleanInstance =
        GetBooleanProperty(PropertyName);

    if (BooleanInstance)
    {
        BooleanInstance->SetValue(Value);
    }
}

bool URiveViewModelInstance::GetBooleanPropertyValue(
    const FString& PropertyName)
{
    URiveViewModelInstanceBoolean* BooleanInstance =
        GetBooleanProperty(PropertyName);

    if (BooleanInstance)
    {
        return BooleanInstance->GetValue();
    }

    return false;
}

URiveViewModelInstanceColor* URiveViewModelInstance::GetColorProperty(
    const FString& PropertyName)
{
    return GetProperty<URiveViewModelInstanceColor>(PropertyName);
}

FColor URiveViewModelInstance::GetColorPropertyValue(
    const FString& PropertyName)
{
    URiveViewModelInstanceColor* ColorInstance = GetColorProperty(PropertyName);

    if (ColorInstance)
    {
        return ColorInstance->GetColor();
    }

    return FColor(0);
}

void URiveViewModelInstance::SetColorPropertyValue(const FString& PropertyName,
                                                   const FColor Value)
{
    URiveViewModelInstanceColor* ColorInstance = GetColorProperty(PropertyName);

    if (ColorInstance)
    {
        ColorInstance->SetColor(Value);
    }
}

URiveViewModelInstanceNumber* URiveViewModelInstance::GetNumberProperty(
    const FString& PropertyName)
{
    return GetProperty<URiveViewModelInstanceNumber>(PropertyName);
}

void URiveViewModelInstance::SetNumberPropertyValue(const FString& PropertyName,
                                                    const float Value)
{
    URiveViewModelInstanceNumber* NumberInstance =
        GetNumberProperty(PropertyName);

    if (NumberInstance)
    {
        NumberInstance->SetValue(Value);
    }
}

float URiveViewModelInstance::GetNumberPropertyValue(
    const FString& PropertyName)
{
    URiveViewModelInstanceNumber* NumberInstance =
        GetNumberProperty(PropertyName);

    if (NumberInstance)
    {
        return NumberInstance->GetValue();
    }

    return 0.0f;
}

URiveViewModelInstanceString* URiveViewModelInstance::GetStringProperty(
    const FString& PropertyName)
{
    return GetProperty<URiveViewModelInstanceString>(PropertyName);
}

void URiveViewModelInstance::SetStringPropertyValue(const FString& PropertyName,
                                                    const FString& Value)
{
    URiveViewModelInstanceString* StringInstance =
        GetStringProperty(PropertyName);

    if (StringInstance)
    {
        StringInstance->SetValue(Value);
    }
}

FString URiveViewModelInstance::GetStringPropertyValue(
    const FString& PropertyName)
{
    URiveViewModelInstanceString* StringInstance =
        GetStringProperty(PropertyName);

    if (StringInstance)
    {
        return StringInstance->GetValue();
    }

    return FString(TEXT(""));
}

URiveViewModelInstanceEnum* URiveViewModelInstance::GetEnumProperty(
    const FString& PropertyName)
{
    return GetProperty<URiveViewModelInstanceEnum>(PropertyName);
}

FString URiveViewModelInstance::GetEnumPropertyValue(
    const FString& PropertyName)
{
    URiveViewModelInstanceEnum* EnumInstance = GetEnumProperty(PropertyName);

    if (EnumInstance)
    {
        return EnumInstance->GetValue();
    }

    return FString(TEXT(""));
}

void URiveViewModelInstance::SetEnumPropertyValue(const FString& PropertyName,
                                                  const FString& Value)
{
    URiveViewModelInstanceEnum* EnumInstance = GetEnumProperty(PropertyName);

    if (EnumInstance)
    {
        EnumInstance->SetValue(Value);
    }
}

TArray<FString> URiveViewModelInstance::GetEnumPropertyValues(
    const FString& PropertyName)
{
    URiveViewModelInstanceEnum* EnumInstance = GetEnumProperty(PropertyName);

    if (EnumInstance)
    {
        return EnumInstance->GetValues();
    }

    return TArray<FString>();
}

URiveViewModelInstanceTrigger* URiveViewModelInstance::GetTriggerProperty(
    const FString& PropertyName)
{
    return GetProperty<URiveViewModelInstanceTrigger>(PropertyName);
}

void URiveViewModelInstance::FireTriggerProperty(const FString& PropertyName)
{
    URiveViewModelInstanceTrigger* TriggerProp =
        GetTriggerProperty(PropertyName);

    if (TriggerProp)
    {
        TriggerProp->Trigger();
    }
}

URiveViewModelInstance* URiveViewModelInstance::GetNestedInstanceByName(
    const FString& PropertyName)
{
    return GetProperty<URiveViewModelInstance>(PropertyName);
}
