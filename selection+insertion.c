#include <stdio.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    selection_sort(arr, n);
    printf("Sorted array using Selection Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int arr2[] = {12, 11, 13, 5, 6};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    insertion_sort(arr2, n);
    printf("Sorted array using Insertion Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    return 0;
}