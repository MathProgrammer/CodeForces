#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length, max_alphabet;
    cin >> length >> max_alphabet;

    string S;
    cin >> S;

    if( (max_alphabet == 1 && length > 1) || (max_alphabet == 2 && length > 2) )
    {
        cout << "NO\n";
        return 0;
    }

    const int NOT_FOUND = -1;
    int first_greater_position = NOT_FOUND;
    char replacement;

    for(int i = length - 1; first_greater_position == NOT_FOUND && i >= 0; i--)
    {


        for(char new_ch = S[i] + 1; new_ch <= 'a' + max_alphabet - 1; new_ch++)
        {
            int possible = true;
            for(int j = i - 1; j >= max(i - 2, 0); j--)
            {
                if(new_ch == S[j])
                    possible = false;
            }

            if(possible)
            {
                first_greater_position = i;
                replacement = new_ch;
                break;
            }
        }
    }

    if(first_greater_position == NOT_FOUND)
    {
        cout << "NO\n";
        return 0;
    }

    string next_good_string;
    for(int i = 0 ; i < first_greater_position; i++)
        next_good_string += S[i];

    next_good_string += replacement;

    for(int i = first_greater_position + 1; i < length; i++)
    {
        char current_char;

        for(current_char = 'a'; current_char <= 'c'; current_char++)
        {
            if( (i - 1 >= 0 && next_good_string[i - 1] == current_char) ||
                (i - 2 >= 0 && next_good_string[i - 2] == current_char) )
            {
                continue;
            }
            else
            {
                next_good_string += current_char;
                break;
            }
        }
    }

    cout << next_good_string;
    return 0;
}
