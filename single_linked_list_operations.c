#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr)
{

    if (ptr == NULL)
    {
        printf("There are no elements in the linked list to traverse!\n");
    }
    else
    {
        printf("Linked List : ");
        while (ptr->next != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

struct Node *insertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node*));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node*));
    ptr->data = data;

    if(head == NULL){
        ptr->next = NULL;
        return ptr;
    }
    else{
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
    }
}
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node*));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
    return head;
}

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteByValue(struct Node * head, int value){
    struct Node *p = head;

    if(head->data == value){
        head = head->next;
        free(p);
    }
    else{
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    else{
        printf("There is no such node with the entered vakue !\n");
    }
    }
    return head;
}

int main()
{
    struct Node *head;
    // head = (struct Node *)malloc(sizeof(struct Node *));
    head = NULL;

    int oprt, sub_oprt;

    while (1)
    {
        printf("PRESS\n1 -> Traverse\n2 -> Insert\n3 -> Delete\n4 -> Exit\n");
        scanf("%d", &oprt);

        if (oprt == 1)
        {
            traverse(head);
        }

        else if (oprt == 2)
        {
            printf("Choose where to insert the element \n1 -> At Begining\n2 -> At end\n3-> After a specified value\n");
            scanf("%d", &sub_oprt);

            int info;
            printf("Enter the value of the new node : ");
            scanf("%d", &info);

            if (sub_oprt == 1)
            {
                head = insertAtBegining(head, info);
            }
            else if (sub_oprt == 2)
            {

                head = insertAtEnd(head, info);
            }
            else if(sub_oprt == 3){
                int value;
                printf("Enter the value of node after which the new node is to be inserted : ");
                scanf("%d",&value);

                struct Node* p = head;
                while(p != NULL){
                    if(p->data == value){
                        break;
                    }
                    else{
                        p = p->next;
                    }
                }
                if(p == NULL){
                    printf("There is no node with its data equal to the entered value!\n");
                }
                else{
                    head = insertAfterNode(head,p,info);
                }
            }
            traverse(head);
        }

        else if(oprt == 3){
            if(head == NULL){
                printf("UNDERFLOW ! There is no node that can be deleted !\n");
            }
            else{
                printf("Choose from where to delete the element \n1 -> At Begining\n2 -> At end\n3-> At a specified value\n");
                scanf("%d", &sub_oprt);

                if(sub_oprt == 1){
                    head = deleteFirst(head);
                }
                else if(sub_oprt == 2){
                    head = deleteAtLast(head);
                }
                else if(sub_oprt == 3){
                    int value;
                    printf("Enter the value : ");
                    scanf("%d",&value);
                    head = deleteByValue(head,value);
                }
                traverse(head);
            }
        }

        else if (oprt == 4)
        {
            break;
        }
    }
}
