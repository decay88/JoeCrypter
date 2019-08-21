#ifndef _IMMINTRIN_H
#define _IMMINTRIN_H

/* immintrin.h - private header for AVX, AVX2, BMI1, BMI2 etc. intrinsics */

#if __POCC__ >= 500
#pragma once
#endif

#include <wmmintrin.h>

#if __POCC__ >= 700 && __POCC_TARGET__ == 3

typedef union __declspec (align(32)) {
    float m256_f32[8];
} __m256;

typedef union __declspec (align(32)) {
    double m256d_f64[4];
} __m256d;

typedef union __declspec (align(32)) {
    signed char m256i_i8[32];
    signed short m256i_i16[16];
    signed int m256i_i32[8];
    signed long long m256i_i64[4];
    unsigned char m256i_u8[32];
    unsigned short m256i_u16[16];
    unsigned int m256i_u32[8];
    unsigned long long m256i_u64[4];
} __m256i;

/*
 * Compare predicates for scalar and packed compare intrinsics
 */
#define _CMP_EQ_OQ     0x00  /* equal (ordered, non-signaling) */
#define _CMP_LT_OS     0x01  /* less-than (ordered, signaling) */
#define _CMP_LE_OS     0x02  /* less-than-or-equal (ordered, signaling) */
#define _CMP_UNORD_Q   0x03  /* unordered (non-signaling) */
#define _CMP_NEQ_UQ    0x04  /* not-equal (unordered, non-signaling) */
#define _CMP_NLT_US    0x05  /* not-less-than (unordered, signaling) */
#define _CMP_NLE_US    0x06  /* not-less-than-or-equal (unordered, signaling) */
#define _CMP_ORD_Q     0x07  /* ordered (non-signaling) */
#define _CMP_EQ_UQ     0x08  /* equal (unordered, non-signaling) */
#define _CMP_NGE_US    0x09  /* not-greater-than-or-equal (unordered, signaling) */
#define _CMP_NGT_US    0x0A  /* not-greater-than (unordered, signaling) */
#define _CMP_FALSE_OQ  0x0B  /* false (ordered, non-signaling) */
#define _CMP_NEQ_OQ    0x0C  /* not-equal (ordered, non-signaling) */
#define _CMP_GE_OS     0x0D  /* greater-than-or-equal (ordered, signaling) */
#define _CMP_GT_OS     0x0E  /* greater-than (ordered, signaling) */
#define _CMP_TRUE_UQ   0x0F  /* true (unordered, non-signaling) */
#define _CMP_EQ_OS     0x10  /* equal (ordered, signaling) */
#define _CMP_LT_OQ     0x11  /* less-than (ordered, non-signaling) */
#define _CMP_LE_OQ     0x12  /* less-than-or-equal (ordered, non-signaling) */
#define _CMP_UNORD_S   0x13  /* unordered (signaling) */
#define _CMP_NEQ_US    0x14  /* not-equal (unordered, signaling) */
#define _CMP_NLT_UQ    0x15  /* not-less-than (unordered, non-signaling) */
#define _CMP_NLE_UQ    0x16  /* not-less-than-or-equal (unordered, non-signaling) */
#define _CMP_ORD_S     0x17  /* ordered (signaling) */
#define _CMP_EQ_US     0x18  /* equal (unordered, signaling) */
#define _CMP_NGE_UQ    0x19  /* not-greater-than-or-equal (unordered, non-signaling) */
#define _CMP_NGT_UQ    0x1A  /* not-greater-than (unordered, non-signaling) */
#define _CMP_FALSE_OS  0x1B  /* false (ordered, signaling) */
#define _CMP_NEQ_OS    0x1C  /* not-equal (ordered, signaling) */
#define _CMP_GE_OQ     0x1D  /* greater-than-or-equal (ordered, non-signaling) */
#define _CMP_GT_OQ     0x1E  /* greater-than (ordered, non-signaling) */
#define _CMP_TRUE_US   0x1F  /* true (unordered, signaling) */

#define _mm256_ceil_ps(x)  _mm256_round_ps((x), 0x0A)
#define _mm256_floor_ps(x)  _mm256_round_ps((x), 0x09)
#define _mm256_ceil_pd(x)  _mm256_round_pd((x), 0x0A)
#define _mm256_floor_pd(x)  _mm256_round_pd((x), 0x09)

#define _XCR_XFEATURE_ENABLED_MASK  0

/* type conversion (not value conversion) */
extern __m128 __cdecl _mm256_castps256_ps128(__m256);
extern __m128d __cdecl _mm256_castpd256_pd128(__m256d);
extern __m128i __cdecl _mm256_castsi256_si128(__m256i);
extern __m256 __cdecl _mm256_castpd_ps(__m256d);
extern __m256 __cdecl _mm256_castsi256_ps(__m256i);
extern __m256  __cdecl _mm256_castps128_ps256(__m128);
extern __m256d __cdecl _mm256_castpd128_pd256(__m128d);
extern __m256d __cdecl _mm256_castps_pd(__m256);
extern __m256d __cdecl _mm256_castsi256_pd(__m256i);
extern __m256i __cdecl _mm256_castsi128_si256(__m128i);
extern __m256i __cdecl _mm256_castps_si256(__m256);
extern __m256i __cdecl _mm256_castpd_si256(__m256d);

/* arithmetic */
extern __m256 __cdecl _mm256_add_ps(__m256, __m256);  /* vaddps */
extern __m256 __cdecl _mm256_sub_ps(__m256, __m256);  /* vsubps */
extern __m256 __cdecl _mm256_mul_ps(__m256, __m256);  /* vmulps */
extern __m256 __cdecl _mm256_div_ps(__m256, __m256);  /* vdivps */
extern __m256 __cdecl _mm256_addsub_ps(__m256, __m256);  /* vaddsubps */
extern __m256 __cdecl _mm256_hadd_ps(__m256, __m256);  /* vhaddps */
extern __m256 __cdecl _mm256_hsub_ps(__m256, __m256);  /* vhsubps */
extern __m256 __cdecl _mm256_max_ps(__m256, __m256);  /* vmaxps */
extern __m256 __cdecl _mm256_min_ps(__m256, __m256);  /* vminps */
extern __m256 __cdecl _mm256_sqrt_ps(__m256);  /* vsqrtps */
extern __m256 __cdecl _mm256_rcp_ps(__m256);  /* vrcpps */
extern __m256 __cdecl _mm256_rsqrt_ps(__m256);  /* vrsqrtps */
extern __m256 __cdecl _mm256_round_ps(__m256, const int);  /* vroundps */
extern __m256 __cdecl _mm256_dp_ps(__m256, __m256, const int);  /* vdpps */
extern __m256d __cdecl _mm256_add_pd(__m256d, __m256d);  /* vaddpd */
extern __m256d __cdecl _mm256_sub_pd(__m256d, __m256d);  /* vsubpd */
extern __m256d __cdecl _mm256_mul_pd(__m256d, __m256d);  /* vmulpd */
extern __m256d __cdecl _mm256_div_pd(__m256d, __m256d);  /* vdivpd */
extern __m256d __cdecl _mm256_addsub_pd(__m256d, __m256d);  /* vaddsubpd */
extern __m256d __cdecl _mm256_hadd_pd(__m256d, __m256d);  /* vhaddpd */
extern __m256d __cdecl _mm256_hsub_pd(__m256d, __m256d);  /* vhsubpd */
extern __m256d __cdecl _mm256_max_pd(__m256d, __m256d);  /* vmaxpd */
extern __m256d __cdecl _mm256_min_pd(__m256d, __m256d);  /* vminpd */
extern __m256d __cdecl _mm256_sqrt_pd(__m256d);  /* vsqrtpd */
extern __m256d __cdecl _mm256_round_pd(__m256d, const int);  /* vroundpd */

