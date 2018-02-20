#include <iostream>
#include <string>

using namespace std;

int main()
{
    int no_of_steps;
    string steps;
    cin >> no_of_steps >> steps;

    int x = 0, y = 0, no_of_changes = 0;

    for(int i = 0; i < no_of_steps - 1; i++)
    {
        if(steps[i] == 'U') y++;
        if(steps[i] == 'R') x++;

        no_of_changes += (x == y && steps[i] == steps[i + 1]);
    }

    cout << no_of_changes;
    return 0;
}
