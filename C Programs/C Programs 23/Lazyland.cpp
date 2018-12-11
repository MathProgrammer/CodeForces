#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_people, distinct_targets;
    scanf("%d %d", &no_of_people, &distinct_targets);

    vector <int> A(no_of_people + 1);
    for(int i = 1; i <= no_of_people; i++)
        scanf("%d", &A[i]);

    vector <int> time(no_of_people + 1);
    for(int i = 1; i <= no_of_people; i++)
        scanf("%d", &time[i]);

    map <int, int> max_time_for_task;
    vector <int> free_time;
    for(int i = 1; i <= no_of_people; i++)
    {
        if(max_time_for_task[A[i]] != 0)
            free_time.push_back(min(time[i], max_time_for_task[A[i]]));

        max_time_for_task[A[i]] = max(max_time_for_task[A[i]], time[i]);
    }

    sort(all(free_time));

    int distinct_numbers = max_time_for_task.size();
    int required_new_distinct_numbers = distinct_targets - distinct_numbers;

    long long total_time = 0;
    for(int i = 0; i < required_new_distinct_numbers; i++)
        total_time += free_time[i];

    printf("%I64d\n", total_time);
    return 0;
}
