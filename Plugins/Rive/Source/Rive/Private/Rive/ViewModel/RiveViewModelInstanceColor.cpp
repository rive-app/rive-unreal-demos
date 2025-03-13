#include "Rive/ViewModel/RiveViewModelInstanceColor.h"

// Use the Rive namespace for convenience
using namespace rive;

FColor URiveViewModelInstanceColor::GetColor()
{
    if (auto* ColorPtr = GetNativePtr())
    {
        return FColor(ColorPtr->value());
    }

    return FColor(0);
}

void URiveViewModelInstanceColor::SetColor(FColor Color)
{
    if (auto* ColorPtr = GetNativePtr())
    {
        ColorPtr->value(Color.ToPackedARGB());
    }
}
