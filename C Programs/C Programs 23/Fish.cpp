#include <cstdio>

const int MAX_FISH = 20;
double probability[(1 << MAX_FISH)];
double eat_probability[MAX_FISH][MAX_FISH];

int is_alive(int n, int bit)
{
    return ( (n&(1LL << bit)) != 0);
}

int kill(int n, int bit)
{
    return (n^(1LL << bit));
}

int no_of_set_bits(int n)
{
    int no_of_1s = 0;

    while(n)
    {
        no_of_1s += n%2;
        n /= 2;
    }

    return no_of_1s;
}

int choose_2(int n)
{
    return (n*(n - 1))/2;
}

int main()
{
    int no_of_fish;
    scanf("%d", &no_of_fish);

    for(int i = 0; i < no_of_fish; i++)
        for(int j = 0; j < no_of_fish; j++)
            scanf("%lf", &eat_probability[i][j]);

    int max_mask = (1LL << no_of_fish) - 1; //Mask has a bit set if fish i is alive.
    probability[max_mask] = 1.0; //All fish alive in the beginning


    for(int mask = max_mask; mask >= 1; mask--)
    {
        for(int eating_fish = 0; eating_fish < no_of_fish; eating_fish++)
        {
            if(is_alive(mask, eating_fish)) //Eating fish is alive
            {
                for(int victim_fish = 0; victim_fish < no_of_fish; victim_fish++)
                {
                    if(is_alive(mask, victim_fish) && eating_fish != victim_fish)
                    {
                        int mask_without_victim = kill(mask, victim_fish);

                        int no_of_alive_fish = no_of_set_bits(mask);
                        int no_of_combinations = choose_2(no_of_alive_fish);

                        probability[mask_without_victim] += (probability[mask]*eat_probability[eating_fish][victim_fish])/no_of_combinations;
                    }
                }
            }
        }
    }


    for(int i = 0; i < no_of_fish; i++)
        printf("%.12lf ", probability[(1LL << i)]);

    return 0;
}
