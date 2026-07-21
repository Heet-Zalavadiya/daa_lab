#include <stdio.h>

void moveZeros(int arr[], int n)
{
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        if (arr[r] != 0)
        {
            if (l != r)
            {
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
            }
            l++;
        }
    }
}

int main()
{
    int arr[] = {1,2,0,4,3,0,5,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    moveZeros(arr, n);

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}