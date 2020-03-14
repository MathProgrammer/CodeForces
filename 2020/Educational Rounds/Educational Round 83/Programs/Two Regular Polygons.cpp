#include <iostream>

using namespace std;

void solve()
{
    int original_vertices, new_vertices;
    cin >> original_vertices >> new_vertices;
    
    cout << (original_vertices%new_vertices == 0 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
