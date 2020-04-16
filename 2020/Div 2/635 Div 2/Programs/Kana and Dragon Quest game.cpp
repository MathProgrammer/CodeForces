#include <iostream>

using namespace std;

void solve()
{
    int total, type_1, type_2;
    cin >> total >> type_1 >> type_2;
    
    while(total/2 + total%2 > 10 && type_1 > 0)
    {
        total = total/2 + 10;
        type_1--;
    }
    
    total -= 10*type_2;
    
    cout << (total <= 0 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
