#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer _EXPORTED_FlushUniforms
// {
//
//   struct <unnamed>
//   {
//       
//       float gradInverseViewportY;    // Offset:    0
//       float tessInverseViewportY;    // Offset:    4
//       float renderTargetInverseViewportX;// Offset:    8
//       float renderTargetInverseViewportY;// Offset:   12
//       uint renderTargetWidth;        // Offset:   16
//       uint renderTargetHeight;       // Offset:   20
//       uint colorClearValue;          // Offset:   24
//       uint coverageClearValue;       // Offset:   28
//       int4 renderTargetUpdateBounds; // Offset:   32
//       float2 atlasTextureInverseSize;// Offset:   48
//       float2 atlasContentInverseViewport;// Offset:   56
//       uint coverageBufferPrefix;     // Offset:   64
//       uint pathIDGranularity;        // Offset:   68
//       float vertexDiscardValue;      // Offset:   72
//       uint wireframeEnabled;         // Offset:   76
//
//   } uniforms;                        // Offset:    0 Size:    80
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// _EXPORTED_FlushUniforms           cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// _EXPORTED_a_span         0   xyzw        0     NONE    uint   xyzw
// SV_VertexID              0   x           1   VERTID    uint   x   
// SV_InstanceID            0   x           2   INSTID    uint       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xyzw        0     NONE   float   xyzw
// SV_Position              0   xyzw        1      POS   float   xyzw
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[1], immediateIndexed
dcl_input v0.xyzw
dcl_input_sgv v1.x, vertex_id
dcl_output o0.xyzw
dcl_output_siv o1.xyzw, position
dcl_temps 2
ushr r0.x, v1.x, l(1)
ige r0.y, l(1), r0.x
ieq r0.xz, r0.xxxx, l(0, 0, 3, 0)
movc r1.z, r0.y, v0.z, v0.w
ushr r1.xyw, r1.zzzz, l(16, 8, 0, 24)
and r1.xyzw, r1.xyzw, l(255, 255, 255, 255)
utof r1.xyzw, r1.xyzw
mul o0.xyzw, r1.xyzw, l(0.003922, 0.003922, 0.003922, 0.003922)
ushr r0.w, v0.x, l(16)
and r1.xyzw, v0.xyyy, l(0x0000ffff, 0x1fffffff, 0x80000000, 0x20000000)
movc r0.y, r0.y, r1.x, r0.w
utof r0.y, r0.y
mad r0.w, r0.y, l(0.000015), l(-0.001953)
mul r0.y, r0.y, l(0.000015)
movc r0.w, r1.w, l(0), r0.w
ine r1.x, r1.z, l(0)
and r0.x, r0.x, r1.x
movc r0.x, r0.x, r0.w, r0.y
add r0.y, r0.x, l(0.001953)
movc r0.y, r1.w, l(1.000000), r0.y
utof r0.w, r1.y
and r1.x, v0.y, l(0x40000000)
ine r1.x, r1.x, l(0)
and r0.z, r0.z, r1.x
movc r0.x, r0.z, r0.y, r0.x
mad o1.x, r0.x, l(2.000000), l(-1.000000)
and r0.x, v1.x, l(1)
movc r0.xy, r0.xxxx, l(1.000000,0,0,0), l(0,1.000000,0,0)
lt r0.z, cb0[0].x, l(0.000000)
movc r0.x, r0.z, r0.y, r0.x
add r0.x, r0.x, r0.w
lt r0.y, l(0.000000), cb0[0].x
iadd r0.y, -r0.y, r0.z
itof r0.y, r0.y
mad o1.y, r0.x, cb0[0].x, -r0.y
mov o1.zw, l(0,0,0,1.000000)
ret 
// Approximately 37 instruction slots used
#endif

