#include <emmintrin.h>
#include <stdio.h>
#include <time.h>
double tvgetf()
{
    struct timespec ts;
    double sec;

    clock_gettime(CLOCK_REALTIME, &ts);
    sec = ts.tv_nsec;
    sec /= 1e9;
    sec += ts.tv_sec;

    return sec;
}
void main()
{
    double t1,t2;
    int a[] = {-2, 0, 1, 2};
    t1 = tvgetf();
    for (int j = 0; j < 100000000; j++) {
        __m128i inA = _mm_loadu_si128((__m128i const *)a);
        __m128i mask = _mm_srai_epi32(inA, 31);
        inA = _mm_andnot_si128(mask, inA);
        _mm_storeu_si128((__m128i *)a, inA);
    }
    t2 = tvgetf();
    for (int i = 0; i < 4; i++) {
        printf("%d\n", a[i]);
    }
    printf("%lf",t2-t1);
}