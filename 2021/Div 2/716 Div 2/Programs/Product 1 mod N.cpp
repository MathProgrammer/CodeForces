#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> subsequence;
    long long product = 1;
    for(int i = 1; i <= n - 2; i++)
    {
        if(__gcd(i, n) == 1)
        {
            product = (product*i)%n;

            subsequence.push_back(i);
        }
    }

    if(product == n - 1)
    {
        product = (product*(n - 1))%n;

        subsequence.push_back(n - 1);
    }

    cout << subsequence.size() << "\n";
    for(int i = 0; i < subsequence.size(); i++)
    {
        cout << subsequence[i] << " ";
    }
    cout << "\n";

    return 0;
}
