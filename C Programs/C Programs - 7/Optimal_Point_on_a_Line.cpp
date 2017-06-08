#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_POINTS 300000 + 1
int points[MAX_POINTS];

int main()
{
    int no_of_points, median, i;
    scanf("%d",&no_of_points);

    for(i = 0; i < no_of_points; i++)
        scanf("%d", &points[i]);

    sort(points, points + no_of_points);
    median = points[(no_of_points - 1)/2];

    printf("%d\n",median);
    return 0;
}

