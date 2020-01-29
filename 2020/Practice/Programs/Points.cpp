#include <iostream>
#include <vector>

using namespace std;

long long calculate(vector <long long> &P, int n)
{
    long long squares = 0;
    for(int i = 1; i <= n; i++)
    {
        squares += (n - 1)*P[i]*P[i];
    }
    
    long long sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += P[i];
    }
    
    long long linear_term = 0;
    for(int i = 1; i <= n; i++)
    {
        linear_term += P[i]*(sum - P[i]);// 2*P[i]*P[i];
    }
    
    return (squares - linear_term);
}

int main()
{
    int no_of_points;
    cin >> no_of_points;
    
    vector <long long> X(no_of_points + 1);
    vector <long long> Y(no_of_points + 1);
    
    for(int i = 1; i <= no_of_points; i++)
    {
        cin >> X[i] >> Y[i];
    }
    
    long long distance = calculate(X, no_of_points) + calculate(Y, no_of_points);
    
    cout << distance << "\n";
    return 0;
}

