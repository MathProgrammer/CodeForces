#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_DIGITS = 18;
vector <long long> classy_numbers;

void precompute(int position, int non_zero_count, long long current_num)
{
    if(non_zero_count > 3)
        return;

    if(position == MAX_DIGITS)
    {
        classy_numbers.push_back(current_num);
        return;
    }

    for(int digit = 0; digit <= 9; digit++)
    {
        precompute(position + 1, non_zero_count + (digit != 0), current_num*10 + digit);
    }
}

int main()
{
    precompute(0, 0, 0);
    classy_numbers.push_back(1e18); //This has 19 digits

    int no_of_tests;
    scanf("%d", &no_of_tests);

    while(no_of_tests--)
    {
        long long left, right;
        scanf("%I64d %I64d", &left, &right);

        int classy_number_count = upper_bound(all(classy_numbers), right) - lower_bound(all(classy_numbers), left);
        printf("%d\n", classy_number_count);
    }
    return 0;
}
