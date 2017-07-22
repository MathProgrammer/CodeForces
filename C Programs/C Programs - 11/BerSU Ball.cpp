#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_girls;
    scanf("%d", &no_of_girls);

    vector <int> girl_skills(no_of_girls);
    for(int i = 0; i < no_of_girls; i++)
        scanf("%d", &girl_skills[i]);

    int no_of_boys;
    scanf("%d", &no_of_boys);

    vector <int> boy_skills(no_of_boys);
    for(int i = 0; i < no_of_boys; i++)
        scanf("%d", &boy_skills[i]);

    sort(all(girl_skills));
    sort(all(boy_skills));

    vector <int> is_available(no_of_boys, true);

    int no_of_pairs = 0;
    for(int i = 0; i < no_of_girls; i++)
    {
        int eligible_boy = lower_bound(all(boy_skills), girl_skills[i] - 1) - boy_skills.begin();

        for( ;abs(boy_skills[eligible_boy] - girl_skills[i]) <= 1 && eligible_boy < no_of_boys; eligible_boy++)
        {
            if(is_available[eligible_boy])
            {
                no_of_pairs++;
                is_available[eligible_boy] = false;
                break;
            }
        }
    }

    printf("%d\n", no_of_pairs);
    return 0;
}
