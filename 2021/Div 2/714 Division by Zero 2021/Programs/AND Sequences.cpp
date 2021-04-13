#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long factorial(long long n, long long mod)
{
    long long answer = 1;
    for(int i = 1; i <= n; i++)
    {
        answer = (answer*i)%mod;
    }

    return answer;
}

long long choose_2(long long n, long long mod)
{
    long long answer = n*(n - 1);

    return (answer%mod);
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    long long array_and = (1LL << 60) - 1;
    map <int, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        array_and &= A[i];

        frequency[A[i]]++;
    }

    const int MOD = 1e9 + 7;
    long long answer = choose_2(frequency[array_and], MOD)*factorial(no_of_elements - 2, MOD);

    answer %= MOD;

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

