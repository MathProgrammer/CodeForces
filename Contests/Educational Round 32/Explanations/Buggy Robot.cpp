#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_instructions;
    string instructions;
    cin >> no_of_instructions >> instructions;

    int lefts = 0, rights = 0, ups = 0, downs = 0;

    for(int i = 0; i < no_of_instructions; i++)
    {
        lefts  += (instructions[i] == 'L');
        rights += (instructions[i] == 'R');
        downs  += (instructions[i] == 'D');
        ups    += (instructions[i] == 'U');
    }

    int max_correct_instructions = 2*min(lefts, rights) + 2*min(ups, downs);
    cout << max_correct_instructions;

    return 0;
}
