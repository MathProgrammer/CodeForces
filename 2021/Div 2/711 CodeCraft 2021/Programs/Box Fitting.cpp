#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements, W;
    cin >> no_of_elements >> W;

    multiset <int> M;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        M.insert(A[i]);
    }

    int no_of_levels = 0, base = W, remaining_base = W;
    while(M.size() > 0)
    {
        no_of_levels++;

        remaining_base = base;

        while(remaining_base > 0 && M.size() > 0)
        {
            auto it = M.lower_bound(remaining_base);

            if(it != M.begin())
            {
                it--;
            }

            int x = *it; //cout << "Remaining = " << remaining_base << " x = " << x << "\n";

            if(x > remaining_base)
            {
                break;
            }
            else
            {
                remaining_base -= x;

                M.erase(it);
            }
        }
    }

    cout << no_of_levels << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
