#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
#define all(v) (v).begin() + 1, (v).end()

using namespace std;

struct info
{
    int left, right, index;

    int operator <(const info &A)
    {
        return (right < A.right);
    }
};

const int MAX_N = 1e5 + 1;
int sum_tree[3*MAX_N];
vector <int> occurence[MAX_N];

void update(int n, int left, int right, int position, int value)
{
    if(right < position || position < left)
        return;

    if(left == right)
    {
        sum_tree[n] = value;
        return;
    }

    int mid = (left + right) >> 1;
    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

int get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left)
        return 0;

    if(query_left <= left && right <= query_right)
        return sum_tree[n];

    int mid = (left + right) >> 1;
    int left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    int right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_sum + right_sum);
}

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <info> Q(no_of_queries + 1);
    for(int i = 1; i <= no_of_queries; i++)
    {
        scanf("%d %d", &Q[i].left, &Q[i].right);
        Q[i].index = i;
    }

    sort(all(Q));

    memset(sum_tree, 0, sizeof(sum_tree));

    int last_query = 1;
    vector <int> answer(no_of_queries + 1);

    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] < MAX_N)
        {
            occurence[A[i]].push_back(i);

            int A_i_frequency = occurence[A[i]].size();

            if(A_i_frequency >= A[i])
            {
                int last = A_i_frequency - A[i];

                int last_occurence = occurence[A[i]][last];

                update(1, 1, no_of_elements, last_occurence, 1);
            }

            if(A_i_frequency >= A[i] + 1)
            {
                int second_last = A_i_frequency - (A[i] + 1);

                int second_last_occurence = occurence[A[i]][second_last];

                update(1, 1, no_of_elements, second_last_occurence, -1);
            }

            if(A_i_frequency >= A[i] + 2)
            {
                int third_last = A_i_frequency - (A[i] + 2);

                int third_last_occurence = occurence[A[i]][third_last];

                update(1, 1, no_of_elements, third_last_occurence, 0);
            }
        }

        while(Q[last_query].right == i)
        {
            answer[Q[last_query].index] = get_sum(1, 1, no_of_elements, Q[last_query].left, Q[last_query].right);

            last_query++;
        }
    }

    for(int i = 1; i <= no_of_queries; i++)
        printf("%d\n", answer[i]);

    return 0;
}
