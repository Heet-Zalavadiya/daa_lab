#include <stdio.h>

int main(void)
{
    int n = 24, sum = 0, l = 1, r = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        while (sum > n)
        {
            sum -= l;
            l++;
        }
        if (sum < n)
        {
            sum += r;
            r++;
        }

        if (sum == n)
        {
            break;
        }
    }

    for (int i = l; i < r; i++)
    {
        printf("%d ", i);
    }

    printf("sum: %d", sum);
    return 0;
}