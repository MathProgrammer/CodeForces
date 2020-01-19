#include <iostream>
#include <string>

using namespace std;

int main()
{
    int no_of_digits, k;
    string S;
    cin >> no_of_digits >> k >> S;
    
    string answer = S;
    for(int i = k; i < no_of_digits; i++)
    {
        answer[i] = answer[i%k];
    }
    
    int is_lesser = false;
    for(int i = 0; i < no_of_digits; i++)
    {
        if(answer[i] > S[i])
        {
            break;
        }
        
        if(answer[i] < S[i])
        {
            is_lesser = true;
            break;
        }
    }
    
    if(!is_lesser)
    {
        cout << no_of_digits << "\n" << answer << "\n";
        return 0;
    }
    
    int change_point = -1;
    for(int i = k - 1; i >= 0; i--)
    {
        if(S[i] != '9')
        {
            change_point = i;
            answer[i] = answer[i] + 1;
            break;
        }
    }
    
    for(int i = change_point + 1; change_point != -1 && i < k; i++)
    {
        answer[i] = '0';
    }
    
    for(int i = k; i < no_of_digits; i++)
    {
        answer[i] = answer[i%k];
    }
    
    cout << no_of_digits << "\n" << answer << "\n";
    return 0;
}