const BYTE g_main[] =
{
     68,  88,  66,  67, 147,  97, 
    229,  21, 147, 206, 184, 179, 
    239, 203,  20, 210,  57, 185, 
     15, 171,   1,   0,   0,   0, 
    104,  10,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    244,   3,   0,   0, 120,   4, 
      0,   0, 208,   4,   0,   0, 
    204,   9,   0,   0,  82,  68, 
     69,  70, 184,   3,   0,   0, 
      1,   0,   0,   0, 116,   0, 
      0,   0,   1,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    254, 255,   0,   1,   0,   0, 
    144,   3,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
     92,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  95,  69,  88,  80, 
     79,  82,  84,  69,  68,  95, 
     70, 108, 117, 115, 104,  85, 
    110, 105, 102, 111, 114, 109, 
    115,   0,  92,   0,   0,   0, 
      1,   0,   0,   0, 140,   0, 
      0,   0,  80,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 180,   0,   0,   0, 
      0,   0,   0,   0,  80,   0, 
      0,   0,   2,   0,   0,   0, 
    108,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    117, 110, 105, 102, 111, 114, 
    109, 115,   0,  60, 117, 110, 
    110,  97, 109, 101, 100,  62, 
      0, 103, 114,  97, 100,  73, 
    110, 118, 101, 114, 115, 101, 
     86, 105, 101, 119, 112, 111, 
    114, 116,  89,   0, 102, 108, 
    111,  97, 116,   0, 171, 171, 
      0,   0,   3,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 220,   0,   0,   0, 
    116, 101, 115, 115,  73, 110, 
    118, 101, 114, 115, 101,  86, 
    105, 101, 119, 112, 111, 114, 
    116,  89,   0, 114, 101, 110, 
    100, 101, 114,  84,  97, 114, 
    103, 101, 116,  73, 110, 118, 
    101, 114, 115, 101,  86, 105, 
    101, 119, 112, 111, 114, 116, 
     88,   0, 114, 101, 110, 100, 
    101, 114,  84,  97, 114, 103, 
    101, 116,  73, 110, 118, 101, 
    114, 115, 101,  86, 105, 101, 
    119, 112, 111, 114, 116,  89, 
      0, 114, 101, 110, 100, 101, 
    114,  84,  97, 114, 103, 101, 
    116,  87, 105, 100, 116, 104, 
      0, 100, 119, 111, 114, 100, 
      0, 171,   0,   0,  19,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 105,   1, 
      0,   0, 114, 101, 110, 100, 
    101, 114,  84,  97, 114, 103, 
    101, 116,  72, 101, 105, 103, 
    104, 116,   0,  99, 111, 108, 
    111, 114,  67, 108, 101,  97, 
    114,  86,  97, 108, 117, 101, 
      0,  99, 111, 118, 101, 114, 
     97, 103, 101,  67, 108, 101, 
     97, 114,  86,  97, 108, 117, 
    101,   0, 114, 101, 110, 100, 
    101, 114,  84,  97, 114, 103, 
    101, 116,  85, 112, 100,  97, 
    116, 101,  66, 111, 117, 110, 
    100, 115,   0, 105, 110, 116, 
     52,   0,   1,   0,   2,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 227,   1, 
      0,   0,  97, 116, 108,  97, 
    115,  84, 101, 120, 116, 117, 
    114, 101,  73, 110, 118, 101, 
    114, 115, 101,  83, 105, 122, 
    101,   0, 102, 108, 111,  97, 
    116,  50,   0, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     36,   2,   0,   0,  97, 116, 
    108,  97, 115,  67, 111, 110, 
    116, 101, 110, 116,  73, 110, 
    118, 101, 114, 115, 101,  86, 
    105, 101, 119, 112, 111, 114, 
    116,   0,  99, 111, 118, 101, 
    114,  97, 103, 101,  66, 117, 
    102, 102, 101, 114,  80, 114, 
    101, 102, 105, 120,   0, 112, 
     97, 116, 104,  73,  68,  71, 
    114,  97, 110, 117, 108,  97, 
    114, 105, 116, 121,   0, 118, 
    101, 114, 116, 101, 120,  68, 
    105, 115,  99,  97, 114, 100, 
     86,  97, 108, 117, 101,   0, 
    119, 105, 114, 101, 102, 114, 
     97, 109, 101,  69, 110,  97, 
     98, 108, 101, 100,   0, 171, 
    199,   0,   0,   0, 228,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   1,   0,   0, 228,   0, 
      0,   0,   4,   0,   0,   0, 
     29,   1,   0,   0, 228,   0, 
      0,   0,   8,   0,   0,   0, 
     58,   1,   0,   0, 228,   0, 
      0,   0,  12,   0,   0,   0, 
     87,   1,   0,   0, 112,   1, 
      0,   0,  16,   0,   0,   0, 
    148,   1,   0,   0, 112,   1, 
      0,   0,  20,   0,   0,   0, 
    167,   1,   0,   0, 112,   1, 
      0,   0,  24,   0,   0,   0, 
    183,   1,   0,   0, 112,   1, 
      0,   0,  28,   0,   0,   0, 
    202,   1,   0,   0, 232,   1, 
      0,   0,  32,   0,   0,   0, 
     12,   2,   0,   0,  44,   2, 
      0,   0,  48,   0,   0,   0, 
     80,   2,   0,   0,  44,   2, 
      0,   0,  56,   0,   0,   0, 
    108,   2,   0,   0, 112,   1, 
      0,   0,  64,   0,   0,   0, 
    129,   2,   0,   0, 112,   1, 
      0,   0,  68,   0,   0,   0, 
    147,   2,   0,   0, 228,   0, 
      0,   0,  72,   0,   0,   0, 
    166,   2,   0,   0, 112,   1, 
      0,   0,  76,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
     20,   0,   0,   0,  15,   0, 
    184,   2,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 189,   0,   0,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  49, 
     48,  46,  49,   0,  73,  83, 
     71,  78, 124,   0,   0,   0, 
      3,   0,   0,   0,   8,   0, 
      0,   0,  80,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  15,  15, 
      0,   0,  97,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   1, 
      0,   0, 109,   0,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  95,  69,  88,  80, 
     79,  82,  84,  69,  68,  95, 
     97,  95, 115, 112,  97, 110, 
      0,  83,  86,  95,  86, 101, 
    114, 116, 101, 120,  73,  68, 
      0,  83,  86,  95,  73, 110, 
    115, 116,  97, 110,  99, 101, 
     73,  68,   0, 171,  79,  83, 
     71,  78,  80,   0,   0,   0, 
      2,   0,   0,   0,   8,   0, 
      0,   0,  56,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  65,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,   0, 
      0,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  83, 
     86,  95,  80, 111, 115, 105, 
    116, 105, 111, 110,   0, 171, 
    171, 171,  83,  72,  69,  88, 
    244,   4,   0,   0,  80,   0, 
      1,   0,  61,   1,   0,   0, 
    106,   8,   0,   1,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   0,   0, 
      0,   0,  96,   0,   0,   4, 
     18,  16,  16,   0,   1,   0, 
      0,   0,   6,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 104,   0, 
      0,   2,   2,   0,   0,   0, 
     85,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  33,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  32,   0,   0,  10, 
     82,   0,  16,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     55,   0,   0,   9,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  42,  16,  16,   0, 
      0,   0,   0,   0,  58,  16, 
     16,   0,   0,   0,   0,   0, 
     85,   0,   0,  10, 178,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  10,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
     16,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
     24,   0,   0,   0,   1,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0, 255,   0, 
      0,   0, 255,   0,   0,   0, 
    255,   0,   0,   0, 255,   0, 
      0,   0,  86,   0,   0,   5, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,  10, 242,  32,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0, 129, 128, 
    128,  59, 129, 128, 128,  59, 
    129, 128, 128,  59, 129, 128, 
    128,  59,  85,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  10,  16,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,  16,   0,   0,   0, 
      1,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  21,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
    255, 255,   0,   0, 255, 255, 
    255,  31,   0,   0,   0, 128, 
      0,   0,   0,  32,  55,   0, 
      0,   9,  34,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  86,   0, 
      0,   5,  34,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,   9, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  55,   1,  64, 
      0,   0,   0,   0,   0, 187, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  55,  55,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  39,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  59,  55,   0, 
      0,   9,  34,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  26,   0,  16,   0, 
      0,   0,   0,   0,  86,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     26,  16,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  64,  39,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   7, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,   9,  18,  32, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  64,   1,  64, 
      0,   0,   0,   0, 128, 191, 
      1,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  55,   0, 
      0,  15,  50,   0,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,  49,   0, 
      0,   8,  66,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     55,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  49,   0, 
      0,   8,  34,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     30,   0,   0,   8,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  43,   0,   0,   5, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  11,  34,  32,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   8, 194,  32, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,  62,   0,   0,   1, 
     83,  84,  65,  84, 148,   0, 
      0,   0,  37,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      9,   0,   0,   0,   5,   0, 
      0,   0,   9,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
