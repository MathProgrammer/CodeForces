#include <stdio.h>

unsigned long long find_minimum(unsigned long long,unsigned long long);
unsigned long long find_maximum(unsigned long long,unsigned long long);
int main()
{
    unsigned long long no_of_people, no_of_teams, minimum_friends, maximum_friends;
    scanf("%I64u %I64u",&no_of_people, &no_of_teams);

    minimum_friends = find_minimum(no_of_people, no_of_teams);
    maximum_friends = find_maximum(no_of_people, no_of_teams);
    printf("%I64u %I64u\n",minimum_friends, maximum_friends);
    return 0;
}

/*The minimum is obtained when every team has at most one more than the minimum number of people.
If there is a team for which the difference between the number of people and the minimum number of people is more than 1, we can reduce the friendships
by transfering a person from that team to the minimum team.
In this arrangement, the friendships can't be reduced. Transfering from two piles with the same amount of people increases the friendships,
And transfering from (p + 1) to p people conserver the number of friendships.
This can be obtained in the following way - Place n/m people in each team. Place the remaining n%m people in different teams.
n = 13, m = 5
.   .   .
.   .   .   .   .
.   .   .   .   .
The number is given by n/m * (n/m C 2) + (n%m)*(n/m)
We first count the number of friendships in all m teams when they have n/m people.
Then when the remaining n%m people are placed into their teams, new n/m friendships are formed in each team. */
unsigned long long find_minimum(unsigned long long no_of_people,unsigned long long no_of_teams)
{
    unsigned long long minimum;

    minimum = no_of_teams*(no_of_people/no_of_teams) * ((no_of_people/no_of_teams) - 1) /2; //n/m * (n/m C 2)
    minimum += (no_of_people%no_of_teams)*( (no_of_people/no_of_teams)); //n%m * (n/m)

    return minimum;
}

/*This is obtained when we place one person in m-1 teams each and place all the remaining people in the last team.
In any other arrangement, the number of friends can be increased by transfering a person from a given team to the team with the maximum number of people.
In this arrangement, no such transfer can take place. This yields the maximum number of friendships. Detailed proofs given in the 'Explanation' part.*/
unsigned long long find_maximum(unsigned long long no_of_people,unsigned long long no_of_teams)
{
    unsigned long long maximum;

    maximum = (no_of_people - no_of_teams + 1)*(no_of_people - no_of_teams + 1 - 1)/2;//(n - (m-1) ) C 2
    return maximum;
}
