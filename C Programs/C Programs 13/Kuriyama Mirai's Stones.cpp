#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements + 1, 0);
    vector <long long> sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &element[i]);
        sum_till[i] = element[i] + sum_till[i - 1];
    }

    sort(all(element));
    vector <long long> sorted_sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sorted_sum_till[i] = element[i] + sorted_sum_till[i - 1];
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int query_type, left, right;
        scanf("%d %d %d", &query_type, &left, &right);

        long long answer = (query_type == 1 ? sum_till[right] - sum_till[left - 1] : sorted_sum_till[right] - sorted_sum_till[left - 1]);
        printf("%I64d\n", answer);
    }
    return 0;
}
