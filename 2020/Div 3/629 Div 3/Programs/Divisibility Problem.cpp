#include <iostream>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    
    a %= b;
    
    int answer = (a == 0 ? 0 : b - a);
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
