#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n <= 2)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes\n";

        if(n%2 == 0)
        {
            cout << "2"; cout << " 1 " << n;

            cout << "\n";

            cout << n - 2 << " " ; for(int i = 2; i < n; i++) cout << i << " "; // This is (n + 1)(n - 2)/2.  n is even. So it is divisible by n + 1
        }
        else if(n%2 == 1)
        {
            cout << "1 " << n;

            cout << "\n";

            cout << n - 1 << " "; for(int i = 1; i < n; i++) cout << i << " "; // This is n(n - 1)/2. n - 1 is even. So divisible by n.
        }
    }

    return 0;
}

