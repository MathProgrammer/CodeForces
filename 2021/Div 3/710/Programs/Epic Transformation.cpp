#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    map <int, int> frequency;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        frequency[A[i]]++;
    }

    vector <int> pile;
    for(auto it = frequency.begin(); it != frequency.end(); it++)
    {
        pile.push_back(it->second);
    }

    sort(pile.begin(), pile.end());

    if(2*pile.back() > no_of_elements)
    {
        int remaining = no_of_elements - pile.back();

        cout << no_of_elements - 2*remaining << "\n";

        return;
    }

    cout << no_of_elements%2 << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

