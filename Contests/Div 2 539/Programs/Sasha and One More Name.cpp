#include <iostream>
#include <string>

using namespace std;

void increment(int &i, int n)
{
    i = (i + 1)%n;
}

void decrement(int &i, int n)
{
    i = (i - 1 + n)%n;
}

int is_palindrome(string &S, int left)
{
    int length = S.size();

    int right = (left - 1);

    for(int forward_i = left, backward_i = right; forward_i != right; increment(forward_i, length), decrement(backward_i, length))
    {
        if(S[forward_i] != S[backward_i])
            return false;
    }

    return true;
}

int is_equal(string &S, int start)
{
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] != S[(i + start)%S.size()])
        {
            return false;
        }
    }

    return true;
}

int is_cut_impossible(string &S)
{
    int same = 0, length = S.size();
    for(int i = 0; i < length; i++)
    {
        same += (S[i] == S[0]);
    }

    int not_possible = ( (length%2 == 0 && same == length ) || (length%2 == 1 && same >= length - 1) );

    return not_possible;
}

int main()
{
    string S;
    cin >> S;

    if(is_cut_impossible(S))
    {
        cout << "Impossible\n";
        return 0;
    }

    for(int start = 1; start < S.size(); start++)
    {
        if(!is_equal(S, start) && is_palindrome(S, start))
        {
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
    return 0;
}
