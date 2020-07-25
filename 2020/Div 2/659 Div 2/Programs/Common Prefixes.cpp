#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int NO_OF_ALPHABETS = 25;
    vector <string> S(no_of_elements + 5);
    for(int i = 1; i <= no_of_elements + 1; i++)
    {
        //S[i].resize(max ( max(A[i], 10), A[i - 1] ) );
                                          
        for(int j = 0; j < A[i - 1]; j++)
        {
            S[i] += S[i - 1][j]; //cout << S[i][j] << "\n";
        }
        
        if(i > no_of_elements)
        {
            if(S[i].size() == 0)
            {
                S[i] += (char)( 'a' + (i)%(NO_OF_ALPHABETS) );
            }
            continue;
        }
        
        
        for(int j = A[i - 1]; j < max(A[i], 1); j++)
        {//cout << "Reached j = " << (char)('a' + (i)%(NO_OF_ALPHABETS) ) << endl;
            S[i] += (char)('a' + (i)%(NO_OF_ALPHABETS) );
        }
    }
    
    for(int i = 1; i <= no_of_elements + 1; i++)
    {
        cout << S[i] << "\n";
    }
}


int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
