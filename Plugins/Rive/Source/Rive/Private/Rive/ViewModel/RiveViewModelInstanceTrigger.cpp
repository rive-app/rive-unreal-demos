#include "Rive/ViewModel/RiveViewModelInstanceTrigger.h"

// Use the Rive namespace for convenience
using namespace rive;

void URiveViewModelInstanceTrigger::Trigger()
{
    if (auto* TriggerPtr = GetNativePtr())
    {
        TriggerPtr->trigger();
        OnValueChanged.Broadcast();
    }
}
