#ifndef SIMD_HELPER_H
#define SIMD_HELPER_H

#include <x86intrin.h>
#include <iostream>
#include <vector>
#include <cassert>


namespace simd_helper {

// You can visualize __m128 as four floats:
//   >> __m128 m = _mm_set_ps(0.0, 1.1, 2.2, 3.3);
//   >> simd_helper::CoutM128<float>(m);  // [3.3, 2.2, 1.1, 0.0]
//
// bool/uchar/char/int/float/double are supported.
//
// In case __m128i, simply cast it
//   >> __m128i m2 = _mm_set_epi32(0, 1, 2, 3);
//   >> simd_helper::CoutM128<int>( (__m128) m2);  // [3, 2, 1, 0]
//
// __m256 is also supported:
//   >> __m256 m3 = _mm256_set_ps(0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7);
//   >> simd_helper::CoutM256<float>(m3);  // [7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1, 0]

template <typename T>
void CoutM128(__m128 m);

template <typename T>
void CoutM256(__m256 m);

}

#endif // SIMD_HELPER_H
