#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(long long n, int bit)
{
    return ((n & (1LL << bit)) != 0);
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int NO_OF_BITS = 31;
    vector <int> bit_frequency(NO_OF_BITS + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int b = 0; b <= NO_OF_BITS; b++)
        {
            if(is_bit_set(A[i], b))
            {
                bit_frequency[b]++;
            }
        }
    }
    
    long long answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long answer_here = 0;
        
        for(int b = 0; b <= NO_OF_BITS; b++)
        {
            if(is_bit_set(A[i], b) && bit_frequency[b] == 1)
            {
                answer_here |= (1LL << b);
            }
        }
        
        if(answer_here > answer)
        {
            swap(A[i], A[1]);
            
            answer = answer_here;
        }
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i] << " ";
    }
    
    cout << "\n";
    return 0;
}
