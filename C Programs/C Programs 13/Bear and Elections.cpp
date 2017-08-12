#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int no_of_candidates;
    scanf("%d", &no_of_candidates);

    int limak_votes;
    priority_queue <int> votes;

    scanf("%d", &limak_votes);
    for(int i = 2; i <= no_of_candidates; i++)
    {
        int vote_i;
        scanf("%d", &vote_i);

        votes.push(vote_i);
    }

    int limak_bribes = 0;
    while(limak_votes + limak_bribes <= votes.top())
    {
        int current_max = votes.top();
        votes.pop();

        current_max--;
        limak_bribes++;
        votes.push(current_max);
    }


    printf("%d\n", limak_bribes);
    return 0;
}

