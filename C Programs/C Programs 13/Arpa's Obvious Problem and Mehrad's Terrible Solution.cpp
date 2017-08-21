#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int no_of_elements, target;
    scanf("%d %d", &no_of_elements, &target);

    map <int, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        frequency[element_i]++;
    }

    long long no_of_good_pairs = 0;
    for(map <int, int>:: iterator i = frequency.begin(); i != frequency.end(); i++)
    {
        int element_i = i->first;
        int frequency_i = i->second;

        int pair_element = target^element_i;
        int pair_frequency = (element_i == pair_element ? frequency_i - 1 : frequency[pair_element]);

        no_of_good_pairs += pair_frequency*1LL*frequency_i;
    }

    no_of_good_pairs = no_of_good_pairs/2;

    printf("%I64d\n", no_of_good_pairs);
    return 0;
}
