#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;
    
    int sum = 0;
    int answer = 0;
    for(int left = -1, right = 0; right < length; right++)
    {
        sum += (S[right] == '(' ? 1 : -1);
        
        if(sum == -1 && left == -1)
        {
            left = right;
            continue;
        }
        
        if(sum == 0)
        {
            if(left != -1)
            {
                answer += (right - (left - 1));
                
                left = -1;
                
                continue;
            }
        }
    }
    
    if(sum != 0)
    {
        answer = -1;
    }
    
    cout << answer << "\n";
    
    return 0;
}
