#include <iostream>
#include <vector>

using namespace std;

long long no_of_elements, total_steps;
vector <long long> A, B;

long long no_of_steps(long long x)
{
    long long steps = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long left = 0, right = A[i] + 1;
        
        //Left is always possible, right is not
        while(right - left > 1)
        {
            long long mid = (left + right)/2;
            
            long long smallest_contribution = A[i] - 3*mid*mid+ 3*mid - 1;
            
            if(smallest_contribution > x)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        
        B[i] = left;
        
        steps += left;
    }
    
    return steps;
}

int main()
{
    cin >> no_of_elements >> total_steps;
    
    A.resize(no_of_elements + 1);
    B.resize(no_of_elements + 1);
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    // > Right is always possible, <= Left is never possible
    long long left = -3e18, right = 3e18;
    while(right - left > 1)
    {
        long long mid = (left + right)/2;
        
        if(no_of_steps(mid) <= total_steps)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    
    long long final_steps = no_of_steps(right);
    
    for(int i = 1; i <= no_of_elements && final_steps < total_steps; i++)
    {
        if(B[i] == A[i])
        {
            continue;
        }
        
        long long new_b = B[i] + 1;
        if(A[i] - 3*new_b*new_b + 3*new_b - 1 == right)
        {
            B[i]++;
            final_steps++;
        }
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << B[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
