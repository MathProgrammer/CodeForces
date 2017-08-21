#include <cstdio>

#define MAX_LENGTH 1000000 + 2

int main()
{
    char lever[MAX_LENGTH];
    scanf("%s", lever);

    bool left = true, right = false;
    long long left_moment = 0, right_moment = 0, weights_till_here = 0;
    int distance_from_pivot;

    for(int i = 0; lever[i] != '\0'; i++)
    {
        if(lever[i] == '^')
        {
            left = false, right = true;
            distance_from_pivot = 0;
        }
        else
        {
            if(left)
            {
                if(lever[i] != '=')
                    weights_till_here += (lever[i] - '0');

                left_moment += weights_till_here;
            }
            else if(right)
            {
                distance_from_pivot++;

                if(lever[i] != '=')
                   right_moment += distance_from_pivot*(lever[i] - '0');
            }
        }
    }

    if(left_moment == right_moment)
        printf("balance\n");
    else
        printf(left_moment > right_moment ? "left\n" : "right\n");

    return 0;
}
