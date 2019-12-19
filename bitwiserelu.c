#include<stdio.h>
int main()
{
    int mask;
    int a[] = {-2, 0, 1, 2};
    for (int i = 0; i < 4; i++) {
        mask = a[i] >> 31;
        a[i] = a[i] & ~(mask);
    }
    for (int i = 0; i < 4; i++) {
        printf("%d\n", a[i]);
    }
}