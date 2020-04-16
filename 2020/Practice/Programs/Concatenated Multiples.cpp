#include <iostream>
#include <vector>
#include <map>

using namespace std;

int no_of_digits(int n)
{
    int count = 0;
    
    while(n)
    {
        count++;
        
        n /= 10;
    }
    //cout << "N = " << n << " Count = " << count << "\n";
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int MAX_DIGITS = 11;
    map <long long, int> frequency_mod[MAX_DIGITS];
    long long answer = 0;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(long long t = 10, d = 1; d < MAX_DIGITS; d++, t = (t*10)%k)
        {
            frequency_mod[d][ (A[i]*t)%k ]++;
            
            //cout << "D = " << d << " M = " << (A[i]*t)%k << " = " << frequency_mod[d][ (A[i]*t)%k ] << "\n";
        }
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long first_part_mod = (0 - A[i]%k + k)%k;
        
        //cout << "Need d = " << no_of_digits(A[i]) << " with M = " << first_part_mod << "\n";
        
        answer += frequency_mod[no_of_digits(A[i])][first_part_mod];
        //cout << "Answer = " << answer << "\n";
        
        long long t = 1;
        for(long long d = 1; d <= no_of_digits(A[i]) ;d++)
        {
            t = (t*10)%k;
        }
        
        if( (t*A[i] + A[i])%k == 0 )
        {   //cout << "Self!\n";
            answer--;
        }
        
        //cout << "Answer = " << answer << "\n";
    }
    cout << answer << "\n";
    
    return 0;
}
