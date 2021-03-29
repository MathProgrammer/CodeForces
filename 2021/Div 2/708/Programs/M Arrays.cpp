#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, m;
    cin >> no_of_elements >> m;

    vector <int> A(no_of_elements + 1);
    vector <int> frequency(m + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        frequency[A[i]%m]++;
    }

    int arrays = (frequency[0] > 0 ? 1 : 0);
    for(int i = 1, j = m - 1; i <= j; i++, j--)
    {
        if(frequency[i] == 0 && frequency[j] == 0)
        {
            continue;
        }

        if(i == j || abs(frequency[i] - frequency[j]) <= 1)
        {
            arrays++;
        }
        else
        {
            arrays += abs(frequency[i] - frequency[j]);
        }
    }

    cout << arrays << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
