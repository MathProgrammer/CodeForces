#include <cstdio>


int main()
{
    int no_of_levels;
    scanf("%d", &no_of_levels);

    int crossed_levels[no_of_levels + 1] = {false};
    int x_levels;
    scanf("%d", &x_levels);

    while(x_levels--)
    {
        int level;
        scanf("%d", &level);
        crossed_levels[level] = true;
    }

    int y_levels;
    scanf("%d", &y_levels);

    while(y_levels--)
    {
        int level;
        scanf("%d", &level);
        crossed_levels[level] = true;
    }

    int possible = true;
    for(int i = 1; i <= no_of_levels; i++)
        if(!crossed_levels[i])
            possible = false;

    printf(possible ? "I become the guy." : "Oh, my keyboard!");

    return 0;
}
