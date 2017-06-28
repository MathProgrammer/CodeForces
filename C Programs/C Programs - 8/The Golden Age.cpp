#include <stdio.h>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(),(v).end()
using namespace std;

int main()
{
    unsigned int a, b, i;
    long long x, y, left_limit, right_limit, max_lucky_years = 0, current_lucky_run;

    scanf("%I64d %I64d %I64d %I64d",&x, &y, &left_limit, &right_limit);

    vector <long long> powers_of_x;
    vector <long long> powers_of_y;
    vector <long long> sums_of_powers_x_y; //All the unlucky years.

    powers_of_x.push_back(1);
    while(powers_of_x.back() <= right_limit/x)
    {
        powers_of_x.push_back(x*powers_of_x.back());
    }

    powers_of_y.push_back(1);
    while(powers_of_y.back() <= right_limit/y)
    {
        powers_of_y.push_back(y*powers_of_y.back());
    }

    sums_of_powers_x_y.push_back(left_limit - 1);
    sums_of_powers_x_y.push_back(right_limit + 1);
    for(a = 0; a < powers_of_x.size(); a++)
    {
        for(b = 0; b < powers_of_y.size(); b++)
        {
            sums_of_powers_x_y.push_back(powers_of_x[a] + powers_of_y[b]);
        }
    }

    sort( all(sums_of_powers_x_y) );

    i = 0;
    while(sums_of_powers_x_y[i] < left_limit - 1)
        i++;

    i++;
    while(sums_of_powers_x_y[i] <= right_limit + 1 && i < sums_of_powers_x_y.size())
    {
        current_lucky_run = sums_of_powers_x_y[i] - sums_of_powers_x_y[i - 1] - 1;

        max_lucky_years = max(max_lucky_years, current_lucky_run);
        i++;
    }

    printf("%I64d\n",max_lucky_years);
    return 0;
}
