#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char stack[100];
char infix[100], postfix[100];
int top = -1;
const int MAX = 100;

bool space(char c) {
    return (c == ' ' || c == '\t');
}

bool isEmpty() {
    return (top == -1);
}

void print() {
    int i = 0;
    cout << "The Equivalent Postfix Expression is: ";
    while (postfix[i]) {
        cout << postfix[i++];
    }
    cout << endl;
}

void push(char c) {
    if (top == MAX - 1) {
        cout << "STACK OVERFLOW" << endl;
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (isEmpty()) {
        cout << "STACK UNDERFLOW" << endl;
        exit(1);
    }
    return stack[top--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void inTOpost() {
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); ++i) {
        symbol = infix[i];
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;
                case '^':
                case '/':
                case '*':
                case '+':
                case '-':
                    while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol;
            }
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    cout << "Enter the Infix Expression: ";
    cin.getline(infix, 100);

    inTOpost();
    print();

    return 0;
}

