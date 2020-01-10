#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long n, p;
    cin >> n >> p;

    int answer = 100;
    for(int i = 0; i < 32; i++)
    {
        if(__builtin_popcount(n - i*p) > i || (n - i*p) < i)
        {
            continue;
        }

        answer = i;

        break;
    }

    cout << (answer == 100 ? -1 : answer);
    return 0;
}
