#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_numbers, no_of_intervals, max_interval_size;
    scanf("%d %d %d", &no_of_numbers, &max_interval_size, &no_of_intervals);

    vector <long long> sum_till(no_of_numbers + 1, 0);
    for(int i = 1; i <= no_of_numbers; i++)
    {
        int number_i;
        scanf("%d", &number_i);
        sum_till[i] = number_i + sum_till[i - 1];
    }

    typedef vector <long long> v_long;
    vector <v_long> maximum_sum_till(no_of_numbers + 1, v_long(no_of_intervals + 1, 0));

    for(int interval_i = 1; interval_i <= no_of_intervals; interval_i++)
    {
        for(int number_i = max_interval_size; number_i <= no_of_numbers; number_i++)
        {
            int right = number_i, left = (number_i - max_interval_size) + 1;
            long long interval_ending_here_sum = sum_till[right] - sum_till[left - 1];

            long long maximum_sum_with_interval_ending_here = maximum_sum_till[left - 1][interval_i - 1] + interval_ending_here_sum ;

            long long maximum_sum_with_interval_ending_before_here = maximum_sum_till[number_i - 1][interval_i];

            maximum_sum_till[number_i][interval_i] = max(maximum_sum_with_interval_ending_here, maximum_sum_with_interval_ending_before_here);
        }
    }

    printf("%I64d\n", maximum_sum_till[no_of_numbers][no_of_intervals]);
    return 0;
}
