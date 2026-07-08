#include <stdio.h>

int recFib(int num)
{
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }
    return recFib(num - 1) + recFib(num - 2);
}

int main(void)
{
    int num = 5;
    for (int i = 0; i <= num; i++)
    {
        printf("%d", recFib(i));
    }

    return 0;
}