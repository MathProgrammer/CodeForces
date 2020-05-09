#include <iostream>
#include <vector>

using namespace std;

long long ceil(long long n, long long d)
{
    return (n/d) + (n%d != 0);
}

int main()
{
    long long H, no_of_elements;
    cin >> H >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <long long> prefix_sum(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_sum[i] = A[i] + prefix_sum[i - 1];
    }
    
    long long answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(H + prefix_sum[i] <= 0)
        {
            answer = i;
            break;
        }
    }
    
    long long sum = abs(prefix_sum[no_of_elements]);
    
    if(answer != 0)
    {
        cout << answer << "\n";
        
        return 0;
    }
    else if(prefix_sum[no_of_elements] >= 0)
    {
        cout << "-1\n";
        
        return 0;
    }
    
    answer = 2e18;
    for(int i = 1; i <= no_of_elements; i++)
    {
        //H + x.P[n]  + P[i] = 0
        long long rounds_required = ceil(H + prefix_sum[i], sum);
        
        answer = min(answer, rounds_required*no_of_elements + i);
    }
    
    cout << answer << "\n";
    return 0;
}
