//Bubble Sort
//By Omar Gamal .. 4/9/2016

#include <stdio.h>

#define MAX_NUMERS 10

//list of numbers, unsorted and then be sorted in the same place
int numbers[MAX_NUMERS];

//temp integer to swap
int temp = 0;


int main()
{
    printf("Enter 10 different space-separated numbers:\n");

    //reading the numbers one by one
    for(int i = 0; i < MAX_NUMERS; i++)
    {
        scanf(" %d", &numbers[i]);
    }

    printf("** ** ** ** ** ** ** ** ** **\n\n");


    //for j times we will compare every two adjacent element and swap them if needed
    for(int j = 0; j < MAX_NUMERS; j++)
    {
        for(int k = 0; k < 9; k++)
        {
            if(numbers[k] > numbers[k+1])
            {
                temp = numbers[k];
                numbers[k] = numbers[k+1];
                numbers[k+1] = temp;
            }
        }
    }

    //printing the sorted list
    for(int l = 0; l < MAX_NUMERS; l++)
        printf("%d  ", numbers[l]);

    printf("\n\n");

    return 0;
}
