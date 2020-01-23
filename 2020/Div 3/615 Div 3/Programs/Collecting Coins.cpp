#include <iostream>

using namespace std;

void solve()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    
    int total = (a + b + c) + n;
    cout << (total%3 == 0 && a <= total/3 && b <= total/3 && c <= total/3 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
