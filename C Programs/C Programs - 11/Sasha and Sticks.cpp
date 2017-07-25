#include <cstdio>

int main()
{
    long long no_of_sticks, one_turn_draw;
    scanf("%I64d %I64d", &no_of_sticks, &one_turn_draw);

    long long no_of_turns = no_of_sticks/one_turn_draw;
    printf(no_of_turns%2 == 1 ? "Yes\n" : "No\n");
    return 0;
}
