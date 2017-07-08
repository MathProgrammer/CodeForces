#include <cstdio>
#include <map>

#define max(a, b) (a > b ? a : b)
using namespace std;

int main()
{
    map <int, int> frequency;
    const int no_of_cards = 5;

    int sum = 0;
    for(int i = 1; i <= no_of_cards; i++)
    {
        int card_i;
        scanf("%d", &card_i);

        sum += card_i;
        frequency[card_i]++;
    }

    int max_subtracted = 0;
    for(map <int, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
    {
        int number_i = it->first;
        int frequency_i = it->second;
        int subtracted_amount = 0;

        if(frequency_i > 1)
        {
            subtracted_amount = (frequency_i > 2 ? 3*number_i : 2*number_i);
        }

        max_subtracted = max(max_subtracted, subtracted_amount);
    }

    printf("%d\n", sum - max_subtracted);
    return 0;
}
