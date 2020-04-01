#include <iostream>

using namespace std;

const int MAX_N = 3 + 2, MAX_BITS = 25;
int matrix[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int is_bit_set(int n, int bit)
{
    return ((n&(1LL << bit)) != 0);
}

int all_ones(int n)
{
    return ( (n&(n + 1)) == 0);
}

int get_msb(int n)
{
    for(int bit = MAX_BITS; bit >= 0; bit--)
    {
        if(is_bit_set(n, bit))
        {
            return bit;
        }
    }
    
    return 0;
}

int complete(int n)
{
    int most_significant_bit = get_msb(n);
    
    int complete_n = 0;
    for(int bit = most_significant_bit; bit >= 0; bit--)
    {
        complete_n |= (1LL << bit);
    }
    
    return complete_n;
}

int main()
{
    int n;
    cin >> n;
    
    if(n == 0)
    {
        cout << "1 1\n";
        
        cout << "1\n";
        
        return 0;
    }
    
    int full_form = (all_ones(n) ? 4*n + 3: 2*complete(n) + 1);
    int complement = full_form - n;
    int msb = (1 << get_msb(full_form));
                     
    matrix[1][1] = full_form; matrix[1][2] = n; matrix[1][3] = complement;
    matrix[2][1] = msb;       matrix[2][2] = n; matrix[2][3] = complement;
    matrix[3][1] = full_form; matrix[3][2] = full_form; matrix[3][3] = n;
    
    cout << "3 3\n";
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        
        cout << "\n";
    }
    
    /*dp[0][1] = matrix[1][1];
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            dp[i][j] = max(matrix[i][j]&dp[i - 1][j], matrix[i][j]&dp[i][j - 1]);
            
            cout << dp[i][j] << " ";
        }
        
        cout << "\n";
    }*/
    return 0;
}
