#include <stdio.h>

int recPow(int b, int e)
{

    if (e == 0)
    {
        return 1;
    }

    return b * recPow(b, e - 1);
}

int main(void)
{
    int base = 3;
    int exp = 3;
    printf("pow : %d", recPow(base, exp));
    return 0;
}