// Write a program to implement binary search algorithm using recursive method.

#include <stdio.h>
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

int binarySearch(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, high, target);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, target);
    }
}

int main()
{
    int arr[N];
    int target = 23;
    int result;
    clock_t start, end;
    if (readFileOfArray("best_case_input.txt", arr, N))
    {
        start = clock();
        result = binarySearch(arr, 0, N - 1, target);
        end = clock();
        printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}