#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 5005;
int prefix_smaller[MAX_N][MAX_N], suffix_smaller[MAX_N][MAX_N];

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    vector <int> index(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        index[A[i]] = i;
    }

    for(int b = 1; b <= no_of_elements; b++)
    {
        for(int c = b + 1; c <= no_of_elements; c++)
        {
            prefix_smaller[b][c] = suffix_smaller[b][c] = 0;
        }
    }

    vector <int> prefix_insertions(no_of_elements + 1, 0);
    for(int element = 1; element <= no_of_elements; element++)
    {
        for(int i = index[element]; i <= no_of_elements; i++)
        {
            prefix_insertions[i]++;
        }

        for(int c = index[element], b = 1; b < c; b++)
        {
            prefix_smaller[b][c] = prefix_insertions[b - 1];
        }

        for(int b = index[element], c = b + 1; c <= no_of_elements; c++)
        {
            suffix_smaller[b][c] = prefix_insertions[no_of_elements] - prefix_insertions[c];
        }
    }

    long long answer = 0;
    for(int b = 2; b + 2 <= no_of_elements; b++)
    {
        for(int c = b + 1; c + 1 <= no_of_elements; c++)
        {
            long long no_of_a = prefix_smaller[b][c], no_of_d = suffix_smaller[b][c];
            answer += no_of_a*no_of_d;
        }
    }

    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}



