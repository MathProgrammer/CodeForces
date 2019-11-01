#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;

    int no_of_rooms = length;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '1')
        {
            no_of_rooms = max(no_of_rooms, 2*max(i + 1, length - i));
        }
    }

    cout << no_of_rooms << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
