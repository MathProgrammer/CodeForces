#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int last_found = 'a' - 1;

    for(int i = 0; i < S.size() && last_found < 'z'; i++)
    {
        if(S[i] <= last_found + 1)
        {
            S[i] = last_found + 1;
            last_found = S[i];
        }
    }

    cout << (last_found == 'z' ? S : "-1");
    return 0;
}
