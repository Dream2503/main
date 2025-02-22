/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. 
*/

#include <stdio.h>

void insertion_sort(int[], int);

int main() {
    int array[20], n, i;
    printf("Enter the no. of elements of the array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    insertion_sort(array, n);

    printf("The array elements after sorting are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void insertion_sort(int array[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

// #include <stdio.h>
// #include <stdlib.h>

// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     int *res = (int*)malloc(2 * sizeof(int)), i, j;

//     for (i = 0; i < numsSize; i++) {
//         for (j = i + 1; j < numsSize; j++) {
//             if (nums[i] + nums[j] == target) {
//                 res[0] = i; res[1] = j;
//                 return res;
//             }
//         }
//     }
//     return res;
// }