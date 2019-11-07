#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct pairs
{
    int a, b, index;

    pairs()
    {
        a = 0; b = 0;
    };

    pairs(int A, int B, int I)
    {
        a = A, b = B, index = I;
    }
};

// (p1 < p2) > (q1 < q2)
int sort_increasing_pairs(pairs &P, pairs &Q)
{
    return (P.b > Q.b);
}

// (p1 > p2) < (q1 > q2)
int sort_decreasing_pairs(pairs&P, pairs &Q)
{
    return (P.a < Q.a);
}

int main()
{
    int no_of_pairs;
    cin >> no_of_pairs;

    vector <pairs> increasing, decreasing;
    for(int i = 1; i <= no_of_pairs; i++)
    {
        int x, y;
        cin >> x >> y;

        if(x < y)
        {
            increasing.push_back(pairs(x, y, i));
        }
        else
        {
            decreasing.push_back(pairs(x, y, i));
        }
    }

    sort(all(increasing), sort_increasing_pairs);
    sort(all(decreasing), sort_decreasing_pairs);

    if(increasing.size() >= decreasing.size())
    {
        cout << increasing.size() << "\n";

        for(int i = 0; i < increasing.size(); i++)
        {
            cout << increasing[i].index << " ";
        }
    }
    else
    {
        cout << decreasing.size() << "\n";

        for(int i = 0; i < decreasing.size(); i++)
        {
            cout << decreasing[i].index << " ";
        }
    }

    return 0;
}
