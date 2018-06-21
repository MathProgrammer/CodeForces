#include <cstdio>
#include <vector>
#include <algorithm>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

typedef long long LL;
const int MAX_N = 2e5 + 5, NOT_FOUND = -1;
LL max_tree[4*MAX_N], sum_tree[4*MAX_N], A[MAX_N];
int no_of_elements;

void build(int n, int left, int right)
{
    if(left == right)
    {
        max_tree[n] = sum_tree[n] = A[left];
        return;
    }

    int mid = (left + right) >> 1;
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
    max_tree[n] = max(max_tree[LEFT(n)], max_tree[RIGHT(n)]);
}

void update(int n, int left, int right, int index, int new_value)
{
    if(right < index || index < left)
        return;

    if(left == right)
    {
        A[index] = new_value;
        sum_tree[n] = max_tree[n] = new_value;
        return;
    }

    int mid = (left + right) >> 1;
    update(LEFT(n), left, mid, index, new_value);
    update(RIGHT(n), mid + 1, right, index, new_value);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
    max_tree[n] = max(max_tree[LEFT(n)], max_tree[RIGHT(n)]);
}

LL get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left)
        return 0;

    if(query_left <= left && right <= query_right)
        return sum_tree[n];

    int mid = (left + right) >> 1;
    LL left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    LL right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_sum + right_sum);
}

int first_index(int n, int left, int right, int query_left, int query_right, LL minimum)
{
    if(right < query_left || query_right < left || max_tree[n] < minimum)
        return NOT_FOUND;

    if(left == right)
        return left;

    int mid = (left + right) >> 1;

    int left_answer = first_index(LEFT(n), left, mid, query_left, query_right, minimum);
    if(left_answer != NOT_FOUND) return left_answer;

    int right_answer = first_index(RIGHT(n), mid + 1, right, query_left, query_right, minimum);
    return right_answer;
}

int get_answer()
{
    LL prefix_sum;
    int index = 1;

    while(index != NOT_FOUND)
    {
        prefix_sum = get_sum(1, 1, no_of_elements, 1, index - 1);

        if(prefix_sum == A[index])
            return index;

        prefix_sum += A[index];

        index = first_index(1, 1, no_of_elements, index + 1, no_of_elements, prefix_sum);
    }

    return index;
}

void solve()
{
    int index, new_value;
    scanf("%d %d", &index, &new_value);

    update(1, 1, no_of_elements, index, new_value);

    int answer = get_answer();
    printf("%d\n", answer);
}

int main()
{
    int no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++)
        scanf("%I64d", &A[i]);

    build(1, 1, no_of_elements);

    while(no_of_queries--)
        solve();

    return 0;
}
