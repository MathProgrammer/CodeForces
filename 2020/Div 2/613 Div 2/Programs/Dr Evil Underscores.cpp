#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL << bit)) != 0 );
}

long long solve(int bit, vector <long long> &A)
{
    if(bit < 0 || A.size() == 0)
    {
        return 0;
    }
    
    vector <long long> set, unset;
    for(int i = 0; i < A.size(); i++)
    {
        if(is_bit_set(A[i], bit))
        {
            set.push_back(A[i]);
        }
        else
        {
            unset.push_back(A[i]);
        }
    }
    
    if(set.size() == 0)
    {
        return solve(bit - 1, unset);
    }
    
    if(unset.size() == 0)
    {
        return solve(bit - 1, set);
    }
    
    return ( (1LL << bit) + min(solve(bit - 1, set), solve(bit - 1, unset)) );
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    long long answer = solve(31, A);
    
    cout << answer << "\n";
    
    return 0;
}
