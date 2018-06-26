#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

struct knight
{
    int position, power, coin;
};

int sort_by_power(const knight &A, const knight &B)
{
    return (A.power < B.power);
}

int main()
{
    int no_of_knights, max_coins;
    scanf("%d %d", &no_of_knights, &max_coins);

    vector <knight> knights(no_of_knights + 1);
    for(int i = 1; i <= no_of_knights; i++) knights[i].position = i;
    for(int i = 1; i <= no_of_knights; i++) scanf("%d", &knights[i].power);
    for(int i = 1; i <= no_of_knights; i++) scanf("%d", &knights[i].coin);

    sort(all(knights), sort_by_power);

    vector <long long> answer(no_of_knights + 1, 0);
    multiset <int> best_coin;

    for(int i = 1; i <= no_of_knights; i++)
    {
        if(knights[i].power == knights[i - 1].power)
        {
            answer[knights[i].position] = answer[knights[i - 1].position] - knights[i - 1].coin + knights[i].coin;
        }
        else
        {
            int c = 1;
            answer[knights[i].position] = knights[i].coin;

            for(multiset <int> :: reverse_iterator it = best_coin.rbegin(); it != best_coin.rend() && c <= max_coins; it++, c++)
            {
                answer[knights[i].position] += *it;
            }
        }

        best_coin.insert(knights[i].coin);
    }


    for(int i = 1; i <= no_of_knights; i++)
        printf("%I64d ", answer[i]);

    return 0;
}

