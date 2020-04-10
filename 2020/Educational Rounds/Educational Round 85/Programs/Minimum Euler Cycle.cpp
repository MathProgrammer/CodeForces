#include <cstdio>

using namespace std;

void solve()
{
    int n;
    long long left, right;
    scanf("%d %I64d %I64d",&n, &left, &right);
    
    long long segment = 0, in_point = 0;
    for(long long i = 1, sum = 0; i <= n; i++)
    {
        long long new_sum = sum + 2*(n - i);
        
        if(i == n)
        {
            new_sum++;
        }
        
        if(new_sum >= left)
        {
            segment = i;
            
            in_point = (left - sum)/2 + i + (left - sum)%2;
            
            break;
        }
        
        sum = new_sum;
    }
    
    for(long long i = left; i <= right; )
    {
        if(segment == n)
        {
            printf("1 ");
            
            break;
        }
        
        if(i%2 == 0)
        {
            printf("%I64d ", in_point);
            
            in_point++;
            
            i++;
        }
        else
        {
            printf("%I64d ", segment);
            
            i++;
            
            if(i > right)
            {
                break;
            }
            
            printf("%I64d ", in_point);
            
            in_point++;
            
            i++;
        }
        
        if(in_point == n + 1)
        {
            segment++;
            
            in_point = segment + 1;
        }
    }
    
    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    
    while(no_of_test_cases--)
    {
        solve();
    }
    
    return 0;
}
