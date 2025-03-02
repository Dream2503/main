#include <stdio.h>
#include <stdlib.h>

char *copy(char*);
char *concat(char*, char*);
char *concat_array(char*[], int);
int is_greater(char*, char*);
void reverse_sort(char*[], int);

int main() {
    int total_test_cases, i, size, j, k, l = 0;
    scanf("%d", &total_test_cases);

    char *result[total_test_cases], *str1, *str2;

    for (i = 0; i < total_test_cases; i++) {
        scanf("%d", &size);
        char *array[size], *temp = (char*)malloc(5 * sizeof(char));

        for (j = 0; j < size; j++) {
            scanf("%s", temp);
            array[j] = copy(temp);
        }
        reverse_sort(array, size);

        for (k = 0; k < size - 1; k++) {
            str1 = concat(array[k], array[k + 1]);
            str2 = concat(array[k + 1], array[k]);

            if (is_greater(str2, str1)) {
                temp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = temp;
            }
            free(str1);
            free(str2);
        }
        result[l++] = concat_array(array, size);

        for (j = 0; j < size; j++) {
            free(array[j]);
        }
    }

    for (j = 0; j < l; j++) {
        printf("%s\n", result[j]);
    }

    for (j = 0; j < l; j++) {
        free(result[j]);
    }
}

char *copy(char *str) {
    int i = 0;
    while (str[i] != '\0') {i++;}

    char *new_str = (char*)malloc(i * sizeof(char));
    i = 0;

    while (str[i] != '\0') {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}

char *concat(char *str1, char *str2) {
    int i = 0, j = 0;

    while (str1[i] != '\0') {i++;}
    while (str2[j] != '\0') {j++;}

    char *new_str = (char*)malloc((i + j) * sizeof(char));
    i = 0; j = 0;

    while (str1[i] != '\0') {
        new_str[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        new_str[i] = str2[j];
        i++; j++;
    }
    new_str[i] = '\0';
    return new_str;
}

char *concat_array(char *array[], int size) {
    int i, j, k = 0;

    for (i = 0; i < size; i++) {
        while (array[i][j] != '\0') {j++;}
        k += j;
    }

    char *new_str = (char*)malloc(k * sizeof(char));
    k = 0;

    for (i = 0; i < size; i++) {
        j = 0;
        while (array[i][j] != '\0') {
            new_str[k] = array[i][j];
            k++; j++;
        }
    }
    new_str[k] = '\0';
    return new_str;
}

int is_greater(char *str1, char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return 0;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0') {
        return 0;
    } else {
        return 1;
    }
}

void reverse_sort(char *array[], int size) {
    int i, j;
    char *temp;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (is_greater(array[j + 1], array[j])) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


// /*
// Name:- Swapnaraj Mohanty
// SIC :- 24BCSH93
// Sec :- C2

// Q. 
// */

// #include <stdio.h>

// void insertion_sort(int[], int);

// int main() {
//     int array[20], n, i;
//     printf("Enter the no. of elements of the array: ");
//     scanf("%d", &n);

//     printf("Enter the array elements: ");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &array[i]);
//     }
//     insertion_sort(array, n);

//     printf("The array elements after sorting are: ");
//     for (i = 0; i < n; i++) {
//         printf("%d ", array[i]);
//     }
//     return 0;
// }

// void insertion_sort(int array[], int n) {
//     int i, j, temp;

//     for (i = 1; i < n; i++) {
//         temp = array[i];
//         j = i - 1;

//         while (j >= 0 && array[j] > temp) {
//             array[j + 1] = array[j];
//             j--;
//         }
//         array[j + 1] = temp;
//     }
// }

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