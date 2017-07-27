#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_cards;
    scanf("%d", &no_of_cards);

    vector <int> card(no_of_cards);
    for(int i = 0; i < no_of_cards; i++)
        scanf("%d", &card[i]);

    int sergey_sum = 0, dima_sum = 0;
    for(int front_i = 0, back_i = no_of_cards - 1, no_of_turns = 1; no_of_turns <= no_of_cards; no_of_turns++)
    {
        int greater_card = max(card[front_i], card[back_i]);

        if(card[front_i] >= card[back_i])
            front_i++;
        else
            back_i--;

        if(no_of_turns%2 == 1)
            sergey_sum += greater_card;
        else
            dima_sum += greater_card;

    }

    printf("%d %d\n", sergey_sum, dima_sum);
    return 0;
}