/* logical */
extern __m256 __cdecl _mm256_and_ps(__m256, __m256);  /* vandps */
extern __m256 __cdecl _mm256_andnot_ps(__m256, __m256);  /* vandnps */
extern __m256 __cdecl _mm256_or_ps(__m256, __m256);  /* vorps */
extern __m256 __cdecl _mm256_xor_ps(__m256, __m256);  /* vxorps */
extern __m256d __cdecl _mm256_and_pd(__m256d, __m256d);  /* vandpd */
extern __m256d __cdecl _mm256_andnot_pd(__m256d, __m256d);  /* vandnpd */
extern __m256d __cdecl _mm256_or_pd(__m256d, __m256d);  /* vorpd */
extern __m256d __cdecl _mm256_xor_pd(__m256d, __m256d);  /* vxorpd */

/* comparison */
extern __m128 __cdecl _mm_cmp_ss(__m128, __m128, const int);  /* vcmpss */
extern __m128d __cdecl _mm_cmp_sd(__m128d, __m128d, const int);  /* vcmpsd */
extern __m128 __cdecl _mm_cmp_ps(__m128, __m128, const int);  /* vcmpps */
extern __m128d __cdecl _mm_cmp_pd(__m128d, __m128d, const int);  /* vcmppd */
extern __m256 __cdecl _mm256_cmp_ps(__m256, __m256, const int);  /* vcmpps */
extern __m256d __cdecl _mm256_cmp_pd(__m256d, __m256d, const int);  /* vcmppd */

/* bitwise comparison */
extern int __cdecl _mm_testz_ps(__m128, __m128);  /* composite (vtestps) */
extern int __cdecl _mm_testc_ps(__m128, __m128);  /* composite (vtestps) */
extern int __cdecl _mm_testnzc_ps(__m128, __m128);  /* composite (vtestps) */
extern int __cdecl _mm_testz_pd(__m128d, __m128d);  /* composite (vtestpd) */
extern int __cdecl _mm_testc_pd(__m128d, __m128d);  /* composite (vtestpd) */
extern int __cdecl _mm_testnzc_pd(__m128d, __m128d);  /* composite (vtestpd) */
extern int __cdecl _mm256_testz_ps(__m256, __m256);  /* composite (vtestps) */
extern int __cdecl _mm256_testc_ps(__m256, __m256);  /* composite (vtestps) */
extern int __cdecl _mm256_testnzc_ps(__m256, __m256);  /* composite (vtestps) */
extern int __cdecl _mm256_testz_pd(__m256d, __m256d);  /* composite (vtestpd) */
extern int __cdecl _mm256_testc_pd(__m256d, __m256d);  /* composite (vtestpd) */
extern int __cdecl _mm256_testnzc_pd(__m256d, __m256d);  /* composite (vtestpd) */
extern int __cdecl _mm256_testz_si256(__m256i, __m256i);  /* composite (vptest) */
extern int __cdecl _mm256_testc_si256(__m256i, __m256i);  /* composite (vptest) */
extern int __cdecl _mm256_testnzc_si256(__m256i, __m256i);  /* composite (vptest) */

/* conversion */
extern __m128 __cdecl _mm256_cvtpd_ps(__m256d);  /* vcvtpd2ps */
extern __m128i __cdecl _mm256_cvtpd_epi32(__m256d);  /* vcvtpd2dq */
extern __m128i __cdecl _mm256_cvttpd_epi32(__m256d);  /* vcvttpd2dq */
extern __m256d __cdecl _mm256_cvtps_pd(__m128);  /* vcvtps2pd */
extern __m256i __cdecl _mm256_cvtps_epi32(__m256);  /* vcvtps2dq */
extern __m256i __cdecl _mm256_cvttps_epi32(__m256);  /* vcvttps2dq */
extern __m256 __cdecl _mm256_cvtepi32_ps(__m256i);  /* vcvtdq2ps */
extern __m256d __cdecl _mm256_cvtepi32_pd(__m128i);  /* vcvtdq2pd */

/* blend */
extern __m256 __cdecl _mm256_blend_ps(__m256, __m256, const int);  /* vblendps */
extern __m256 __cdecl _mm256_blendv_ps(__m256, __m256, __m256);  /* vblendvps */
extern __m256d __cdecl _mm256_blend_pd(__m256d, __m256d, const int);  /* vblendpd */
extern __m256d __cdecl _mm256_blendv_pd(__m256d, __m256d, __m256d);  /* vblendvpd */

/* permute */
extern __m128 __cdecl _mm_permute_ps(__m128, const int);  /* vpermilps */
extern __m128 __cdecl _mm_permutevar_ps(__m128, __m128i);  /* vpermilps */
extern __m128d __cdecl _mm_permute_pd(__m128d, const int);  /* vpermilpd */
extern __m128d __cdecl _mm_permutevar_pd(__m128d, __m128i);  /* vpermilpd */
extern __m256 __cdecl _mm256_permute_ps(__m256, const int);  /* vpermilps */
extern __m256 __cdecl _mm256_permutevar_ps(__m256, __m256i);  /* vpermilps */
extern __m256d __cdecl _mm256_permute_pd(__m256d, const int);  /* vpermilpd */
extern __m256d __cdecl _mm256_permutevar_pd(__m256d, __m256i);  /* vpermilpd */
extern __m256 __cdecl _mm256_permute2f128_ps(__m256, __m256, const int);  /* vperm2f128 */
extern __m256d __cdecl _mm256_permute2f128_pd(__m256d, __m256d, const int);  /* vperm2f128 */
extern __m256i __cdecl _mm256_permute2f128_si256(__m256i, __m256i, const int);  /* vperm2f128 */

