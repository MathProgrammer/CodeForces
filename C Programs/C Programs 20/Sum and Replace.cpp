#include <cstdio>
#include <vector>

#define LEFT(n) ( (n << 1) )
#define RIGHT(n) ( (n << 1)|1 )

using namespace std;

const int MAX_N = 1e6 + 10, MAX_ELEMENTS = 5e5 + 6;
vector <int> no_of_divisors(MAX_N, 0);

int max_tree[3*MAX_ELEMENTS];
long long sum_tree[3*MAX_ELEMENTS];
int A[MAX_ELEMENTS];

void precompute_divisors()
{
    vector <int> largest_prime_factor(MAX_N, 0);
    no_of_divisors[1] = 1;

    for(int i = 2; i < MAX_N; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int multiple = i; multiple < MAX_N; multiple += i)
            {
                largest_prime_factor[multiple] = i;
            }
        }

        int exponent = 0, reduced_i = i;

        while(reduced_i%largest_prime_factor[i] == 0)
        {
            reduced_i /= largest_prime_factor[i];
            exponent++;
        }

        no_of_divisors[i] = (exponent + 1)*no_of_divisors[reduced_i];
    }
}

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

long long get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left)
        return 0;

    if(query_left <= left && right <= query_right)
        return sum_tree[n];

    int mid = (left + right) >> 1;
    long long left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    long long right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_sum + right_sum);
}

void update(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left || max_tree[n] <= 2)
        return;

    if(left == right)
    {
        A[left] = no_of_divisors[A[left]];
        max_tree[n] = sum_tree[n] = A[left];
        return;
    }

    int mid = (left + right) >> 1;

    update(LEFT(n), left, mid, query_left, query_right);
    update(RIGHT(n), mid + 1, right, query_left, query_right);

    max_tree[n] = max(max_tree[LEFT(n)], max_tree[RIGHT(n)]);
    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

int main()
{
    precompute_divisors();

    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    build(1, 1, no_of_elements);

    while(no_of_queries--)
    {
        const int SUM = 2, REPLACE = 1;
        int query_type, left, right;
        scanf("%d %d %d", &query_type, &left, &right);

        if(query_type == SUM)
        {
            long long sum = get_sum(1, 1, no_of_elements, left, right);
            printf("%I64d\n", sum);
        }
        else if(query_type == REPLACE)
        {
            update(1, 1, no_of_elements, left, right);
        }
    }

    return 0;
}
