#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);

    const int MAX_N = 1e5 + 15;
    vector <int> last_multiple_index(MAX_N, 0);

    for(int i = 1; i <= no_of_queries; i++)
    {
        int number, y;
        scanf("%d %d", &number, &y);

        int last_index = i - y;
        int divisors = 0, bad_divisors = 0;

        for(int d = 1; d*d <= number; d++)
        {
            if(number%d == 0)
            {
                divisors += (d*d == number ? 1 : 2);

                if(last_multiple_index[d] >= last_index)
                {
                    bad_divisors++;
                }

                if(d*d != number && last_multiple_index[number/d] >= last_index)
                {
                    bad_divisors++;
                }

                last_multiple_index[d] = last_multiple_index[number/d] = i;
            }
        }

        int good_divisors = divisors - bad_divisors;

        printf("%d\n", good_divisors);
    }

    return 0;
}
