#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Stack{
    int top;
    unsigned size;
    int* arr;
};

struct Stack* Create(unsigned size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
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

void push(struct Stack* stack, int item){
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

int main()
{
    // struct Stack* stack = Create(7);
    // printf("\nPushing started\n");
    // push(stack, 10);
    // push(stack, 15);
    // push(stack, 20);
    // push(stack, 30);
    // push(stack, 40);
    // push(stack, 50);
    // pop(stack);
    // pop(stack);

    // printf("\n%d\n",stack->arr[pop(stack)]);
    int choice,size;

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
    printf("\n1: Push\n");
    printf("\n2: Pop\n");
    printf("\n3: Peek\n");

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

    return 0;
}