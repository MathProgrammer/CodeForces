#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_steps, no_of_dirty_steps;
    scanf("%d %d", &no_of_steps, &no_of_dirty_steps);

    vector <int> dirty_steps(no_of_dirty_steps);
    for(int i = 0; i < no_of_dirty_steps; i++)
        scanf("%d", &dirty_steps[i]);

    sort(all(dirty_steps));

    bool is_possible = true;
    if(no_of_dirty_steps > 0)
    {
        if(dirty_steps.front() == 1 || dirty_steps.back() == no_of_steps)
        {
            is_possible = false;
        }
        else
        {
            for(int i = 2; i < no_of_dirty_steps; i++)
            {
                if(dirty_steps[i] == dirty_steps[i - 1] + 1 && dirty_steps[i] == dirty_steps[i - 2] + 2) //Three consecutive dirty steps
                {
                    is_possible = false;
                    break;
                }
            }
        }
    }


    printf(is_possible ? "YES\n" : "NO\n");
    return 0;
}
