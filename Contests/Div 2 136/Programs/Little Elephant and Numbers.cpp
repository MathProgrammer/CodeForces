#include <cstdio>
#include <vector>

using namespace std;

void get(int n, vector <int> &frequency)
{
    while(n)
    {
        frequency[n%10]++;

        n /= 10;
    }
}

int common_digit(int a, int b)
{
    vector <int> a_frequency(10, 0);
    get(a, a_frequency);

    vector <int> b_frequency(10, 0);
    get(b, b_frequency);

    for(int i = 0; i < 10; i++)
        if(a_frequency[i] > 0 && b_frequency[i] > 0)
            return true;

    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    int answer = 0;
    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            answer += common_digit(i, n);

            answer += (i*i != n && common_digit(n/i, n));
        }
    }

    printf("%d\n", answer);
    return 0;
}
