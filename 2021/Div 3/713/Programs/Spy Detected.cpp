#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector < pair<int, int> > A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i].first;

        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int index = (A[1].first == A[2].first ? A[no_of_elements].second : A[1].second);

    cout << index << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
