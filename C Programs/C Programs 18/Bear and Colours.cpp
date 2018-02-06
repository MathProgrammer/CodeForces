#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_balls;
    scanf("%d", &no_of_balls);

    vector <int> colour(no_of_balls + 1, 0);
    for(int i = 1; i <= no_of_balls; i++)
        scanf("%d", &colour[i]);

    vector <int> no_of_winning_intervals(no_of_balls + 1);
    for(int start = 1; start <= no_of_balls; start++)
    {
        vector <int> frequency(no_of_balls + 1, 0);
        int winner = 0;

        for(int i = start; i <= no_of_balls; i++)
        {
            frequency[colour[i]]++;

            if(frequency[colour[i]] > frequency[winner] || (frequency[colour[i]] == frequency[winner] && colour[i] < winner))
                winner = colour[i];

            no_of_winning_intervals[winner]++;
        }
    }

    for(int ball_i = 1; ball_i <= no_of_balls; ball_i++)
        printf("%d ", no_of_winning_intervals[ball_i]);

    return 0;
}
