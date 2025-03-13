#include "Rive/ViewModel/RiveViewModelInstanceNumber.h"

// Use the Rive namespace for convenience
using namespace rive;

float URiveViewModelInstanceNumber::GetValue()
{
    if (auto* NumberPtr = GetNativePtr())
        NumberPtr->value();

    return 0.0f;
}

void URiveViewModelInstanceNumber::SetValue(float Value)
{
    if (auto* NumberPtr = GetNativePtr())
    {
        NumberPtr->value(Value);
    }
}
