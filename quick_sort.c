//QuickSort
//By Omar Gamal ... 5/9/2016

#include <stdio.h>

//maximum number of the list
#define MAX 10

//array of numbers, array sets 1 if the number is sorted and 0 if not sorted
int number[MAX];
int state[MAX];

//increments every time a number is sorted in its right place
char sorted = 0;


//reading the numbers from the user
void readNumbers()
{
    printf("Give me some 10 random numbers\n");

    for(int i = 0; i < MAX; i++)
    {
        scanf("%d", &number[i]);
        state[i] = 0;
    }
}


//determining the pivot, small cursor and large cursor
void choosePivot()
{
    int stopPivot = 0;
    int stopSmall = 0;
    int stopLarge = 0;

    int pivot = 0;
    int smallCursor = 0;
    int largeCursor = 0;

    int j = 0;

    //to get pivot, will repeat until the flag is raised
    while(stopPivot == 0)
    {
        if(state[j] == 0)
        {
            pivot = j;
            stopPivot = 1;
        }
        j++;
    }

    //to get small cursor, will repeat until the flag is raised
    while(stopSmall == 0)
    {
        if(state[pivot+1] == 0)
        {
            smallCursor = (pivot+1);
            stopSmall = 1;
        }

        else
        {
            smallCursor = pivot;
            stopSmall = 1;
        }
    }

    
    //to get large cursor, will repeat until the flag is raised
    if(state[pivot+1] == 1)
    {
        largeCursor = pivot;
    }

    else
    {
        j = smallCursor;

        while(stopLarge == 0)
        {
            if((state[j+1] == 1) || ((j+1) == MAX))
            {
                largeCursor = j;
                stopLarge = 1;
            }
            j++;
        }
    }

    sort(pivot, smallCursor, largeCursor);
}


//the function that sorts the whole thing
void sort(int pivot, int smallCursor, int largeCursor)
{
    char smallStop = 0;
    char largeStop = 0;

    int stopSort = 0;
    
    //will continue sorting in the same level until the pivot is sorted and raise the flag
    while(stopSort == 0)
    {
        //if the smaller cursor is less than or equal the pivot it will move right
        if(number[smallCursor] <= number[pivot])
        {
            smallCursor++;
        }

        else
        {
            smallStop = 1;
        }

        //if the larger cursor is larger than the pivot it will move left
        if(number[largeCursor] > number[pivot])
        {
            largeCursor--;
        }

        else
        {
            largeStop = 1;
        }


        //when the cursors overlap the large cursor swaps with the pivot, resets the stops and increment the sorted
        if((smallCursor - largeCursor) == 1)
        {
            int temp;

            temp = number[pivot];
            number[pivot] = number[largeCursor];
            number[largeCursor] = temp;

            state[largeCursor] = 1;
            sorted++;
            stopSort = 1;

            smallStop = 0;
            largeStop = 0;
        }

        //if the cursors stop away from each other they swap
        if((smallStop == 1) && (largeStop == 1))
        {
            int temp;

            temp = number[smallCursor];
            number[smallCursor] = number[largeCursor];
            number[largeCursor] = temp;

            smallStop = 0;
            largeStop = 0;
        }
    }
}


//the function that prints the sorted shit
void printNumbers()
{
    printf("You sorted list is: \n");

    for(int i = 0; i < MAX; i++)
    {
        printf("%d  ", number[i]);
    }

    printf("\n\n\n");
}


int main()
{
    readNumbers();

    while(sorted < MAX)
    {
        choosePivot();
    }

    printNumbers();

    return 0;
}
