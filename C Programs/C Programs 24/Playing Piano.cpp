#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int NO_OF_FINGERS = 5, MAX_NOTES = 2e5 + 5;
int is_possible[MAX_NOTES][NO_OF_FINGERS];

int main()
{
    int no_of_notes;
    cin >> no_of_notes;

    vector <int> notes(no_of_notes + 1);
    for(int i = 1; i <= no_of_notes; i++)
        cin >> notes[i];

    memset(is_possible, false, sizeof(is_possible));

    for(int i = 1; i <= no_of_notes; i++)
    {
        for(int finger = 1; finger <= NO_OF_FINGERS; finger++)
        {
            if(i == 1)
            {
                is_possible[i][finger] = true;
                continue;
            }

            if(notes[i - 1] <= notes[i])
            {
                for(int previous_finger = 1; previous_finger < finger; previous_finger++)
                {
                    if(is_possible[i - 1][previous_finger])
                    {
                        is_possible[i][finger] = true;
                    }
                }
            }

            if(notes[i - 1] >= notes[i])
            {
                for(int previous_finger = NO_OF_FINGERS; previous_finger > finger; previous_finger--)
                {
                    if(is_possible[i - 1][previous_finger])
                    {
                        is_possible[i][finger] = true;
                    }
                }
            }
        }
    }

    int fingering_possible = false;
    for(int finger = 1; finger <= NO_OF_FINGERS; finger++)
    {
        if(is_possible[no_of_notes][finger])
            fingering_possible = true;
    }

    if(!fingering_possible)
    {
        cout << "-1\n";
        return 0;
    }

    vector <int> playing_finger(no_of_notes + 1);
    for(int i = no_of_notes; i >= 1; i--)
    {
        if(i == no_of_notes)
        {
            for(int finger = 1; finger <= NO_OF_FINGERS; finger++)
            {
                if(is_possible[i][finger])
                {
                    playing_finger[i] = finger;
                    break;
                }
            }

            continue;
        }

        if(notes[i] < notes[i + 1])
        {
            for(int finger = playing_finger[i + 1] - 1; finger >= 1; finger--)
            {
                if(is_possible[i][finger])
                {
                    playing_finger[i] = finger;
                    break;
                }
            }
        }

        if(notes[i] > notes[i + 1])
        {
            for(int finger = playing_finger[i + 1] + 1; finger <= NO_OF_FINGERS; finger++)
            {
                if(is_possible[i][finger])
                {
                    playing_finger[i] = finger;
                    break;
                }
            }
        }

        if(notes[i] == notes[i + 1])
        {
            for(int finger = 1; finger <= NO_OF_FINGERS; finger++)
            {
                if(is_possible[i][finger] && finger != playing_finger[i + 1])
                {
                    playing_finger[i] = finger;
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= no_of_notes; i++)
        cout << playing_finger[i] << " ";

    return 0;
}
