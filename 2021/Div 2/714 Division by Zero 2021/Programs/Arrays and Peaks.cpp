#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, no_of_peaks;
    cin >> no_of_elements >> no_of_peaks;

    if(no_of_peaks > no_of_elements/2 - (no_of_elements%2 == 0))
    {
        cout << "-1\n";

        return;
    }

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        A[i] = i;
    }

    for(int i = 2, peaks = 0; peaks < no_of_peaks && i < no_of_elements; i += 2, peaks++)
    {
        swap(A[i], A[i + 1]);
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i] << " ";
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
