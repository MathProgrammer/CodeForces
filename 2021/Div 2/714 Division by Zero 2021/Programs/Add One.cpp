#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 2e5 + 5, MOD = 1e9 + 7;
int length[MAX_N];

void precompute()
{
    for(int i = 0; i <= 8; i++)
    {
        length[i] = 2;
    }

    length[9] = 3;

    for(int i = 10; i < MAX_N; i++)
    {
        length[i] = (length[i - 9] + length[i - 10])%MOD;
    }
}

void solve()
{
    int n, no_of_operations;
    cin >> n >> no_of_operations;

    long long answer = 0;
    while(n > 0)
    {
        int digit = n%10;

        long long this_length = (no_of_operations < 10 - digit ? 1 : length[no_of_operations - (10 - digit)]);

        //cout << "D = " << digit << " this = " << this_length << "\n";

        n /= 10;

        answer = (answer + this_length)%MOD;
    }

    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}


