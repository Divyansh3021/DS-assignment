#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop()
{
    struct node *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printList()
{
    struct node *temp = head;

    while(temp != NULL)
    {
         printf("%d ", temp->data);
         temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;

Menu:
    printf("Enter your choice: \n");
    printf("1: Push\n2: Pop \n3: Print stack\n");

    scanf("%d", &choice);

    if(choice == 1){
        int push_element;
        printf("Enter the number you want to push: ");
        scanf("%d", &push_element);
        push(push_element);
        printf("\n\nNew stack: ");
        printList();
    }

    else if(choice == 2){
        pop();
        printf("\nNew stack is: ");
        printList();
        printf("\n");
    }

    else if(choice == 3){
        printf("\nCurrent stack is: ");
        printList();
    }

    goto Menu;

    return 0;
}