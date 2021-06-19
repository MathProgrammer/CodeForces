#include <iostream>
#include <vector>

using namespace std;

int is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }

    return true;
}

int is_odd_power_of_2(int n)
{
    int exponent = 0;

    while(n%2 == 0)
    {
        n /= 2;
        exponent++;
    }

    return (n == 1 && exponent%2 == 1);
}

void solve()
{
    int n;
    cin >> n;

    if(is_prime(n) || n == 1 || is_odd_power_of_2(n))
    {
        cout << "Bob\n";
        return;
    }

    cout << (n%2 == 1 ? "Bob" : "Alice") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}


