#include <bits/stdc++.h>

using namespace std;

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 2e5 + 15;
int sum_tree[3*MAX_N];

void update(int n, int left, int right, int index, int value)
{
    if(right < left || right < index || index < left)
        return;

    if(right == left)
    {
        sum_tree[n] = value;
        return;
    }

    int mid = (left + right) >> 1;
    update(LEFT(n), left, mid, index, value);
    update(RIGHT(n), mid + 1, right, index, value);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

int get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(right < left || right < query_left || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
        return sum_tree[n];

    int mid = (left + right) >> 1;
    int left_answer = get_sum(LEFT(n), left, mid, query_left, query_right);
    int right_answer = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_answer + right_answer);
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    vector <int> index[no_of_elements + 1];

    memset(sum_tree, 0, sizeof(sum_tree));

    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);
        A[i] = min(A[i], no_of_elements);

        update(1, 1, no_of_elements, i, 1);

        index[A[i]].push_back(i);
    }

    long long answer = 0;

    for(int i = 1; i <= no_of_elements; i++)
    {
        answer += get_sum(1, 1, no_of_elements, i + 1, A[i]);

        for(int j = 0; j < index[i].size(); j++)
        {
            update(1, 1, no_of_elements, index[i][j], 0);
        }
    }

    printf("%I64d\n", answer);
    return 0;
}
