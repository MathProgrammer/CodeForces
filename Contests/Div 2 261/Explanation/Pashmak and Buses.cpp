#include <cstdio>

const int MAX_N = 1015;
int arrangement[MAX_N][MAX_N];

int possible(int people, int buses, int days)
{
    //Check if k^d > n
    for(int power = 1, d = 0; d <= days; power *= buses, d++)
    {
        if(power >= people)
            return true;
    }

    return false;
}

int main()
{
    int no_of_people, no_of_buses, no_of_days;
    scanf("%d %d %d", &no_of_people, &no_of_buses, &no_of_days);

    if(!possible(no_of_people, no_of_buses, no_of_days))
    {
        printf("-1\n");
        return 0;
    }

    for(int p = 0; p < no_of_people; p++)
    {
        for(int d = 0; d < no_of_days; d++)
        {
            arrangement[p][d] = (p == 0 ? 0 : arrangement[p - 1][d]);
        }

        for(int d = no_of_days - 1; d >= 0; d--)
        {
            arrangement[p][d]++;
            arrangement[p][d] %= no_of_buses;

            if(arrangement[p][d] != 0)
                break;
        }
    }

    for(int d = 0; d < no_of_days; d++)
    {
        for(int p = 0; p < no_of_people; p++)
        {
            printf("%d ", arrangement[p][d] + 1);
        }
        printf("\n");
    }

    return 0;
}
