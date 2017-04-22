#include <stdio.h>

unsigned long calculate_no_of_paths(short, short, short);

int main()
{
    short sum, no_of_children, d;
    unsigned long no_of_paths;
    scanf("%hu %hu %hu",&sum, &no_of_children, &d);
    no_of_paths = calculate_no_of_paths(sum, no_of_children, d);
    printf("%lu\n",no_of_paths);
    return 0;
}

unsigned long calculate_no_of_paths(short sum, short no_of_children, short d)
{
    unsigned long no_of_paths[101][2];
    short i, j;
    const unsigned long mod = (1e9 + 7);

    no_of_paths[0][0] = 1;
    no_of_paths[0][1] = 0;
    /*Here, f(n, i) represents the number of paths which sum up to n. i is a boolean value which is 1 if the path contains an edge atleast d and 0 otherwise
    We make a recurrence based on selecting each child separately.
    f(n, 0) = f(n-1, 0) + f(n-2, 0) + ... + f(n - min{n, d-1}, 0)
    Other case -
    f(n, 1) = f(n-1, 1) + f(n-2, 1) + ... + f(n - min{n, d-1}, 1) + {f(n - d, 0) + f(n - d, 1} + ... + {f(n - k, 0) + f(n - k, 1)}*/
    for(i = 1; i <= sum; i++)
    {
        no_of_paths[i][0] = no_of_paths[i][1] = 0;

        for(j = 1; ((j <= no_of_children) && (i-j >= 0)); j++)
        {
            if(j < d)
            {
                no_of_paths[i][0] =(no_of_paths[i][0]+ no_of_paths[i-j][0])%mod;
                no_of_paths[i][1] = (no_of_paths[i][1] + no_of_paths[i-j][1])%mod;
            }
            else
            {
                no_of_paths[i][1] = (no_of_paths[i][1] + no_of_paths[i-j][0])%mod;
                no_of_paths[i][1] = (no_of_paths[i][1] + no_of_paths[i-j][1])%mod;
            }
        }
    }
    return no_of_paths[sum][1];
}
