#include <iostream>
#include <vector>

using namespace std;

long long power_mod(long long x, long long power, long long mod)
{
    long long result = 1;
    
    while(power > 0)
    {
        if(power%2 == 1)
            result = (result*x)%mod;
        
        x = (x*x)%mod;
        power = power/2;
    }
    
    return result;
}

int main()
{
    const int MAX_N = 1e6 + 5, MOD = 1e9 + 7;
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> multiple_count(MAX_N, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        multiple_count[A[i]]++;
    }
    
    for(int m = 1; m < MAX_N; m++)
    {
        for(int multiple = 2*m; multiple < MAX_N; multiple += m)
        {
            multiple_count[m] += multiple_count[multiple];
        }
    }
    
    vector <long long> answer(MAX_N, 0);
    for(int m = MAX_N - 1; m >= 1; m--)
    {
        answer[m] = multiple_count[m]*power_mod(2, multiple_count[m] - 1, MOD);
        
        answer[m] %= MOD; //cout << answer[m] << "\n";
        
        for(int multiple = 2*m; multiple < MAX_N; multiple += m)
        {
            answer[m] = (answer[m] - answer[multiple] + MOD)%MOD;
        }
        //cout << answer[m] << "\n";
        //cout << "Answer " << m << " = " << answer[m] << "\n";
    }
    
    long long total_answer = 0;
    for(int m = 2; m < MAX_N; m++)
    {
        total_answer = (total_answer + answer[m]*m)%MOD;
    }
    
    cout << total_answer << "\n";
    return 0;
}
