#include<stdio.h>

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


int BinarySearch(int arr[], int start, int end, int element){
    if(end >= start)
    {
        int middle = start + (end - start)/2;
        if(arr[middle] == element)
        {
            return middle;
        }

        if(arr[middle] > element)
        {
            return BinarySearch(arr, start, middle-1, element);
        }

        else
        {
            return BinarySearch(arr, middle+1, end, element);
        }
    }
    return -1;
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
    int element;
    printf("Enter the element to insert: \n");
    scanf("%d", &element);
    arr.array1[arr.length] = element;
    arr.length++;
    return arr.length;
    // printArr();
}



int main(){

    setValues();
    // int array[20];
    int size = 0;
    int element = 56;

    int choice;
Menu:
    printf("Enter your choice: \n");
    printf("1. Insertion\n");
    printf("2. Binary Search\n");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        size = insertion();
        printArr();
    }

    else if(choice == 2)
    {
        int find_elem;
        printf("\n\nEnter the element you want to find:\n");
        scanf("%d", &find_elem);
        int index = BinarySearch(arr.array1, 0, arr.length-1, find_elem);
        printf("Element found at %d position\n", index+1);

    }
    goto Menu;
}
