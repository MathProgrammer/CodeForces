#include <iostream>
#include <vector>
#include <algorithm>

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

    int sorted = true;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] != i)
        {
            sorted = false;
        }
    }

    int steps;

    if(sorted)
    {
        steps = 0;
    }
    else if(A[1] == 1 || A[no_of_elements] == no_of_elements)
    {
        steps = 1;
    }
    else if(A[no_of_elements] == 1 && A[1] == no_of_elements)
    {
        steps = 3;
    }
    else
    {
        steps = 2;
    }

    cout << steps << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
 
