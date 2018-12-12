#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int sort_by_length(const string &A, const string &B)
{
    return (A.size() < B.size());
}

int substring_of(string S, string sub_S)
{
    for(int i = 0; i + sub_S.size() - 1 < S.size(); i++)
    {
        int substring = true;

        for(int j = 0; j < sub_S.size(); j++)
        {
            if(S[i + j] != sub_S[j])
            {
                substring = false;
            }
        }

        if(substring)
            return true;
    }

    return false;
}

int main()
{
    int no_of_strings;
    cin >> no_of_strings;

    vector <string> S(no_of_strings);
    for(int i = 0; i < no_of_strings; i++)
        cin >> S[i];

    sort(all(S), sort_by_length);

    for(int i = 1; i < no_of_strings; i++)
    {
        if(!substring_of(S[i], S[i - 1]))
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < no_of_strings; i++)
        cout << S[i] << "\n";

    return 0;
}

