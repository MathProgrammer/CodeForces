#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_soldiers, no_of_queries;
    scanf("%d %d", &no_of_soldiers, &no_of_queries);

    vector <long long> strength(no_of_soldiers + 1);
    for(int i = 1; i <= no_of_soldiers; i++)
        scanf("%I64d", &strength[i]);

    vector <long long> sum(no_of_soldiers + 1, 0);
    for(int i = 1; i <= no_of_soldiers; i++)
        sum[i] = sum[i - 1] + strength[i];

    long long total_arrows = 0;
    while(no_of_queries--)
    {
        long long arrows;
        scanf("%I64d", &arrows);

        total_arrows += arrows;

        if(total_arrows >= sum[no_of_soldiers])
            total_arrows = 0;

        int no_of_dead_soldiers = upper_bound(all(sum), total_arrows) - sum.begin() - 1;

        int no_of_alive_soldiers = no_of_soldiers - no_of_dead_soldiers;

        printf("%d\n", no_of_alive_soldiers);
    }

    return 0;
}
