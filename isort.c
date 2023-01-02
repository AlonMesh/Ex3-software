#include "Ex3.h"
#define SIZE 50
#include <stdio.h>
void shift_element(int* arr, int i)
{
    for(int j = i; j>0; j--)
    {  
        *(arr+j) = *(arr+j-1);
    }
}

// int* arr shall point to the arr[0] manually
void insertion_sort(int* arr)
{
    for(int i = 0; i < SIZE; i++)
    {
      for (int j = i; j > 0; j--) {
             if (*(arr+j-1) > *(arr+j)) {
                int temp = *(arr+j);
                shift_element(arr+j-1, 1);
                *(arr+j-1) = temp;
             }
        }
    }
}

void main() {
    // CRITIC: we need to get an input from file.txt. Now well do it primitive.
    int arr[SIZE];
    
    // Read integers from standard input and store them in the arrayint
    int i = 0;
    int *ptr = arr;
    while (i < SIZE && scanf("%d", ptr) == 1) {
        ptr++;
        i++;
    }

    insertion_sort(arr);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", *(arr + i));
        if (i!=SIZE-1) {
            printf(",");
        }
    }
    printf("\n"); //sus!!
   
}