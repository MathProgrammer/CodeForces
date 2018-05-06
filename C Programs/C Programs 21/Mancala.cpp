#include <iostream>
#include <vector>

using namespace std;

long long score_by_distributing(int chosen, vector <long long> stone, int no_of_holes)
{
    int quotient = stone[chosen]/no_of_holes, remainder = stone[chosen]%no_of_holes;

    stone[chosen] = 0;

    int current = chosen;
    do
    {
        stone[current] += quotient;

        current = (current + 1)%no_of_holes;
    }
    while(current != chosen);

    current = (chosen + 1)%no_of_holes;
    while(remainder > 0)
    {
        stone[current]++;
        remainder--;

        current = (current + 1)%no_of_holes;
    }

    long long score = 0;
    for(int i = 0; i < stone.size(); i++)
        if(stone[i]%2 == 0)
            score += stone[i];

    return score;
}

int main()
{
    const int NO_OF_HOLES = 14;
    vector <long long> stone(NO_OF_HOLES);
    for(int i = 0; i < NO_OF_HOLES; i++)
        cin >> stone[i];

    long long maximum_score = 0;
    for(int i = 0; i < NO_OF_HOLES; i++)
        maximum_score = max(maximum_score, score_by_distributing(i, stone, NO_OF_HOLES));

    cout << maximum_score;
    return 0;
}
