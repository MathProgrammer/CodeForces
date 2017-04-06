#include <stdio.h>

int main()
{
    unsigned long long no_of_paths;
    unsigned long long no_of_arrangements;
    scanf("%I64u",&no_of_paths);
    //nC5 nP5
    no_of_arrangements = (no_of_paths)*(no_of_paths -1)/2* (no_of_paths -2)/3* (no_of_paths-3)/4*(no_of_paths-4)/5;
    no_of_arrangements *= (no_of_paths)*(no_of_paths -1)* (no_of_paths -2)* (no_of_paths-3)*(no_of_paths-4);
    printf("%I64u\n",no_of_arrangements);
    return 0;
}
