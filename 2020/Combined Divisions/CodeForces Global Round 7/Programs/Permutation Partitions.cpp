#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

long long get_sum(long long n)
{
    return (n*(n + 1))/2;
}

int main()
{
    int no_of_elements, no_of_parts;
    cin >> no_of_elements >> no_of_parts;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <long long> indices;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] > no_of_elements - no_of_parts)
        {
            indices.push_back(i);
        }
    }
    
    sort(all(indices));
    
    long long best_sum = get_sum(no_of_elements) - get_sum(no_of_elements - no_of_parts);
    
    long long no_of_ways = 1;
    
    const long long MOD = 998244353;
    
    for(int i = 1; i < no_of_parts; i++)
    {   
        no_of_ways *= (indices[i] - indices[i - 1]);
        
        no_of_ways %= MOD;
    }
    
    cout << best_sum << " " << no_of_ways << "\n";
    return 0;
}
