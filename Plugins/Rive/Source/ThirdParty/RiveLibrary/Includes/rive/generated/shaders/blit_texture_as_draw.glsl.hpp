#pragma once

#include "blit_texture_as_draw.exports.h"

namespace rive {
namespace gpu {
namespace glsl {
const char blit_texture_as_draw[] = R"===(/*
 * Copyright 2024 Rive
 */

VARYING_BLOCK_BEGIN
#ifndef _EXPORTED_USE_TEXEL_FETCH_WITH_FRAG_COORD
NO_PERSPECTIVE VARYING(0, float2, v_texCoord);
#endif
VARYING_BLOCK_END

#ifdef _EXPORTED_VERTEX
VERTEX_TEXTURE_BLOCK_BEGIN
VERTEX_TEXTURE_BLOCK_END

VERTEX_STORAGE_BUFFER_BLOCK_BEGIN
VERTEX_STORAGE_BUFFER_BLOCK_END

VERTEX_MAIN(_EXPORTED_blitVertexMain, Attrs, attrs, _vertexID, _instanceID)
{
    // Fill the entire screen. The caller will use a scissor test to control the
    // bounds being drawn.
    float2 coord;
    coord.x = (_vertexID & 1) == 0 ? -1. : 1.;
    coord.y = (_vertexID & 2) == 0 ? -1. : 1.;
#ifndef _EXPORTED_USE_TEXEL_FETCH_WITH_FRAG_COORD
    VARYING_INIT(v_texCoord, float2);
    v_texCoord.x = coord.x * .5 + .5;
    v_texCoord.y = coord.y * -.5 + .5;
    VARYING_PACK(v_texCoord);
#endif
    float4 pos = float4(coord, 0, 1);
    EMIT_VERTEX(pos);
}
#endif // @VERTEX

#ifdef _EXPORTED_FRAGMENT
FRAG_TEXTURE_BLOCK_BEGIN
TEXTURE_RGBA8(0, 0, _EXPORTED_sourceTexture);
FRAG_TEXTURE_BLOCK_END

#ifndef _EXPORTED_USE_TEXEL_FETCH_WITH_FRAG_COORD
SAMPLER_DYNAMIC(0, 1, blitSampler)
#endif

FRAG_DATA_MAIN(half4, _EXPORTED_blitFragmentMain)
{
    half4 srcColor;
#ifndef _EXPORTED_USE_TEXEL_FETCH_WITH_FRAG_COORD
    VARYING_UNPACK(v_texCoord, float2);
    srcColor = TEXTURE_SAMPLE_LOD(_EXPORTED_sourceTexture, blitSampler, v_texCoord, .0);
#else
    srcColor = TEXEL_FETCH(_EXPORTED_sourceTexture, int2(floor(_fragCoord.xy)));
#endif
    EMIT_FRAG_DATA(srcColor);
}
#endif // @FRAGMENT
)===";
} // namespace glsl
} // namespace gpu
} // namespace rive