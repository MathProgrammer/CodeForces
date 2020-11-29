#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(int n, int bit)
{
    return ( (n&(1LL << bit)) != 0 );
}

int msb(int n)
{
    const int NO_OF_BITS = 31;
    
    for(int i = NO_OF_BITS; i >= 0; i--)
    {
        if(is_bit_set(n, i))
        {
            return i;
        }
    }
    
    return 0;
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
    
    int possible = false;
    
    const int NO_OF_BITS = 31;
    vector <int> msb_frequency(NO_OF_BITS + 1, 0);
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        msb_frequency[msb(A[i])]++;
    }
    
    int answer = no_of_elements + 1;
    for(int bit = 0; bit < NO_OF_BITS; bit++)
    {
        if(msb_frequency[bit] >= 3)
        {
            possible = true;
            answer = 1;
            
            break;
        }
    }
    
    vector <int> prefix_xor(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_xor[i] = prefix_xor[i - 1]^A[i];
    }
    
    for(int i = 1; i < no_of_elements && answer > 1; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            int prefix = prefix_xor[i]^prefix_xor[j];
            int prefix_operations = (i - 1) - j;
            
            for(int k = i + 1; k <= no_of_elements; k++)
            {
                int suffix = prefix_xor[k]^prefix_xor[i];
                int suffix_operations = k - (i + 1);
                
                if(prefix > suffix)
                {
                    possible = true;
                    answer = min(answer, prefix_operations + suffix_operations);
                }
            }
        }
    }
    
    cout << (possible ? answer : -1) << "\n";
    return 0;
}
