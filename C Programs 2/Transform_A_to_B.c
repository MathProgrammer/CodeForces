#include <stdio.h>
#define MAX_INTERMEDIATE_NUMBERS 40

void find_path(unsigned long, unsigned long,short *, unsigned long[]);
void display_path_of_numbers(unsigned long[], short);

int main()
{
    short no_of_intermediate_numbers = 0;
    unsigned long start_number, end_number, path_of_numbers[MAX_INTERMEDIATE_NUMBERS];

    scanf("%lu %lu",&start_number, &end_number);

    find_path(start_number, end_number, &no_of_intermediate_numbers, path_of_numbers);//No of intermediate answers is passed by reference

    //Displaying The Answer. If the path ends in the start number, a path exists.
    if(path_of_numbers[no_of_intermediate_numbers] == start_number)
    {
        printf("YES\n");
        printf("%lu\n",no_of_intermediate_numbers+1); //Right now, no_of_intermediate_numbers is the length of the path from b to a, starting from 0.
        display_path_of_numbers(path_of_numbers, no_of_intermediate_numbers);
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

//Determines the path from a to b
void find_path(unsigned long start_number,unsigned long end_number,short *no_of_intermediate_numbers,unsigned long path_of_numbers[])
{
    path_of_numbers[0] = end_number;
    for(*no_of_intermediate_numbers = 0; path_of_numbers[*no_of_intermediate_numbers] > start_number; *no_of_intermediate_numbers = *no_of_intermediate_numbers+1)
    {
        if(path_of_numbers[*no_of_intermediate_numbers]%2 == 0)
        {
            path_of_numbers[*no_of_intermediate_numbers + 1] = path_of_numbers[*no_of_intermediate_numbers]/2;
        }
        else
        {
            //Checking if the given number can be attained by 10x + 1. For example, there is no integer x, for which 10x + 1 = 15
            if( (path_of_numbers[*no_of_intermediate_numbers] - 1) %10 == 0)
            {
                path_of_numbers[*no_of_intermediate_numbers + 1] = (path_of_numbers[*no_of_intermediate_numbers] - 1)/10;
            }
            else //There is no integer x, for which 10x + 1 is the current number
            {
                path_of_numbers[*no_of_intermediate_numbers + 1] = 0; //This will exit the loop because start number has to be atleast 1.
            }
        }
    }
}

//Displays the path from start to end number i.e. in reverse order of how it was built
void display_path_of_numbers(unsigned long path_of_numbers[], short no_of_intermediate_numbers)
{
    short i;

    for(i = no_of_intermediate_numbers; i >= 0; i--)
    {
        printf("%lu\t",path_of_numbers[i]);
    }
}
