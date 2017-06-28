#include <cstdio>

#define MAX_LENGTH 100 + 1

int main()
{
    bool produces_output = false;
    char program[MAX_LENGTH];
    scanf("%s", program);

    for(int i = 0; program[i] != '\0'; i++)
    {
        if(program[i] == 'H' || program[i] == 'Q' || program[i] == '9')
        {
            produces_output = true;
            break;
        }
    }

    printf(produces_output ? "YES\n" : "NO\n");
    return 0;
}
