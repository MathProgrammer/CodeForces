#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    long long maximum_value, maximum_with_last_difference_added, maximum_with_last_difference_removed;

    maximum_with_last_difference_added = abs(element[2] - element[1]);
    maximum_with_last_difference_removed = 0;
    maximum_value = maximum_with_last_difference_added;

    for(int i = 3; i <= no_of_elements; i++)
    {
        long long maximum_with_this_difference_added, maximum_with_this_difference_removed, maximum_value_ending_here;

        maximum_with_this_difference_added = max(0LL, maximum_with_last_difference_removed) + abs(element[i] - element[i - 1]);
        maximum_with_this_difference_removed = maximum_with_last_difference_added - abs(element[i] - element[i - 1]);

        maximum_value_ending_here = max(maximum_with_this_difference_added, maximum_with_this_difference_removed);
        maximum_value = max(maximum_value, maximum_value_ending_here);

        maximum_with_last_difference_added = maximum_with_this_difference_added;
        maximum_with_last_difference_removed = maximum_with_this_difference_removed;
    }

    printf("%I64d\n", maximum_value);
    return 0;
}
