#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_programmers, no_of_pairs;
    scanf("%d %d", &no_of_programmers, &no_of_pairs);

    vector <int> skill(no_of_programmers + 1, 0);
    for(int i = 1; i <= no_of_programmers; i++)
        scanf("%d", &skill[i]);

    vector <int> sorted_skill(no_of_programmers + 1, 0);
    for(int i = 1; i <= no_of_programmers; i++) sorted_skill[i] = skill[i];

    sort(all(sorted_skill));

    vector <int> no_of_juniors(no_of_programmers + 1);
    for(int i = 1; i <= no_of_programmers; i++)
    {
        no_of_juniors[i] = upper_bound(all(sorted_skill), skill[i] - 1) - sorted_skill.begin() - 1;
    }

    for(int i = 1; i <= no_of_pairs; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if(skill[u] > skill[v])
        {
            no_of_juniors[u]--;
        }
        else if(skill[v] - skill[u])
        {
            no_of_juniors[v]--;
        }
    }

    for(int i = 1; i <= no_of_programmers; i++) printf("%d ", no_of_juniors[i]);

    return 0;
}
