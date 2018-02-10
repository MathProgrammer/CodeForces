#include <cstdio>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int no_of_people;
    scanf("%d", &no_of_people);

    set <string> people;
    while(no_of_people--)
    {
        string current_possesser;
        cin >> current_possesser;

        printf(people.count(current_possesser) == 1 ? "YES\n" : "NO\n");
        people.insert(current_possesser);
    }

    return 0;
}
