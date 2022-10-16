#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long answer_x = -1, answer_y = -1;
    for(long long x = a + 1; x <= c; x++)
    {
        long long complement = (a*b)/__gcd(a*b, x);
        //cout << "X = " << x << " Complement = " << complement << "\n";

        long long y = complement;

        for(int i = 1; y <= b; i++)
        {
            y = i*complement;
        }
        //cout << "Y = " << y << "\n";
        if(y <= d)
        {
            answer_x = x, answer_y = y;
            break;
        }
    }

    cout << answer_x << " " << answer_y << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
