#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int a_element_is;
    scanf("%d", &a_element_is);

    map <int, int> cost;
    for(int i = 1; i <= a_element_is; i++)
    {
        int element_i, cost_i;
        scanf("%d %d", &element_i, &cost_i);
        cost[element_i] = cost_i;
    }

    int b_element_is;
    scanf("%d", &b_element_is);

    for(int i = 1; i <= b_element_is; i++)
    {
        int element_i, cost_i;
        scanf("%d %d", &element_i, &cost_i);

        cost[element_i] = max(cost[element_i], cost_i);
    }

    long long total_cost = 0;
    for(map <int, int> :: iterator it = cost.begin(); it != cost.end(); it++)
    {
        total_cost += it->second;
    }

    printf("%I64d\n", total_cost);
    return 0;
}
