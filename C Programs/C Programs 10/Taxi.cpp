#include <cstdio>
#define min(a, b) (a < b ? a : b)

int main()
{
    int no_of_groups;
    scanf("%d", &no_of_groups);

    int no_of_1s = 0, no_of_2s = 0, no_of_3s = 0, no_of_4s = 0;
    int group_i;
    for(int i = 1; i <= no_of_groups; i++)
    {
        scanf("%d", &group_i);

        no_of_1s += (group_i == 1);
        no_of_2s += (group_i == 2);
        no_of_3s += (group_i == 3);
        no_of_4s += (group_i == 4);
    }

    int no_of_rides_with_3_and_1 = min(no_of_3s, no_of_1s);

    int no_of_rides = no_of_4s + no_of_rides_with_3_and_1 + no_of_2s/2;

    //The remaining groups of 2s 3s and 4s
    no_of_3s -= no_of_rides_with_3_and_1;
    no_of_1s -= no_of_rides_with_3_and_1;
    no_of_2s = no_of_2s%2;

    no_of_rides += no_of_3s; //Pair up as many 3s with 1s and then the remaining 3s go alone.

    //Pair of 1s with the remaining 2s
    if(no_of_2s > 0)
    {
        no_of_1s -= 2;
        no_of_rides++;
    }

    if(no_of_1s > 0)
        no_of_rides += no_of_1s/4 + (no_of_1s%4 != 0);

    printf("%d\n", no_of_rides);

    return 0;
}