/* load/store */
extern __m128 __cdecl _mm_broadcast_ss(const float *);  /* vbroadcastss */
extern __m256 __cdecl _mm256_broadcast_ss(const float *);  /* vbroadcastss */
extern __m256d __cdecl _mm256_broadcast_sd(const double *);  /* vbroadcastsd */
extern __m256 __cdecl _mm256_load_ps(const float *);  /* vmovaps */
extern __m256d __cdecl _mm256_load_pd(const double *);  /* vmovapd */
extern __m256i __cdecl _mm256_load_si256(const __m256i *);  /* vmovdqa */
extern __m256 __cdecl _mm256_loadu_ps(const float *);  /* vmovups */
extern __m256d __cdecl _mm256_loadu_pd(const double *);  /* vmovupd */
extern __m256i __cdecl _mm256_loadu_si256(const __m256i *);  /* vmovdqu */
extern __m128 __cdecl _mm_maskload_ps(const float *, __m128i);  /* vmaskmovps */
extern __m128d __cdecl _mm_maskload_pd(const double *, __m128i);  /* vmaskmovpd */
extern __m256 __cdecl _mm256_maskload_ps(const float *, __m256i);  /* vmaskmovps */
extern __m256d __cdecl _mm256_maskload_pd(const double *, __m256i);  /* vmaskmovpd */
extern void __cdecl _mm256_store_ps(float *, __m256);  /* vmovaps */
extern void __cdecl _mm256_store_pd(double *, __m256d);  /* vmovapd */
extern void __cdecl _mm256_storeu_ps(float *, __m256);  /* vmovups */
extern void __cdecl _mm256_storeu_pd(double *, __m256d);  /* vmovupd */
extern void __cdecl _mm256_store_si256(__m256i *, __m256i);  /* vmovdqa */
extern void __cdecl _mm256_storeu_si256(__m256i *, __m256i);  /* vmovdqu */
extern void __cdecl _mm256_stream_ps(float *, __m256);  /* vmovntps */
extern void __cdecl _mm256_stream_pd(double *, __m256d);  /* vmovntpd */
extern void __cdecl _mm256_stream_si256(__m256i *, __m256i);  /* vmovntdq */
extern void __cdecl _mm_maskstore_ps(float *, __m128i, __m128);  /* vmaskmovps */
extern void __cdecl _mm_maskstore_pd(double *, __m128i, __m128d);  /* vmaskmovpd */
extern void __cdecl _mm256_maskstore_ps(float *, __m256i, __m256);  /* vmaskmovps */
extern void __cdecl _mm256_maskstore_pd(double *, __m256i, __m256d);  /* vmaskmovpd */

/* system */
extern unsigned long long __cdecl _xgetbv(unsigned int);  /* xgetbv */
extern void __cdecl _xsetbv(unsigned int, unsigned long long);  /* xsetbv */
extern void __cdecl _fxsave(void *);  /* fxsave */
extern void __cdecl _fxrstor(void *);  /* fxrstor */
extern void __cdecl _xsave(void *, unsigned long long);  /* xsave */
extern void __cdecl _xsaveopt(void *, unsigned long long);  /* xsaveopt */
extern void __cdecl _xrstor(void *, unsigned long long);  /* xrstor */
#if __POCC_TARGET__ == 3
extern void __cdecl _fxsave64(void *);  /* fxsave64 */
extern void __cdecl _fxrstor64(void *);  /* fxrstor64 */
extern void __cdecl _xsave64(void *, unsigned long long);  /* xsave64 */
extern void __cdecl _xsaveopt64(void *, unsigned long long);  /* xsaveopt64 */
extern void __cdecl _xrstor64(void *, unsigned long long);  /* xrstor64 */
#endif /* __POCC_TARGET__ == 3 */

/* misc */
extern __m128 __cdecl _mm256_extractf128_ps(__m256, const int);  /* vextractf128 */
extern __m128d __cdecl _mm256_extractf128_pd(__m256d, const int);  /* vextractf128 */
extern __m128i __cdecl _mm256_extractf128_si256(__m256i, const int);  /* vextractf128 */
extern __m256 __cdecl _mm256_insertf128_ps(__m256, __m128, const int);  /* vinsertf128 */
extern __m256d __cdecl _mm256_insertf128_pd(__m256d, __m128d, const int);  /* vinsertf128 */
extern __m256i __cdecl _mm256_insertf128_si256(__m256i, __m128i, const int);  /* vinsertf128 */
extern __m256i __cdecl _mm256_lddqu_si256(const __m256i *);  /* vlddqu */
extern __m256d __cdecl _mm256_movedup_pd(__m256d);  /* vmovddup */
extern __m256 __cdecl _mm256_moveldup_ps(__m256);  /* vmovsldup */
extern __m256 __cdecl _mm256_movehdup_ps(__m256);  /* vmovshdup */
extern int __cdecl _mm256_movemask_ps(__m256);  /* vmovmskps */
extern int __cdecl _mm256_movemask_pd(__m256d);  /* vmovmskpd */
extern __m256 __cdecl _mm256_shuffle_ps(__m256, __m256, const int);  /* vshufps */
extern __m256d __cdecl _mm256_shuffle_pd(__m256d, __m256d, const int);  /* vshufpd */
extern __m256 __cdecl _mm256_unpacklo_ps(__m256, __m256);  /* vunpcklps */
extern __m256d __cdecl _mm256_unpacklo_pd(__m256d, __m256d);  /* vunpcklpd */
extern __m256 __cdecl _mm256_unpackhi_ps(__m256, __m256);  /* vunpckhps */
extern __m256d __cdecl _mm256_unpackhi_pd(__m256d, __m256d);  /* vunpckhpd */
extern void __cdecl _mm256_zeroall(void);  /* vzeroall */
extern void __cdecl _mm256_zeroupper(void);  /* vzeroupper */
extern __m256 __cdecl _mm256_setzero_ps(void);  /* vxorps */
extern __m256d __cdecl _mm256_setzero_pd(void);  /* vxorpd */
extern __m256i __cdecl _mm256_setzero_si256(void);  /* vpxor */

extern __m256 __cdecl _mm256_set_ps(float, float, float, float, float, float, float, float);  /* composite */
extern __m256 __cdecl _mm256_setr_ps(float, float, float, float, float, float, float, float);  /* composite */
extern __m256d __cdecl _mm256_set_pd(double, double, double, double);  /* composite */
extern __m256d __cdecl _mm256_setr_pd(double, double, double, double);  /* composite */
extern __m256i __cdecl _mm256_set_epi32(int, int, int, int, int, int, int, int);  /* composite */
extern __m256i __cdecl _mm256_setr_epi32(int, int, int, int, int, int, int, int);  /* composite */
extern __m256i __cdecl _mm256_set_epi64x(long long, long long, long long, long long);  /* composite */
extern __m256i __cdecl _mm256_setr_epi64x(long long, long long, long long, long long);  /* composite */
extern __m256 __cdecl _mm256_set1_ps(float);  /* composite */
extern __m256d __cdecl _mm256_set1_pd(double);  /* composite */
extern __m256i __cdecl _mm256_set1_epi32(int);  /* composite */
extern __m256i __cdecl _mm256_set1_epi64x(long long);  /* composite */

#undef _CRTPCK

