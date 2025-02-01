#include <stdio.h>
#include <string.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

struct student {
    char name[20];
    int rn;
    int age;
};

struct stack {
    int TOS;
    struct student s[MAX];
};

void push(struct stack *ss, struct student st) {
    if (ss->TOS == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        ss->TOS += 1;
        ss->s[ss->TOS] = st;
    }
}

struct student pop(struct stack *ss) {
    struct student st = {"", -1, -1};  // Initialize with default values
    if (ss->TOS == -1) {
        printf("Stack Underflow\n");
    } else {
        st = ss->s[ss->TOS];
        ss->TOS -= 1;
    }
    return st;
}

struct student peek(struct stack *ss) {
    struct student st = {"", -1, -1};  // Initialize with default values
    if (ss->TOS == -1) {
        printf("Stack Underflow\n");
    } else {
        st = ss->s[ss->TOS];
    }
    return st;
}

int isFull(struct stack *ss) {
    return (ss->TOS == MAX - 1) ? TRUE : FALSE;
}

int isEmpty(struct stack *ss) {
    return (ss->TOS == -1) ? TRUE : FALSE;
}

int main() {
    int choice;
    struct student s;
    struct stack stk = {-1};

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Is Full\n5. Is Empty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isFull(&stk)) {
                    printf("Enter your name: ");
                    scanf("%s", s.name);
                    printf("Enter your roll number: ");
                    scanf("%d", &s.rn);
                    printf("Enter your age: ");
                    scanf("%d", &s.age);
                    push(&stk, s);
                } else {
                    printf("Cannot push: Stack is full.\n");
                }
                break;

            case 2:
                if (!isEmpty(&stk)) {
                    s = pop(&stk);
                    printf("The removed member is:\n");
                    printf("NAME: %s\n", s.name);
                    printf("AGE: %d\n", s.age);
                    printf("ROLL NUMBER: %d\n", s.rn);
                } else {
                    printf("Cannot pop: Stack is empty.\n");
                }
                break;

            case 3:
                if (!isEmpty(&stk)) {
                    s = peek(&stk);
                    printf("Value at the top is:\n");
                    printf("NAME: %s\n", s.name);
                    printf("AGE: %d\n", s.age);
                    printf("ROLL NUMBER: %d\n", s.rn);
                } else {
                    printf("Cannot peek: Stack is empty.\n");
                }
                break;

            case 4:
                if (isFull(&stk)) {
                    printf("Stack is Full\n");
                } else {
                    printf("Stack is Not Full\n");
                }
                break;

            case 5:
                if (isEmpty(&stk)) {
                    printf("Stack is Empty\n");
                } else {
                    printf("Stack is Not Empty\n");
                }
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
