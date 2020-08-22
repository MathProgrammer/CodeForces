#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 222;
long long max_till[MAX_N][MAX_N][MAX_N];

int any_two_zero(int r, int g, int b)
{
    int zeroes = (r == 0) + (g == 0) + (b == 0);
    
    return (zeroes >= 2);
}

int main()
{
    int red, green, blue;
    cin >> red >> green >> blue;
    
    vector <long long> R(red + 1);
    for(int i = 1; i <= red; i++)
    {
        cin >> R[i];
    }
    sort(all(R));
    
    vector <long long> G(green + 1);
    for(int i = 1; i <= green; i++)
    {
        cin >> G[i];
    }
    sort(all(G));
    
    vector <long long> B(blue + 1);
    for(int i = 1; i <= blue; i++)
    {
        cin >> B[i];
    }
    sort(all(B));
    
    for(int i = 0; i <= red; i++)
    {
        for(int j = 0; j <= green; j++)
        {
            for(int k = 0; k <= blue; k++)
            {
                if( (i == 0 && j == 0 && k == 0) || (any_two_zero(i, j, k)) )
                {
                    max_till[i][j][k] = 0;
                    continue;
                }
                
                if(i == 0)
                {
                    max_till[i][j][k] = G[j]*B[k] + max_till[i][j - 1][k - 1];
                    continue;
                }
                
                if(j == 0)
                {
                    max_till[i][j][k] = B[k]*R[i] + max_till[i - 1][j][k - 1];
                    continue;
                }
                
                if(k == 0)
                {   //cout << "R = " << R[i] << " and B = " << B[j] << "\n";
                    max_till[i][j][k] = R[i]*G[j] + max_till[i - 1][j - 1][k];
                    //cout << "F(" << i << "," << j << "," << k << ") = " << max_till[i][j][k] << "\n";
                    continue;
                }
                
                max_till[i][j][k] = R[i]*G[j] + max_till[i - 1][j - 1][k];
                
                max_till[i][j][k] = max(max_till[i][j][k], G[j]*B[k] + max_till[i][j - 1][k - 1]);
                
                max_till[i][j][k] = max(max_till[i][j][k], B[k]*R[i] + max_till[i - 1][j][k - 1]);
                
                //cout << "F(" << i << "," << j << "," << k << ") = " << max_till[i][j][k] << "\n";
            }
        }
    }
    
    cout << max_till[red][green][blue] << "\n";
    
    return 0;
}
