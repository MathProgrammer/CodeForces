#include <cstdio>
#include <set>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

struct info
{
    int value, position;

    info(int v = 0, int p = 0)
    {
        value = v;
        position = p;
    }

    int operator<(const info &A) const
    {
        return (position < A.position);
    }
};

using namespace std;

typedef long long LL;
const int MAX_N = 2e5 + 5, NOT_FOUND = -1, MAX_BITS = 32;

LL sum_tree[3*MAX_N], A[MAX_N];
multiset <info> S[MAX_BITS];
int no_of_elements;

void build(int n, int left, int right)
{
    if(left == right)
    {
        sum_tree[n] = A[left];
        return;
    }

    int mid = (left + right) >> 1;
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

void update(int n, int left, int right, int index, int new_value)
{
    if(right < index || index < left)
        return;

    if(left == right)
    {
        A[index] = new_value;
        sum_tree[n] = new_value;
        return;
    }

    int mid = (left + right) >> 1;
    update(LEFT(n), left, mid, index, new_value);
    update(RIGHT(n), mid + 1, right, index, new_value);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
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

int no_of_bits(int n)
{
    int bits = 0;

    while(n > 0)
    {
        n = n >> 1;
        bits++;
    }

    return bits;
}

int get_answer()
{
    for(int bit = 0; bit < MAX_BITS; bit++) //Iterating over the priority queue for each no of bits
    {
        int i = 1;
        for(multiset <info> :: iterator it = S[bit].begin(); it != S[bit].end() && i <= 2; i++, it++)//The first two elements, by index
        {
            int index = it->position;

            if(get_sum(1, 1, no_of_elements, 1, index - 1) == A[index])
                return index;
        }
    }

    return NOT_FOUND;
}

void remove_from_multiset(info element, int multiset_no)
{
    multiset <info> :: iterator it = S[multiset_no].find(element);

    if(it != S[multiset_no].end())
        S[multiset_no].erase(it);
}

void solve()
{
    int index, new_value;
    scanf("%d %d", &index, &new_value);

    info element(A[index], index);
    remove_from_multiset(element, no_of_bits(A[index]));

    S[no_of_bits(new_value)].insert(info(new_value, index));

    update(1, 1, no_of_elements, index, new_value);

    int answer = get_answer();
    printf("%d\n", answer);
}

int main()
{
    int no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%I64d", &A[i]);
        S[no_of_bits(A[i])].insert(info(A[i], i));
    }

    build(1, 1, no_of_elements);

    while(no_of_queries--)
        solve();

    return 0;
}
