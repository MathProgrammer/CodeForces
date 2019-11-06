#include <iostream>

using namespace std;

void solve()
{
    long long no_of_n, no_of_1, n, target;
    cin >> no_of_n >> no_of_1 >> n >> target;

    //Nx + y = B

    long long nearest = min((target/n)*n, no_of_n*n);

    cout << ((target - nearest <= no_of_1) ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
