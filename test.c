#include <stdbool.h>
#include <stdio.h>
#define n 10

int stacks[n], top1 = -1, top2 = n;

void push1(int);
void push2(int);
int pop1();
int pop2();
bool is_full();
bool is_empty1();
bool is_empty2();
void display();

int main() {
    push1(5);
    push1(10);
    push2(20);
    push2(30);
    display();

    printf("Popped from Stack1: %d\n", pop1());
    printf("Popped from Stack2: %d\n", pop2());
    display();

    return 0;
}

void push1(int element) {
    if (is_full()) {
        printf("Stack1 Overflow\n");
    } else {
        stacks[++top1] = element;
    }
}

void push2(int element) {
    if (is_full()) {
        printf("Stack2 Overflow\n");
    } else {
        stacks[--top2] = element;
    }
}

int pop1() {
    if (is_empty1()) {
        printf("Stack1 Underflow\n");
        return -1;
    }
    return stacks[top1--];
}

int pop2() {
    if (is_empty2()) {
        printf("Stack2 Underflow\n");
        return -1;
    }
    return stacks[top2++];
}

bool is_full() {
    if (top2 == top1 + 1) {
        return 1;
    } else {
        return 0;
    }
}

bool is_empty1() {
    if (top1 == -1) {
        return 1;
    } else {
        return 0;
    }
}

bool is_empty2() {
    if (top2 == n) {
        return 1;
    } else {
        return 0;
    }
}

void display() {
    int i;

    if (is_empty1()) {
        printf("Stack1 is empty\n");
    } else {
        printf("Stack1: ");

        for (i = 0; i <= top1; i++) {
            printf("%d ", stacks[i]);
        }
    }
    if (is_empty2()) {
        printf("Stack2 is empty\n");
    } else {
        printf("\nStack2: ");

        for (i = n - 1; i >= top2; i--) {
            printf("%d ", stacks[i]);
        }
        printf("\n");
    }
}