static inline __m256i __cdecl _mm256_set_epi8(char n1,  char n2,  char n3,  char n4,  char n5,  char n6,  char n7,  char n8,  char n9,  char n10, char n11, char n12, char n13, char n14, char n15, char n16, 
                                              char n17, char n18, char n19, char n20, char n21, char n22, char n23, char n24, char n25, char n26, char n27, char n28, char n29, char n30, char n31, char n32) {
#define _CRTPCK(a,b,c,d)  (((unsigned char)(d)<<24)|((unsigned char)(c)<<16)|((unsigned char)(b)<<8)|((unsigned char)(a)))
    return _mm256_set_epi32(_CRTPCK(n4,n3,n2,n1), _CRTPCK(n8,n7,n6,n5), _CRTPCK(n12,n11,n10,n9), _CRTPCK(n16,n15,n14,n13), _CRTPCK(n20,n19,n18,n17), _CRTPCK(n24,n23,n22,n21), _CRTPCK(n28,n27,n26,n25), _CRTPCK(n32,n31,n30,n29));
#undef _CRTPCK
}

static inline __m256i __cdecl _mm256_setr_epi8(char n1,  char n2,  char n3,  char n4,  char n5,  char n6,  char n7,  char n8,  char n9,  char n10, char n11, char n12, char n13, char n14, char n15, char n16, 
                                               char n17, char n18, char n19, char n20, char n21, char n22, char n23, char n24, char n25, char n26, char n27, char n28, char n29, char n30, char n31, char n32) {
#define _CRTPCK(a,b,c,d)  (((unsigned char)(a)<<24)|((unsigned char)(b)<<16)|((unsigned char)(c)<<8)|((unsigned char)(d)))
    return _mm256_setr_epi32(_CRTPCK(n4,n3,n2,n1), _CRTPCK(n8,n7,n6,n5), _CRTPCK(n12,n11,n10,n9), _CRTPCK(n16,n15,n14,n13), _CRTPCK(n20,n19,n18,n17), _CRTPCK(n24,n23,n22,n21), _CRTPCK(n28,n27,n26,n25), _CRTPCK(n32,n31,n30,n29));
#undef _CRTPCK
}

static inline __m256i __cdecl _mm256_set_epi16(short n1, short n2, short n3, short n4, short n5, short n6, short n7, short n8, short n9, short n10, short n11, short n12, short n13, short n14, short n15, short n16) {
#define _CRTPCK(a,b)  (((unsigned short)(b)<<16)|((unsigned short)(a)))
    return _mm256_set_epi32(_CRTPCK(n2,n1), _CRTPCK(n4,n3), _CRTPCK(n6,n5), _CRTPCK(n8,n7), _CRTPCK(n10,n9), _CRTPCK(n12,n11), _CRTPCK(n14,n13), _CRTPCK(n16,n15));
#undef _CRTPCK
}

static inline __m256i __cdecl _mm256_setr_epi16(short n1, short n2, short n3, short n4, short n5, short n6, short n7, short n8, short n9, short n10, short n11, short n12, short n13, short n14, short n15, short n16) {
#define _CRTPCK(a,b)  (((unsigned short)(a)<<16)|((unsigned short)(b)))
    return _mm256_set_epi32(_CRTPCK(n2,n1), _CRTPCK(n4,n3), _CRTPCK(n6,n5), _CRTPCK(n8,n7), _CRTPCK(n10,n9), _CRTPCK(n12,n11), _CRTPCK(n14,n13), _CRTPCK(n16,n15));
#undef _CRTPCK
}

static inline __m256i __cdecl _mm256_set1_epi8(char n) {
#define _CRTPCK(a)  (((unsigned char)(a)<<24)|((unsigned char)(a)<<16)|((unsigned char)(a)<<8)|((unsigned char)(a)))
    return _mm256_set_epi32(_CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n));
#undef _CRTPCK
}

static inline __m256i __cdecl _mm256_set1_epi16(short n) {
#define _CRTPCK(a)  (((unsigned short)(a)<<16)|((unsigned short)(a)))
    return _mm256_set_epi32(_CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n), _CRTPCK(n));
#undef _CRTPCK
}

#endif /* __POCC__ >= 700 && __POCC_TARGET__ == 3 */

#if __POCC__ >= 800 && __POCC_TARGET__ == 3

/* FMA operations (use the assembler, dude!) */
/*
__m128  __cdecl _mm_fmadd_ps(__m128, __m128, __m128);
__m128d __cdecl _mm_fmadd_pd(__m128d, __m128d, __m128d);
__m128  __cdecl _mm_fmadd_ss(__m128, __m128, __m128);
__m128d __cdecl _mm_fmadd_sd(__m128d, __m128d, __m128d);
__m128  __cdecl _mm_fmsub_ps(__m128, __m128, __m128);
__m128d __cdecl _mm_fmsub_pd(__m128d, __m128d, __m128d);
__m128  __cdecl _mm_fmsub_ss(__m128, __m128, __m128);
__m128d __cdecl _mm_fmsub_sd(__m128d, __m128d, __m128d);
__m128  __cdecl _mm_fnmadd_ps(__m128, __m128, __m128);
__m128d __cdecl _mm_fnmadd_pd(__m128d, __m128d, __m128d);
__m128  __cdecl _mm_fnmadd_ss(__m128, __m128, __m128);
__m128d __cdecl _mm_fnmadd_sd(__m128d, __m128d, __m128d);
__m128  __cdecl _mm_fnmsub_ps(__m128, __m128, __m128);
__m128d __cdecl _mm_fnmsub_pd(__m128d, __m128d, __m128d);
__m128  __cdecl _mm_fnmsub_ss(__m128, __m128, __m128);
__m128d __cdecl _mm_fnmsub_sd(__m128d, __m128d, __m128d);

__m256  __cdecl _mm256_fmadd_ps(__m256, __m256, __m256);
__m256d __cdecl _mm256_fmadd_pd(__m256d, __m256d, __m256d);
__m256  __cdecl _mm256_fmsub_ps(__m256, __m256, __m256);
__m256d __cdecl _mm256_fmsub_pd(__m256d, __m256d, __m256d);
__m256  __cdecl _mm256_fnmadd_ps(__m256, __m256, __m256);
__m256d __cdecl _mm256_fnmadd_pd(__m256d, __m256d, __m256d);
__m256  __cdecl _mm256_fnmsub_ps(__m256, __m256, __m256);
__m256d __cdecl _mm256_fnmsub_pd(__m256d, __m256d, __m256d);

__m128  __cdecl _mm_fmaddsub_ps(__m128, __m128, __m128);
__m128d __cdecl _mm_fmaddsub_pd(__m128d, __m128d, __m128d);
__m128  __cdecl _mm_fmsubadd_ps(__m128, __m128, __m128);
__m128d __cdecl _mm_fmsubadd_pd(__m128d, __m128d, __m128d);

__m256  __cdecl _mm256_fmaddsub_ps(__m256, __m256, __m256);
__m256d __cdecl _mm256_fmaddsub_pd(__m256d, __m256d, __m256d);
__m256  __cdecl _mm256_fmsubadd_ps(__m256, __m256, __m256);
__m256d __cdecl _mm256_fmsubadd_pd(__m256d, __m256d, __m256d);
*/

