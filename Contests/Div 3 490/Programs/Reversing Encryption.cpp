#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void get_divisors(vector <int> &divisors, int n)
{
    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            divisors.push_back(i);

            if(i*i != n)
                divisors.push_back(n/i);
        }
    }
}

int main()
{
    int length;
    string S;
    cin >> length >> S;

    vector <int> divisors;
    get_divisors(divisors, length);
    sort(divisors.begin(), divisors.end());

    for(int i = 0; i < divisors.size(); i++)
    {
        reverse(S.begin(), S.begin() + divisors[i]);
    }

    cout << S;
    return 0;
}
