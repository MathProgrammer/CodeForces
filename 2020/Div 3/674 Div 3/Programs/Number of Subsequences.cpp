#include <iostream>
#include <vector>

using namespace std;

long long sum_till(long long n)
{
    return (n*(n + 1))/2;
}

long long sum(long long L, long long R)
{
    return sum_till(R) - sum_till(L - 1);
}

int main()
{
    int length;
    string S;
    cin >> length >> S;
    
    vector <int> prefix_questions(S.size() + 1, 0);
    vector <int> prefix_a(S.size() + 1, 0);
    prefix_a[0] = (S[0] == 'a');
    prefix_questions[0] = (S[0] == '?');
    
    for(int i = 1; i < S.size(); i++)
    {
        prefix_a[i] = prefix_a[i - 1] + (S[i] == 'a');
        prefix_questions[i] = prefix_questions[i - 1] + (S[i] == '?');
    }
    
    vector <int> suffix_questions(S.size() + 1, 0);
    vector <int> suffix_c(S.size() + 1, 0);
    for(int i = S.size() - 1; i >= 0; i--)
    {
        suffix_c[i] = suffix_c[i + 1] + (S[i] == 'c');
        suffix_questions[i] = suffix_questions[i + 1] + (S[i] == '?');
    }
    
    const int MOD = 1e9 + 7;
    vector <long long> power_3(length + 1, 1);
    for(int i = 1; i <= length; i++)
    {
        power_3[i] = (3*power_3[i - 1])%MOD;
    }
    
    long long answer = 0;
    for(int i = 1; i < S.size() - 1; i++)
    {
        if(S[i] == 'b' || S[i] == '?')
        {
            long long a_s = prefix_a[i - 1], c_s = suffix_c[i + 1];
            long long before_questions = prefix_questions[i - 1], after_questions = suffix_questions[i + 1];
            
            long long prefix_value = (a_s*power_3[before_questions])%MOD + (before_questions > 0 ? (before_questions*power_3[before_questions - 1])%MOD : 0);
            prefix_value %= MOD;
            
            long long suffix_value = (c_s*power_3[after_questions])%MOD + (after_questions > 0 ? (after_questions*power_3[after_questions - 1] )%MOD : 0);
            suffix_value %= MOD;
        
            answer = (answer + prefix_value*suffix_value)%MOD;
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
