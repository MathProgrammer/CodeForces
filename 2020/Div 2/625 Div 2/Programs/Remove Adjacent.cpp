#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;
    
    int removed = 0;
    for(int alpha = 'z'; alpha > 'a'; alpha--)
    {
        for(int attempts = 1; attempts <= length; attempts++)
        {
            for(int i = 0; i < length; i++)
            {
                if( (i + 1) < length && S[i] == alpha && S[i] == S[i + 1] + 1)
                {
                    S.erase(i, 1);
                    removed++;
                    
                    continue;
                }
                
                if( (i - 1) >= 0 && S[i] == alpha && S[i] == S[i - 1] + 1)
                {
                    S.erase(i, 1);
                    removed++;
                }
            }
        }
    }
    
    cout << removed << "\n";
    return 0;
}
