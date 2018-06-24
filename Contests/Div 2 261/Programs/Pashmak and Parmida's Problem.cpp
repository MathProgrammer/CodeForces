#include <cstdio>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 1e6;
LL sum_tree[3*MAX_N];

void update(int n, int left, int right, int position, int value)
{
    if(right < position || position < left)
        return;

    if(left == right)
    {
        sum_tree[n] += value;

        return;
    }

    int mid = (left + right) >> 1;

    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

LL get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(right < query_left || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
        return sum_tree[n];

    int mid = (left + right) >> 1;

    LL left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    LL right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_sum + right_sum);
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    map <int, int> left_frequency;
    vector <int> left(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        left_frequency[A[i]]++;

        left[i] = left_frequency[A[i]];
    }

    map <int, int> right_frequency;
    vector <int> right(no_of_elements + 1, 0);
    for(int i = no_of_elements; i >= 1; i--)
    {
        right_frequency[A[i]]++;

        right[i] = right_frequency[A[i]];
    }

    LL answer = 0;
    for(int i = no_of_elements; i >= 1; i--)
    {
        answer += get_sum(1, 1, no_of_elements, 1, left[i] - 1); //Adding all rights that are smaller than left

        update(1, 1, no_of_elements, right[i], 1);
    }

    printf("%I64d\n", answer);
    return 0;
}
