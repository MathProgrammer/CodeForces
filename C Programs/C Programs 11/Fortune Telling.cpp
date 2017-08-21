#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    const int odd_oo = 1e9 + 1;
    int no_of_flowers, answer;
    scanf("%d", &no_of_flowers);

    int sum_of_even_numbers = 0, sum_of_odd_numbers = 0, smallest_odd_number = odd_oo;
    for(int i = 1; i <= no_of_flowers; i++)
    {
        int petals;
        scanf("%d", &petals);

        if(petals%2 == 0)
            sum_of_even_numbers += petals;
        else
        {
            sum_of_odd_numbers += petals;
            smallest_odd_number = min(smallest_odd_number, petals);
        }
    }

    if(sum_of_odd_numbers == 0)
        answer = 0;
    else
        if(sum_of_odd_numbers%2 == 0)
            answer = sum_of_even_numbers + sum_of_odd_numbers - smallest_odd_number; //To keep the sum odd
        else if(sum_of_odd_numbers%2 == 1)
            answer = sum_of_even_numbers + sum_of_odd_numbers;

    printf("%d\n", answer);

    return 0;
}
