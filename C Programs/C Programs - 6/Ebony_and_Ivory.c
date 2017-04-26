#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int main()
{
    int ebony, ivory, shield, i;
    scanf("%d %d %d", &ebony, &ivory, &shield);
    short *is_possible = malloc( (shield + 100)*sizeof(short));
    *(is_possible + 0) = true;

    for(i = 0; i <= shield; i++)
    {
        if(*(is_possible + i) == true) //If c is possible, then c + a, and c + b are possible as well.
        {
            *(is_possible + i + ebony) = true;
            *(is_possible + i + ivory) = true;
        }
    }

    printf(*(is_possible + shield) == true ? "Yes\n" : "No\n");
    free(is_possible);
    return 0;
}

