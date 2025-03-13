#include "Rive/ViewModel/RiveViewModelInstanceEnum.h"
#include "Logs/RiveLog.h"

using namespace rive;

FString URiveViewModelInstanceEnum::GetValue()
{
    if (auto* EnumPtr = GetNativePtr())
    {
        return FString(EnumPtr->value().c_str());
    }
    return FString(TEXT(""));
}

void URiveViewModelInstanceEnum::SetValue(const FString& Value)
{
    // Since there's a bug in Unreal's GetOptions, we need to
    // validate the value before setting it.

    if (GetValues().Contains(Value))
    {
        if (auto* EnumPtr = GetNativePtr())
        {
            EnumPtr->value(TCHAR_TO_UTF8(*Value));
        }
    }
    else
    {
        UE_LOG(LogRive,
               Warning,
               TEXT("No "
                    "enum option with name '%s'."),
               *Value);
    }
}

TArray<FString> URiveViewModelInstanceEnum::GetValues() const
{
    TArray<FString> Values;

    if (auto* EnumPtr = GetNativePtr())
    {
        auto EnumValues = EnumPtr->values();
        for (const auto& Val : EnumValues)
        {
            Values.Add(FString(Val.c_str()));
        }
    }

    return Values;
}

void URiveViewModelInstanceEnum::GetValuesInternal(
    TArray<FString>& Options) const
{
    Options = GetValues();
}
