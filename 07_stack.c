
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

// Infix to Postfix Conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;

    for(i = 0; infix[i]; i++) {
        c = infix[i];

        if(isalnum(c)) { // Operand
            postfix[k++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(top != -1 && stack[top] != '(')
                postfix[k++] = pop();

            pop(); // remove '('
        }
        else { // Operator
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();

            push(c);
        }
    }

    while(top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Evaluate Postfix Expression
int evalPostfix(char postfix[]) {
    int stack2[MAX], top2 = -1, i, a, b;

    for(i = 0; postfix[i]; i++) {
        if(isdigit(postfix[i])) {
            stack2[++top2] = postfix[i] - '0';
        }
        else {
            b = stack2[top2--];
            a = stack2[top2--];

            switch(postfix[i]) {
                case '+': stack2[++top2] = a + b; break;
                case '-': stack2[++top2] = a - b; break;
                case '*': stack2[++top2] = a * b; break;
                case '/': stack2[++top2] = a / b; break;
                case '^': stack2[++top2] = pow(a, b); break;
            }
        }
    }

    return stack2[top2];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression (operands single digit only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    int result = evalPostfix(postfix);

    printf("Evaluation Result: %d\n", result);

    return 0;
}
