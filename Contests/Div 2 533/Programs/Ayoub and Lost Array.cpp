#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7, MAX_N = 2e5 + 5;
long long no_of_ways[MAX_N][3];

int get_count(int limit, int remainder)
{
    if(remainder == 0)
        return limit/3;
    else
        return (limit/3 + (limit%3 >= remainder));
}

int main()
{
    int no_of_elements, left, right;
    scanf("%d %d %d", &no_of_elements, &left, &right);

    vector <long long> frequency(3, 0);

    for(int i = 0; i < 3; i++)
    {
        frequency[i] = get_count(right, i) - get_count(left - 1, i);
    }

    no_of_ways[0][0] = 1;
    no_of_ways[0][1] = no_of_ways[0][2] = 0;

    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int last = 0; last < 3; last++)
        {
            for(int previous = 0; previous < 3; previous++)
            {
                int total_remainder = (previous + last)%3;

                no_of_ways[i][total_remainder] += (frequency[last]*no_of_ways[i - 1][previous])%MOD;

                no_of_ways[i][total_remainder] %= MOD;
            }
        }

    }

    printf("%I64d\n", no_of_ways[no_of_elements][0]);
    return 0;
}
