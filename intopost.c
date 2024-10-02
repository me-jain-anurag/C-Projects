#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[40];

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int prior(char a)
{
    if (a == '#' || a == '(') return 1;
    if (a == '+' || a == '-') return 2;
    if (a == '*' || a == '/') return 3;
    if (a == '^' || a == '$') return 4;
}

int main()
{
    char infix[30], postfix[30];
    int i, j = 0;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    push('#');

    for (i = 0; i < strlen(infix); i++)
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while (prior(stack[top]) >= prior(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }

    while (stack[top] != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("The postfix expression is: %s\n", postfix);
    
    return 0; 
}