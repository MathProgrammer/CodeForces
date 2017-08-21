#include <cstdio>

#define MAX_LENGTH 300000 + 2

int main()
{
    char calculator[MAX_LENGTH];
    scanf("%s", calculator);

    long long no_of_multiples_of_4 = ( (calculator[0] - '0')%4 == 0);

    for(int i = 0; calculator[i + 1] != '\0'; i++)
    {
        int current_suffix = (calculator[i] - '0')*10 + (calculator[i + 1] - '0');
        int no_of_strings_ending_with_this_suffix = i + 1;

        if(current_suffix%4 == 0)
            no_of_multiples_of_4 += no_of_strings_ending_with_this_suffix;

        no_of_multiples_of_4 += ( (calculator[i + 1] - '0')%4 == 0);
    }

    printf("%I64d\n", no_of_multiples_of_4);
    return 0;
}
