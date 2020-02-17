#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 205, UNCOLOURED = -1, RED = 0, BLUE = 1;
vector <int> graph[MAX_N];

int other(int c)
{
    return (c == RED ? BLUE : RED);
}

int main()
{
    int length;
    string S;
    
    cin >> length >> S;
    
    vector <int> colour(length, UNCOLOURED);
    for(int i = 0; i < length; i++)
    {
        if(colour[i] == UNCOLOURED)
        {
            colour[i] = RED;
        }
        
        for(int j = i + 1; j < length; j++)
        {
            if(S[j] < S[i] && colour[j] == UNCOLOURED)
            {
                colour[j] = other(colour[i]);
                
                continue;
            }
            
            if(S[j] < S[i] && colour[i] == colour[j])
            {
                cout << "NO\n";
                
                return 0;
            }
        }
    }
    
    cout << "YES\n";
    for(int i = 0; i < length; i++)
    {
        cout << colour[i];
    }
    cout << "\n";

    return 0;
}
