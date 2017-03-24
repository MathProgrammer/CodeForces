#include <stdio.h>
#include <string.h>

int read_and_execute_program(unsigned int);
int main()
{
    unsigned int lines_of_code;
    int final_value_of_x;
    scanf("%u",&lines_of_code);

    final_value_of_x = read_and_execute_program(lines_of_code);
    printf("%d",final_value_of_x);
    return 0;
}

int read_and_execute_program(unsigned int lines_of_code)
{
    char current_line_of_code[4]; //Each line of code has three characters
    unsigned int no_of_increments = 0, no_of_decrements = 0, i;
    int final_value;

    //Count the number of increment and decrement statements
    for(i = 0; i < lines_of_code; i++)
    {
        scanf("%s", current_line_of_code);

        if( (strcmp(current_line_of_code, "++X") == 0) || (strcmp(current_line_of_code, "X++") == 0) )
        {
            no_of_increments++;
        }
        else if( (strcmp(current_line_of_code, "--X") == 0) || (strcmp(current_line_of_code, "X--") == 0) )
        {
            no_of_decrements++;
        }
    }

    final_value = no_of_increments - no_of_decrements; //This is the final answer.
    return final_value;
}
