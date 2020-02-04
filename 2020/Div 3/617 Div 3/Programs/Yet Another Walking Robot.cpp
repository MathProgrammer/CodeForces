#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;
    
    map <pair <int, int>, int> position;
    int minimum_distance = length + 1, left = 0, right = length + 1;
    
    position[make_pair(0, 0)] = -1;
    for(int x = 0, y = 0, i = 0; i < length; i++)
    {
        switch(S[i])
        {
            case 'L' : x++; break;
            case 'R' : x--; break;
            case 'U' : y++; break;
            case 'D' : y--; break;
        }
        
        if(position.count(make_pair(x, y)) != 0)
        {
            int last_i = position[make_pair(x, y)] + 1;
            
            int distance = (i) - (last_i - 1);
            
            if(distance < minimum_distance)
            {
                minimum_distance = distance;
                left = last_i ; right = i;
            }
        }
        
        position[make_pair(x, y)] = i;
    }
    
    if(minimum_distance > length)
    {
        cout << "-1\n";
        return;
    }
    
    cout << left + 1 << " " << right + 1 << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}

