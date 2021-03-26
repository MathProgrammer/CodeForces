#include <iostream>

using namespace std;

void solve()
{
    long long rows, columns, x;
    cin >> rows >> columns >> x;

    long long column_no = (x/rows) + (x%rows != 0);
    long long row_no = x - rows*(column_no - 1);

    long long new_no = columns*(row_no - 1) + column_no;

    cout << new_no << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

