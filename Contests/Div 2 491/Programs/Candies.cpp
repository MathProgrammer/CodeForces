#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long LL;

LL taken_candies(LL total_candies, LL k)
{
    LL self_candies = 0;

    while(total_candies > 0)
    {
        self_candies += min(k, total_candies);

        total_candies = total_candies - k;

        LL lost_candies = total_candies/10;

        total_candies -= lost_candies;
    }

    return self_candies;
}

int main()
{
    LL no_of_candies;
    scanf("%I64d", &no_of_candies);

    LL target_candies = no_of_candies/2 + no_of_candies%2;

    LL left = 1, right = no_of_candies, answer = 1;

    while(left <= right)
    {
        LL mid = (left + right) >> 1;

        if(taken_candies(no_of_candies, mid) >= target_candies)
        {
            if(mid == 1 || taken_candies(no_of_candies, mid - 1) < target_candies)
            {
                answer = mid;
                break;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%I64d\n", answer);
    return 0;
}


