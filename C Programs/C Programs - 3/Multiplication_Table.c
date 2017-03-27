#include <stdio.h>

int main()
{
    unsigned int no_of_rows, no_of_boxes_containing_num = 0, i;
    unsigned long number;

    scanf("%u %lu",&no_of_rows, &number);

    //The question of finding the number of boxes that contain n, is equivalent to counting the number of ordered pairs(i, j) such that i*j = n
    for(i = 1;( (i*i < number) && (i <= no_of_rows) ); i++)
    {
        if( (number%i == 0) && (number/i <=no_of_rows) ) //Checking if the spot[i, x/i] exists on the square
        {
            no_of_boxes_containing_num = no_of_boxes_containing_num + 2; //Two boxes [i, x/i] and [x/i, i]
        }
    }

    if( (i*i == number)  && (i <=no_of_rows) )
    {
        no_of_boxes_containing_num++; //Perfect square [i, i]
    }

    printf("%u\n",no_of_boxes_containing_num);
    return 0;
}
