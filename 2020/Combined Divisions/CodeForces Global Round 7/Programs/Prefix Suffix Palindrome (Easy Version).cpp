#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 5005;
int max_palindrome_in[MAX_N][MAX_N];

pair <int, int> get_prefix_suffix(string S)
{
    for(int length = 1; length <= S.size(); length++)
    {
        for(int left = 0, right = left + length - 1; right < S.size(); left++, right++)
        {
            max_palindrome_in[left][right] = 0;
            
            if(length == 1)
            {
                max_palindrome_in[left][right] = 1;
                continue;
            }
            
            if(length == 2)
            {
                max_palindrome_in[left][right] = (S[left] == S[right] ? 2 : 0);
                continue;
            }
            
            if(S[left] == S[right] && max_palindrome_in[left + 1][right - 1] != 0)
            {
                max_palindrome_in[left][right] = 2 + max_palindrome_in[left + 1][right - 1];
            }
        }
    }
    
    int best_prefix = 0;
    for(int i = 0; i < S.size(); i++)
    {
        best_prefix = max(best_prefix, max_palindrome_in[0][i]);
    }
    
    int best_suffix = 0;
    for(int i = S.size() - 1; i >= 0; i--)
    {
        best_suffix = max(best_suffix, max_palindrome_in[i][S.size() - 1]);
    }
    
    return make_pair(best_prefix, best_suffix);
}

void solve()
{
    string S;
    cin >> S;
    
    int matching_part = 0, prefix_palindrome = 0, suffix_palindrome = 0;
    for(int i = 0, j = S.size() - 1; i < j; i++, j--)
    {
        if(S[i] == S[j])
        {
            matching_part++;
        }
        else
        {
            break;
        }
    }
    
    string remaining_S;
    for(int i = matching_part; i < S.size() - matching_part; i++)
    {
        remaining_S += S[i];
    }
    //cout << "Remaining = " << remaining_S << "\n";
    pair <int, int> prefix_suffix = get_prefix_suffix(remaining_S);
    prefix_palindrome = prefix_suffix.first;
    suffix_palindrome = prefix_suffix.second;
    
    if(prefix_palindrome > suffix_palindrome)
    {
        suffix_palindrome = 0;
    }
    else
    {
        prefix_palindrome = 0;
    }
    
    string answer;
    for(int i = 0; i < matching_part; i++)
    {
        answer += S[i];
    }
    
    for(int i = 0; i < prefix_palindrome; i++)
    {
        answer += remaining_S[i];
    }
    
    for(int i = remaining_S.size() - suffix_palindrome; i < remaining_S.size(); i++)
    {
        answer += remaining_S[i];
    }
    
    for(int i = S.size() - matching_part; i < S.size(); i++)
    {
        answer += S[i];
    }
   
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
