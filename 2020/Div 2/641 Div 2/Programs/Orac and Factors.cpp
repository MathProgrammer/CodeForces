#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 5;
vector <int> smallest_multiple(MAX_N, 0);

void precompute()
{
    for(int i = 2; i < MAX_N; i++)
    {
        for(long long multiple = i; multiple < MAX_N; multiple += i)
        {
            if(smallest_multiple[multiple] == 0)
            {
                smallest_multiple[multiple] = i;
            }
        }
    }
}

void solve()
{
    long long n, k;
    cin >> n >> k;
    
    n += smallest_multiple[n];
    k--;
    
    n += k*2;
    
    cout << n << "\n";
}

int main()
{
    precompute();
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
