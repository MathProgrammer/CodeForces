#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int length, k;
    string A, B;
    cin >> length >> k >> A >> B;
    
    const int NO_OF_ALPHABETS = 26;
    vector <int> frequency_A(NO_OF_ALPHABETS + 1, 0), frequency_B(NO_OF_ALPHABETS + 1, 0);
    for(int i = 0; i < length; i++)
    {
        frequency_A[A[i] - 'a']++;
        frequency_B[B[i] - 'a']++;
    }
    
    int possible = true;
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        if(frequency_A[alpha]%k != frequency_B[alpha]%k)
        {
            possible = false;
        }
    }
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        if(frequency_B[alpha] > frequency_A[alpha])
        {
            possible = false;
            break;
        }
        
        int extra = frequency_A[alpha] - frequency_B[alpha];
        
        frequency_A[alpha + 1] += extra;
    }
    
    cout << (possible ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
