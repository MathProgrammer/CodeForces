#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_cards;
    scanf("%d", &no_of_cards);

    vector <int> card(no_of_cards);
    for(int i = 0; i < no_of_cards; i++) scanf("%d", &card[i]);

    if(no_of_cards == 1)
    {
        printf("-1\n");
        return 0;
    }

    vector <int> new_cards;

    if(no_of_cards == 2 && (card[0] != card[1]) && (card[0] + card[1])%2 == 0)
    {
        new_cards.push_back( (card[0] + card[1])/2 );
    }

    sort(all(card));

    int min_difference = card[1] - card[0];
    for(int i = 2; i < no_of_cards; i++)
        min_difference = min(min_difference, card[i] - card[i - 1]);

    int ap_possible = true, new_middle_cards = 0;
    for(int i = 1; i < no_of_cards; i++)
    {
        if(card[i] - card[i - 1] != min_difference)
        {
            if(card[i] - card[i - 1] == 2*min_difference)
            {
                new_middle_cards++;
            }
            else
            {
                ap_possible = false;
            }
        }
    }

    if(ap_possible)
    {
        if(min_difference == 0)
        {
            new_cards.push_back(card[0]);
        }
        else if(new_middle_cards == 0)
        {
            new_cards.push_back(card[0] - min_difference);
            new_cards.push_back(card[no_of_cards - 1] + min_difference);
        }
        else if(new_middle_cards == 1)
        {
            for(int i = 1; i < no_of_cards; i++)
                if(card[i] - card[i - 1] == 2*min_difference)
                    new_cards.push_back(card[i - 1] + min_difference);
        }
    }

    sort(all(new_cards));

    printf("%d\n", new_cards.size());
    for(int i = 0; i < new_cards.size(); i++)
        printf("%d ", new_cards[i]);

    return 0;
}
