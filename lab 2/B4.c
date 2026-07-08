#include <stdio.h>

void loop(int num, int size) {
    for (int i = num; i <= size; i++)
    {
        printf("[");
        for (int j = num; j <= i; j++)
        {
            printf("%d,",j);
        }
        printf("]");
    }
    
}

int main(void) {
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("[");
    for (int i = 1; i <= size; i++)
    {
        loop(i,size);
    }
    printf("]");
    

    return 0;
}