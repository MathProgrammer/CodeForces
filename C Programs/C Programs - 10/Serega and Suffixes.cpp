#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    vector <int> element(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    vector <unsigned int> no_of_distinct_elements_from_here(no_of_elements + 1, 0);
    set <int> distinct_elements;
    for(int i = no_of_elements; i >= 1; i--)
    {
        distinct_elements.insert(element[i]);

        no_of_distinct_elements_from_here[i] = distinct_elements.size();
    }

    for(int i = 0; i < no_of_queries; i++)
    {
        int start_i;
        scanf("%d", &start_i);
        printf("%u\n", no_of_distinct_elements_from_here[start_i]);
    }

    return 0;
}
