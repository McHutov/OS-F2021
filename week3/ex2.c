#include <stdio.h>

void swapp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr,int size){
    for(int i = size - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                swapp(&arr[j], &arr[j+1]);
            }
        }
    }
}


int main() {
    int arr[100];
    int n;

    printf("Pls, enter the size of array: ");
    scanf("%d", &n);
    printf("Enter elements of array:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);
    
    printf("After sorting:\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}




