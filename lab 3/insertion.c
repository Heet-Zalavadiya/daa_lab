#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

int readFileOfArray(const char *filename, int arr[], int n)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("File not found\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    return 1;
}

void insertion(int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[N];

    clock_t start, end;
    if (readFileOfArray("average_case_input.txt", arr, N))
    {
        start = clock();
        insertion(N, arr);
        end = clock();
        printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }
    if (readFileOfArray("best_case_input.txt", arr, N))
    {
        start = clock();
        insertion(N, arr); 
        end = clock();
        printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }
    if (readFileOfArray("worst_case_input.txt", arr, N))
    {
        start = clock();
        insertion(N, arr);
        end = clock();
        printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }

    return 0;
}