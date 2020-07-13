#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long choose_2(long long n)
{
    return (n*(n - 1))/2;
}

int main()
{
    int no_of_elements, p, k;
    cin >> no_of_elements >> p >> k;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    map <long long, int> value_frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long value = (A[i]*A[i])%p;
        value = (value*A[i])%p;
        value = (value*A[i])%p;
        
        value = (value - k*A[i])%p;
        
        value = (value + p)%p;
        
        value_frequency[value]++;
    }
    
    long long no_of_pairs = 0;
    for(auto it = value_frequency.begin(); it != value_frequency.end(); it++)
    {
        no_of_pairs += choose_2(it->second);
    }
    
    cout << no_of_pairs << "\n";
    
    return 0;
}
