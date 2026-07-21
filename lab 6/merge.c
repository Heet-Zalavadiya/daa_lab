// Write a program to implement merge sort algorithm.

#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int v[n1];
    int u[n2];

    for (int i = 0; i < n1; i++)
    {
        v[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        u[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (v[i] <= u[j])
        {
            arr[k] = v[i];
            i++;
        }
        else
        {
            arr[k] = u[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = v[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = u[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    return 0;
}