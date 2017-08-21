#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int get_gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return get_gcd(max(a, b)%min(a, b), min(a, b));
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int gcd = get_gcd(a, b);

    vector <int> factors;
    for(int i = 1; i*i <= gcd; i++)
    {
        if(gcd%i == 0)
        {
            if(i*i == gcd)
            {
                factors.push_back(i);
            }
            else
            {
                factors.push_back(i);
                factors.push_back(gcd/i);
            }
        }
    }

    sort(all(factors));

    int number_of_queries;
    scanf("%d", &number_of_queries);

    for(int i = 1; i <= number_of_queries; i++)
    {
        int left, right, answer;
        scanf("%d %d", &left, &right);

        int index = upper_bound(factors.begin(), factors.end(), right) - factors.begin(); //Returns 1 indexed
        index--;

        if(factors[index] < left)
            answer = -1;
        else
            answer = factors[index];

        printf("%d\n", answer);
    }

    return 0;
}
