#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    long long sum = 0, minimum = 1e12, maximum = 0;
    multiset <long long> S, original_S;
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        original_S.insert(A[i]);

        sum += A[i];
        minimum = min(minimum, A[i]);
        maximum = max(maximum, A[i]);
    }

    S.insert(sum);

    int possible = true;
    while(S.size() > 0 && *(S.begin()) >= minimum && *(S.rbegin()) >= *(original_S.rbegin()))
    {
        auto it1 = (S.rbegin());
        long long x = *it1;

        if(original_S.count(x) > 0)
        {
            original_S.erase(original_S.find(x));
            S.erase(S.find(x));

            continue;
        }

        S.erase(S.find(x));
        long long new_x = x/2, new_y = x/2 + (x%2 != 0);


        S.insert(new_x);
        S.insert(new_y);
    }

    possible = (S.size() == 0);

    cout << (possible ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

