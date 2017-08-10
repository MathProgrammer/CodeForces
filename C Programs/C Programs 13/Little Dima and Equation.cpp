#include <cstdio>
#include <vector>

using namespace std;

long long int_power(int x, int n)
{
    long long power = 1;
    for(int i = 1; i <= n; i++)
    {
        power *= x;
    }
    return power;
}

int sum_of_digits(int x)
{
    const int base = 10;
    int digit_sum = 0;

    while(x > 0)
    {
        digit_sum += x%base;
        x = x/base;
    }
    return digit_sum;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    vector <int> solutions;

    for(int digit_sum = 1; digit_sum <= 81; digit_sum++)
    {
        long long x = b*int_power(digit_sum, a) + c;
        if(sum_of_digits(x) == digit_sum && x > 0 && x < 1e9)
            solutions.push_back(x);
    }

    printf("%d\n", solutions.size());
    for(unsigned int i = 0; i < solutions.size(); i++)
        printf("%d ", solutions[i]);

    return 0;
}
