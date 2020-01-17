#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, mod;
    cin >> n >> mod;
    
    vector <long long> factorial(n + 1);
    factorial[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        factorial[i] = (factorial[i - 1]*i)%mod;
    }
    
    long long sum = 0;
    
    for(int length = 1; length <= n; length++)
    {
        long long no_of_segments = n - length + 1;
        
        long long ways_for_one_segment = (factorial[n - length + 1]*factorial[length])%mod;
        
        sum += (no_of_segments*ways_for_one_segment)%mod;
    }
    
    cout << sum%mod << "\n";
    return 0;
}
