#include <iostream>

using namespace std;

void solve()
{
    long long money, a, b, cost;
    cin >> money >> a >> b >> cost;

    long long paid_candies = (money/cost);
    long long free_candies = (paid_candies/a)*b;

    long long total_candies = paid_candies + free_candies;
    cout << total_candies << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
