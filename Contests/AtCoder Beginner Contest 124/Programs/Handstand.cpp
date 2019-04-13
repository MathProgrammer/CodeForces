#include <iostream>
#include <vector>
#include <string>

using namespace std;

void get_value(vector <int> &L, string &S, char given_ch)
{
    int current_segment = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == given_ch)
        {
            current_segment++;
        }
        else if(current_segment != 0 && S[i] != given_ch)
        {
            L.push_back(current_segment);
            current_segment = 0;
        }

        if(S[i] == given_ch && i + 1 == S.size())
        {
            L.push_back(current_segment);
        }
    }
}

int main()
{
    int length, max_flips;
    string S;
    cin >> length >> max_flips >> S;

    vector <int> zero_segments;
    get_value(zero_segments, S, '0');

    vector <int> one_segments;
    get_value(one_segments, S, '1');

    int max_length = 0, current_0_length = 0, current_1_length = 0,left_segment = 0;

    for(int i = 0; i < zero_segments.size() || i < one_segments.size(); i++)
    {
        if(i < zero_segments.size())
        {
            current_0_length += zero_segments[i];
        }

        if(i < one_segments.size())
        {
            current_1_length += one_segments[i];
        }

        if(i >= max_flips)
        {
            current_0_length -= zero_segments[left_segment];
            current_1_length -= one_segments[left_segment];

            left_segment++;
        }

        int extra = 0;

        if(S[0] == '0' && left_segment != 0)
        {
            extra = one_segments[left_segment - 1];
        }

        if(S[0] == '1' && i + 1 < one_segments.size())
        {
            extra = one_segments[i + 1];
        }

        int current_length = current_0_length + current_1_length + extra;

        max_length = max(max_length, current_length);
    }

    cout << max_length;
    return 0;
}
