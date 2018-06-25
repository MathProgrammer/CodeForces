#include <cstdio>
#include <vector>

using namespace std;

int ceil(int numerator, int denominator)
{
    int quotient = numerator/denominator;
    int remainder = numerator%denominator;

    return (quotient + (remainder != 0));
}

int main()
{
    int no_of_queues;
    scanf("%d", &no_of_queues);

    vector <int> length(no_of_queues + 1);
    for(int i = 0; i < no_of_queues; i++)
        scanf("%d", &length[i]);

    for(int i = 0; i < no_of_queues; i++)
        length[i] = max(length[i] - i, 0);

    vector <int> rounds_to_arrive_at(no_of_queues);
    for(int i = 0; i < no_of_queues; i++)
        rounds_to_arrive_at[i] = ceil(length[i], no_of_queues);

    const int oo = 1e9;
    int best_queue, minimum_rounds = oo;
    for(int i = 0; i < no_of_queues; i++)
        if(rounds_to_arrive_at[i] < minimum_rounds)
            minimum_rounds = rounds_to_arrive_at[i], best_queue = i + 1;

    printf("%d\n", best_queue);

    return 0;
}
