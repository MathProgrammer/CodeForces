#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    unsigned int n, number_of_factors;
    scanf("%d %d", &n, &number_of_factors);

    vector <int> factor;
    for(unsigned int i = 2; i <= n ; i++)
    {
        while(n%i == 0)
        {
            if(factor.size() == number_of_factors)
                factor.back() *=i;
            else
                factor.push_back(i);

            n = n/i;
        }
    }

    if(factor.size() < number_of_factors)
        printf("-1\n");
    else
        for(unsigned int i = 0; i < number_of_factors; i++)
            printf("%d ",factor[i]);

    return 0;
}
