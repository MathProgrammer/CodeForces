#include <stdio.h>

int main()
{
    int number_of_vertices;
    long long number_of_regions;
    scanf("%d",&number_of_vertices);

    //Each vertex had (n - 3) lines drawn from it. Since, there are no intersections, each line increases the number of regions by 1.
    number_of_regions = (number_of_vertices - 2)*1LL*(number_of_vertices - 2);
    printf("%I64d\n",number_of_regions);
    return 0;
}
