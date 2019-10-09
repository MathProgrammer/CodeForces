#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    long long length;
    string S;
    cin >> length >> S;

    vector <int> segments;
    for(int i = 0; i < S.size(); i++)
    {
        if(i == 0 || S[i] != S[i - 1])
        {
            segments.push_back(1);
        }
        else
        {
            segments.back()++;
        }
    }

    long long bad_strings = 0;
    for(int i = 0; i + 1 < segments.size(); i++)
    {
        bad_strings += segments[i] + segments[i + 1] - 1;
    }

    long long total_strings = (length*(length - 1))/2;
    long long good_substrings = total_strings - bad_strings;

    cout << good_substrings;
    return 0;
}
