#include <iostream>
#include <string>

using namespace std;

int is_palindrome(string S, int left, int right)
{
    while(left <= right)
    {
        if(S[left++] != S[right--])
            return false;
    }

    return true;
}

int main()
{
    string S;
    cin >> S;
    int length = S.size();

    if(!is_palindrome(S, 0, length - 1))
        cout << length;
    else if(!is_palindrome(S, 0, length - 2) || !is_palindrome(S, 1, length - 1))
        cout << length - 1;
    else
        cout << "0";

    return 0;
}
