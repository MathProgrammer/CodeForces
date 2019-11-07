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

    int max_length = 0;
    for(int l = 1; l <= no_of_elements; l++)
    {
        int planks = 0;
        for(int i = 1; i <= no_of_elements; i++)
        {
            planks += (A[i] >= l);
        }

        if(planks >= l)
            max_length = max(max_length, l);
    }

    cout << max_length << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
