#include <stdio.h>
#define NO_OF_SHUFFLES 3

int main()
{
    int ball_shell, shell_1, shell_2, i;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    fscanf(input, "%d", &ball_shell);

    for(i = 1; i <= NO_OF_SHUFFLES; i++)
    {
        fscanf(input,"%d %d",&shell_1, &shell_2);
        if(ball_shell == shell_1)
        {
            ball_shell =  shell_2;
        }
        else if(ball_shell == shell_2)
        {
            ball_shell = shell_1;
        }
    }
    fprintf(output,"%d\n",ball_shell);

    fclose(input);
    fclose(output);
    return 0;
}
