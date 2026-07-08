#include <stdio.h>

int recSum(int n) {
    if (n == 0)
    {
        return 0;
    }
    return n + recSum(n - 1);
}

int main(void) {
    int num = 5;
    printf("sum : %d",recSum(num));
    return 0;
}