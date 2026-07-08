#include <stdio.h>
#include <time.h>
#define N 100

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

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[N];

    clock_t start, end;
    if (readFileOfArray("best_case_input.txt", arr, N))
    {
        start = clock();
        heapsort(arr, N);
        end = clock();
        printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }

    if (readFileOfArray("average_case_input.txt", arr, N))
    {
        start = clock();
        heapsort(arr, N);
        end = clock();
        printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }
    if (readFileOfArray("worst_case_input.txt", arr, N))
    {
        start = clock();
        heapsort(arr, N);
        end = clock();
        printf("Time taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }
    return 0;
}