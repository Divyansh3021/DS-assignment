#include<stdio.h>
#include<stdlib.h>

//declaring global variables
int menuChoice, process = 0;

//declaring a structure
struct array
{
    int length;
    int array1[10];
} arr;

// setting value of variables inside the structure
void setValues()
{
    arr.length = 0;
}

int menu()
{
    printf("Enter 1 for insertion operation\n");
    printf("Enter 2 for deletion operation\n");
    printf("Enter 3 for traversing operation\n");
    printf("Enter 4 to perform linear search\n");
    printf("Enter 5 for selection sort\n");
    printf("Enter 9 to take program exit\n");
    scanf("%d", &menuChoice);
}

int shortMenu()
{
    printf("Enter 1 for insertion operation\n");
    printf("Enter 9 to take program exit\n");
    scanf("%d", &menuChoice);
}

void printArr()
{
    if (arr.length == 0)
    {
        printf("The array is empty\n");
    }
    else
    {
        printf("The array is : ");
        for (int i = 0; i < arr.length - 1; i++)
        {
            printf("%d, ", arr.array1[i]);
        }
        printf("%d\n", arr.array1[arr.length - 1]);
    }
    printf("\n");
}

int insertion()
{
    int element, index, option;
    int begin()
    {
        printf("Enter element to insert at the beginning\n");
        scanf("%d", &element);
        if (arr.length>0)
        {
            for (int i = arr.length; i >=0 ; i--)
            {
                arr.array1[i] = arr.array1[i-1];
            }
        }
        arr.array1[0] = element;
        arr.length++;
        printArr();
    }
    int inMiddle()
    {
        printf("Enter the index: ");
        scanf("%d", &index);
        if (index<=arr.length)
        {    
            printf("Enter element to insert at the index:%d\n", index);
            scanf("%d", &element);
            
            for (int i = arr.length; i > index; i--)
            {
                arr.array1[i] = arr.array1[i-1];
            }
            arr.array1[index] = element;
            arr.length++;
            printArr();
        }
        // checks
        else
        {
            printf("Please enter correct index");
        }
        
    }
    int end()
    {
        printf("Enter the element to insert in the end: \n");
        scanf("%d", &element);
        arr.array1[arr.length] = element;
        arr.length++;
        printArr();
    }
insertOneCheckpoint:
    switch (arr.length)
    {
    case 0:
        begin();
        break;

    case 1:
        printf("Enter 1 to enter in the start\n");
        printf("Enter 2 to enter in the end\n");
        scanf("%d", &option);
        if (option == 1)
        {
            begin();
        }
        else if (option == 2)
        {
            end();
        }
        else
        {
            printf("Choice out of range\n");
            goto insertOneCheckpoint;
        }
        break;

    case 2 ... 9:
        printf("Enter 1 to enter in beginning\n");
        printf("Enter 2 to enter in end\n");
        printf("Enter 3 to enter at a specific index\n");
        scanf("%d", &option);
        if (option == 1)
        {
            begin();
        }
        else if (option == 2)
        {
            end();
        }
        else if (option == 3)
        {
            inMiddle();
        }
        else
        {
            printf("selected option is out of range\n");
            goto insertOneCheckpoint;
        }
        break;
    default:
        printf("Index out of bounds\n");
        break;

    }
}

int deletion()
{
    int index;
insertDeleteCheckpoint:
    printf("Enter the index of the element that you want to remove from array\n");
    scanf("%d", &index);
    if (index >= 0 && index <= arr.length)
    {
        for (int i = index; i <= arr.length; i++)
        {
            arr.array1[i] = arr.array1[i + 1];
        }
        arr.length--;
        printArr();
    }
    else
    {
        printf("Index out of range\n");
        goto insertDeleteCheckpoint;
    }
}

int traverse(){
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d\n",i);
    }

    //commented because we are printing the array already in this function
    // printArr();
}

int searching()
{
    int element, index = -1;
SearchingCheckpoint:
    printf("Enter the element you want to search in the array: \n");
    scanf("%d", &element);
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.array1[i] == element)
        {
            index = i;
        }
    }
    if (index >= 0)
    {
        printf("The index of %d is %d\n", element, index);
    }
    else
    {
        printf("No element like %d is present in array\n",element);
        goto SearchingCheckpoint;
    }
}


int sorting()
{
    int min, index, temp;
    for (int i = 0; i < arr.length; i++)
    {
        min = arr.array1[i];
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.array1[j] < min)
            {
                min = arr.array1[j];
                index = j;
            }
        }
        temp = arr.array1[i];
        arr.array1[i] = min;
        arr.array1[index] = temp;
    }
    printArr();
}


int main(){
    setValues();
    printArr();

printMenu:
    if (arr.length == 0)
    {
        shortMenu();
        switch (menuChoice)
        {
        case 1:
            insertion();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid input!! Enter correct input\n");
            goto printMenu;
            break;
        }
    }

    else
    {
        menu();
        switch (menuChoice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            traverse();
            break;
        case 4:
            searching();
            break;
        case 5:
            sorting();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter correct input\n");
            goto printMenu;
            break;
        }
    }

    goto printMenu;
    return 0;

}