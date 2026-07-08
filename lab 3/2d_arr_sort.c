#include <stdio.h>

int main()
{
    int arr[][2] = {
        {2, 4},
        {1, 2},
        {7, 8},
        {5, 6},
        {6, 8}};

    int n = 5;
    int temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][0] > arr[j][0])
            {
                temp1 = arr[i][0];
                temp2 = arr[i][1];

                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];

                arr[j][0] = temp1;
                arr[j][1] = temp2;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1][0] < arr[i][1])
        {
            printf("False");
            return 0;
        }
    }

    printf("True");

    return 0;
}