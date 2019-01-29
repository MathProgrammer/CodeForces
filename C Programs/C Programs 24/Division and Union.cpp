#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct line
{
    int left, right, position;

    line(int l, int r, int p)
    {
        left = l, right = r, position = p;
    }

    int operator <(const line &L)
    {
        return (right < L.right);
    }
};

void solve()
{
    int no_of_segments;
    cin >> no_of_segments;

    vector <line> L;
    for(int i = 0; i < no_of_segments; i++)
    {
        int left, right;
        cin >> left >> right;

        L.push_back(line(left, right, i));
    }

    sort(all(L));

    vector <int> minimum_left_from(no_of_segments);
    for(int i = no_of_segments - 1; i >= 0; i--)
    {
        if(i == no_of_segments - 1)
            minimum_left_from[i] = L[i].left;
        else
            minimum_left_from[i] = min(minimum_left_from[i + 1], L[i].left);
    }

    const int NOT_FOUND = -1;
    int first_group_ending = NOT_FOUND;

    for(int i = 0; i < no_of_segments - 1; i++)
    {
        if(L[i].right < minimum_left_from[i + 1])
            first_group_ending = i;
    }

    if(first_group_ending == NOT_FOUND)
    {
        cout << NOT_FOUND << "\n";
        return ;
    }

    vector <int> group(no_of_segments);
    for(int i = 0; i < no_of_segments; i++)
        group[L[i].position] = (i <= first_group_ending ? 1 : 2);

    for(int i = 0; i < no_of_segments; i++)
        cout << group[i] << " ";

    cout << "\n";
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}
