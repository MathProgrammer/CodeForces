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

    vector <int> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
    }

    int segments = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] == B[i])
        {
            continue;
        }

        if(A[i] > B[i])
        {
            segments = 100;
            break;
        }

        if(B[i] - A[i] != B[i - 1] - A[i - 1])
        {
            segments++;
        }
    }

    cout << (segments > 1 ? "No\n" : "Yes\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
