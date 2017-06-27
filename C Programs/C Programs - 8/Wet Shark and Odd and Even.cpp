#include <stdio.h>

#define min(a, b) (a < b ? a : b)

int main()
{
    int min_odd_number, number_of_elements, number_i;
    long long sum = 0;
    scanf("%d", &number_of_elements);

    min_odd_number = 1e9 + 1;
    for(int i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &number_i);
        sum += number_i;

        if(number_i%2 == 1)
            min_odd_number = min(min_odd_number, number_i);
    }

    printf("%I64d\n", sum%2 == 0 ? sum : sum - min_odd_number);
    return 0;
}
