#include <iostream>
#include <vector>

using namespace std;

string concatenate_prefix(string S, int prefix, int k)
{
    string answer;
    for(int i = 0; i < k; i++)
    {
        answer += S[i%prefix];
    }
    return answer;
}

int main()
{
    int length, k;
    cin >> length >> k;
    string S;
    cin >> S;

    string answer = concatenate_prefix(S, length, k);
    for(int i = 1; i <= S.size(); i++)
    {
        string current = concatenate_prefix(S, i, k);
        if(current < answer)
        {
            answer = current;
        }

    }

    cout << answer << "\n";

    return 0;
}
