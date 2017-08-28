#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int strength, no_of_dragons;
    scanf("%d %d", &strength, &no_of_dragons);

    vector < pair <int, int> > dragon(no_of_dragons);
    for(int i = 0; i < no_of_dragons; i++)
        scanf("%d %d", &dragon[i].first, &dragon[i].second);

    sort(all(dragon));

    int can_defeat_all_dragons = true;
    for(int i = 0; i < no_of_dragons; i++)
    {
        int strength_of_dragon = dragon[i].first;
        int bonus = dragon[i].second;

        if(strength <= strength_of_dragon)
        {
            can_defeat_all_dragons = false;
            break;
        }
        else
        {
            strength += bonus;
        }
    }

    printf(can_defeat_all_dragons ? "YES\n" : "NO\n");
    return 0;
}
