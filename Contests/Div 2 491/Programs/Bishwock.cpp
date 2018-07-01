#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const int NO_OF_ROWS = 2;
    vector <string> S(NO_OF_ROWS);

    for(int i = 0; i < NO_OF_ROWS; i++)
        cin >> S[i];

    int no_of_columns = S[0].size();
    int free_spaces = 0, placed_pieces = 0;
    for(int i = 0; i < no_of_columns; i++)
    {
        int column_spaces = (S[0][i] == '0') + (S[1][i] == '0');

        free_spaces += column_spaces;

        if(free_spaces >= 3)
        {
            free_spaces -=3;
            placed_pieces++;
        }
        else
        {
            free_spaces = column_spaces;
        }

    }

    cout << placed_pieces;
    return 0;
}
