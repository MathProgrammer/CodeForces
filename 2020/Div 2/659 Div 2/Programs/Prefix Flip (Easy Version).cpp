#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    string A, B;
    int length;
    cin >> length >> A >> B;
    
    vector <int> moves;
    
    for(int i = A.size() - 1; i >= 0; i--)
    {
        if(A[i] != B[i])
        {
            moves.push_back(i + 1);
            moves.push_back(1);
            moves.push_back(i + 1);
        }
    }
    
    cout << moves.size() << " ";
    
    for(int i = 0; i < moves.size(); i++)
    {
        cout << moves[i] << " ";
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
