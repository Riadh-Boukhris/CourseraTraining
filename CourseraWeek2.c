#include <stdio.h>


void printArr(int *arr, int arrSize){
    printf("Array = ");
    for (int i = 0; i < arrSize; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
}

int maxVal(int *arr , int arrSize){
    int max = 0;
    for(int i = 0; i < arrSize; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void swap(int *a, int *b){
    int k = *a;
    *a = *b;
    *b = k;
}

void place(int* arr, int arrSize){
    int k = arr[1];
    printf("k = %d\t", k);
    for(int i = 1; i < arrSize - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[arrSize - 1] = k;

    
}

int getWinner(int* arr, int arrSize, int k) {
    
    if ( k >= arrSize){
        return maxVal(arr, arrSize);
    }

    int cnt = 0;
    while (cnt < k) {
        if (arr[0] >= arr[1]) {
            cnt++;
            place(arr, arrSize);
        } else {
            cnt = 1;
            swap(&arr[0], &arr[1]);
            place(arr, arrSize);
        }
    }
    return arr[0];
}


int main() {
    int arr[] = {1, 25, 35, 42, 68, 70};
    int k = 2;
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    
    int winner = getWinner(arr, arrSize, k);
    
    printf("The winner is: %d\n", winner);
    
    return 0;
}