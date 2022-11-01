#include <stdio.h>

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int copyReversed(int* arrA, int* arrB, int n){
    int i = n-1, j = 0;
    for(int i = n-1; i>=0; i--){
        arrB[j] = arrA[i];
        j++;
    }
}
int main()
{
    int arrA[5] = {1, 2, 3, 4, 5}, arrB[5];
    int n = sizeof(arrA)/sizeof(arrA[0]);
    printArr(arrA, n);
    copyReversed(arrA, arrB, n);
    printArr(arrB, n);
    return 0;
}
