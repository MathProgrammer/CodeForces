#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements;
    char symbol;
    cin >> no_of_elements >> symbol;

    string S;
    cin >> S;

    const char GREEN = 'g';
    int first_green = 0;
    for(int i = 0; i < no_of_elements; i++)
    {
        if(S[i] == GREEN)
        {
            first_green = i;
            break;
        }
    }

    const int NO_GREEN_TO_RIGHT = -1;
    vector <int> nearest_green(no_of_elements + 1, NO_GREEN_TO_RIGHT);
    for(int i = no_of_elements - 1; i >= 0; i--)
    {
        nearest_green[i] = (S[i] == GREEN ? i : nearest_green[i + 1]);

        if(nearest_green[i] == NO_GREEN_TO_RIGHT)
        {
            nearest_green[i] = first_green;
        }

        //cout << "nearest green " << i << " = " << nearest_green[i] << "\n";
    }

    int answer = 0;
    for(int i = 0; i < no_of_elements; i++)
    {
        if(S[i] == symbol)
        {
            int distance = (nearest_green[i] >= i ? nearest_green[i] - i : S.size() - i + first_green);

            answer = max(answer, distance);
        }
    }

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}


