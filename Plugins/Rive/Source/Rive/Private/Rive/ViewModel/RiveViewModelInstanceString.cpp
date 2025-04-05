#include "Rive/ViewModel/RiveViewModelInstanceString.h"

/**
 * Wrapper class for rive::ViewModelInstanceStringRuntime
 */
FString URiveViewModelInstanceString::GetValue()
{
    auto* StringPtr = GetNativePtr();

    if (!StringPtr)
    {
        UE_LOG(LogTemp,
               Error,
               TEXT("URiveViewModelInstanceString::GetValue() "
                    "GetNativePtr() is null."));

        return FString();
    }

    return FString(StringPtr->value().c_str());
}

void URiveViewModelInstanceString::SetValue(const FString& Value)
{
    auto* StringPtr = GetNativePtr();

    if (!StringPtr)
    {
        UE_LOG(LogTemp,
               Error,
               TEXT("URiveViewModelInstanceString::SetValue() "
                    "GetNativePtr() is null."));
    }

    StringPtr->value(TCHAR_TO_UTF8(*Value));
}
