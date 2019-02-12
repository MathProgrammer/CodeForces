#include <iostream>
#include <vector>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

const int MOD = 1e9 + 7, MAX_N = 305;

typedef long long LL;

vector <LL> primes;
vector <LL> prime_inverse;
vector <LL> mask(MAX_N, 0);


int is_bit_set(LL n, int position)
{
    return ( (n&(1LL << position)) != 0);
}

void set_bit(LL &n, int position)
{
    n |= (1LL << position);
}

LL fast_power(LL base, LL power)
{
    LL result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*base)%MOD;

        base = (base*base)%MOD;
        power = power >> 1;
    }

    return result;
}

void precompute_primes()
{
    vector <int> is_prime(MAX_N, true);

    for(int i = 2; i < MAX_N; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < MAX_N; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

void precompute_prime_inverse()
{
    for(int i = 0; i < primes.size(); i++)
    {
        LL inverse = fast_power(primes[i], MOD - 2);

        prime_inverse.push_back(inverse);
    }
}

void precompute_mask()
{
    for(int i = 1; i < MAX_N; i++)
    {
        mask[i] = 0;

        for(int bit = 0; bit < primes.size(); bit++)
        {
            if(i%primes[bit] == 0)
            {
                set_bit(mask[i], bit);
            }
        }
    }
}

struct Product_Tree
{
    vector <LL> tree, lazy;

    Product_Tree(){}

    Product_Tree(int n)
    {
        tree.resize(4*n, 1);
        lazy.resize(4*n, 1);
    }

    void propagate(int n, int left, int right)
    {
        LL range = right - (left - 1);
        tree[n] = (tree[n]*fast_power(lazy[n], range))%MOD;

        if(left != right)
        {
            lazy[LEFT(n)] = (lazy[LEFT(n)]*lazy[n])%MOD;
            lazy[RIGHT(n)] = (lazy[RIGHT(n)]*lazy[n])%MOD;
        }

        lazy[n] = 1;
    }

    void update(int n, int left, int right, int query_left, int query_right, int value)
    {
        if(lazy[n] > 1)
        {
            propagate(n, left, right);
        }

        if(right < query_left || query_right < left)
        {
            return;
        }

        if(query_left <= left && right <= query_right)
        {
            lazy[n] = (lazy[n]*value)%MOD;

            propagate(n, left, right);

            return;
        }

        int mid = (left + right)/2;

        update(LEFT(n), left, mid, query_left, query_right, value);
        update(RIGHT(n), mid + 1, right, query_left, query_right, value);

        tree[n] = (tree[LEFT(n)]*tree[RIGHT(n)])%MOD;
    }

    LL get_product(int n, int left, int right, int query_left, int query_right)
    {
        if(lazy[n] > 1)
        {
            propagate(n, left, right);
        }

        if(right < query_left || query_right < left)
        {
            return 1LL;
        }

        if(query_left <= left && right <= query_right)
        {
            return tree[n];
        }

        int mid = (left + right)/2;

        LL left_product = get_product(LEFT(n), left, mid, query_left, query_right);
        LL right_product = get_product(RIGHT(n), mid + 1, right, query_left, query_right);

        LL product = (left_product*right_product)%MOD;

        return product;
    }
};

struct OR_Tree
{
    vector <LL> tree, lazy;

    OR_Tree(){}

    OR_Tree(int n)
    {
        tree.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    void propagate(int n, int left, int right)
    {
        tree[n] |= lazy[n];

        if(left != right)
        {
            lazy[LEFT(n)]  |= lazy[n];
            lazy[RIGHT(n)] |= lazy[n];
        }

        lazy[n] = 0;
    }

    void update(int n, int left, int right, int query_left, int query_right, LL value)
    {
        if(lazy[n])
        {
            propagate(n, left, right);
        }

        if(right < query_left || query_right < left)
        {
            return;
        }

        if(query_left <= left && right <= query_right)
        {
            lazy[n] |= value;

            propagate(n, left, right);

            return;
        }

        int mid = (left + right)/2;

        update(LEFT(n), left, mid, query_left, query_right, value);
        update(RIGHT(n), mid + 1, right, query_left, query_right, value);

        tree[n] = (tree[LEFT(n)]|tree[RIGHT(n)]);
    }

    LL get_mask(int n, int left, int right, int query_left, int query_right)
    {
        if(lazy[n])
        {
            propagate(n, left, right);
        }

        if(right < query_left || query_right < left)
        {
            return 0;
        }

        if(query_left <= left && right <= query_right)
        {
            return tree[n];
        }

        int mid = (left + right)/2;
        LL left_mask = get_mask(LEFT(n), left, mid, query_left, query_right);
        LL right_mask = get_mask(RIGHT(n), mid + 1, right, query_left, query_right);

        LL mask = (left_mask|right_mask);
        return mask;
    }
};

Product_Tree product_tree;
OR_Tree OR_tree;
int no_of_elements, no_of_queries;

void read_input()
{
    cin >> no_of_elements >> no_of_queries;

    product_tree = Product_Tree(no_of_elements);
    OR_tree = OR_Tree(no_of_elements);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        cin >> element;

        product_tree.update(1, 1, no_of_elements, i, i, element);
        OR_tree.update(1, 1, no_of_elements, i, i, mask[element]);
    }
}

void solve()
{
    string query;
    int left, right;
    cin >> query >> left >> right;

    if(query == "MULTIPLY")
    {
        int x;
        cin >> x;

        product_tree.update(1, 1, no_of_elements, left, right, x);
        OR_tree.update(1, 1, no_of_elements, left, right, mask[x]);
    }
    else if(query == "TOTIENT")
    {
        LL totient = product_tree.get_product(1, 1, no_of_elements, left, right);

        LL segment_mask = OR_tree.get_mask(1, 1, no_of_elements, left, right);

        for(int bit = 0; bit < primes.size(); bit++)
        {
            if(!is_bit_set(segment_mask, bit))
                continue;

            totient = (totient*(primes[bit] - 1))%MOD;
            totient = (totient*prime_inverse[bit])%MOD;
        }

        cout << totient << "\n";
    }
}

int main()
{
    precompute_primes();
    precompute_prime_inverse();
    precompute_mask();

    read_input();

    while(no_of_queries--)
        solve();

    return 0;
}
