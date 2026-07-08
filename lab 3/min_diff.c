#include <stdio.h>

int main()
{
    int arr[] = {1, 19, -4, 31, 38, 25, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    int min = arr[1] - arr[0];

    for (int i = 1; i < n - 1; i++)
    {
        int diff = arr[i + 1] - arr[i];
        if (diff < min)
        {
            min = diff;
        }
    }

    printf("Minimum diff: %d", min);

    return 0;
}