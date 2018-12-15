#include <iostream>

using namespace std;

int ceil(int numerator, int denominator)
{
    int quotient = numerator/denominator;
    int remainder = numerator%denominator;

    return (quotient + (remainder!= 0));
}

void solve()
{
    int target_score;
    cin >> target_score;

    int no_of_rolls = ceil(target_score, 7);
    cout << no_of_rolls << "\n";
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}

