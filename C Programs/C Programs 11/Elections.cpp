#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_candidates, no_of_cities;
    scanf("%d %d", &no_of_candidates, &no_of_cities);

    vector <int> no_of_wins_for(no_of_candidates + 1, 0);
    for(int city_i = 1; city_i <= no_of_cities; city_i++)
    {
        int round_winner = 1, winner_votes = 0; //If everyone gets 0 votes, the first candidate must win.

        for(int candidate_i = 1; candidate_i <= no_of_candidates; candidate_i++)
        {
            int votes;
            scanf("%d", &votes);

            if(votes > winner_votes)
            {
                round_winner = candidate_i;
                winner_votes = votes;
            }
        }

        no_of_wins_for[round_winner]++;
    }

    int winner = 0;
    for(int i = 1; i <= no_of_candidates; i++)
        if(no_of_wins_for[i] > no_of_wins_for[winner])
            winner = i;

    printf("%d\n", winner);
    return 0;
}
