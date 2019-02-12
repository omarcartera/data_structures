//Straight Selection Sort
//By Omar Gamal ... 6/9/2016

#include <stdio.h>

#define MAX_NUMBERS 10

//unsorted set of numbers
int unsorted[MAX_NUMBERS];

//the set after sorting
int sorted[MAX_NUMBERS];

//the sorted number position in the new array
int position=0;

int main()
{
    printf("Enter 10 unsorted unique numbers\n");

    //reading the numbers one by one
    for(int i = 0; i < MAX_NUMBERS; i++)
    {
        scanf(" %d", &unsorted[i]);
    }

    //choosing a pivot as numbers[j] and comparing it to every other number as numbers[k]
    for(int j = 0; j < MAX_NUMBERS; j++)
    {
        for(int k = 0; k < MAX_NUMBERS; k++)
        {
            if(unsorted[j] >= unsorted[k])
                position++;
        }

        sorted[position-1] = unsorted[j];
        position = 0;
    }

    //printing the sorted list of numbers
    for(int l = 0; l < MAX_NUMBERS; l++)
    {
        printf("%d  ", sorted[l]);
    }

    return 0;
}