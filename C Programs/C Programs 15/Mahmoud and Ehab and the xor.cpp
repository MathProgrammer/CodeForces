#include <cstdio>

int main()
{
    int no_of_numbers, x;
    scanf("%d %d", &no_of_numbers, &x);

    if(no_of_numbers == 1)
    {
        printf("YES\n%d\n", x);
    }
    else if(no_of_numbers == 2)
    {
        if(x == 0)
            printf("NO\n");
        else
            printf("YES\n0 %d\n", x);
    }
    else
    {
        const int POWER_2 = 1 << 19, PREVIOUS_POWER_2 = 1 << 18;
        int bitwise_xor = 0;

        printf("YES\n");
        for(int i = 1; i <= no_of_numbers - 3; i++)
        {
            bitwise_xor ^= i;
            printf("%d ", i);
        }

        if(bitwise_xor == x)
            printf("%d %d %d\n", POWER_2, PREVIOUS_POWER_2, (POWER_2|PREVIOUS_POWER_2));
        else
            printf("%d %d %d\n", PREVIOUS_POWER_2, (POWER_2^bitwise_xor^x), (POWER_2|PREVIOUS_POWER_2));
    }

    return 0;
}
