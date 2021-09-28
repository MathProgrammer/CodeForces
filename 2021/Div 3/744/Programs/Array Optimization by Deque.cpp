#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

const int MAX_N = 2e5 + 5;
int sum_tree[3*MAX_N];

void build(int n, int left, int right)
{
    if(left == right)
    {
        sum_tree[n] = 0;
        return;
    }

    int mid = (left + right)/2;
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

void update(int n, int left, int right, int position, int value)
{
    if(position < left || right < position)
    {
        return;
    }

    if(left == right)
    {
        sum_tree[n] += value;

        return;
    }

    int mid = (left + right)/2;

    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

int get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(right < left || query_right < left || right < query_left)
    {
        return 0;
    }

    if(query_left <= left && right <= query_right)
    {
        return sum_tree[n];
    }

    int mid = (left + right)/2;
    int left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    int right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_sum + right_sum);
}

void compress_coordinates(int no_of_elements, vector <int> &A)
{
    vector <int> sorted_A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sorted_A[i] = A[i];
    }

    sort(sorted_A.begin() + 1, sorted_A.end());

    map <int, int> label;
    label[sorted_A[1]] = 1;
    for(int i = 2; i <= no_of_elements; i++)
    {
        label[sorted_A[i]] = (sorted_A[i] == sorted_A[i - 1] ? label[sorted_A[i - 1]] : label[sorted_A[i - 1]] + 1);
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        A[i] = label[A[i]];
    }
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    compress_coordinates(no_of_elements, A);
    build(1, 1, no_of_elements);

    long long inversions = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        //cout << "Currently " << A[i] << "\n";
        int prefix_sum = get_sum(1, 1, no_of_elements, 1, A[i] - 1);
        int suffix_sum = get_sum(1, 1, no_of_elements, A[i] + 1, no_of_elements);
        update(1, 1, no_of_elements, A[i], 1);
        //cout << "Prefix = " << prefix_sum << " Suffix = " << suffix_sum << "\n";

        inversions += min(prefix_sum, suffix_sum);
    }

    cout << inversions << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
