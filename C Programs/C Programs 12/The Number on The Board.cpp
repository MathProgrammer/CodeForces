#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
#define MAX_LENGTH 100000 + 2
using namespace std;

int main()
{
    int digit_sum;
    char number_on_board[MAX_LENGTH];
    scanf("%d %s", &digit_sum, number_on_board);

    vector <int> board_number;
    int board_digit_sum = 0;
    for(int i = 0; number_on_board[i] != '\0'; i++)
    {
        board_digit_sum += number_on_board[i] - '0';
        board_number.push_back(number_on_board[i] - '0');
    }

    sort(all(board_number));

    int min_no_of_digit_changes = 0;
    for(unsigned int i = 0; i < board_number.size() && board_digit_sum < digit_sum; i++)
    {
        if(board_number[i] != 9)
        {
            board_digit_sum += 9 - board_number[i];
            min_no_of_digit_changes++;
        }
    }

    printf("%d\n", min_no_of_digit_changes);
    return 0;
}
