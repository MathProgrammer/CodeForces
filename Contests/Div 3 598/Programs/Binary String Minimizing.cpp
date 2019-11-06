#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    long long length, moves;
    cin >> length >> moves;

    string S;
    cin >> S;

    long long current_distance = 0;
    for(int i = 0; i < length && moves > 0; i++)
    {
        if(S[i] == '1')
        {
            current_distance++;
        }
        else
        {
            int steps_taken = min(current_distance, moves);

            swap(S[i], S[i - steps_taken]);

            moves -= steps_taken;
        }
    }

    cout << S << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

