#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(),(v).end()

using namespace std;

int main()
{
    int number_of_people, number_of_attempts;
    scanf("%d %d", &number_of_people, &number_of_attempts);

    vector <int> attempts (number_of_people);
    for(int i = 0; i < number_of_people; i++)
        scanf("%d", &attempts[i]);

    sort(all(attempts));

    int no_of_teams = 0, i = 0;
    while(i + 2 < number_of_people && (attempts[i +2] + number_of_attempts) <= 5)
    {
        i += 3;
        no_of_teams++;
    }

    printf("%d\n",no_of_teams);
    return 0;
}
