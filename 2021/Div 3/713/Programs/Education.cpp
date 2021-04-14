#include <iostream>
#include <vector>

using namespace std;

long long ceil(long long n, long long d)
{
    if(d == 0 || n <= 0)
    {
        return 0;
    }

    return (n/d) + (n%d != 0);
}

void solve()
{
    int no_of_elements, computer_cost;
    cin >> no_of_elements >> computer_cost;

    vector <long long> A(no_of_elements + 1), B(no_of_elements);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    for(int i = 1; i <= no_of_elements - 1; i++)
    {
        cin >> B[i];
    }

    vector <long long> savings(no_of_elements + 1); //Savings on reaching day i
    vector <long long> minimum_days_to_reach(no_of_elements + 1); //Days to reach i. Earn on day f(i) + 1
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long days_here = ceil(B[i - 1] - savings[i - 1], A[i - 1]);

        savings[i] = days_here*A[i - 1] - (B[i - 1] - savings[i - 1]);

        minimum_days_to_reach[i] = minimum_days_to_reach[i - 1] + days_here + (i > 1);
    }

    long long no_of_days = 1e15;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long days_for_this_last_salary = ceil(computer_cost - savings[i], A[i]);

        no_of_days = min(no_of_days, days_for_this_last_salary + minimum_days_to_reach[i]);
    }

    cout << no_of_days << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
