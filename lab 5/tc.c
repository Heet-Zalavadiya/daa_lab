#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void bestCase() {
    FILE *fp;
    fp = fopen("best_case_input.txt", "w");
    for (int i = 1; i <= N; i++)
    {
        fprintf(fp,"\n%d",i);
    }
    fclose(fp);
}

void worstCase() {
    FILE *fp;
    fp = fopen("worst_case_input.txt", "w");
    for (int i = N; i >= 1; i--)
    {
        fprintf(fp,"\n%d",i);
    }
    fclose(fp);
}

void averageCase() {
    FILE *fp;
    fp = fopen("average_case_input.txt", "w");
    if (fp == NULL) return;

    int n = N;
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        fclose(fp);
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    srand((unsigned)time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp,"\n%d",arr[i]);
    }

    free(arr);
    fclose(fp);
}

int main(void) {
    bestCase();
    worstCase();
    averageCase();
    return 0;
}