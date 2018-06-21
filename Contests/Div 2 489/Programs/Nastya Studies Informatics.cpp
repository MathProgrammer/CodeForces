#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
using namespace std;

long long gcd_(long long p, long long q)
{
    if(min(p, q) == 0)
        return max(p, q);
    else
        return gcd_(min(p, q), max(p, q)%min(p, q));
}

int main()
{
    long long left, right, gcd, lcm;
    scanf("%I64d %I64d %I64d %I64d", &left, &right, &gcd, &lcm);

    //search for pg, qg, where pq = l/g
    int good_pairs = 0;
    long long reduced_lcm = lcm/gcd;
    for(int i = 1; i*i <= reduced_lcm; i++)
    {
        if(reduced_lcm%i == 0)
        {
            long long p = i, q = reduced_lcm/i;

            if(left <= p*gcd && p*gcd <= right && left <= q*gcd && q*gcd <= right && gcd_(p, q) == 1)
            {   //printf("p = %d, q = %d\n", p, q);
                if(p == q)
                    good_pairs++;
                else
                    good_pairs += 2;
            }
        }
    }

    printf("%d\n", good_pairs);
    return 0;
}

