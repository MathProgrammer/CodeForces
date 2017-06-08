#include <stdio.h>

#define MAX_LENGTH 100 + 1
#define true 1
#define false 0

int main()
{
    int a[MAX_LENGTH], missing_number, zero_index = -1, no_of_zeroes, entire_length,i, is_possible = false;
    scanf("%d %d",&entire_length, &no_of_zeroes);

    for(i = 0; i < entire_length; i++)
    {
        scanf("%d", &a[i]);

        if(a[i] == 0)
            zero_index = i;
        else if(i > 0 && a[i] <= a[i - 1])
            is_possible = true;

    }
    for(i = 0; i < no_of_zeroes; i++)
        scanf("%d",&missing_number);

    //If there is more than one zero, it is always possible to make the sequence non-increasing.
    if(no_of_zeroes > 1)
    {
        is_possible = true;
    }
    else
    {
        if(zero_index == 0)
        {
            if(missing_number >= a[zero_index + 1])
                is_possible = true;
        }
        else if(zero_index == entire_length - 1)
        {
            if(missing_number <= a[zero_index - 1])
                is_possible = true;
        }
        else if(missing_number >= a[zero_index + 1] || missing_number <= a[zero_index - 1])
        {
            is_possible = true;
        }
    }


    printf(is_possible ? "Yes\n" : "No\n");
    return 0;
}
