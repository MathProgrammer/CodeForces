#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    vector <int> element(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    vector <int> no_of_queries_starting_here(no_of_elements + 1, 0);
    vector <int> no_of_queries_ending_here(no_of_elements + 1, 0);

    for(int i = 1; i <= no_of_queries; i++)
    {
        int left_i, right_i;
        scanf("%d %d", &left_i, &right_i);

        no_of_queries_starting_here[left_i]++;

        if(right_i + 1 <= no_of_elements)
            no_of_queries_ending_here[right_i + 1]++;
    }

    int no_of_queries_on_this_index = 0;
    vector <int> no_of_times_index_queried(no_of_elements + 1, 0);

    for(int i = 1; i <= no_of_elements; i++)
    {
        no_of_queries_on_this_index += (no_of_queries_starting_here[i] - no_of_queries_ending_here[i]);

        no_of_times_index_queried[i] = no_of_queries_on_this_index;
    }

    sort(all(element));
    sort(all(no_of_times_index_queried));

    long long maximum_sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
        maximum_sum += no_of_times_index_queried[i]*1LL*element[i];

    printf("%I64d\n", maximum_sum);
    return 0;
}
