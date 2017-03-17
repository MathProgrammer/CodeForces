#include <stdio.h>
#include <string.h>

#define ANSWER_SIZE 4
int main()
{
    char answer[ANSWER_SIZE];
    short no_of_odd_steps, no_of_even_steps;

    scanf("%hu %hu",&no_of_even_steps, &no_of_odd_steps);

    if( (no_of_odd_steps - no_of_even_steps <= 1) && (no_of_odd_steps - no_of_even_steps >= -1) )
    {
        if( (no_of_odd_steps == 0) && (no_of_even_steps == 0)) //If both are zero, then the answer is no
        {
            strcpy(answer, "NO");
        }
        else
        {
            strcpy(answer, "YES");
        }
    }
    else
    {
        strcpy(answer, "NO");
    }

    printf("%s\n",answer);
}