/* Integer 256-bit vector comparison operations */
extern __m256i __cdecl _mm256_cmpeq_epi8(__m256i, __m256i);  /* vpcmpeqb */
extern __m256i __cdecl _mm256_cmpeq_epi16(__m256i, __m256i);  /* vpcmpeqw */
extern __m256i __cdecl _mm256_cmpeq_epi32(__m256i, __m256i);  /* vpcmpeqd */
extern __m256i __cdecl _mm256_cmpeq_epi64(__m256i, __m256i);  /* vpcmpeqq */

extern __m256i __cdecl _mm256_cmpgt_epi8(__m256i, __m256i);  /* vpcmpgtb */
extern __m256i __cdecl _mm256_cmpgt_epi16(__m256i, __m256i);  /* vpcmpgtw */
extern __m256i __cdecl _mm256_cmpgt_epi32(__m256i, __m256i);  /* vpcmpgtd */
extern __m256i __cdecl _mm256_cmpgt_epi64(__m256i, __m256i);  /* vpcmpgtq */

/* Integer 256-bit vector MIN/MAX operations */
extern __m256i __cdecl _mm256_max_epi8(__m256i, __m256i);  /* vpmaxsb */
extern __m256i __cdecl _mm256_max_epi16(__m256i, __m256i);  /* vpmaxsw */
extern __m256i __cdecl _mm256_max_epi32(__m256i, __m256i);  /* vpmaxsd */
extern __m256i __cdecl _mm256_max_epu8(__m256i, __m256i);  /* vpmaxub */
extern __m256i __cdecl _mm256_max_epu16(__m256i, __m256i);  /* vpmaxuw */
extern __m256i __cdecl _mm256_max_epu32(__m256i, __m256i);  /* vpmaxud */

extern __m256i __cdecl _mm256_min_epi8(__m256i, __m256i);  /* vpminsb */
extern __m256i __cdecl _mm256_min_epi16(__m256i, __m256i);  /* vpminsw */
extern __m256i __cdecl _mm256_min_epi32(__m256i, __m256i);  /* vpminsd */
extern __m256i __cdecl _mm256_min_epu8(__m256i, __m256i);  /* vpminub */
extern __m256i __cdecl _mm256_min_epu16(__m256i, __m256i);  /* vpminuw */
extern __m256i __cdecl _mm256_min_epu32(__m256i, __m256i);  /* vpminud */

/* Integer 256-bit vector logical operations */
extern __m256i __cdecl _mm256_and_si256(__m256i, __m256i);  /* vpand */
extern __m256i __cdecl _mm256_andnot_si256(__m256i, __m256i);  /* vpandn */
extern __m256i __cdecl _mm256_or_si256(__m256i, __m256i);  /* vpor */
extern __m256i __cdecl _mm256_xor_si256(__m256i, __m256i);  /* vpxor */

/* Integer 256-bit vector arithmetic operations */
extern __m256i __cdecl _mm256_abs_epi8(__m256i);  /* vpabsb */
extern __m256i __cdecl _mm256_abs_epi16(__m256i);  /* vpabsw */
extern __m256i __cdecl _mm256_abs_epi32(__m256i);  /* vpabsd */

extern __m256i __cdecl _mm256_add_epi8(__m256i, __m256i);  /* vpaddb */
extern __m256i __cdecl _mm256_add_epi16(__m256i, __m256i);  /* vpaddw */
extern __m256i __cdecl _mm256_add_epi32(__m256i, __m256i);  /* vpaddd */
extern __m256i __cdecl _mm256_add_epi64(__m256i, __m256i);  /* vpaddq */

extern __m256i __cdecl _mm256_adds_epi8(__m256i, __m256i);  /* vpaddsb */
extern __m256i __cdecl _mm256_adds_epi16(__m256i, __m256i);  /* vpaddsw */
extern __m256i __cdecl _mm256_adds_epu8(__m256i, __m256i);  /* vpaddusb */
extern __m256i __cdecl _mm256_adds_epu16(__m256i, __m256i);  /* vpaddusw */

extern __m256i __cdecl _mm256_sub_epi8(__m256i, __m256i);  /* vpsubb */
extern __m256i __cdecl _mm256_sub_epi16(__m256i, __m256i);  /* vpsubw */
extern __m256i __cdecl _mm256_sub_epi32(__m256i, __m256i);  /* vpsubd */
extern __m256i __cdecl _mm256_sub_epi64(__m256i, __m256i);  /* vpsubq */

extern __m256i __cdecl _mm256_subs_epi8(__m256i, __m256i);  /* vpsubsb */
extern __m256i __cdecl _mm256_subs_epi16(__m256i, __m256i);  /* vpsubsw */
extern __m256i __cdecl _mm256_subs_epu8(__m256i, __m256i);  /* vpsubusb */
extern __m256i __cdecl _mm256_subs_epu16(__m256i, __m256i);  /* vpsubusw */

extern __m256i __cdecl _mm256_avg_epu8(__m256i, __m256i);  /* vpavgb */
extern __m256i __cdecl _mm256_avg_epu16(__m256i, __m256i);  /* vpavgw */

extern __m256i __cdecl _mm256_hadd_epi16(__m256i, __m256i);  /* vphaddw */
extern __m256i __cdecl _mm256_hadd_epi32(__m256i, __m256i);  /* vphaddd */
extern __m256i __cdecl _mm256_hadds_epi16(__m256i, __m256i);  /* vphaddsw */

extern __m256i __cdecl _mm256_hsub_epi16(__m256i, __m256i);  /* vphsubw */
extern __m256i __cdecl _mm256_hsub_epi32(__m256i, __m256i);  /* vphsubd */
extern __m256i __cdecl _mm256_hsubs_epi16(__m256i, __m256i);  /* vphsubsw */

extern __m256i __cdecl _mm256_madd_epi16(__m256i, __m256i);  /* vpmaddwd */
extern __m256i __cdecl _mm256_maddubs_epi16(__m256i, __m256i);  /* vpmaddubsw */

extern __m256i __cdecl _mm256_mulhi_epi16(__m256i, __m256i);  /* vpmulhw */
extern __m256i __cdecl _mm256_mulhi_epu16(__m256i, __m256i);  /* vpmulhuw */

extern __m256i __cdecl _mm256_mullo_epi16(__m256i, __m256i);  /* vpmullw */
extern __m256i __cdecl _mm256_mullo_epi32(__m256i, __m256i);  /* vpmulld */

extern __m256i __cdecl _mm256_mul_epi32(__m256i, __m256i);  /* vpmuldq */
extern __m256i __cdecl _mm256_mul_epu32(__m256i, __m256i);  /* vpmuludq */

extern __m256i __cdecl _mm256_mulhrs_epi16(__m256i, __m256i);  /* vpmulhrsw */

extern __m256i __cdecl _mm256_sign_epi8(__m256i, __m256i);  /* vpsignb */
extern __m256i __cdecl _mm256_sign_epi16(__m256i, __m256i);  /* vpsignw */
extern __m256i __cdecl _mm256_sign_epi32(__m256i, __m256i);  /* vpsignd */

