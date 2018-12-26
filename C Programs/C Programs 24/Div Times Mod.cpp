#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    const int oo = 1e9;
    int answer = oo;

    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            int quotient = i, remainder = n/i;

            if(remainder < k)
                answer = min(answer, quotient*k + remainder);

            quotient = n/i, remainder = i;
            if(remainder < k)
                answer = min(answer, quotient*k + remainder);
        }
    }

    cout << answer;
    return 0;
}
