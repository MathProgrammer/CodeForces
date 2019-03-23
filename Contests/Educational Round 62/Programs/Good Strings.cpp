#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;

    int answer;
    for(int i = 0; i < length; i++)
    {
        if(S[i] == '>')
        {
            answer = i;
            break;
        }
    }

    for(int i = length - 1; i >= 0; i--)
    {
        if(S[i] == '<')
        {
            answer = min(answer, length - 1 - i);
            break;
        }
    }

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