extern __m256i __cdecl _mm256_sad_epu8(__m256i, __m256i);  /* vpsadbw */
extern __m256i __cdecl _mm256_mpsadbw_epu8(__m256i, __m256i, const int);  /* vmpsadbw */

/* Integer 128/256-bit vector arithmetic/logical shift operations */
extern __m128i __cdecl _mm_sllv_epi32(__m128i, __m128i);  /* vpsllvd */
extern __m128i __cdecl _mm_sllv_epi64(__m128i, __m128i);  /* vpsllvq */

extern __m128i __cdecl _mm_srav_epi32(__m128i, __m128i);  /* vpsravd */

extern __m128i __cdecl _mm_srlv_epi32(__m128i, __m128i);  /* vpsrlvd */
extern __m128i __cdecl _mm_srlv_epi64(__m128i, __m128i);  /* vpsrlvq */

extern __m256i __cdecl _mm256_slli_si256(__m256i, const int);  /* vpslldq */
extern __m256i __cdecl _mm256_srli_si256(__m256i, const int);  /* vpsrldq */

extern __m256i __cdecl _mm256_sll_epi16(__m256i, __m128i);  /* vpsllw */
extern __m256i __cdecl _mm256_sll_epi32(__m256i, __m128i);  /* vpslld */
extern __m256i __cdecl _mm256_sll_epi64(__m256i, __m128i);  /* vpsllq */

extern __m256i __cdecl _mm256_slli_epi16(__m256i, int);  /* vpsllw */
extern __m256i __cdecl _mm256_slli_epi32(__m256i, int);  /* vpslld */
extern __m256i __cdecl _mm256_slli_epi64(__m256i, int);  /* vpsllq */

extern __m256i __cdecl _mm256_sllv_epi32(__m256i, __m256i);  /* vpsllvd */
extern __m256i __cdecl _mm256_sllv_epi64(__m256i, __m256i);  /* vpsllvq */

extern __m256i __cdecl _mm256_sra_epi16(__m256i, __m128i);  /* vpsraw */
extern __m256i __cdecl _mm256_sra_epi32(__m256i, __m128i);  /* vpsrad */
extern __m256i __cdecl _mm256_srai_epi16(__m256i, int);  /* vpsraw */
extern __m256i __cdecl _mm256_srai_epi32(__m256i, int);  /* vpsrad */

extern __m256i __cdecl _mm256_srav_epi32(__m256i, __m256i);  /* vpsravd */

extern __m256i __cdecl _mm256_srl_epi16(__m256i, __m128i);  /* vpsrlw */
extern __m256i __cdecl _mm256_srl_epi32(__m256i, __m128i);  /* vpsrld */
extern __m256i __cdecl _mm256_srl_epi64(__m256i, __m128i);  /* vpsrlq */

extern __m256i __cdecl _mm256_srli_epi16(__m256i, int);  /* vpsrlw */
extern __m256i __cdecl _mm256_srli_epi32(__m256i, int);  /* vpsrld */
extern __m256i __cdecl _mm256_srli_epi64(__m256i, int);  /* vpsrlq */

extern __m256i __cdecl _mm256_srlv_epi32(__m256i, __m256i);  /* vpsrlvd */
extern __m256i __cdecl _mm256_srlv_epi64(__m256i, __m256i);  /* vpsrlvq */

/* Integer 128/256-bit vector pack/blend/shuffle/insert/extract operations */
extern __m256i __cdecl _mm256_alignr_epi8(__m256i, __m256i, const int);  /* vpalignr */

extern __m128i __cdecl _mm_blend_epi32(__m128i, __m128i, const int);  /* vpblendd */
extern __m256i __cdecl _mm256_blend_epi16(__m256i, __m256i, const int);  /* vpblendw */
extern __m256i __cdecl _mm256_blend_epi32(__m256i,__m256i, const int);  /* vpblendd */
extern __m256i __cdecl _mm256_blendv_epi8(__m256i, __m256i, __m256i);  /* vpblendvb */

extern __m256i __cdecl _mm256_packs_epi16(__m256i, __m256i);  /* vpacksswb */
extern __m256i __cdecl _mm256_packs_epi32(__m256i, __m256i);  /* vpackssdw */
extern __m256i __cdecl _mm256_packus_epi16(__m256i, __m256i);  /* vpackuswb */
extern __m256i __cdecl _mm256_packus_epi32(__m256i, __m256i);  /* vpackusdw */

extern __m256i __cdecl _mm256_unpackhi_epi8(__m256i, __m256i);  /* vpunpckhbw */
extern __m256i __cdecl _mm256_unpackhi_epi16(__m256i, __m256i);  /* vpunpckhwd */
extern __m256i __cdecl _mm256_unpackhi_epi32(__m256i, __m256i);  /* vpunpckhdq */
extern __m256i __cdecl _mm256_unpackhi_epi64(__m256i, __m256i);  /* vpunpckhqdq */

extern __m256i __cdecl _mm256_unpacklo_epi8(__m256i, __m256i);  /* vpunpcklbw */
extern __m256i __cdecl _mm256_unpacklo_epi16(__m256i, __m256i);  /* vpunpcklwd */
extern __m256i __cdecl _mm256_unpacklo_epi32(__m256i, __m256i);  /* vpunpckldq */
extern __m256i __cdecl _mm256_unpacklo_epi64(__m256i, __m256i);  /* vpunpcklqdq */

extern __m256i __cdecl _mm256_shuffle_epi8(__m256i, __m256i);  /* vpshufb */
extern __m256i __cdecl _mm256_shuffle_epi32(__m256i, const int);  /* vpshufd */

extern __m256i __cdecl _mm256_shufflehi_epi16(__m256i, const int);  /* vpshufhw */
extern __m256i __cdecl _mm256_shufflelo_epi16(__m256i, const int);  /* vpshuflw */

extern __m128i __cdecl _mm256_extracti128_si256(__m256i, const int);  /* vextracti128 */
extern __m256i __cdecl _mm256_inserti128_si256(__m256i, __m128i, const int);  /* vinserti128 */

/* Scalar to 128/256-bit vector broadcast operations */
extern __m128  __cdecl _mm_broadcastss_ps(__m128);  /* vbroadcastss */
extern __m128d __cdecl _mm_broadcastsd_pd(__m128d);  /* vbroadcastsd */

extern __m128i __cdecl _mm_broadcastb_epi8(__m128i);  /* vpbroadcastb */
extern __m128i __cdecl _mm_broadcastw_epi16(__m128i);  /* vpbroadcastw */
extern __m128i __cdecl _mm_broadcastd_epi32(__m128i);  /* vpbroadcastd */
extern __m128i __cdecl _mm_broadcastq_epi64(__m128i);  /* vpbroadcastq */

extern __m256  __cdecl _mm256_broadcastss_ps(__m128);  /* vbroadcastss */
extern __m256d __cdecl _mm256_broadcastsd_pd(__m128d);  /* vbroadcastsd */

