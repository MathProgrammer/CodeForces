#include <cstdio>

int main()
{
    int no_of_apples, weight_i;
    scanf("%d", &no_of_apples);

    int no_of_100s = 0, no_of_200s = 0;
    for(int i = 1; i <= no_of_apples; i++)
    {
        scanf("%d", &weight_i);

        no_of_100s += (weight_i == 100);
        no_of_200s += (weight_i == 200);
    }

    no_of_200s = (no_of_200s%2); //Distribute half of them to either group.
    no_of_100s = no_of_100s - 2*no_of_200s; //Balancing out the 200;

    printf(no_of_100s%2 == 0 && no_of_100s >= 0 ? "YES\n" : "NO\n"); //check if remaining 100s can be divided in half.
    return 0;
}
