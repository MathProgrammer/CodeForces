#include <iostream>

using namespace std;

void solve()
{
    long long left_jump, right_jump, total_jumps;
    cin >> right_jump >> left_jump >> total_jumps;

    long long no_of_right_jumps = total_jumps/2 + total_jumps%2;
    long long no_of_left_jumps = total_jumps/2;

    long long right_distance = no_of_right_jumps*right_jump;
    long long left_distance = no_of_left_jumps*left_jump;

    long long distance = right_distance - left_distance;
    cout << distance << "\n";
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}
