#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_terms_A, no_of_terms_B, p;
    cin >> no_of_terms_A >> no_of_terms_B >> p;
    
    vector <int> A(no_of_terms_A + 1);
    for(int i = 0; i < no_of_terms_A; i++)
    {
        cin >> A[i];
    }
    
    vector <int> B(no_of_terms_B + 1);
    for(int i = 0; i < no_of_terms_B; i++)
    {
        cin >> B[i];
    }
    
    int first_A = 0;
    while(A[first_A]%p == 0)
    {
        first_A++;
    }
    
    int first_B = 0;
    while(B[first_B]%p == 0)
    {
        first_B++;
    }
    
    int answer = first_A + first_B;
    cout << answer << "\n";
    
    return 0;
}
