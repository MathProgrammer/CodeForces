#include <iostream>
#include <algorithm>

using namespace std;

long long laziness[100001];
int main()
{
    const int MOD = 1e4 + 7;
    int no_of_students, i;
    long long minimum_time = 0LL;
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> no_of_students;

    for(i = 0; i < no_of_students; i++)
        cin >> laziness[i];

    sort(laziness, laziness + no_of_students);

    for(i = 0; i < no_of_students; i++)
        minimum_time = (minimum_time + laziness[i]*laziness[no_of_students - i - 1])%MOD;

    cout << minimum_time;
    return 0;
}
