#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_cards;
    scanf("%d", &no_of_cards);

    map <int, int> present;
    map <int, int> front_frequency;
    map <int, int> back_frequency;

    for(int i = 1; i <= no_of_cards; i++)
    {
        int front, back;
        scanf("%d %d", &front, &back);

        front_frequency[front]++;

        if(front != back) //If front and back have the same colour, count only for front.
            back_frequency[back]++;

        present[front] = true;
        present[back] = true;
    }

    int half = no_of_cards/2 + no_of_cards%2;
    int minimum_moves = no_of_cards + 1;

    for(map <int, int> :: iterator it = present.begin(); it != present.end(); it++)
    {
        int colour = it->first;

        if(front_frequency[colour] + back_frequency[colour] >= half)
        {
            int moves_for_this_colour = half - front_frequency[colour];

            minimum_moves = min(minimum_moves, max(0, moves_for_this_colour));
        }
    }

    printf("%d\n", minimum_moves > no_of_cards ? -1 : minimum_moves);
    return 0;
}
