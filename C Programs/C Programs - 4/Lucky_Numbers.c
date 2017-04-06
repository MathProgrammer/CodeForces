#include <stdio.h>

int main()
{
    unsigned long long max_door_plate_length, no_of_unique_numbers;
    scanf("%I64u",&max_door_plate_length);

    //Answer = 2 + 2^2 + 2^3 + ... + 2^n = 2^{n + 1} - 2. When 2 is right shifted n times, the 1 is in position n+1, which is 2^{n+1}
    no_of_unique_numbers = (2LL << max_door_plate_length) - 2;
    printf("%I64u",no_of_unique_numbers);
    return 0;
}
