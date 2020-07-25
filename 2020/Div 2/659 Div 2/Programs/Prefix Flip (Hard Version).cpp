#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    string A, B;
    int length;
    cin >> length >> A >> B;
    
    A += '0', B += '0';
    
    vector <int> moves_A, moves_B;
    
    for(int i = 1; i <= length; i++)
    {
        if(A[i] != A[i - 1])
        {
            moves_A.push_back(i);
        }
        
        if(B[i] != B[i - 1])
        {
            moves_B.push_back(i);
        }
    }
    
    cout << moves_A.size() + moves_B.size() << " ";
    
    for(int i = 0; i < moves_A.size(); i++)
    {
        cout << moves_A[i] << " ";
    }
    
    for(int i = moves_B.size() - 1; i >= 0; i--)
    {
        cout << moves_B[i] << " ";
    }
    
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
