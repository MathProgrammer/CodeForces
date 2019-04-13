#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int change_to_0_first = 0;
    for(int i = 0; i < S.size(); i++)
    {
        change_to_0_first += (S[i] != '0' + i%2);
    }

    int change_to_1_first = 0;
    for(int i = 0; i < S.size(); i++)
    {
        change_to_1_first += (S[i] != '1' - i%2);
    }

    int minimum_changes = min(change_to_0_first, change_to_1_first);

    cout << minimum_changes;
    return 0;
}
