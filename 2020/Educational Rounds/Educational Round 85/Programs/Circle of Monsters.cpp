#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_monsters;
    scanf("%d", &no_of_monsters);
    
    vector <long long> A(no_of_monsters + 1), B(no_of_monsters + 1);
    for(int i = 1; i <= no_of_monsters; i++)
    {
        scanf("%I64d %I64d", &A[i], &B[i]);
    }
    
    long long total = 0;
    for(int i = 1; i <= no_of_monsters; i++)
    {
        if(i == 1)
        {
            total += (B[no_of_monsters] >= A[1] ? 0 : A[1] - B[no_of_monsters]);
            
            continue;
        }
        
        total += (B[i - 1] >= A[i] ? 0 : A[i] - B[i - 1]);
    }
    
    long long effective_hit = max(A[1] - B[no_of_monsters], 0LL);
    long long best_first = A[1] - effective_hit;
    for(int i = 2; i <= no_of_monsters; i++)
    {
        effective_hit = max(A[i] - B[i - 1], 0LL);
        
        best_first = min(best_first, A[i] - effective_hit);
    }
    
    total += best_first;
    
    printf("%I64d\n", total);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
