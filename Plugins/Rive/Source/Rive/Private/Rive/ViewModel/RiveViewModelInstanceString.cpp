#include "Rive/ViewModel/RiveViewModelInstanceString.h"

/**
 * Wrapper class for rive::ViewModelInstanceStringRuntime
 */
FString URiveViewModelInstanceString::GetValue()
{
    if (auto* StringPtr = GetNativePtr())
    {
        if (StringPtr)
            return FString(StringPtr->value().c_str());
    }
    return FString();
}

void URiveViewModelInstanceString::SetValue(const FString& Value)
{
    if (auto* StringPtr = GetNativePtr())
    {
        if (StringPtr)
            StringPtr->value(TCHAR_TO_UTF8(*Value));
    }
}
