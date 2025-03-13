#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RiveViewModelPropertyInterface.h"
#include "RiveViewModelInstanceValue.generated.h"

namespace rive
{
class ViewModelInstanceValueRuntime;
}

class URiveViewModelInstance;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnValueChangedDelegate);

UCLASS(BlueprintType)
class RIVE_API URiveViewModelInstanceValue : public UObject
{
    GENERATED_BODY()

public:
    void Initialize(
        rive::ViewModelInstanceValueRuntime* InViewModelInstanceValue,
        URiveViewModelInstance* InRoot);

    void HandleCallbacks();
    void ClearCallbacks();

    UFUNCTION(BlueprintCallable, Category = "Rive")
    void BindToValueChange(UObject* Object, FName FunctionName);

    UFUNCTION(BlueprintCallable, Category = "Rive")
    void UnbindFromValueChange(UObject* Object, FName FunctionName);

    UFUNCTION(BlueprintCallable, Category = "Rive")
    void UnbindAllFromValueChange();

protected:
    virtual void BeginDestroy() override;

    rive::ViewModelInstanceValueRuntime* GetNativePtr() const
    {
        return ViewModelInstanceValuePtr;
    }

    UPROPERTY()
    FOnValueChangedDelegate OnValueChanged;

private:
    UPROPERTY()
    URiveViewModelInstance* Root = nullptr;

    rive::ViewModelInstanceValueRuntime* ViewModelInstanceValuePtr = nullptr;
};
