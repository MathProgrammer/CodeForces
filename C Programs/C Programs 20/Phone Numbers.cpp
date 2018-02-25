#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int length, answer_length;
    string A;
    cin >> length >> answer_length >> A;

    const int NO_OF_ALPHABETS = 26;
    vector <int> present(NO_OF_ALPHABETS, false);
    for(int i = 0; i < A.size(); i++) present[A[i] - 'a'] = true;

    char smallest_alphabet;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(present[i])
        {
            smallest_alphabet = 'a' + i;
            break;
        }
    }

    if(answer_length > length)
    {
        cout << A;
        for(int i = A.size(); i < answer_length; i++) cout << smallest_alphabet;

        return 0;
    }

    int first_change_point, greater_char_available = false;
    char char_at_first_change_point;

    for(int i = answer_length - 1; i >= 0 && !greater_char_available; i--)
    {
        for(char alphabet = A[i] + 1; alphabet <= 'z'; alphabet++)
        {
            if(present[alphabet - 'a'])
            {
                greater_char_available = true;

                first_change_point = i;
                char_at_first_change_point = alphabet;

                break;
            }
        }
    }

    for(int i = 0; i < first_change_point; i++) cout << A[i];
    cout << char_at_first_change_point;
    for(int i = first_change_point + 1; i < answer_length; i++) cout << smallest_alphabet;

    return 0;
}
