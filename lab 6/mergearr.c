#include <stdio.h>

int main()
{
    int a[] = {1, 5, 9, 10, 15, 20};
    int b[] = {2, 3, 8, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    for (int i = 0; i < n; i++)
    {
        int minj = 0;
        for (int j = 1; j < m; j++)
        {
            if (b[j] < b[minj])
            {
                minj = j;
            }
        }

        if (a[i] > b[minj])
        {
            int temp = a[i];
            a[i] = b[minj];
            b[minj] = temp;
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < m; j++)
        {
            if (b[j] < b[min])
            {
                min = j;
            }
        }

        int temp = b[i];
        b[i] = b[min];
        b[min] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    for (int j = 0; j < m; j++)
    {
        printf("%d ", b[j]);
    }

    return 0;
}