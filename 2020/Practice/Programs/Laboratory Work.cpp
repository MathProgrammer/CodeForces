#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_points;
    cin >> no_of_points;
    
    vector <int> X(no_of_points);
    for(int i = 0; i < no_of_points; i++)
    {
        cin >> X[i];
    }
    
    sort(all(X));
    
    int minimum = X[0];
    
    const int MAX_TYPES = 3;
    vector <int> frequency(MAX_TYPES, 0);
    for(int i = 0; i < no_of_points; i++)
    {
        frequency[X[i] - minimum]++;
    }
    
    vector <int> new_frequency(MAX_TYPES, 0);
    for(int t = 0; t < MAX_TYPES; t++)
    {
        new_frequency[t] = frequency[t];
    }
    
    if(frequency[1]/2 > min(frequency[0], frequency[2]) && frequency[2] > 0 && frequency[0] > 0)
    {
        new_frequency[0] = frequency[0] + frequency[1]/2;
        new_frequency[1] = frequency[1]%2;
        new_frequency[2] = frequency[2] + frequency[1]/2;
    }
    else if(frequency[1]/2 <= min(frequency[0], frequency[2]))
    {
        new_frequency[0] = frequency[0] - min(frequency[0], frequency[2]);
        new_frequency[1] = frequency[1] + 2*min(frequency[0], frequency[2]);
        new_frequency[2] = frequency[2] - min(frequency[0], frequency[2]);
    }
    
    int equal_elements = 0;
    for(int t = 0; t < MAX_TYPES; t++)
    {
        equal_elements += min(frequency[t], new_frequency[t]);
    }
    
    cout << equal_elements << "\n";
    
    for(int t = 0; t < MAX_TYPES; t++)
    {
        for(int i = 0; i < new_frequency[t]; i++)
        {
            cout << minimum + t << " ";
        }
    }
    
    cout << "\n";
    
    return 0;
}
