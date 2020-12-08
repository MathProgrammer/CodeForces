#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 5, MOD = 998244353;
vector <int> mu(MAX_N, 1);
vector <int> A(MAX_N);
map <int, long long> frequency;

long long square(long long n)
{
    return (n*n)%MOD;
}

long long power_mod(long long x, long long power)
{
    long long result = 1;
    
    while(power > 0)
    {
        if(power%2)
            result = (result*x)%MOD;
        
        x = (x*x)%MOD;
        power = power >> 1;
    }
    
    return result;
}

void precompute()
{
    vector <int> is_prime(MAX_N + 1, true);
    is_prime[1] = is_prime[0] =  false;
    mu[1] = 1;
    
    for(int i = 2; i < MAX_N; i++)
    {
        if(!is_prime[i])
        {
            continue;
        }
        
        for(int multiple = i; multiple < MAX_N; multiple += i)
        {
            mu[multiple] *= -1;
            
            is_prime[multiple] = false;
        }
        
        for(long long square = i*1LL*i; square < MAX_N; square += i*1LL*i)
        {
            mu[square] = 0;
        }
    }
}

long long count_with_gcd(int x)
{
    long long square_sum = 0, pairwise_sum = 0, sum = 0, total = 0;
    
    for(int i = x; i < MAX_N; i += x)
    {
        square_sum += ( square(i)*frequency[i] )%MOD;
        square_sum %= MOD;
        
        sum += (i*frequency[i])%MOD;
        sum %= MOD;
        
        total += frequency[i];
    }
    
    pairwise_sum = (sum*sum - square_sum + MOD)%MOD;
    
    
    long long answer = 0;
    
    if(total >= 2)
    {
        //cout << " Squares = " << square_sum << " Pairs = " << pairwise_sum << "\n";
        
        long long t_minus_1 = (total + MOD - 1)%MOD, t_minus_2 = (total + MOD - 2)%MOD;
        
        long long same_term = ((t_minus_1)*power_mod(2, total - 2))%MOD;
        same_term = (same_term*square_sum)%MOD;
        
        long long different_term = power_mod(2, total - 2);
        
        if(total >= 3)
        {
            different_term += (power_mod(2, total - 3)*t_minus_2)%MOD;
            
            different_term %= MOD;
        }
        //cout << "Multiplier = " << different_term << "\n";
        different_term = (different_term*pairwise_sum)%MOD;
        
        //cout << "Answer for x = " << x << " = " << same_term << " + " << different_term;
        answer = (same_term + different_term)%MOD; //cout << " = " << answer << "\n";
    }
    
    return answer;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    precompute();
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        cin >> frequency[A[i]];
    }
    
    long long answer = 0;
    for(int i = 1; i < MAX_N; i++)
    {
        answer += mu[i]*count_with_gcd(i);
        
        answer = (answer + MOD)%MOD;
    }
    
    cout << answer << "\n";
    
    return 0;
}
