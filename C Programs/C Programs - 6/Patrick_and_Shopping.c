#include <stdio.h>
#define min(a,b) (a < b ? a : b)
int main()
{
    int distance_1, distance_2, distance_between_shops, minimum_distance;
    scanf("%d %d %d",&distance_1, &distance_2, &distance_between_shops);

    minimum_distance = min(distance_1 + distance_between_shops + distance_2, 2*(distance_1 + distance_2));
    minimum_distance = min(minimum_distance, 2*(distance_1 + distance_between_shops));
    minimum_distance = min(minimum_distance, 2*(distance_2 + distance_between_shops));
    printf("%d\n",minimum_distance);
    return 0;
}
