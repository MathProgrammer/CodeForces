#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main()
{
    int no_of_sides;
    cin >> no_of_sides;

    const int FIBO_LIMIT_MAX_SIDES = 45;
    if(no_of_sides > FIBO_LIMIT_MAX_SIDES)
    {
        cout << "YES\n";
        return 0;
    }

    vector <int> side(no_of_sides);
    for(int i = 0; i < no_of_sides; i++) cin >> side[i];

    sort(all(side));

    int triangle_possible = false;
    for(int i = no_of_sides - 1; i >= 2; i--)
    {
        if(side[i] < side[i - 1] + side[i - 2])
        {
            triangle_possible = true;
            break;
        }
    }

    cout << (triangle_possible ? "YES\n" : "NO\n");
    return 0;
}
