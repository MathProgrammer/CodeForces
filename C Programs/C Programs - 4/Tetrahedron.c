#include <stdio.h>
#include <stdlib.h>

unsigned long long find_no_of_cycles(unsigned long long);
const long long mod = 1000000007;
int main()
{
    unsigned long long no_of_moves, no_of_cyclic_paths;
    scanf("%I64u",&no_of_moves);
    no_of_cyclic_paths = find_no_of_cycles(no_of_moves);
    printf("%I64u\n",no_of_cyclic_paths);
    return 0;
}

unsigned long long find_no_of_cycles(unsigned long long no_of_moves)
{
    unsigned long long paths_from_D_i, path_D_i_minus_1;
    unsigned long long paths_from_ABC_i, path_ABC_i_minus_1;
    unsigned long long i, no_of_cycles;

    //f(X, n) is the number of ways to reach D in n moves when ant is on vertex X
    paths_from_D_i = 1; //f(D, 0) = 1
    paths_from_ABC_i = 0; //f(ABC, 0) = 1

    for(i = 1; i <= no_of_moves; i++)
    {
        path_D_i_minus_1 = paths_from_D_i ;
        path_ABC_i_minus_1 = paths_from_ABC_i;

        paths_from_D_i = (3LL* path_ABC_i_minus_1)%mod; //f(D,i) = 3f(ABC, i-1) - From D ant can go to either A, B or C having spent one move.
        paths_from_ABC_i = (path_D_i_minus_1 + 2LL*path_ABC_i_minus_1)%mod; //f(ABC, i) = f(D,i-1) + 2f(ABC, i-1) - From A, B, C ant can go to either D or two other vertices
    }

    no_of_cycles = paths_from_D_i;//f(D, n) is the required number and this is the last value stored in f(D, i)

    return no_of_cycles;
}
