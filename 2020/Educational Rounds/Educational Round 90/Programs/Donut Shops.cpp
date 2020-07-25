#include <iostream>

using namespace std;

void solve()
{
    long long cost, box_size, box_cost;
    cin >> cost >> box_size >> box_cost;
    
    int answer_1 = (cost < box_cost ? 1 : -1);
    int answer_2 = (cost*box_size > box_cost ? box_size : -1);
    
    cout << answer_1 << " " << answer_2 << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
