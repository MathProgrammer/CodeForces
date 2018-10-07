#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 1e5 + 5, MAX_WEIGHT = 10;
int answer[MAX_N];
int available[MAX_WEIGHT + 1];

int possible(int difference, int current_weigh_no, int no_of_weighs)
{
    if(current_weigh_no > no_of_weighs)
    {
        return true;
    }

    int previous_weight = answer[current_weigh_no - 1];

    for(int next_weight = difference + 1; next_weight <= MAX_WEIGHT; next_weight++)
    {
        if(available[next_weight] && next_weight != previous_weight)
        {
            answer[current_weigh_no] = next_weight;

            if(possible(next_weight - difference, current_weigh_no + 1, no_of_weighs))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int no_of_weighs;
    string weights;
    cin >> weights >> no_of_weighs;

    for(int i = 1; i <= MAX_WEIGHT; i++)
        available[i] = (weights[i - 1] == '1');

    if(possible(0, 1, no_of_weighs))
    {
        cout << "YES\n";

        for(int i = 1; i <= no_of_weighs; i++)
        {
            cout << answer[i] << " ";
        }
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
