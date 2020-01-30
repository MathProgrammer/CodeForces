#include <iostream>
#include <cstdio>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    
    int no_of_1s = 0, no_of_7s = 0;
    
    if(n%2 == 0)
    {
        no_of_1s = n/2;
    }
    else
    {
        no_of_1s = (n - 3)/2;
        no_of_7s = 1;
    }
    
    if(no_of_7s > 0)
    {
        printf("7");
    }
    
    for(int i = 1; i <= no_of_1s; i++)
    {
        printf("1");
    }
    
    printf("\n");
    
    return;
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
