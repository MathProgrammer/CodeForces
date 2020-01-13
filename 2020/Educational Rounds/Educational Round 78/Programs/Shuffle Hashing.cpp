#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    string password, hash;
    cin >> password >> hash;
    
    const int NO_OF_ALPHABETS = 26;
    vector <int> password_frequency(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < password.size(); i++)
    {
        password_frequency[password[i] - 'a']++;
    }
    
    int possible = false;
    for(int i = 0; i + password.size() <= hash.size() && !possible; i++)
    {
        vector <int> hash_frequency(NO_OF_ALPHABETS, 0);

        for(int j = 0; j < password.size(); j++)
        {
            hash_frequency[hash[i + j] - 'a']++;
        }
       
        possible = true;
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            if(password_frequency[alpha] != hash_frequency[alpha])
            { 
                possible = false;
            }
        }
        
    }
    
    cout << (possible ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
