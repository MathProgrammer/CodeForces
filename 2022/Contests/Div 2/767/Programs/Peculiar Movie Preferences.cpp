#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int is_palindrome(string &S)
{
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] != S[S.size() - 1 - i])
        {
            return false;
        }
    }

    return true;
}

int check_self(vector <string> &S, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(is_palindrome(S[i]))
        {
            return true;
        }
    }

    return false;
}

int check_full_concatenation(vector <string> &S, int n)
{
    map <string, int> is_present;
    for(int i = 1; i <= n; i++)
    {
        string reverse_s = S[i];
        reverse(all(reverse_s));

        if(is_present[reverse_s])
        {
            return true;
        }

        is_present[S[i]] = true;
    }

    return false;
}

int check_length_3(vector <string> &S, int n)
{
    map <string, int> is_present;
    for(int i = 1; i <= n; i++)
    {
        if(S[i].size() == 3)
        {
            continue;
        }

        if(S[i].size() == 1)
        {
            is_present[S[i]] = true;
            continue;
        }

        string last;
        last += S[i][1];
        if(is_present[last])
        {
            return true;
        }
    }

    is_present.clear();

    for(int i = n; i >= 1; i--)
    {
         if(S[i].size() == 3)
        {
            continue;
        }

        if(S[i].size() == 1)
        {
            is_present[S[i]] = true;
            continue;
        }

        string last;
        last += S[i][0];
        if(is_present[last])
        {
            return true;
        }
    }

    return false;
}

int check_length_4(vector <string> &S, int n)
{
    map <string, int> is_present;
    for(int i = 1; i <= n; i++)
    {
        if(S[i].size() == 2)
        {
            continue;
        }

        if(S[i].size() == 1)
        {
            is_present[S[i]] = true;
            continue;
        }

        if(S[i][0] == S[i][1])
        {
            string last;
            last += S[i][2];
            if(is_present[last])
            {
                return true;
            }
        }
    }

    is_present.clear();

    for(int i = n; i >= 1; i--)
    {
        if(S[i].size() == 2)
        {
            continue;
        }

        if(S[i].size() == 1)
        {
            is_present[S[i]] = true;
            continue;
        }

        if(S[i][1] == S[i][2])
        {
            string last;
            last += S[i][0];
            if(is_present[last])
            {
                return true;
            }
        }
    }

    return false;
}

int check_length_5(vector <string> &S, int n)
{
    map <string, int> is_present;
    for(int i = 1; i <= n; i++)
    {
        if(S[i].size() == 1)
        {
            continue;
        }

        if(S[i].size() == 2)
        {
            is_present[S[i]] = true;
            continue;
        }

        string last;
        last += S[i][2];
        last += S[i][1];
        if(is_present[last])
        {
            return true;
        }

    }

    is_present.clear();

    for(int i = n; i >= 1; i--)
    {
        if(S[i].size() == 1)
        {
            continue;
        }

        if(S[i].size() == 2)
        {
            is_present[S[i]] = true;
            continue;
        }

        string last;
        last += S[i][1];
        last += S[i][0];
        if(is_present[last])
        {
            return true;
        }
    }

    return false;
}



void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <string> S(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> S[i];
    }

    int has_awesome_sequence =   check_self(S, no_of_elements)
                              || check_full_concatenation(S, no_of_elements)
                              || check_length_3(S, no_of_elements)
                              || check_length_4(S, no_of_elements)
                              || check_length_5(S, no_of_elements);


    cout << (has_awesome_sequence ? "YES" : "NO") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

