#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ceil(int a, int b)
{
    return (a/b) + (a%b != 0);
}

int main()
{
    int no_of_elements, attack, opponent_attack, secrets;
    cin >> no_of_elements >> attack >> opponent_attack >> secrets;
    
    vector <int> H(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> H[i];
    }
    
    vector <int> skips_required(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        H[i] %= (attack + opponent_attack);
        
        if(H[i] == 0)
        {
            H[i] = (attack + opponent_attack);
        }
        
        H[i] = max(H[i] - attack, 0);
        
        skips_required[i] = ceil(H[i], attack);
    }
    
    sort(skips_required.begin(), skips_required.end());
    
    long long total_skips = 0, points = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(total_skips + skips_required[i] > secrets)
        {
            break;
        }
        
        total_skips += skips_required[i];
        
        points++;
    }
    
    cout << points << "\n";
    return 0;
}
