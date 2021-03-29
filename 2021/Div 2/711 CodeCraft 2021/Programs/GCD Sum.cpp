#include <iostream>
#include <algorithm>

using namespace std;

long long sum_of_digits(long long n)
{
    long long sum = 0;

    while(n)
    {
        sum += n%10;

        n /= 10;
    }

    return sum;
}

void solve()
{
    long long n;
    cin >> n;

    long long answer = n;
    while(__gcd(answer, sum_of_digits(answer)) == 1)
        answer++;

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
