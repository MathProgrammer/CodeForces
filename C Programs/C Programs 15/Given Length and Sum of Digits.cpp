#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int sum, no_of_digits;
    scanf("%d %d", &no_of_digits, &sum);

    if(sum == 0 && no_of_digits == 1)
    {
        printf("0 0\n"); return 0;
    }
    else if(sum == 0 || sum > 9*no_of_digits)
    {
        printf("-1 -1\n"); return 0;
    }

    vector <int> minimum_number(no_of_digits + 1, 0);

    int remaining_sum = sum - 1, i;
    for(i = no_of_digits; i > 0 && remaining_sum > 0; i--)
    {
        if(remaining_sum >= 9)
        {
            minimum_number[i] = 9;
            remaining_sum -= 9;
        }
        else
        {
            minimum_number[i] = remaining_sum;
            remaining_sum = 0;
        }
    }

    minimum_number[1] = (minimum_number[1] == 0 ? 1 : minimum_number[1] + 1);

    vector <int> maximum_number(no_of_digits + 1, 0);
    remaining_sum = sum;
    for(i = 1; i <= no_of_digits && remaining_sum > 0; i++)
    {
        if(remaining_sum >= 9)
        {
            maximum_number[i] = 9;
            remaining_sum -= 9;
        }
        else
        {
            maximum_number[i] = remaining_sum;
            remaining_sum = 0;
        }
    }
    for(int i = 1; i <= no_of_digits; i++) printf("%d", minimum_number[i]);

    printf(" ");

    for(int i = 1; i <= no_of_digits; i++) printf("%d", maximum_number[i]);

    return 0;
}
