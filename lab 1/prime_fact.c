#include <stdio.h>

void primeFact(int n)
{
    while (n % 2 == 0)
    {
        printf("2 ");
        n /= 2;
    }
    while (n % 3 == 0)
    {
        printf("3 ");
        n /= 3;
    }
    while (n % 5 == 0)
    {
        printf("5 ");
        n /= 5;
    }
    while (n % 7 == 0)
    {
        printf("7 ");
        n /= 7;
    }

    if (n > 1)
    {
        printf("%d ",n);
    }
    
}

int main(void)
{
    int num = 12;
    primeFact(num);
    return 0;
}