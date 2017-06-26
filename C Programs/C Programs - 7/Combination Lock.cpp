#include <stdio.h>
#include <algorithm>
#define MAX_LENGTH 1000 + 1

using namespace std;

int main()
{
    char current_state[MAX_LENGTH], final_state[MAX_LENGTH];
    int number_of_moves = 0, number_of_locks;
    scanf("%d %s %s", &number_of_locks, current_state, final_state);

    for(int i = 0; i < number_of_locks; i++)
    {
        int start, ending;
        start = min(current_state[i], final_state[i]) - '0';
        ending = max(current_state[i], final_state[i]) - '0';

        number_of_moves += min(ending - start,  10 + start - ending); //Optimal to go forwards or backwards
    }

    printf("%d\n", number_of_moves);
    return 0;
}
