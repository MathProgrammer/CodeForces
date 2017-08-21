#include <cstdio>
#include <algorithm>
#include <vector>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_problems, max_solved_difficulty;
    scanf("%d %d", &no_of_problems, &max_solved_difficulty);

    vector <int> difficulty(no_of_problems);
    for(int i = 0; i < no_of_problems; i++)
    {
        scanf("%d", &difficulty[i]);
    }

    sort(all(difficulty));

    int no_of_practice_problems_required = 0;
    int range = 2*max_solved_difficulty;

    for(int i = 0; i < no_of_problems; i++)
    {
        if(difficulty[i] > range)
        {
             while(difficulty[i] > range)
            {
                no_of_practice_problems_required++;

                range = range*2;
            }
        }

        range = max(2*difficulty[i], range);
    }

    printf("%d\n", no_of_practice_problems_required);
    return 0;
}
