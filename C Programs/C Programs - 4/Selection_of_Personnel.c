#include <stdio.h>

int main()
{
    unsigned long long no_of_applications, no_of_teams, no_of_applications_choose_5, no_of_applications_choose_6, no_of_applications_choose_7;
    scanf("%I64u",&no_of_applications);

    no_of_applications_choose_5 = (no_of_applications)*(no_of_applications-1)/2*(no_of_applications-2)/3*(no_of_applications-3)/4*(no_of_applications-4)/5;

    //nC6 = nC5 *(n - 5)/6 and nC7 = nC6* (n - 5)/6
    no_of_applications_choose_6 =  no_of_applications_choose_5*(no_of_applications - 5)/6;
    no_of_applications_choose_7 =  no_of_applications_choose_6*(no_of_applications - 6)/7;
    no_of_teams = no_of_applications_choose_5 + no_of_applications_choose_6 + no_of_applications_choose_7;

    printf("%I64u\n",no_of_teams);
    return 0;
}
