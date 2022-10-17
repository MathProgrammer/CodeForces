#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

int power_2(int n)
{
    int power = 0;

    while(n%2 == 0 && n > 0)
    {
        power++;
        n /= 2;
    }

    return power;
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <int> index_power(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        index_power[i] = power_2(i);
    }

    sort(all(index_power));
    reverse(all(index_power));

    int total_power = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        total_power += power_2(A[i]);
    }

    int no_of_operations = 0;
    for(int i = 1; i <= no_of_elements && total_power < no_of_elements && index_power[i] > 0; i++)
    {
        total_power += index_power[i];
        no_of_operations++;
    }

    const int NOT_POSSIBLE = -1;
    cout << (total_power < no_of_elements ? NOT_POSSIBLE : no_of_operations) << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

