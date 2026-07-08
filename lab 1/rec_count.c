#include <stdio.h>

int recCount(int n,int c) {
    if (n == 0)
    {
        return c;
    }
    c++;
    return recCount(n/10,c);
}

int main(void) {
    int num = 3560;
    int count = 0;
    printf("count : %d",recCount(num,count));
    return 0;
}