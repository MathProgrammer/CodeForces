#include <iostream>
#include <vector>

using namespace std;

int some_non_zero(vector <int> &A)
{
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > 0)
        {
            return true;
        }
    }
    
    return false;
}

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL << bit)) != 0);
}

int main()
{
    long long array_xor, array_sum;
    cin >> array_xor >> array_sum;
    
    if(array_xor > array_sum || (array_xor%2 != array_sum%2))
    {
        cout << "-1\n";
        
        return 0;
    }
    
    if(array_xor == array_sum)
    {
        if(array_xor == 0)
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
            cout << array_xor << "\n";
        }
       
        return 0;
    }
    
    const int MAX_BITS = 63;
    vector <int> frequency(MAX_BITS, 0);
    for(int bit = 0; bit < MAX_BITS; bit++)
    {
        if(is_bit_set(array_xor, bit))
        {
            array_sum -= (1LL << bit);
            
            frequency[bit]++;
        }
    }
    
    for(int bit = 0; bit < MAX_BITS; bit++)
    {
        if(is_bit_set(array_sum, bit))
        {
            int best_spot = max(bit - 1, 0);
            long long best_no_of_terms = frequency[best_spot] + 2;
            
            for(int i = bit - 1; i >= 0; i--)
            {
                if(frequency[i] + (1LL << (bit - i)) <= best_no_of_terms)
                {
                    best_no_of_terms = frequency[i] + (1LL << (bit - i));
                    
                    best_spot = i;
                }
            }
            
            frequency[best_spot] += (1LL << (bit - best_spot));
            
            array_sum -= (1LL << bit);
        }
    }
    
    vector <long long> A;
    while(some_non_zero(frequency))
    {
        long long current = 0;
        
        for(int bit = 0; bit < MAX_BITS; bit++)
        {
            if(frequency[bit] > 0)
            {
                current |= (1LL << bit);
                
                frequency[bit]--;
            }
        }
        
        A.push_back(current);
    }
    
    long long xorr = 0, sum = 0;
    cout << A.size() << "\n";
    for(int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
        xorr ^= A[i];
        sum += A[i];
    }
   
    cout << "\n";
    
    return 0;
}
