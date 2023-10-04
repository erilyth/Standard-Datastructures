#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 1000

char stack[MAX_SIZE];
char fin[MAX_SIZE];
int top = -1; // Stack's top pointer

// Function declarations
void push(char ch);
char pop();
bool isOperator(char ch);
int precedence(char ch);

int main() {
    char A[MAX_SIZE];
    int count = 0, final = 0, c;
    
    while ((c = getchar()) != '\n') {
        A[count++] = c;
    }
    A[count] = '\0'; // Null terminate the string for good measure

    // Postfix conversion
    for (int i = 0; i < count; i++) {
        if (A[i] == '(') {
            push(A[i]);
        } else if (A[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                fin[final++] = pop();
            }
            pop(); // Remove '(' from stack
        } else if (isOperator(A[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(A[i])) {
                fin[final++] = pop();
            }
            push(A[i]);
        } else {
            fin[final++] = A[i];
        }
    }

    while (top != -1) {
        fin[final++] = pop();
    }
    
    fin[final] = '\0';
    printf("%s\n", fin);

    return 0;
}

void push(char ch) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = ch;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
