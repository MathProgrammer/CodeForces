#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
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

    sort(all(A));
    int best_1 = 1;
    for(int i = 2; i <= no_of_elements; i++)
    {
        if(A[i] - A[i - 1] < A[best_1 + 1] - A[best_1])
        {
            best_1 = i - 1;
        }
    }

    vector <int> answer(no_of_elements + 1);
    answer[1] = A[best_1];
    answer[no_of_elements] = A[best_1 + 1];

    int p = 2;
    for(int i = best_1 + 2; i <= no_of_elements; i++)
    {
        answer[p++] = A[i];
    }
    for(int i = 1; i < best_1; i++)
    {
        answer[p++] = A[i];
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << answer[i] << " ";
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



