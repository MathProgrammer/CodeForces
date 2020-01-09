#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define all(v) (v).begin(), (v).end()
using namespace std;

int min_3(int a, int b, int c)
{
    return min(a, min(b, c));
}

int maximise_houses(int n, vector <int> X)
{
    set <int> S;
    for(int i = 1; i <= n; i++)
    {
        if(S.find(X[i] - 1) == S.end())
        {
            S.insert(X[i] - 1);
        }
        else if(S.find(X[i]) == S.end())
        {
            S.insert(X[i]);
        }
        else if(S.find(X[i] + 1) == S.end())
        {
            S.insert(X[i] + 1);
        }
    }
    
    return S.size();
}

int minimise_houses(int n, vector <int> X)
{
    vector <vector <int> > minimum_houses(n + 1, vector <int> (4, 0));
    
    const int BACKWARD = 0, SAME = 1, FORWARD = 2;
    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
        {
            minimum_houses[i][BACKWARD] = minimum_houses[i][SAME] = minimum_houses[i][FORWARD] = 1;
            
            //continue;
        }
        else if(X[i - 1] < X[i] - 2)
        {
            minimum_houses[i][BACKWARD] =
            minimum_houses[i][SAME] =
            minimum_houses[i][FORWARD] = 1 + min_3(minimum_houses[i - 1][BACKWARD], minimum_houses[i - 1][SAME], minimum_houses[i - 1][FORWARD]);
            
            //continue;
        }
        else if(X[i - 1] + 1 == X[i] - 1)
        {
            minimum_houses[i][BACKWARD] = min_3(minimum_houses[i - 1][FORWARD], 1 + minimum_houses[i - 1][SAME], 1 + minimum_houses[i - 1][BACKWARD]);
            
            minimum_houses[i][SAME] =
            minimum_houses[i][FORWARD] = 1 + min_3(minimum_houses[i - 1][BACKWARD], minimum_houses[i - 1][SAME], minimum_houses[i - 1][FORWARD]);
            
            //continue;
        }
        else if(X[i - 1] + 1 == X[i])
        {
            minimum_houses[i][BACKWARD] = min_3(1 + minimum_houses[i - 1][BACKWARD], minimum_houses[i - 1][SAME], 1 + minimum_houses[i - 1][FORWARD]);
            
            minimum_houses[i][SAME] = min_3(1 + minimum_houses[i - 1][BACKWARD], 1 + minimum_houses[i - 1][SAME], minimum_houses[i - 1][FORWARD]);
            
            minimum_houses[i][FORWARD] = 1 + min_3(minimum_houses[i - 1][BACKWARD],
                                                   minimum_houses[i - 1][SAME],
                                                   minimum_houses[i - 1][FORWARD]);
            
            //continue;
        }
        else if(X[i - 1] == X[i])
        {
            minimum_houses[i][BACKWARD] = minimum_houses[i - 1][BACKWARD];
            minimum_houses[i][SAME] = minimum_houses[i - 1][SAME];
            minimum_houses[i][FORWARD] = minimum_houses[i - 1][FORWARD];
            
            //continue;
        }
    }
    
    return min_3(minimum_houses[n][BACKWARD], minimum_houses[n][SAME], minimum_houses[n][FORWARD]);
}

int main()
{
    int no_of_friends;
    cin >> no_of_friends;
    
    vector <int> X(no_of_friends + 1);
    for(int i = 1; i <= no_of_friends; i++)
    {
        cin >> X[i];
    }
    
    sort(all(X));
    
    int minimum_houses = minimise_houses(no_of_friends, X);
    int maximum_houses = maximise_houses(no_of_friends, X);
    
    cout << minimum_houses << " " << maximum_houses << "\n";
    return 0;
}
