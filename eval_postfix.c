#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>


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

int pop(struct Stack* stack)
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
    return stack->top;

}

int top(struct Stack* stack)
{
    if(underflow(stack))
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void evalPostfix(char postfix[]){
    int i = 0;
    char ch;
    int val;
    int A, B;

    while(postfix[i] != ')'){
        ch = postfix[i];
        if(isdigit(ch)){
            push(postfix, ch - '0');
        }

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            A = pop(postfix);
            B = pop(postfix);

            switch (ch) /* ch is an operator */
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            /* push the value obtained above onto the stack */
            push(postfix, val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop(postfix));
        }
    }
}


int main(){
int size, choice;
Size:
printf("\nEnter the size of stack: ");
scanf("%d", &size);

if (size<1)
{
    printf("\nInvalid Size!!\n");
    goto Size;
}

struct Stack* stack = Create(size);

Menu:
    printf("\nChoose the operation: \n");
    printf("\n1: Push char\n");
    printf("\n2: Pop char\n");
    printf("\n3: Evaluate postfix\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        int item;
        printf("\nEnter the number: ");
        scanf("%d", &item);
        push(stack, item);
    }

    else if(choice == 2){
        pop(stack);
    }

    else if(choice == 3){
        int peek = top(stack);
        printf("\nTop is: %d\n", peek);
    }
    goto Menu;
}