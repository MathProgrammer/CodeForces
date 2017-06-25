#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> fibonacci;

void precompute_fibonacci()
{
    const int MAX = 1e9;

    fibonacci.push_back(0);
    fibonacci.push_back(1);

    for(int i = 2; fibonacci[i - 1] + fibonacci[i - 2] <= MAX; i++)
        fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);
}

int main()
{
    precompute_fibonacci();

    int n;
    scanf("%d", &n);

    if(n == 0) //F(0)
        printf("0 0 0\n");
    else if(n == 1)//F(1) and F(2)
        printf("1 0 0\n");
    else if(n == 2) //F(3)
        printf("1 1 0\n");
    else
    {
        int index = 4;

        while(fibonacci[index] != n)
         index++;

        printf("%d %d %d\n",fibonacci[index - 1], fibonacci[index - 3], fibonacci[index - 4]);
    }

    return 0;
}
