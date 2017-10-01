#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <long long> sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        sum_till[i] = sum_till[i - 1] + element_i;
    }

    vector <long long> sum_from(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_from[i] = sum_till[no_of_elements] - sum_till[i - 1];
    }

    long long no_of_ways = 0, total_sum = sum_till[no_of_elements];

    if(total_sum%3 != 0)
    {
        printf("%I64d\n", no_of_ways);
        return 0;
    }

    vector <int> no_of_places_that_sum_to_a_third_from(no_of_elements + 2, 0);
    for(int i = no_of_elements; i >= 1; i--)
    {
        no_of_places_that_sum_to_a_third_from[i] = no_of_places_that_sum_to_a_third_from[i + 1] +
                                                   (3*sum_from[i] == total_sum);
    }

    for(int i = 1; i <= no_of_elements - 2; i++)
    {
        if(3*sum_till[i] == total_sum)
        {
            no_of_ways += no_of_places_that_sum_to_a_third_from[i + 2];
        }
    }

    printf("%I64d\n", no_of_ways);
    return 0;
}
