#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

struct Stack{
    int top;
    unsigned size;
    char* arr;
};

struct Stack* Create(unsigned size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (char*)malloc(stack->size * sizeof(char));
    return stack;
}

bool overflow(struct Stack* stack)
{
    if(stack->top == stack->size - 1){
        // printf("\nSize barabar hai\n");
        return true;
    };

    return false;

}

bool underflow(struct Stack* stack){

    if(stack->top == -1){
        return true;
    }
    return false;
}

void push(struct Stack* stack, char item){
    if(overflow(stack))
    {
        printf("\nStack Overflow\n");
        printf("\nTop is: %d\n",stack->arr[stack->top]);
        return;
    }
    stack->top++;
    stack->arr[stack->top] = item;
    printf("\n%d Pushed to stack\n", stack->arr[stack->top]);
    printf("\nNew top is: %d\n", stack->arr[stack->top]);
    return;
}

char pop(struct Stack* stack)
{
    if(underflow(stack) == true)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    printf("\nPopped from stack : %d\n", stack->arr[stack->top]);
    stack->top--;
    // printf("\nNew Stack top is: %d\n", stack->arr[stack->top]);
    // printf("\n%d popped from stack\n", stack->arr[stack->top]);
    return stack->arr[stack->top];

}

int preference(char x){
    if(x == '('){
        return 0;
    }
    else if (x=='+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
}

int main(){
    struct Stack* stack = Create(20);
    // char exp[20];
    char *e, x;
    printf("\nEnter the expression: ");
    scanf("%s", stack->arr);
    e = stack->arr;

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c", *e);
        else if(*e == '(')
            push(stack,*e);
        else if(*e == ')')
        {
            while((x = pop(stack)) != '(')
            printf("%c", x);
        }
        else
        {
            while(preference(stack->top) >= preference(*e))
            {
                printf("%c",pop(stack));
            }
            push(stack,*e);
        }
        e++;
    }
    while(stack->top != -1)
    {
        printf("%c", pop(stack));
    }
}