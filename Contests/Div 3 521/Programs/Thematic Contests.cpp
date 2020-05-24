#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int get_count_ending(int ending, vector <int> &A)
{
    int count = 0;
    
    for(int i = A.size() - 1, current = ending; i >= 0 && A[i] >= current; i--)
    {
        count += current;
        
        if(current%2 == 1)
        {
            break;
        }
        
        current /= 2;
    }
    
    return count;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    map <int, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        frequency[A[i]]++;
    }
    
    vector <int> frequencies;
    for(auto it = frequency.begin(); it != frequency.end(); it++)
    {
        frequencies.push_back(it->second);
    }
    
    sort(all(frequencies));
    
    int maximum = 0;
    for(int i = 0; i <= frequencies.back(); i++)
    {
        maximum = max(maximum, get_count_ending(i, frequencies));
    }
    
    cout << maximum << "\n";
    return 0;
}
