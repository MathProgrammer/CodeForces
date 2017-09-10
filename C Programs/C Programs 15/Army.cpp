#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_ranks;
    scanf("%d", &no_of_ranks);

    vector <int> no_of_days_to_reach(no_of_ranks + 1, 0);
    for(int rank_i = 2; rank_i <= no_of_ranks; rank_i++)
    {
        int day_i;
        scanf("%d", &day_i);

        no_of_days_to_reach[rank_i] = no_of_days_to_reach[rank_i - 1] + day_i;
    }

    int starting_rank, ending_rank;
    scanf("%d %d", &starting_rank, &ending_rank);

    printf("%d\n", no_of_days_to_reach[ending_rank] - no_of_days_to_reach[starting_rank]);
    return 0;
}
