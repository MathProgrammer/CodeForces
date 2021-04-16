#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> B(no_of_elements + 3);
    for(int i = 1; i <= no_of_elements + 2; i++)
    {
        cin >> B[i];
    }

    sort(B.begin(), B.end());

    vector <long long> sum_till(no_of_elements + 3, 0);
    for(int i = 1; i <= no_of_elements + 2; i++)
    {
        sum_till[i] = sum_till[i - 1] + B[i];
    }

    int found = false;
    int x = no_of_elements + 1;
    if(sum_till[no_of_elements] == B[no_of_elements + 1])
    {
        found = true;
    }

    for(int i = 1; i <= no_of_elements + 1; i++)
    {
        if(sum_till[no_of_elements + 1] - B[i] == B[no_of_elements + 2])
        {
            x = i;

            found = true;

            break;
        }
    }

    if(!found)
    {
        cout << "-1\n";

        return;
    }

    for(int i = 1; i <= no_of_elements + 1; i++)
    {
        if(i == x)
        {
            continue;
        }

        cout << B[i] << " ";
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

