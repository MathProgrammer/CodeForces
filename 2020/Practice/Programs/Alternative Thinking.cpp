#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;
    
    int alternating_subsequence = 0;
    for(int i = 0; i < length; i++)
    {
        if(i == 0 || S[i] != S[i - 1])
        {
            alternating_subsequence++;
        }
    }
    
    int answer = min(alternating_subsequence + 2, length);
    cout << answer << "\n";
    
    return 0;
}
