#include <iostream>
#include <vector>
#include <algorithm>

#define min(a, b) (a < b ? a : b)
#define all(v) (v).begin(), (v).end()
using namespace std;

const int NO_OF_ALPHABETS = 26;
vector <long long> cost[NO_OF_ALPHABETS];

int main()
{
    int length, max_elements;
    cin >> length >> max_elements;

    vector <int> A(length);
    for(int i = 0; i < length; i++)
        cin >> A[i];

    string S;
    cin >> S;

    long long total = 0;
    vector <int> last_pressed_costs;
    char last_pressed = '#';

    for(int i = 0; i <= length; i++)
    {
        if(i == length ||S[i] != last_pressed)
        {
            sort(all(last_pressed_costs));

            reverse(all(last_pressed_costs));

            for(int j = 0; j < min(max_elements, last_pressed_costs.size()); j++)
            {
                total += last_pressed_costs[j];
            }

            last_pressed_costs.clear();
        }

        if(i == length) continue;

        last_pressed = S[i];
        last_pressed_costs.push_back(A[i]);

    }

    cout << total;
    return 0;
}
