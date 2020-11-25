#include <iostream>

using namespace std;

char other(char c1, char c2)
{
    const int NO_OF_ALPHABETS = 26;
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        char current = 'a' + alpha;
        
        if(current != c1 && current != c2)
        {
            return current;
        }
    }
    
    return 'z';
}

int main()
{
    int length, differences;
    string S, T;
    cin >> length >> differences >> S >> T;
    
    int same = 0;
    for(int i = 0; i < length; i++)
    {
        if(S[i] == T[i])
        {
            same++;
        }
    }
    
    int matches = length - differences;
   
    int minimum_length = same + 2*max(matches - same, 0);
    
    if(minimum_length > length)
    {
        cout << "-1\n";
        
        return 0;
    }
    
    string answer = S;
    int a_matches = length, b_matches = same;
    for(int i = 0; i < length; i++)
    {
        if(S[i] != T[i])
        {
            if(b_matches < matches)
            {
                answer[i] = T[i];
            
                a_matches--;
                b_matches++;
            }
            else if(a_matches > matches)
            {
                answer[i] = other(S[i], T[i]);
                
                a_matches--;
            }
        }
    }
    
    for(int i = 0; i < length && (a_matches > matches || b_matches > matches); i++)
    {
        if(S[i] == T[i])
        {
            answer[i] = other(S[i], T[i]);
            
            a_matches--;
            b_matches--;
        }
    }
    
    cout << answer << "\n";
    return 0;
}
