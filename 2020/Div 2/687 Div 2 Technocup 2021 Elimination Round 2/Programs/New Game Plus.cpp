#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, no_of_resets;
    cin >> no_of_elements >> no_of_resets;
    
    int no_of_stacks = no_of_resets + 1;
    
    vector <long long> A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    sort(all(A));
    
    vector <long long> suffix_sum(no_of_elements + 5, 0);
    for(int i = no_of_elements - 1; i >= 0; i--)
    {
        suffix_sum[i] = suffix_sum[i + 1] + A[i];
    }
    
    long long total = 0;
    
    //Distribute Negative Integers Evenly
    for(int i = 0; i < no_of_elements; i++)
    {
        total += A[i]*(i/no_of_stacks);
    }
    
    for(int i = no_of_elements - 1; i >= 0; i--)
    {
        if(i%no_of_stacks == 0) //This element stays on same level
        {
            continue;
        }
        //cout << "i = " << i << " Total = " << total  << " and suffix = " << suffix_sum[i] << "\n";
        total = max(total, total + suffix_sum[i]); //cout << "total = " << total << "\n";
    }
    
    cout << total << "\n";
    return 0;
}
