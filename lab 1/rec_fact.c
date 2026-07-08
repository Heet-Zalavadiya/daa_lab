#include <stdio.h>

int recFact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * recFact(n - 1);
}

int main(void)
{
    int num = 5;
    printf("fact: %d", recFact(num));
    return 0;
}