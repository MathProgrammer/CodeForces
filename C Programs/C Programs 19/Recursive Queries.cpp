#include <cstdio>
#include <vector>

using namespace std;

const int LIMIT = 1e6 + 5;
int answer[LIMIT][10];

int non_zero_digit_product(int n)
{
    int product = 1;

    while(n)
    {
        product *= (n%10 != 0 ? n%10 : 1);
        n /= 10;
    }

    return product;
}

void precompute()
{
    vector <int> g(LIMIT, 0);
    for(int i = 1; i < LIMIT; i++)
        g[i] = (i < 10 ? i : g[non_zero_digit_product(i)]);

    for(int i = 1; i < LIMIT; i++)
        answer[i][0] = 0;

    for(int i = 1; i < LIMIT; i++)
    {
        for(int digit = 1; digit < 10; digit++)
        {
            answer[i][digit] = answer[i - 1][digit];
        }

        if(g[i] < 10)
            answer[i][g[i]]++;
    }
}

int main()
{
    precompute();

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int left, right, k;
        scanf("%d %d %d", &left, &right, &k);

        printf("%d\n", answer[right][k] - answer[left - 1][k]);
    }

    return 0;
}
