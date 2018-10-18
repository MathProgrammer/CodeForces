#include <iostream>

using namespace std;

int digit_sum(long long n)
{
    int sum = 0;

    while(n)
    {
        sum += n%10;
        n = n/10;
    }

    return sum;
}

long long to_int(string &S)
{
    long long n = 0;

    for(int i = 0; i < S.size(); i++)
        n = n*10 + (S[i] - '0');

    return n;
}

int main()
{
    string N;
    cin >> N;

    string A;
    A = N[0] - 1;
    for(int i = 1; i < N.size(); i++)
        A += '9';

    long long n = to_int(N), a = to_int(A);
    long long b = n - a;

    cout << digit_sum(a) + digit_sum(b);
    return 0;
}
