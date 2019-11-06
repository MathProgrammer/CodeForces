#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector <int> permutation(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> permutation[i];
    }

    int last_operated = 0;
    for(int no_of_operations = 0; no_of_operations <= n - 1 && last_operated < n - 1; )
    {
        int minimum = n + 1;
        int p = last_operated + 1;
        for(int i = last_operated + 1; i <= n; i++)
        {
            if(permutation[i] < minimum)
            {
                minimum = permutation[i];
                p = i;
            }
        }

        for(int i = p - 1; i > last_operated && no_of_operations <= n - 1; i--)
        {
            swap(permutation[i], permutation[i + 1]);
            no_of_operations++;
        }

        last_operated = max(last_operated + 1, p - 1);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << permutation[i] << " ";
    }

    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
