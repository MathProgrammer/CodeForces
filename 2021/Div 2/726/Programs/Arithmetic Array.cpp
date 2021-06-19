#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    int sum = 0;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    int answer = 0;

    if(sum > no_of_elements)
    {
        answer = sum - no_of_elements;
    }
    else if(sum < no_of_elements)
    {
        answer = 1;
    }
    else if(sum == no_of_elements)
    {
        answer = 0;
    }

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
