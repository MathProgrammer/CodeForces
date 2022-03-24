#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    int minimum = 1, maximum = 1;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] >= A[maximum])
        {
            maximum = i;
        }
        else if(A[i] < A[minimum])
        {
            minimum = i;
        }
    }

    cout << minimum << " " << maximum << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
