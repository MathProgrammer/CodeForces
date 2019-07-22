#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> length(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> length[i];

    sort(all(length));

    int no_of_steps = min(length[no_of_elements - 1] - 1, no_of_elements - 2);
    cout << no_of_steps << "\n";
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}
