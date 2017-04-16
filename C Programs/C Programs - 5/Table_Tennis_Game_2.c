#include <stdio.h>

long find_no_of_sets(unsigned long,unsigned long ,unsigned long);

int main()
{
    unsigned long no_of_points_in_a_set, misha_points, vanya_points;
    long no_of_sets;
    scanf("%lu %lu %lu",&no_of_points_in_a_set, &misha_points, &vanya_points);
    no_of_sets = find_no_of_sets(no_of_points_in_a_set, misha_points, vanya_points);
    printf("%ld\n",no_of_sets);
    return 0;
}

long find_no_of_sets(unsigned long no_of_points_in_a_set,unsigned long misha_points,unsigned long vanya_points)
{
    long no_of_sets, misha_sets, vanya_sets;

    //(a +b) might cause overflow. So doing (a%k + b%k) %k
    misha_sets = misha_points/no_of_points_in_a_set;
    vanya_sets = vanya_points/no_of_points_in_a_set;

    no_of_sets = (misha_sets + vanya_sets);

    if( (no_of_sets == 0) ||(misha_sets == 0 && vanya_points%no_of_points_in_a_set != 0) ||(vanya_sets == 0 && misha_points%no_of_points_in_a_set != 0) )
    {
        no_of_sets = -1;
    }

    return no_of_sets;
}
