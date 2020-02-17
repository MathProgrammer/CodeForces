#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

#define all(v) (v).begin(), (v).end()
using namespace std;

int is_palindrome(string S)
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

int main()
{
    int no_of_strings, length;
    cin >> no_of_strings >> length;
    
    vector <string> S(no_of_strings + 1);
    for(int i = 1; i <= no_of_strings; i++)
    {
        cin >> S[i];
    }
    
    vector <int> strings_index;
    vector <int> reverse_strings_index;
    for(int i = 1; i <= no_of_strings; i++)
    {
        for(int j = i + 1; j <= no_of_strings; j++)
        {
            if(is_palindrome(S[i] + S[j]))
            {
                strings_index.push_back(i);
                reverse_strings_index.push_back(j);
            }
        }
    }
    
    string middle;
    for(int i = 1; i <= no_of_strings; i++)
    {
        if(is_palindrome(S[i]))
        {
            middle = S[i];
        }
    }
    
    int final_length = strings_index.size() + (middle.size() != 0) + reverse_strings_index.size();
    
    final_length *= length;
    
    cout << final_length << "\n";
    
    for(int i = 0; i < strings_index.size(); i++)
    {
        cout << S[strings_index[i]];
    }
    
    if(middle.size() != 0)
    {
        cout << middle;
    }
    
    for(int i = reverse_strings_index.size() - 1; i >= 0; i--)
    {
        cout << S[reverse_strings_index[i]];
    }
    
    cout << "\n";
    return 0;
}
