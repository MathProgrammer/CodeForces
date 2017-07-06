#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_groups;
    long long answer = 0;
    scanf("%d", &no_of_groups);

    vector <int> group(no_of_groups + 1, 0);
    for(int i = 1; i <= no_of_groups; i++)
    {
        scanf("%d", &group[i]);
    }


    sort(all(group));
    for(unsigned int i = group.size() - 1; i >= 1; i--)
    {
        int no_of_times_i_is_counted = (i == group.size() - 1 ? i : i + 1);
        answer += no_of_times_i_is_counted*1LL*group[i];
    }

    printf("%I64d\n", answer);
    return 0;
}
