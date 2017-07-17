#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

typedef pair <int, int> int_pair;

int main()
{
    int no_of_instruments, no_of_days, day_i;
    scanf("%d %d", &no_of_instruments, &no_of_days);

    vector < int_pair > no_of_days_to_learn;
    for(int i = 0; i < no_of_instruments; i++)
    {
        scanf("%d", &day_i);
        no_of_days_to_learn.push_back( make_pair(day_i, i + 1));
    }

    sort(all(no_of_days_to_learn));

    vector <int> learnt_instrument;
    for(int i = 0; i < no_of_instruments && no_of_days > 0; i++)
    {
        no_of_days -= no_of_days_to_learn[i].first;

        if(no_of_days >= 0)
            learnt_instrument.push_back(no_of_days_to_learn[i].second);
    }

    printf("%u\n", learnt_instrument.size());
    for(unsigned int i = 0; i < learnt_instrument.size(); i++)
            printf("%d ", learnt_instrument[i]);

    return 0;
}
