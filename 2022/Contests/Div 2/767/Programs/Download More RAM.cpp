#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements, present_RAM;
    cin >> no_of_elements >> present_RAM;

    vector <pair <int, int> > ram(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> ram[i].first;
    }

    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> ram[i].second;
    }

    sort(ram.begin(), ram.end());

    int answer = present_RAM;
    for(int i = 0; i < no_of_elements; i++)
    {
        if(ram[i].first <= answer)
        {
            answer += ram[i].second;
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
