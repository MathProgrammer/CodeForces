#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

typedef long long LL;

using namespace std;

struct fraction
{
    long long numerator, denominator;

    fraction(){}

    fraction(long long N, long long D)
    {
        long long G = __gcd(abs(N), abs(D));

        numerator = N/G;
        denominator = D/G;

        if(denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
    }

    const int operator <(const fraction &F) const
    {
        return (denominator*F.numerator - numerator*F.denominator < 0);
    }
};

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <LL> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    vector <LL> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> B[i];

    int both_zeroes = 0;
    for(int i = 1; i <= no_of_elements; i++)
        both_zeroes += (A[i] == 0 && B[i] == 0);

    map <fraction, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] == 0)
            continue;

        frequency[fraction(-B[i], A[i])]++;
    }

    int max_frequency = 0;
    for(map <fraction, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
    {
        max_frequency = max(max_frequency, it->second);
    }

    int answer = max_frequency + both_zeroes;

    cout << answer;
    return 0;
}
