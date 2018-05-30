#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 3015;
const long long oo = 1e10;

struct info
{
    int font_size, cost, position;
};

long long min_tree[4*MAX_N];
long long max_tree[4*MAX_N];

int compare_by_size(const info &A, const info &B)
{
    if(A.font_size == B.font_size)
        return (A.position > B.position);
    else
        return (A.font_size < B.font_size);
}

void build_min_tree(int n, int left, int right)
{
    if(left == right)
    {
        min_tree[n] = oo;
        return;
    }

    int mid = (left + right) >> 1;
    build_min_tree(LEFT(n), left, mid);
    build_min_tree(RIGHT(n), mid + 1, right);

    min_tree[n] = min(min_tree[LEFT(n)], min_tree[RIGHT(n)]);
}

void update_min(int n, int left, int right, int position, int value)
{
    if(position < left || right < position)
        return;

    if(left == right)
    {
        min_tree[n] = value;
        return;
    }

    int mid = (left + right) >> 1;
    update_min(LEFT(n), left, mid, position, value);
    update_min(RIGHT(n), mid + 1, right, position, value);

    min_tree[n] = min(min_tree[LEFT(n)], min_tree[RIGHT(n)]);
}

long long get_min(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left || query_right < query_left)
        return oo;

    if(query_left <= left && right <= query_right)
        return min_tree[n];

    int mid = (left + right) >> 1;
    long long left_min = get_min(LEFT(n), left, mid, query_left, query_right);
    long long right_min = get_min(RIGHT(n), mid + 1, right, query_left, query_right);

    return min(left_min, right_min);
}

int main()
{
    int no_of_displays;
    scanf("%d", &no_of_displays);

    vector <info> A(no_of_displays + 1);

    for(int i = 1; i <= no_of_displays; i++)
        A[i].position = i;

    for(int i = 1; i <= no_of_displays; i++)
        scanf("%d", &A[i].font_size);

    for(int i = 1; i <= no_of_displays; i++)
        scanf("%d", &A[i].cost);

    sort(A.begin() + 1, A.end(), compare_by_size);

    build_min_tree(1, 1, no_of_displays);
    vector <long long> best_left(no_of_displays + 1, oo);
    for(int i = 1; i <= no_of_displays; i++)
    {
        update_min(1, 1, no_of_displays, A[i].position, A[i].cost);

        best_left[i] = get_min(1, 1, no_of_displays, 1, A[i].position - 1);
    }

    build_min_tree(1, 1, no_of_displays);
    vector <long long> best_right(no_of_displays + 1, oo);
    for(int i = no_of_displays; i >= 1; i--)
    {
        update_min(1, 1, no_of_displays, A[i].position, A[i].cost);

        best_right[i] = get_min(1, 1, no_of_displays, A[i].position + 1, no_of_displays);
    }

    long long best_cost = oo;
    for(int i = 1; i <= no_of_displays; i++)
        best_cost = min(best_cost, best_left[i] + A[i].cost + best_right[i]);

    printf(best_cost >= oo ? "-1\n" : "%I64d\n", best_cost);
    return 0;
}
