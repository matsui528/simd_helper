#include <iostream>
#include "simd_helper.h"

int main(){

    // ==== Basic usage ====
    // Visualize __m128 as four floats
    __m128 m = _mm_set_ps(0.0, 1.1, 2.2, 3.3);
    simd_helper::CoutM128<float>(m);  // [3.3, 2.2, 1.1, 0.0]

    // In case __m128i or __m128d, simply cast it
    __m128i m2 = _mm_set_epi32(0, 1, 2, 255);
    simd_helper::CoutM128<int>( (__m128) m2);  // [255, 2, 1, 0]

    // Condier m2 is a set of eight chars.
    // [255, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
    simd_helper::CoutM128<unsigned char>( (__m128) m2);

    // Condier m2 is a set of eight unsigned chars.
    // [-1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
    simd_helper::CoutM128<char>( (__m128) m2);

    // CoutM128<bool> shows an actual bit order (little endian on x86)
    // [11111111|00000000|00000000|00000000|
    //  01000000|00000000|00000000|00000000|
    //  10000000|00000000|00000000|00000000|
    //  00000000|00000000|00000000|00000000|]
    simd_helper::CoutM128<bool>( (__m128) m2);


    // ==== Little endian ====
    // Let's shift 1 bit to the "left" direction, in 32bit wise manner (0 padding)
    __m128i m2_left_shifted = _mm_slli_epi32(m2, 1);

    // Because the least bit is removed, the result is:
    // m2:              [255, 2, 1, 0] = [0b11111111, 0b10, 0b1, 0b0]
    // m2_left_shifted: [510, 4, 2, 0] = [0b111111110, 0b100, 0b10, 0b0]
    // This makes sense.
    simd_helper::CoutM128<int>( (__m128) m2_left_shifted);

    // However, please be careful that, in a bit level, this means a "right" shift,
    // because of the little endian
    // [01111111|10000000|00000000|00000000|
    //  00100000|00000000|00000000|00000000|
    //  01000000|00000000|00000000|00000000|
    //  00000000|00000000|00000000|00000000|]
    simd_helper::CoutM128<bool>( (__m128) m2_left_shifted);


    // ==== __m256 ====
    __m256 m3 = _mm256_set_ps(0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7);
    simd_helper::CoutM256<float>(m3);  // [7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1, 0]


    // ==== Input order ====
    __m128 m4 = _mm_set_ps(0, 1, 2, 3);
    __attribute__((aligned(16))) float vals[4] = {0, 1, 2, 3};
    __m128 m5 = _mm_load_ps(vals);  // If the data is loaded from the array, the order is preserved
    simd_helper::CoutM128<float>(m4);  // [3, 2, 1, 0]
    simd_helper::CoutM128<float>(m5);  // [0, 1, 2, 3]  the original order


    // ==== Back to the memory ====
    __attribute__((aligned(16))) float ret1[4];
    __attribute__((aligned(16))) float ret2[4];
    _mm_store_ps(ret1, m4);
    _mm_store_ps(ret2, m5);

    auto cout_vec = [](float *vec){
        for (size_t i = 0; i < 4; ++i)
            std::cout << vec[i] << ", ";
        std::cout << std::endl;
    };

    cout_vec(ret1);  // [3, 2, 1, 0]   The order is as is
    cout_vec(ret2);  // [0, 1, 2, 3]   The order is as is

}
