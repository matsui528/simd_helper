#include "simd_helper.h"

namespace simd_helper {


template<typename T>
void CoutM128(__m128 m)
{
    T *m_ = (T *) &m;
    assert(16 % sizeof(T) == 0);
    size_t N = 16 / sizeof(T);
    for (size_t n = 0; n < N; ++n) {
        std::cout << m_[n] << ", ";
    }
    std::cout << std::endl;
}

template void CoutM128<int>(__m128 m);
template void CoutM128<float>(__m128 m);
template void CoutM128<double>(__m128 m);


template<>
void CoutM128<bool>(__m128 m)
{
    unsigned char *m_ = (unsigned char *) &m;
    for (size_t n = 0; n < 16; ++n) {
        unsigned char c = m_[n];
        for (size_t b = 0; b < 8; ++b) {
            // This shows an actual bit order.
            // If you don't care any bit-level operations,
            // This should be
            //   >> bool ret = c & (1 << (8 - b - 1))
            bool ret = c & (1 << b);
            std::cout << ret;
        }
        std::cout << "|";
    }
    std::cout << std::endl;
}

template<>
void CoutM128<char>(__m128 m)
{
    char *m_ = (char *) &m;
    for (size_t n = 0; n < 16; ++n) {
        // int cast is required
        std::cout << (int) m_[n] << ", ";
    }
    std::cout << std::endl;
}

template<>
void CoutM128<unsigned char>(__m128 m)
{
    unsigned char *m_ = (unsigned char *) &m;
    for (size_t n = 0; n < 16; ++n) {
        // int cast is required
        std::cout << (int) m_[n] << ", ";
    }
    std::cout << std::endl;
}




template<typename T>
void CoutM256(__m256 m)
{
    T *m_ = (T *) &m;
    assert(32 % sizeof(T) == 0);
    size_t N = 32 / sizeof(T);
    for (size_t n = 0; n < N; ++n) {
        std::cout << m_[n] << ", ";
    }
    std::cout << std::endl;
}

template void CoutM256<int>(__m256 m);
template void CoutM256<float>(__m256 m);
template void CoutM256<double>(__m256 m);


template<>
void CoutM256<bool>(__m256 m)
{
    unsigned char *m_ = (unsigned char *) &m;
    for (size_t n = 0; n < 32; ++n) {
        unsigned char c = m_[n];
        for (size_t b = 0; b < 8; ++b) {
            // This shows an actual bit order.
            // If you don't care any bit-level operations,
            // This should be
            //   >> bool ret = c & (1 << (8 - b - 1))
            bool ret = c & (1 << b);
            std::cout << ret;
        }
        std::cout << "|";
    }
    std::cout << std::endl;
}

template<>
void CoutM256<char>(__m256 m)
{
    char *m_ = (char *) &m;
    for (size_t n = 0; n < 32; ++n) {
        // int cast is required
        std::cout << (int) m_[n] << ", ";
    }
    std::cout << std::endl;
}

template<>
void CoutM256<unsigned char>(__m256 m)
{
    unsigned char *m_ = (unsigned char *) &m;
    for (size_t n = 0; n < 32; ++n) {
        // int cast is required
        std::cout << (int) m_[n] << ", ";
    }
    std::cout << std::endl;
}




} // namespace simd_helper
