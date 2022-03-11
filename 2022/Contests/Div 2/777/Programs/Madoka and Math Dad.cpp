#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int sum;
    cin >> sum;

    string answer;
    for(int i = 0, s = 0; i + 3 <= sum; i += 3, s += 3)
    {
        answer += "21";
    }

    switch(sum%3)
    {
        case 2 : answer += "2"; break;
        case 1 : if(sum == 1)
                {
                    answer = "1";
                }
                else
                {
                    answer = "1" + answer;
                }
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


 
