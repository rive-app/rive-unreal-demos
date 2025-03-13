#include "Rive/ViewModel/RiveViewModel.h"
#include "Rive/ViewModel/RiveViewModelInstance.h"
#include "Logs/RiveLog.h"

THIRD_PARTY_INCLUDES_START
#include "rive/viewmodel/runtime/viewmodel_runtime.hpp"
THIRD_PARTY_INCLUDES_END

void URiveViewModel::Initialize(rive::ViewModelRuntime* InViewModel)
{
    ViewModelRuntimePtr = TUniquePtr<rive::ViewModelRuntime>(InViewModel);
}

FString URiveViewModel::GetName() const
{
    return ViewModelRuntimePtr.IsValid()
               ? FString(ViewModelRuntimePtr->name().c_str())
               : FString(TEXT(""));
}

int32 URiveViewModel::GetInstanceCount() const
{
    return ViewModelRuntimePtr.IsValid()
               ? static_cast<int32>(ViewModelRuntimePtr->instanceCount())
               : 0;
}

URiveViewModelInstance* URiveViewModel::CreateDefaultInstance() const
{
    if (ViewModelRuntimePtr.IsValid())
    {
        rive::ViewModelInstanceRuntime* DefaultInstance =
            ViewModelRuntimePtr->createDefaultInstance();
        if (DefaultInstance)
        {
            URiveViewModelInstance* InstanceWrapper =
                NewObject<URiveViewModelInstance>();
            InstanceWrapper->Initialize(DefaultInstance);
            return InstanceWrapper;
        }
    }
    return nullptr;
}

URiveViewModelInstance* URiveViewModel::CreateInstance()
{
    if (ViewModelRuntimePtr)
    {
        rive::ViewModelInstanceRuntime* RuntimeInstance =
            ViewModelRuntimePtr->createInstance();
        if (RuntimeInstance)
        {
            URiveViewModelInstance* InstanceWrapper =
                NewObject<URiveViewModelInstance>();
            InstanceWrapper->Initialize(RuntimeInstance);
            return InstanceWrapper;
        }
    }
    return nullptr;
}

TArray<FString> URiveViewModel::GetInstanceNames() const
{
    TArray<FString> InstanceNames;
    if (ViewModelRuntimePtr.IsValid())
    {
        auto Names = ViewModelRuntimePtr->instanceNames();
        for (const auto& Name : Names)
        {
            InstanceNames.Add(FString(Name.c_str()));
        }
    }
    return InstanceNames;
}

URiveViewModelInstance* URiveViewModel::CreateInstanceFromIndex(
    int32 Index) const
{
    if (!ViewModelRuntimePtr.IsValid())
    {
        UE_LOG(LogRive, Warning, TEXT("ViewModelRuntimePtr is null."));
        return nullptr;
    }

    if (Index < 0 ||
        Index >= static_cast<int32>(ViewModelRuntimePtr->instanceCount()))
    {
        UE_LOG(LogRive,
               Warning,
               TEXT("Index '%d' is out of range. "
                    "Valid range is [0, %d)."),
               Index,
               ViewModelRuntimePtr->instanceCount());
        return nullptr;
    }

    rive::ViewModelInstanceRuntime* Instance =
        ViewModelRuntimePtr->createInstanceFromIndex(
            static_cast<size_t>(Index));
    if (Instance)
    {
        URiveViewModelInstance* InstanceWrapper =
            NewObject<URiveViewModelInstance>();
        InstanceWrapper->Initialize(Instance);
        return InstanceWrapper;
    }

    UE_LOG(LogRive,
           Warning,
           TEXT("Failed to retrieve ViewModelInstance "
                "at index '%d'."),
           Index);
    return nullptr;
}

URiveViewModelInstance* URiveViewModel::CreateInstanceFromName(
    const FString& Name) const
{
    if (!ViewModelRuntimePtr.IsValid())
    {
        UE_LOG(LogRive, Warning, TEXT("ViewModelRuntimePtr is null."));
        return nullptr;
    }

    rive::ViewModelInstanceRuntime* Instance =
        ViewModelRuntimePtr->createInstanceFromName(TCHAR_TO_UTF8(*Name));
    if (Instance)
    {
        URiveViewModelInstance* InstanceWrapper =
            NewObject<URiveViewModelInstance>();
        InstanceWrapper->Initialize(Instance);
        return InstanceWrapper;
    }

    UE_LOG(LogRive,
           Warning,
           TEXT("Failed to retrieve ViewModelInstance "
                "with name '%s'."),
           *Name);
    return nullptr;
}

TArray<FString> URiveViewModel::GetPropertyNames() const
{
    TArray<FString> PropertyNames;
    if (ViewModelRuntimePtr.IsValid())
    {
        auto Properties = ViewModelRuntimePtr->properties();
        for (const auto& Property : Properties)
        {
            PropertyNames.Add(FString(Property.name.c_str()));
        }
    }
    return PropertyNames;
}

rive::DataType URiveViewModel::GetPropertyTypeByName(const FString& Name) const
{
    if (ViewModelRuntimePtr.IsValid())
    {
        auto Properties = ViewModelRuntimePtr->properties();
        for (auto& Property : Properties)
        {
            if (Property.name == TCHAR_TO_UTF8(*Name))
                return Property.type;
        }
    }

    return rive::DataType::none;
}
