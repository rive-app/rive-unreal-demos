#include "Rive/ViewModel/RiveViewModelInstanceBoolean.h"

// Use the Rive namespace for convenience
using namespace rive;

bool URiveViewModelInstanceBoolean::GetValue()
{
    if (auto* BooleanPtr = GetNativePtr())
    {
        return BooleanPtr->value();
    }
    return false; // Default value if the instance is null
}

void URiveViewModelInstanceBoolean::SetValue(bool Value)
{
    if (auto* BooleanPtr = GetNativePtr())
    {
        BooleanPtr->value(Value);
    }
}
