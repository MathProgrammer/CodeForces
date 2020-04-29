#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long x, long long y)
{
    if(min(x, y) == 0)
    {
        return max(x, y);
    }
    
    return gcd(max(x, y)%min(x, y), min(x, y));
}

long long get_count(vector <long long> &sum, long long lcm, long long N)
{
    long long full_cycles = N/lcm;
    
    return full_cycles*sum[lcm] + sum[N%lcm];
}

void solve()
{
    int a, b, no_of_queries;
    cin >> a >> b >> no_of_queries;
    
    if(a > b)
    {
        swap(a, b);
    }
    
    long long lcm = (a*b)/gcd(a, b);
    vector <long long> good_integers_sum(lcm + 1, 0);
    for(int i = 1; i <= lcm; i++)
    {
        good_integers_sum[i] = good_integers_sum[i - 1] + ( (i%a)%b != (i%b)%a );
    }
    
    while(no_of_queries--)
    {
        long long left, right;
        cin >> left >> right;
        
        long long answer = get_count(good_integers_sum, lcm, right) - get_count(good_integers_sum, lcm, left - 1);
        
        cout << answer << " ";
    }
    
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
