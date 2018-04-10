#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 5e5 + 15, NOT_FOUND = -1;

int gcd_tree[3*MAX_N], A[MAX_N], no_of_elements;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

void build(int n, int left, int right)
{
    if(left == right)
    {
        gcd_tree[n] = A[left];
        return;
    }

    int mid = (left + right) >> 1;

    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    gcd_tree[n] = gcd(gcd_tree[LEFT(n)], gcd_tree[RIGHT(n)]);
}

void update(int n, int left, int right, int index, int value)
{
    if(right < index || index < left)
        return;

    if(left == right)
    {
        gcd_tree[n] = value;
        return;
    }

    int mid = (left + right) >> 1;
    update(LEFT(n), left, mid, index, value);
    update(RIGHT(n), mid + 1, right, index, value);

    gcd_tree[n] = gcd(gcd_tree[LEFT(n)], gcd_tree[RIGHT(n)]);
}

int get_first_indivisible_element(int n, int left, int right, int query_left, int query_right, int x)
{
    if(gcd_tree[n]%x == 0 || right < query_left || query_right < left || right < left || query_right < query_left)
        return NOT_FOUND;

    if(left == right) //Leaf node and it's not divisible. So, it has to be this element.
        return left;

    int mid = (left + right) >> 1;

    int left_answer = get_first_indivisible_element(LEFT(n), left, mid, query_left, query_right, x);

    if(left_answer != NOT_FOUND)
        return left_answer;

    int right_answer = get_first_indivisible_element(RIGHT(n), mid + 1, right, query_left, query_right, x);

    return right_answer;
}

void solve()
{
    const int GUESS_GCD = 1, UPDATE = 2;

    int query_type;
    scanf("%d ", &query_type);

    if(query_type == GUESS_GCD)
    {
        int left, right, x;
        scanf("%d %d %d", &left, &right, &x);

        int first_indivisible_element = get_first_indivisible_element(1, 1, no_of_elements, left, right, x);

        if(first_indivisible_element == NOT_FOUND) //Entire range divisible by x.
        {
            printf("YES\n");
        }
        else if(first_indivisible_element != NOT_FOUND) //If 2 elements are not divisible by x, answer is NO. Else, if it is <= 1, answer is YES
        {
            int second_indivisible_element = get_first_indivisible_element(1, 1, no_of_elements, first_indivisible_element + 1, right, x);

            printf(second_indivisible_element == NOT_FOUND ? "YES\n" : "NO\n");
        }
    }
    else if(query_type == UPDATE)
    {
        int index, value;
        scanf("%d %d", &index, &value);

        update(1, 1, no_of_elements, index, value);
    }
}

int main()
{
    scanf("%d", &no_of_elements);

    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    build(1, 1, no_of_elements);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
        solve();

    return 0;
}
