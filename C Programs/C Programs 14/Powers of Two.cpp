#include <cstdio>
#include <map>
#include <set>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    set <int> original_array;
    map <int, int> frequency;
    for(int i = 0; i < no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        frequency[element_i]++;
        original_array.insert(element_i);
    }

    long long no_of_pairs = 0;
    for(map <int, int> :: iterator i = frequency.begin(); i != frequency.end(); i++)
    {
        int element_i = i->first;
        int frequency_i = i->second;

        for(int power = 0; power <= 31; power++)
        {
            int power_of_2 = (1 << power);

            int pair_element = power_of_2 - element_i;
            int pair_frequency = 0;

            if(pair_element > 0 && original_array.count(pair_element) == 1)
                pair_frequency = (element_i == pair_element ? frequency_i - 1 : frequency[pair_element]);

            no_of_pairs += frequency_i*1LL*pair_frequency;

        }
    }

    no_of_pairs = no_of_pairs/2;

    printf("%I64d\n", no_of_pairs);
    return 0;
}
