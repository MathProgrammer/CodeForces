#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    typedef pair <int, int> pair_int;

    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements);

    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &element[i]);

    vector <pair_int> swaps;
    //Selection Sort
    for(int i = 0; i < no_of_elements; i++)
    {
        int min_i_index = i;
        for(int j = i + 1; j < no_of_elements; j++)
        {
            if(element[j] < element[min_i_index])
                min_i_index = j;
        }

        if(min_i_index != i)
        {
            swaps.push_back(make_pair(i, min_i_index));

            swap(element[min_i_index], element[i]);
        }
    }

    printf("%u\n", swaps.size());
    for(unsigned int i = 0; i < swaps.size(); i++)
    {
        printf("%d %d\n", swaps[i].first, swaps[i].second);
    }
    return 0;
}
