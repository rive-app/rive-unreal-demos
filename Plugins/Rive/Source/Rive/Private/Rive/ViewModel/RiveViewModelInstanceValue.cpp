#include "Rive/ViewModel/RiveViewModelInstanceValue.h"
#include "Rive/ViewModel/RiveViewModelInstance.h"

void URiveViewModelInstanceValue::Initialize(
    rive::ViewModelInstanceValueRuntime* InViewModelInstanceValue,
    URiveViewModelInstance* InRoot)
{
    ViewModelInstanceValuePtr = InViewModelInstanceValue;
    Root = InRoot;
}

void URiveViewModelInstanceValue::BeginDestroy()
{
    ClearCallbacks();
    Super::BeginDestroy();
}

void URiveViewModelInstanceValue::HandleCallbacks()
{
    if (ViewModelInstanceValuePtr && ViewModelInstanceValuePtr->hasChanged())
    {
        ViewModelInstanceValuePtr->clearChanges();
        OnValueChanged.Broadcast();
    }
}

void URiveViewModelInstanceValue::ClearCallbacks()
{
    OnValueChanged.Clear();
    if (Root)
        Root->RemoveCallbackProperty(this);
}

void URiveViewModelInstanceValue::BindToValueChange(UObject* Object,
                                                    FName FunctionName)
{
    if (FunctionName.IsNone() || !Object)
    {
        UE_LOG(
            LogTemp,
            Warning,
            TEXT("BindToValueChange failed: Invalid Owner or Function Name."));

        return;
    }

    if (ViewModelInstanceValuePtr && ViewModelInstanceValuePtr->hasChanged())
    {
        ViewModelInstanceValuePtr->clearChanges();
    }

    FScriptDelegate Delegate;
    Delegate.BindUFunction(Object, FunctionName);

    OnValueChanged.AddUnique(Delegate);

    if (Root)
        Root->AddCallbackProperty(this);
}

void URiveViewModelInstanceValue::UnbindFromValueChange(UObject* Object,
                                                        FName FunctionName)
{
    if (FunctionName.IsNone() || !Object)
    {
        UE_LOG(
            LogTemp,
            Warning,
            TEXT("BindToValueChange failed: Invalid Owner or Function Name."));

        return;
    }

    FScriptDelegate Delegate;
    Delegate.BindUFunction(Object, FunctionName);

    OnValueChanged.Remove(Delegate);

    if (Root)
        Root->RemoveCallbackProperty(this);
}

void URiveViewModelInstanceValue::UnbindAllFromValueChange()
{
    ClearCallbacks();
}
