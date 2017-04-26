#include <stdio.h>

int main()
{
    int no_of_elements, i, current_number, previous_number = 0,step_length, no_of_steps_to_be_added, no_of_operations_performed = 0;
    scanf("%d %d",&no_of_elements, &step_length);

    for(i = 1; i <= no_of_elements; i++)
    {
        scanf("%d",&current_number);
        if(previous_number >= current_number)
        {
            //We need to add enough steps to make current number atleast previous number + 1.
            //This is at least (previous number - current number + 1)/step length
            //If it is not a perfect multiple of step length, then we need to add one more step because integer division finds the floor.
            no_of_steps_to_be_added = (previous_number - current_number + 1)/step_length;
            no_of_steps_to_be_added += (previous_number - current_number + 1)%step_length == 0 ? 0 : 1;

            current_number = current_number + no_of_steps_to_be_added*step_length;
            no_of_operations_performed += no_of_steps_to_be_added;
        }
        previous_number = current_number;
    }

    printf("%d\n",no_of_operations_performed);
    return 0;
}
