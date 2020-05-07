#include <iostream>

using namespace std;

void solve()
{
    int rows, columns;
    cin >> rows >> columns;
    
    if(min(rows, columns) == 1)
    {
        cout << "YES\n";
        return;
    }
    
    cout << (max(rows, columns) <= 2 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
