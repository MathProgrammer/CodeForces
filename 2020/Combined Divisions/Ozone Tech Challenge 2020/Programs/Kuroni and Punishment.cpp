#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>

using namespace std;

void factorise(set <long long> &F, long long n)
{
    if(n <= 1)
    {
        return;
    }
    //cout << "N = " << n << "\n";
    
    for(long long i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            F.insert(i);
            
            while(n%i == 0)
            {
                n /= i;
            }
        }
    }
    
    if(n > 1)
    {
        F.insert(n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int MAX_TRIES = 100;
    random_shuffle(A.begin() + 1, A.end());
    
    set <long long> factors;
    for(int i = 1; i <= MAX_TRIES && i <= no_of_elements; i++)
    {
        factorise(factors, A[i]);
        factorise(factors, A[i] - 1);
        factorise(factors, A[i] + 1);
    }
    
    long long minimum_moves = no_of_elements;
    for(auto it = factors.begin(); it != factors.end(); it++)
    {
        long long x = *it; //cout << "X = " << x << "\n";
        
        long long moves_here = 0;
        
        for(int i = 1; i <= no_of_elements; i++)
        {
            long long moves_for_this_elements = (x - A[i]%x);
            
            if(A[i] >= x)
            {
                moves_for_this_elements = min(moves_for_this_elements, A[i]%x);
            }
            
            moves_here += moves_for_this_elements; //cout << "Moves = " << moves_for_this_elements << "\n";
        }
        
        minimum_moves = min(minimum_moves, moves_here);
    }
    
    cout << minimum_moves << "\n";
    return 0;
}
