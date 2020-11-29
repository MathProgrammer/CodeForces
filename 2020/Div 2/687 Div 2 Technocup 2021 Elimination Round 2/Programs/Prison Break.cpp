#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int rows, columns, i, j;
    cin >> rows >> columns >> i >> j;
    
    int row_answer = max(rows - i, i - 1);
    int column_answer = max(columns - j, j - 1);
    
    int answer = row_answer + column_answer;
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
