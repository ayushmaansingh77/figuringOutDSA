#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100


char s[max];
int top = -1;


int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == max - 1;
}
void push(char x)
{
    if (isFull()) {
        printf("stack overflow\n");
        
    }
    s[++top] = x;
}
char pop()
{
    if (isEmpty()) {
        printf("stack underflow\n");
       return 'e';
    }
    return s[top--];
}
char peek()
{
    if (isEmpty()) return '\0';
    return s[top];
}


int priority(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 3;
    if (op == '+' || op == '-') return 2;
    return 0;
}
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}


void infixTopostfix(const char *input, char *ans)
{
    int i = 0;            
    int j = 0;           
    int n = (int)strlen(input);

    top = -1;             

    while (i < n) {
        char ch = input[i];

        if (isspace((unsigned char)ch)) {
            i++;
            continue;
        }

        
        if (isalpha((unsigned char)ch) || isdigit((unsigned char)ch) || ch == '.') {
            while (i < n && (isalnum((unsigned char)input[i]) || input[i] == '.')) {
                ans[j++] = input[i++];
            }
            ans[j++] = ' '; 
            continue;
        }

        
        if (ch == '(') {
            push(ch);
            i++;
            continue;
        }

        
        if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                ans[j++] = pop();
                ans[j++] = ' ';
            }
            if (isEmpty()) {
                printf("Mismatched parentheses\n");
                break;
            }
            pop(); 
            i++;
            continue;
        }

        
        if (isOperator(ch)) {
            
            while (!isEmpty() && isOperator(peek()) &&
                   (priority(peek()) > priority(ch) ||
                    (priority(peek()) == priority(ch) && ch != '^'))) {
                ans[j++] = pop();
                ans[j++] = ' ';
            }
            push(ch);
            i++;
            continue;
        }

       
        
    }

   
    while (!isEmpty()) {
        char t = pop();
        if (t == '(' || t == ')') {
            printf( "Mismatched parentheses\n");
            break;
        }
        ans[j++] = t;
        ans[j++] = ' ';
    }

    
    if (j > 0 && ans[j-1] == ' ') 
    {j--;}
    ans[j] = '\0';
}


int main()
{
    char input[max];
    char ans[3 * max]; 

    printf("Enter infix expression (max %d chars):\n", max - 1);
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Input error\n");
        return 1;
    }
    
    size_t L = strlen(input);
    if (L > 0 && input[L-1] == '\n') input[L-1] = '\0';

    infixTopostfix(input, ans);

    printf("Postfix: %s\n", ans);
    return 0;
}
