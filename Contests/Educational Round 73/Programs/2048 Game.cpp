#include <iostream>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    long long sum = 0;
    while(no_of_elements--)
    {
        int element;
        cin >> element;

        if(element <= 2048)
            sum += element;
    }

    cout << (sum >= 2048 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_tests;
    cin >> no_of_tests;

    while(no_of_tests--)
        solve();

    return 0;
}
