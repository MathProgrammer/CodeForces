#include <iostream>
#include <vector>

using namespace std;

char opposite(char ch)
{
    return (ch == 'A' ? 'B' : 'A');
}

int main()
{
    int no_of_numbers;
    cin >> no_of_numbers;

    vector <int> A(no_of_numbers);
    for(int i = 0; i < no_of_numbers; i++)
        cin >> A[i];

    const int MAX = 105;
    vector <int> frequency(MAX, 0);
    for(int i = 0; i < no_of_numbers; i++)
        frequency[A[i]]++;

    int frequency_1_elements = 0, frequency_more_than_2_elements = 0;
    for(int i = 0; i < MAX; i++)
    {
        if(frequency[i] == 1) frequency_1_elements++;

        if(frequency[i] > 2) frequency_more_than_2_elements++;
    }

    if(frequency_1_elements%2 == 1 && frequency_more_than_2_elements == 0)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    string split;

    const int USED = 0, NOT_USED = 1;
    int special = (frequency_1_elements%2 == 0 ? USED : NOT_USED), special_char = -1;
    char last = 'B', special_place;

    for(int i = 0; i < no_of_numbers; i++)
    {
        if(frequency[A[i]] == 1)
        {
            split += opposite(last);
            last = opposite(last);
        }
        else if(frequency[A[i]] > 2 && special == NOT_USED)
        {
            split += opposite(last);
            special_place = opposite(last);
            last = opposite(last);

            special_char = A[i];
            special = USED;
        }
        else if(A[i] == special_char)
        {
            split += opposite(special_place);
        }
        else
        {
            split += 'A';
        }
    }

    cout << split;
    return 0;
}
