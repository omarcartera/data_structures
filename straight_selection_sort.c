//Straight Selection Sort
//By Omar Gamal ... 6/9/2016

#include <stdio.h>

#define MAX_NUMBERS 5

//unsorted set of numbers
int numbers[MAX_NUMBERS];

//the set after sorting
int sorted[MAX_NUMBERS];


int main()
{
    printf("Enter %d unsorted unique numbers\n", MAX_NUMBERS);

    //reading the numbers one by one
    for(int i = 0; i < MAX_NUMBERS; i++)
    {
        scanf(" %d", &numbers[i]);
    }

    //choosing a pivot as numbers[j] and comparing it to every other number as numbers[k]
    for(int j = 0; j < MAX_NUMBERS; j++)
    {
    	//the sorted number position in the new array
		int position = 0;

        for(int k = 0; k < MAX_NUMBERS; k++)
        {
            if(numbers[j] > numbers[k])
				position++;
        }

        while((numbers[j] == sorted[position]) && (sorted[position] != 0))
        	position++;

        printf("Position is %d: \n", position);
        sorted[position] = numbers[j];
    }

    //printing the sorted list of numbers
    for(int l = 0; l < MAX_NUMBERS; l++)
    {
        printf("%d  ", sorted[l]);
    }

    return 0;
}