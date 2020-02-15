#include <iostream>

using namespace std;

void solve()
{
    long long position_1, position_2, distance_1, distance_2;
    cin >> position_1 >> position_2 >> distance_1 >> distance_2;
    
    long long time = ((position_2 - position_1)%(distance_1 + distance_2) == 0 ? (position_2 - position_1)/(distance_1 + distance_2) : -1);
    cout << time << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
