#include <cstdio>
#include <vector>

using namespace std;

int population_count(int x)
{
    int no_of_1s = x;

    const int MASK_1 = 0x55555555;
    const int MASK_2 = 0x33333333;
    const int MASK_3 = 0x0F0F0F0F;
    const int MASK_4 = 0x00FF00FF;
    const int MASK_5 = 0x0000FFFF;

    no_of_1s = (no_of_1s&MASK_1) + ( (no_of_1s >> 1) & MASK_1);
    no_of_1s = (no_of_1s&MASK_2) + ( (no_of_1s >> 2) & MASK_2);
    no_of_1s = (no_of_1s&MASK_3) + ( (no_of_1s >> 4) & MASK_3);
    no_of_1s = (no_of_1s&MASK_4) + ( (no_of_1s >> 8) & MASK_4);
    no_of_1s = (no_of_1s&MASK_5) + ( (no_of_1s >> 16) & MASK_5);

    return no_of_1s;
}
int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int MAX_BITS = 32;
    vector <int> no_of_elements_with_i_bits_set(MAX_BITS, 0);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        no_of_elements_with_i_bits_set[population_count(element_i)]++;
    }

    long long no_of_pairs = 0;
    for(int i = 0; i < MAX_BITS; i++)
    {
        int frequency_i_pop_count = no_of_elements_with_i_bits_set[i];

        no_of_pairs += frequency_i_pop_count*1LL*(frequency_i_pop_count - 1);
    }
    no_of_pairs = no_of_pairs/2; //All pairs are counted up to order

    printf("%I64d\n", no_of_pairs);
    return 0;
}
