#include <emmintrin.h>
#include <stdio.h>
void main()
{
    int a[] = {-2, 0, 1, 2};
    __m128i inA = _mm_loadu_si128 ((__m128i const *)a);
    __m128i mask = _mm_srai_epi32 (inA, 31);
    inA = _mm_andnot_si128 (mask, inA);
    _mm_storeu_si128 ((__m128i *) a, inA);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", a[i]);
    }
}