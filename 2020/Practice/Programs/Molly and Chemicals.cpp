#include <iostream>
#include <vector>
#include <map>

using namespace std;

void precompute(vector <long long> &P, long long k)
{
    P.push_back(1);
    
    if(k == 0 || k == 1)
    {
        return;
    }
    
    if(k == -1)
    {
        P.push_back(-1);
        return;
    }
    
    long long oo = 1e14;
    
    while(abs(P.back()) <= oo)
    {   //cout << P.back() << "\n";
        P.push_back(P.back()*k);
    }
}

int main()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    vector <long long> powers;
    precompute(powers, k);
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    map <long long, int> prefix_sum_frequency;
    long long prefix = 0;
    prefix_sum_frequency[prefix] = 1;
    
    long long no_of_segments = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix += A[i];
        
        for(int j = 0; j < powers.size(); j++)
        {
            no_of_segments += prefix_sum_frequency[prefix - powers[j]];
        }
        
        prefix_sum_frequency[prefix]++;
    }
    
    cout << no_of_segments << "\n";
    
    return 0;
}
