#include <cstdio>
#include <set>
#include <map>

#define MAX_LENGTH 1000000 + 2
using namespace std;

int main()
{
    int no_of_guests, no_of_guards;
    char guests[MAX_LENGTH];
    scanf("%d %d %s", &no_of_guests, &no_of_guards, guests);

    map <char, int> last_appearance;
    for(int i = 0; i < no_of_guests; i++)
        last_appearance[guests[i]] = i;

    set <char> entering_guests;
    bool unsafe_situation = false;
    for(int i = 0; i < no_of_guests; i++)
    {
        entering_guests.insert(guests[i]);
        if(entering_guests.size() > no_of_guards)
            unsafe_situation = true;

        if(last_appearance[guests[i]] == i)
            entering_guests.erase(guests[i]);
    }

    printf(unsafe_situation ? "YES\n" : "NO\n");
    return 0;
}
