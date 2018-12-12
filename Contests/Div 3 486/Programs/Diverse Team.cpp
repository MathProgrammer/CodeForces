#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_students, team_size;
    scanf("%d %d", &no_of_students, &team_size);

    const int MAX_RATING = 115;
    vector <int> team;
    vector <int> rating_used(MAX_RATING, false);

    for(int i = 1; i <= no_of_students; i++)
    {
        int rating_i;
        scanf("%d", &rating_i);

        if(!rating_used[rating_i])
            team.push_back(i);

        rating_used[rating_i] = true;
    }

    if(team.size() >= team_size)
    {
        printf("YES\n");
        for(int i = 0; i < team_size; i++)
            printf("%d ", team[i]);
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}

