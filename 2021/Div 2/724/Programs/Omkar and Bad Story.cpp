#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    int has_negative = false;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        if(A[i] < 0)
        {
            has_negative = true;
        }
    }

    if(has_negative)
    {
        cout << "NO\n";

        return ;
    }

    int length = 300;
    cout << "YES\n";
    cout << length << "\n";
    for(int i = 0; i < length; i++)
    {
        cout << i << " ";
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
