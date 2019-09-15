#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int is_non_decreasing(string S)
{
    for(int i = 0; i + 1 < S.size(); i++)
    {
        if(S[i] > S[i + 1])
            return false;
    }

    return true;
}

int possible_to_split(string S, int n)
{
    string new_string_lesser_than_n, new_string_greater_than_n;

    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] - '0' < n)
        {
            new_string_lesser_than_n += S[i];
        }
        else if(S[i] - '0' > n)
        {
            new_string_greater_than_n += S[i];
        }
    }

    return (is_non_decreasing(new_string_greater_than_n) && is_non_decreasing(new_string_lesser_than_n));
}

void solve()
{
    int length;
    string S;
    cin >> length >> S;

    int possible_endings_1 = 0;
    for(possible_endings_1 = 0; possible_endings_1 < 10; possible_endings_1++)
    {
        if(!possible_to_split(S, possible_endings_1))
        {
            continue;
        }

        int first_sequence_ending = 0;
        for(int i = 0; i < length; i++)
        {
            if(S[i] - '0' < possible_endings_1)
            {
                first_sequence_ending = i;
            }
        }

        int second_sequence_beginning = length - 1;
        for(int i = length - 1; i >= 0; i--)
        {
            if(S[i] - '0' > possible_endings_1)
            {
                second_sequence_beginning = i;
            }
        }

        int colouring_possible = true;
        for(int i = second_sequence_beginning; i < first_sequence_ending; i++)
        {
            if(S[i] - '0' == possible_endings_1)
            {
                colouring_possible = false;
            }
        }

        if(!colouring_possible)
            continue;

        string colouring;
        for(int i = 0; i < length; i++)
        {
            if( (S[i] - '0' < possible_endings_1) || (S[i] - '0' == possible_endings_1 && i >= first_sequence_ending) )
            {
                colouring += '1';
            }
            else if( (S[i] - '0' > possible_endings_1) || (S[i] - '0' == possible_endings_1 && i <= second_sequence_beginning))
            {
                colouring += '2';
            }
        }

        cout << colouring << "\n";

        return;
    }

    if(possible_endings_1 == 10)
    {
        cout << "-\n";

        return;
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

