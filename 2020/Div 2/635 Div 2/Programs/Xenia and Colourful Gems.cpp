#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define all(v) (v).begin(), (v).end()
using namespace std;

long long square(long long n)
{
    return n*n;
}

void find_best(vector <long long> &X, vector <long long> &Y, vector <long long> &Z, long long &answer)
{
    for(int j = 1; j < Y.size(); j++)
    {
        int i = lower_bound(all(X), Y[j]) - X.begin();
        
        int k = lower_bound(all(Z), Y[j]) - Z.begin();
        
        if(i != X.size() && k != Z.size())
        {
            answer = min(answer, square(X[i] - Y[j]) + square(Y[j] - Z[k]) + square(Z[k] - X[i]));
        }
        
        if(i > 1 && k != Z.size())
        {
            i--;
            
            answer = min(answer, square(X[i] - Y[j]) + square(Y[j] - Z[k]) + square(Z[k] - X[i]));
        }
    }
}

void solve()
{
    int no_of_red, no_of_green, no_of_blue;
    cin >> no_of_red >> no_of_green >> no_of_blue;
    
    vector <long long> R(no_of_red + 1);
    for(int i = 1; i <= no_of_red; i++)
    {
        cin >> R[i];
    }
    sort(all(R));
    
    vector <long long> G(no_of_green + 1);
    for(int i = 1; i <= no_of_green; i++)
    {
        cin >> G[i];
    }
    sort(all(G));
    
    vector <long long> B(no_of_blue + 1);
    for(int i = 1; i <= no_of_blue; i++)
    {
        cin >> B[i];
    }
    sort(all(B));
    
    long long answer = LLONG_MAX; //cout << answer << "\n";
    find_best(R, G, B, answer); find_best(R, B, G, answer);
    
    find_best(G, R, B, answer); find_best(G, B, R, answer);
    
    find_best(B, G, R, answer); find_best(B, R, G, answer);
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
