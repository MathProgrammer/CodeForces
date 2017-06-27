#include <stdio.h>

#define min(a,b) (a < b ? a : b)

int main()
{
    int experienced_people_no, newbie_no, no_of_available_people;
    int no_of_teams;
    scanf("%d %d", &experienced_people_no, &newbie_no);

    no_of_teams = min(experienced_people_no, newbie_no);

    /*No of teams cannot exceed the min(E, N) ... We choose the highest configuration possible.
    To check if a configuration is possible, make I teams of (E, N, _) and then check if the third spot can be filled in all i teams.*/
    while(no_of_teams > 0)
    {
        no_of_available_people = (experienced_people_no + newbie_no) - 2*no_of_teams;

        if(no_of_available_people >= no_of_teams)
            break;

        no_of_teams--;
    }

    printf("%d\n", no_of_teams);
    return 0;
}

