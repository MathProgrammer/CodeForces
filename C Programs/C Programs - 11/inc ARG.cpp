#include <cstdio>

#define MAX_LENGTH 100 + 2

int main()
{
    int no_of_bits;
    char initial_state[MAX_LENGTH];
    scanf("%d %s", &no_of_bits, initial_state);

    int first_zero_location = no_of_bits; //Assume there is no 0 so it will be outside the register at first
    for(int i = 0; i < no_of_bits; i++)
    {
        if(initial_state[i] == '0')
        {
            first_zero_location = i + 1; //0-indexed
            break;
        }
    }

    printf("%d\n", first_zero_location);
    return 0;
}
