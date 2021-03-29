#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    vector <int> frequency(101, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        frequency[A[i]]++;
    }

    for(int i = 0; i <= 100; i++)
    {
        if(frequency[i] > 0)
        {
            cout << i << " ";

            frequency[i]--;
        }
    }


    for(int i = 0; i <= 100; i++)
    {
        while(frequency[i] > 0)
        {
            cout << i << " ";

            frequency[i]--;
        }
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
