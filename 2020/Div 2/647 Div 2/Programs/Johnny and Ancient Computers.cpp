#include <iostream>

using namespace std;

long long ceil(long long n, long long d)
{
    return (n/d) + (n%d != 0);
}

void solve()
{
    long long a, b;
    cin >> a >> b;
    
    if(a > b)
    {
        swap(a, b);
    }
    
    int steps = 0;
    
    while(a < b)
    {
        a *= 2;
        steps++;
    }
    
    int actual_steps = (a == b ? ceil(steps, 3) : -1);
    
    cout << actual_steps << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
