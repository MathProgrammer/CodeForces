#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    long long no_of_operations, x;
    cin >> no_of_operations >> x;
    
    map <long long, int> is_present;
    map <long long, int> last;
    
    int mex = 0;
    for(int i = 1; i <= no_of_operations; i++)
    {
        long long current;
        cin >> current;
        
        current %= x;
        
        is_present[x*last[current] + current] = true;
        last[current]++;
        
        while(is_present[mex])
        {
            mex++;
        }
        
        cout << mex << "\n";
    }
    
    return 0;
}
