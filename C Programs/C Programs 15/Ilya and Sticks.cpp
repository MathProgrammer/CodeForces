#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_sticks;
    scanf("%d", &no_of_sticks);

    vector <int> length(no_of_sticks);
    for(int i = 0; i < no_of_sticks; i++)
        scanf("%d", &length[i]);

    sort(all(length));

    int side_1 = 0, side_2 = 0;
    long long area = 0;
    for(int i = no_of_sticks - 1; i - 1 >= 0; i--)
    {
        if(length[i] - length[i - 1] <= 1)
        {
            if(side_1 == 0)
            {
                side_1 = length[i - 1];
            }
            else if(side_2 == 0)
            {
                side_2 = length[i - 1];

                area += side_1*1LL*side_2;

                side_1 = side_2 = 0;
            }
            i--;
        }
    }

    printf("%I64d\n", area);
    return 0;
}
