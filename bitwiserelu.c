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
int main()
{
    double t1, t2;
    int mask;
    int a[] = {-2, 0, 1, 2};
    t1 = tvgetf();
    for (int j = 0; j < 100000000; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            mask = a[i] >> 31;
            a[i] = a[i] & ~(mask);
        }
    }
    t2 = tvgetf();

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("%lf\n", t2 - t1);
}