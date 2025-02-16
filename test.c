/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a user defined function to search for the element in the array by using binary search algorithm. Call it in main() to display the position of
    the element, if it is found, otherwise display suitable error message if it is not found.
*/

#include <stdio.h>

void merge(int[], int, int[], int, int[], int*);

int main() {
    int array1[20], array2[20], array[40], n1, n2, n, i;
    printf("Enter the no. of elements of the array1: ");
    scanf("%d", &n1);

    printf("Enter the array1 elements: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &array1[i]);
    }
    printf("Enter the no. of elements of the array2: ");
    scanf("%d", &n2);

    printf("Enter the array2 elements: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &array2[i]);
    }
    merge(array1, n1, array2, n2, array, &n);

    printf("The array elements after merging are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void merge(int array1[], int n1, int array2[], int n2, int array[], int *n) {
    int i = 0, j = 0, k = 0;
    *n = n1 + n2;

    while (i < n1 && i < n2) {
        if (array1[i] < array2[j]) {
            array[k++] = array1[i++];
        } else {
            array[k++] = array2[j++];
        }
    }
    while (i < n1) {
        array[k++] = array1[i++];
    }
    while (j < n2) {
        array[k++] = array2[j++];
    }
}