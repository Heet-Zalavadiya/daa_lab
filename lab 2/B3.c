#include <stdio.h>

int main(void) {
    int arr[] = {10,-2,20,-3,-4,30,40};
    int size = sizeof(arr)/sizeof(arr[0]);
    int pos[100],p = 0;
    int neg[100],n = 0;

    for (int i = 0; i < size; i++)
    {
        if(arr[i] >= 0) {
            pos[p] = arr[i];
            p++;
        }
        else {
            neg[n] = arr[i];
            n++;
        }
    }
    
    printf("Pos \n");
    for (int i = 0; i < p; i++)
    {
        printf("%d ",pos[i]);
    }
    printf("\nNeg \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",neg[i]);
    }

    printf("\n Printing Final Array \n");
    int i = 0;
    int j = 0;
    while (i < p && j < n)
    {
        printf("%d ",pos[i]);
        i++;
        printf("%d ",neg[j]);
        j++;
    }
    while (i < p)
    {
        printf("%d ",pos[i]);
        i++;
    }
    while (j < n)
    {
        printf("%d ",neg[j]);
        j++;
    }
    
    return 0;
}