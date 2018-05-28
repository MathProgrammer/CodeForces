#include <iostream>

using namespace std;

int is_palindrome(string S)
{
    for(int i = 0; i < S.size(); i++)
        if(S[i] != S[S.size() - 1 - i])
            return false;

    return true;
}

int main()
{
    string S;
    cin >> S;

    for(int length = S.size(); length >= 1; length--)
    {
        for(int i = 0; i + length - 1 < S.size(); i++)
        {
            if(!is_palindrome(S.substr(i, length)))
            {
                cout << length;
                return 0;
            }
        }
    }

    cout << "0";
    return 0;
}