extern __m256i __cdecl _mm256_broadcastb_epi8(__m128i);  /* vpbroadcastb */
extern __m256i __cdecl _mm256_broadcastw_epi16(__m128i);  /* vpbroadcastw */
extern __m256i __cdecl _mm256_broadcastd_epi32(__m128i);  /* vpbroadcastd */
extern __m256i __cdecl _mm256_broadcastq_epi64(__m128i);  /* vpbroadcastq */

extern __m256i __cdecl _mm256_broadcastsi128_si256(__m128i);  /* composite */

/* Integer 256-bit vector signed/unsigned extension operations */
extern __m256i __cdecl _mm256_cvtepi8_epi16(__m128i);  /* vpmovsxbw */
extern __m256i __cdecl _mm256_cvtepi8_epi32(__m128i);  /* vpmovsxbd */
extern __m256i __cdecl _mm256_cvtepi8_epi64(__m128i);  /* vpmovsxbq */
extern __m256i __cdecl _mm256_cvtepi16_epi32(__m128i);  /* vpmovsxwd */
extern __m256i __cdecl _mm256_cvtepi16_epi64(__m128i);  /* vpmovsxwq */
extern __m256i __cdecl _mm256_cvtepi32_epi64(__m128i);  /* vpmovsxdq */

extern __m256i __cdecl _mm256_cvtepu8_epi16(__m128i);  /* vpmovzxbw */
extern __m256i __cdecl _mm256_cvtepu8_epi32(__m128i);  /* vpmovzxbd */
extern __m256i __cdecl _mm256_cvtepu8_epi64(__m128i);  /* vpmovzxbq */
extern __m256i __cdecl _mm256_cvtepu16_epi32(__m128i);  /* vpmovzxwd */
extern __m256i __cdecl _mm256_cvtepu16_epi64(__m128i);  /* vpmovzxwq */
extern __m256i __cdecl _mm256_cvtepu32_epi64(__m128i);  /* vpmovzxdq */

/* whatever */
extern int __cdecl _mm256_movemask_epi8(__m256i);  /* vpmovmskb */

/* Masked load/store operations */
extern __m128i __cdecl _mm_maskload_epi32(const int *, __m128i);  /* vpmaskmovd */
extern __m128i __cdecl _mm_maskload_epi64(const long long *, __m128i);  /* vpmaskmovq */

extern void __cdecl _mm_maskstore_epi32(int *, __m128i, __m128i);  /* vpmaskmovd */
extern void __cdecl _mm_maskstore_epi64(long long *, __m128i, __m128i);  /* vpmaskmovq */

extern __m256i __cdecl _mm256_maskload_epi32(const int *, __m256i);  /* vpmaskmovd */
extern __m256i __cdecl _mm256_maskload_epi64(const long long *, __m256i);  /* vpmaskmovq */

extern void __cdecl _mm256_maskstore_epi32(int *, __m256i, __m256i);  /* vpmaskmovd */
extern void __cdecl _mm256_maskstore_epi64(long long *, __m256i, __m256i);  /* vpmaskmovq */

/* Permute elements in vector operations */
extern __m256  __cdecl _mm256_permutevar8x32_ps(__m256, __m256i);  /* vpermps */
extern __m256i __cdecl _mm256_permutevar8x32_epi32(__m256i, __m256i);  /* vpermd */

extern __m256d __cdecl _mm256_permute4x64_pd(__m256d, const int);  /* vpermpd */
extern __m256i __cdecl _mm256_permute4x64_epi64(__m256i, const int);  /* vpermq */

extern __m256i __cdecl _mm256_permute2x128_si256(__m256i, __m256i, const int);  /* vperm2i128 */

/* Load 32-bytes from memory using non-temporal aligned hint */
extern __m256i __cdecl _mm256_stream_load_si256(const __m256i *);  /* vmovntdqa */

/* Masked gather from memory to vector register operations */
extern __m128 __cdecl _mm_mask_i32gather_ps(__m128, const float *, __m128i, __m128, const int);  /* vgatherdps */
extern __m128 __cdecl _mm_mask_i64gather_ps(__m128, const float *, __m128i, __m128, const int);  /* vgatherqps */
extern __m128d __cdecl _mm_mask_i32gather_pd(__m128d, const double *, __m128i, __m128d, const int);  /* vgatherdpd */
extern __m128d __cdecl _mm_mask_i64gather_pd(__m128d, const double *, __m128i, __m128d, const int);  /* vgatherqpd */

extern __m128i __cdecl _mm_mask_i32gather_epi32(__m128i, const int *, __m128i, __m128i, const int);  /* vpgatherdd */
extern __m128i __cdecl _mm_mask_i32gather_epi64(__m128i, const long long *, __m128i, __m128i, const int);  /* vpgatherdq */
extern __m128i __cdecl _mm_mask_i64gather_epi32(__m128i, const int *, __m128i, __m128i, const int);  /* vpgatherqd */
extern __m128i __cdecl _mm_mask_i64gather_epi64(__m128i, const long long *, __m128i, __m128i, const int);  /* vpgatherqq */

extern __m256 __cdecl _mm256_mask_i32gather_ps(__m256, const float *, __m256i, __m256, const int);  /* vgatherdps */
extern __m128 __cdecl _mm256_mask_i64gather_ps(__m128, const float *, __m256i, __m128, const int);  /* vgatherqps */
extern __m256d __cdecl _mm256_mask_i32gather_pd(__m256d, const double *, __m128i, __m256d, const int);  /* vgatherdpd */
extern __m256d __cdecl _mm256_mask_i64gather_pd(__m256d, const double *, __m256i, __m256d, const int);  /* vgatherqpd */

extern __m256i __cdecl _mm256_mask_i32gather_epi32(__m256i, const int *, __m256i, __m256i, const int);  /* vpgatherdd */
extern __m256i __cdecl _mm256_mask_i32gather_epi64(__m256i, const long long *, __m128i, __m256i, const int);  /* vpgatherdq */
extern __m128i __cdecl _mm256_mask_i64gather_epi32(__m128i, const int *, __m256i, __m128i, const int);  /* vpgatherqd */
extern __m256i __cdecl _mm256_mask_i64gather_epi64(__m256i, const long long *, __m256i, __m256i, const int);  /* vpgatherqq */

/* Gather from memory to vector register operations */
extern __m128 __cdecl _mm_i32gather_ps(const float *, __m128i, const int);  /* vgatherdps */
extern __m128 __cdecl _mm_i64gather_ps(const float *, __m128i, const int);  /* vgatherqps */
extern __m128d __cdecl _mm_i32gather_pd(const double *, __m128i, const int);  /* vgatherdpd */
extern __m128d __cdecl _mm_i64gather_pd(const double *, __m128i, const int);  /* vgatherqpd */

extern __m128i __cdecl _mm_i32gather_epi32(const int *, __m128i, const int);  /* vpgatherdd */
extern __m128i __cdecl _mm_i32gather_epi64(const long long *, __m128i, const int);  /* vpgatherdq */
extern __m128i __cdecl _mm_i64gather_epi32(const int *, __m128i, const int);  /* vpgatherqd */
extern __m128i __cdecl _mm_i64gather_epi64(const long long *, __m128i, const int);  /* vpgatherqq */

