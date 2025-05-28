#pragma once

#include "specialization.exports.h"

namespace rive {
namespace gpu {
namespace glsl {
const char specialization[] = R"===(layout(constant_id = CLIPPING_SPECIALIZATION_IDX) const
    bool kEnableClipping = true;
layout(constant_id = CLIP_RECT_SPECIALIZATION_IDX) const
    bool kEnableClipRect = true;
layout(constant_id = ADVANCED_BLEND_SPECIALIZATION_IDX) const
    bool kEnableAdvancedBlend = true;
layout(constant_id = FEATHER_SPECIALIZATION_IDX) const
    bool kEnableFeather = true;
layout(constant_id = EVEN_ODD_SPECIALIZATION_IDX) const
    bool kEnableEvenOdd = true;
layout(constant_id = NESTED_CLIPPING_SPECIALIZATION_IDX) const
    bool kEnableNestedClipping = true;
layout(constant_id = HSL_BLEND_MODES_SPECIALIZATION_IDX) const
    bool kEnableHSLBlendModes = true;
layout(constant_id = CLOCKWISE_FILL_SPECIALIZATION_IDX) const
    bool kClockwiseFill = true;
layout(constant_id = BORROWED_COVERAGE_PREPASS_SPECIALIZATION_IDX) const
    bool kBorrowedCoveragePrepass = true;
layout(constant_id = VULKAN_VENDOR_ID_SPECIALIZATION_IDX) const uint
    kVulkanVendorID = 0;

#define _EXPORTED_ENABLE_CLIPPING  kEnableClipping
#define _EXPORTED_ENABLE_CLIP_RECT  kEnableClipRect
#define _EXPORTED_ENABLE_ADVANCED_BLEND  kEnableAdvancedBlend
#define _EXPORTED_ENABLE_FEATHER  kEnableFeather
#define _EXPORTED_ENABLE_EVEN_ODD  kEnableEvenOdd
#define _EXPORTED_ENABLE_NESTED_CLIPPING  kEnableNestedClipping
#define _EXPORTED_ENABLE_HSL_BLEND_MODES  kEnableHSLBlendModes
#define _EXPORTED_CLOCKWISE_FILL  kClockwiseFill
#define _EXPORTED_BORROWED_COVERAGE_PREPASS  kBorrowedCoveragePrepass
#define _EXPORTED_VULKAN_VENDOR_ID  kVulkanVendorID
)===";
} // namespace glsl
} // namespace gpu
} // namespace rive