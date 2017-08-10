#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_people;
    scanf("%d", &no_of_people);

    vector < pair <int, int> > cards;
    for(int i = 1; i <= no_of_people; i++)
    {
        int card_i;
        scanf("%d", &card_i);
        cards.push_back(make_pair(card_i, i));
    }

    sort(all(cards));
    vector < pair <int, int> > dealt_cards;
    for(int front_i = 0, back_i = no_of_people - 1; front_i < back_i; front_i++, back_i--)
    {
        int front_index = cards[front_i].second;
        int back_index = cards[back_i].second;

        dealt_cards.push_back(make_pair(front_index, back_index));
    }

    for(unsigned int i = 0; i < dealt_cards.size(); i++)
        printf("%d %d\n", dealt_cards[i].first, dealt_cards[i].second);

    return 0;
}
