#include <stdio.h>
#include <stdlib.h>

int* factors(int);
int is_perfect(int);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (is_perfect(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }
    return 0;
}

int *factors(int num) {
    int *fact = (int*)malloc(8 * sizeof(int));
    int size = 8, i, j = 1;

    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            if (j == size) {
                size *= 2;
                fact = (int*)realloc(fact, size * sizeof(int));
            }
            fact[j++] = i;
        }
    }
    fact[0] = j;
    return fact;
}

int is_perfect(int num) {
    int *f = factors(num);
    int i, sum = 0;
    for (i = 1; i < f[0]; i++) {
        sum += f[i];
    }
    free(f);
    return sum == num;
}