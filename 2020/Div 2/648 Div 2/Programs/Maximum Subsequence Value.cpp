#include <iostream>
#include <vector>
#include <set>

using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL << bit)) != 0 );
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    long long answer = 0;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int j = i; j <= no_of_elements; j++)
        {
            for(int k = j; k <= no_of_elements; k++)
            {
                answer = max(answer, A[i]|A[j]|A[k]);
            }
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
