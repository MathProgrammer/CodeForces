#include <iostream>

using namespace std;

void solve()
{
    int no_of_grains, a, b, c, d;
    cin >> no_of_grains >> a >> b >> c >> d;
    
    int minimum_weight = no_of_grains*(a - b);
    int maximum_weight = no_of_grains*(a + b);
    
    int minimum_capacity = (c - d);
    int maximum_capacity = (c + d);
    
    cout << (minimum_weight > maximum_capacity || maximum_weight < minimum_capacity ? "No\n" : "Yes\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
