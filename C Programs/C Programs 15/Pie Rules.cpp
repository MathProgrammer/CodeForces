#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_pieces;
    scanf("%d", &no_of_pieces);

    vector <int> pie(no_of_pieces + 1);
    for(int i = 1; i <= no_of_pieces; i++)
        scanf("%d", &pie[i]);

    vector <int> sum_from(no_of_pieces + 3, 0);
    const int NO_OF_PLAYERS = 2, ALICE = 0, BOB = 1;
    int maximum_from[no_of_pieces + 1][NO_OF_PLAYERS];

    for(int i = no_of_pieces; i >= 1; i--)
    {
        sum_from[i] = sum_from[i + 1] + pie[i];

        if(i == no_of_pieces)
        {
            maximum_from[i][ALICE] = maximum_from[i][BOB] = pie[i];
        }
        else
        {
            maximum_from[i][ALICE] = max(maximum_from[i + 1][ALICE], pie[i] + sum_from[i + 1] - maximum_from[i + 1][BOB]);
            maximum_from[i][BOB] = max(maximum_from[i + 1][BOB], pie[i] + sum_from[i + 1] - maximum_from[i + 1][BOB]);
        }
    }

    int maximum_for_alice = sum_from[1] - maximum_from[1][BOB];

    printf("%d %d\n", maximum_for_alice, maximum_from[1][BOB]);
    return 0;
}
