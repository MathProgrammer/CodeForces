#include <iostream>
#include <vector>

using namespace std;

long long get_sum(long long n)
{
    return (n*(n + 1))/2;
}

void solve()
{
    int no_of_contestants, start_time, duration;
    cin >> no_of_contestants >> start_time >> duration;

    long long answer;
    long long batch_1 = min(no_of_contestants, duration/start_time);

    answer = get_sum(batch_1 - 1);
    no_of_contestants -= batch_1;

    long long one_contestant_intersections = duration/start_time;
    answer += no_of_contestants*(one_contestant_intersections);

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