extern __m256 __cdecl _mm256_i32gather_ps(const float *, __m256i, const int);  /* vgatherdps */
extern __m128 __cdecl _mm256_i64gather_ps(const float *, __m256i, const int);  /* vgatherqps */
extern __m256d __cdecl _mm256_i32gather_pd(const double *, __m128i, const int);  /* vgatherdpd */
extern __m256d __cdecl _mm256_i64gather_pd(const double *, __m256i, const int);  /* vgatherqpd */

extern __m256i __cdecl _mm256_i32gather_epi32(const int *, __m256i, const int);  /* vpgatherdd */
extern __m256i __cdecl _mm256_i32gather_epi64(const long long *, __m128i, const int);  /* vpgatherdq */
extern __m128i __cdecl _mm256_i64gather_epi32(const int *, __m256i, const int);  /* vpgatherqd */
extern __m256i __cdecl _mm256_i64gather_epi64(const long long *, __m256i, const int);  /* vpgatherqq */

#endif /* __POCC__ >= 800 && __POCC_TARGET__ == 3 */

#if __POCC__ >= 800 && (__POCC_TARGET__ == 1 || __POCC_TARGET__ == 3)

/*
 * Integer bit-manipulation operations
 */
/* adcx, adox? */
extern unsigned int __cdecl _andn_u32(unsigned int, unsigned int);  /* andn */
extern unsigned int __cdecl _bextr_u32(unsigned int, unsigned int, unsigned int);  /* bextr */
extern unsigned int __cdecl _blsi_u32(unsigned int);  /* blsi */
extern unsigned int __cdecl _blsmsk_u32(unsigned int);  /* blsmsk */
extern unsigned int __cdecl _blsr_u32(unsigned int);  /* blsr */
extern unsigned int __cdecl _bzhi_u32(unsigned int, unsigned int);  /* bzhi */
extern unsigned int __cdecl _mulx_u32(unsigned int, unsigned int, unsigned int *);  /* mulx */
extern unsigned int __cdecl _pdep_u32(unsigned int, unsigned int);  /* pdep */
extern unsigned int __cdecl _pext_u32(unsigned int, unsigned int);  /* pext */
extern unsigned int __cdecl _rorx_u32(unsigned int, const unsigned int);  /* rorx */
extern int __cdecl _sarx_i32(int, unsigned int);  /* sarx */
extern unsigned int __cdecl _shlx_u32(unsigned int, unsigned int);  /* shlx */
extern unsigned int __cdecl _shrx_u32(unsigned int, unsigned int);  /* shrx */
#if __POCC_TARGET__ == 3
extern unsigned long long __cdecl _andn_u64(unsigned long long, unsigned long long);  /* andn */
extern unsigned long long __cdecl _bextr_u64(unsigned long long, unsigned int, unsigned int);  /* bextr */
extern unsigned long long __cdecl _blsi_u64(unsigned long long);  /* blsi */
extern unsigned long long __cdecl _blsmsk_u64(unsigned long long);  /* blsmsk */
extern unsigned long long __cdecl _blsr_u64(unsigned long long);  /* blsr */
extern unsigned long long __cdecl _bzhi_u64(unsigned long long, unsigned int);  /* bzhi */
extern unsigned long long __cdecl _mulx_u64(unsigned long long, unsigned long long, unsigned long long *);  /* mulx */
extern unsigned long long __cdecl _pdep_u64(unsigned long long, unsigned long long);  /* pdep */
extern unsigned long long __cdecl _pext_u64(unsigned long long, unsigned long long);  /* pext */
extern unsigned long long __cdecl _rorx_u64(unsigned long long, const unsigned int);  /* rorx */
extern long long __cdecl _sarx_i64(long long, unsigned long long);  /* sarx */
extern unsigned long long __cdecl _shlx_u64(unsigned long long, unsigned long long);  /* shlx */
extern unsigned long long __cdecl _shrx_u64(unsigned long long, unsigned long long);  /* shrx */
#endif /* __POCC_TARGET__ == 3 */

/* count leading zero bits */
extern unsigned int __cdecl _lzcnt_u32(unsigned int);  /* lzcnt */
#if __POCC_TARGET__ == 3
extern unsigned long long __cdecl _lzcnt_u64(unsigned long long);  /* lzcnt */
#endif /* __POCC_TARGET__ == 3 */

/* count trailing zero bits */
extern unsigned int __cdecl _tzcnt_u32(unsigned int);  /* tzcnt */
#if __POCC_TARGET__ == 3
extern unsigned long long __cdecl _tzcnt_u64(unsigned long long);  /* tzcnt */
#endif /* __POCC_TARGET__ == 3 */

/* invalidate processor context */
extern void __cdecl _invpcid(unsigned int, void *);  /* invpcid */

/*
 * Hardware Lock Elision
 */
/*
long _InterlockedCompareExchange_HLEAcquire(long volatile *,long,long);
long _InterlockedCompareExchange_HLERelease(long volatile *,long,long);
__int64 _InterlockedCompareExchange64_HLEAcquire(__int64 volatile *,__int64,__int64);
__int64 _InterlockedCompareExchange64_HLERelease(__int64 volatile *,__int64,__int64);
void *_InterlockedCompareExchangePointer_HLEAcquire(void *volatile *,void *,void *);
void *_InterlockedCompareExchangePointer_HLERelease(void *volatile *,void *,void *);
long _InterlockedExchangeAdd_HLEAcquire(long volatile *,long);
long _InterlockedExchangeAdd_HLERelease(long volatile *,long);
__int64 _InterlockedExchangeAdd64_HLEAcquire(__int64 volatile *,__int64);
__int64 _InterlockedExchangeAdd64_HLERelease(__int64 volatile *,__int64);
void _Store_HLERelease(long volatile *,long);
void _Store64_HLERelease(__int64 volatile *,__int64);
void _StorePointer_HLERelease(void * volatile *,void *);
*/

/*
 * Restricted Transactional Memory
 */
#define _XBEGIN_STARTED   (~0U)
#define _XABORT_EXPLICIT  (1U<<0)
#define _XABORT_RETRY     (1U<<1)
#define _XABORT_CONFLICT  (1U<<2)
#define _XABORT_CAPACITY  (1U<<3)
#define _XABORT_DEBUG     (1U<<4)
#define _XABORT_NESTED    (1U<<5)
#define _XABORT_CODE(x)   (((x) >> 24) & 0xFF)

extern unsigned int __cdecl _xbegin(void);  /* xbegin */
extern void __cdecl _xend(void);  /* xend */
extern void __cdecl _xabort(const unsigned int);  /* xabort */
extern unsigned char __cdecl _xtest(void);  /* xtest */

#endif /* __POCC__ >= 800 && (__POCC_TARGET__ == 1 || __POCC_TARGET__ == 3) */

#endif /* _IMMINTRIN_H */
