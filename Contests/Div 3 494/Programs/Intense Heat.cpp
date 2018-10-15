#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_days, k;
    scanf("%d %d", &no_of_days, &k);

    vector <int> temperature(no_of_days + 1);
    for(int i = 1; i <= no_of_days; i++)
        scanf("%d", &temperature[i]);

    vector <long long> sum_till(no_of_days + 1, 0);
    for(int i = 1; i <= no_of_days; i++)
        sum_till[i] = sum_till[i - 1] + temperature[i];

    double best = 0;
    for(int length = k; length <= no_of_days; length++)
    {
        for(int left = 1, right = left + length - 1; right <= no_of_days; left++, right++)
        {
            double average_here = (1.0*(sum_till[right] - sum_till[left - 1]))/(1.0*length);

            best = max(best, average_here);
        }
    }

    printf("%.12f\n", best);
    return 0;
}
