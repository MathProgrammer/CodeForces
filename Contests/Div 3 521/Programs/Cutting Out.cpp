#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map <int, int> frequency;
vector <int> A;

int possible(int no_of_arrays, int length, vector <int> &answer)
{
    vector <int> filled;
    
    for(auto it = frequency.begin(); it != frequency.end() && filled.size() < length; it++)
    {
        int required_frequency = (it->second)/no_of_arrays;
        
        for(int i = 1; i <= required_frequency; i++)
        {
            filled.push_back(it->first);
        }
    }
    
    if(filled.size() >= length)
    {
        answer = filled;
    }
    
    return (filled.size() >= length);
}

int main()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    A.resize(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
     
    for(int i = 1; i <= no_of_elements; i++)
    {
        frequency[A[i]]++;
    }
    
    //L is always possible, R is always not possible
    vector <int> answer;
    int left = 0, right = no_of_elements + 1;
    while(right - left > 1)
    {
        int mid = (left + right)/2;
        
        if(possible(mid, k, answer))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
        
    for(int i = 0; i < k; i++)
    {
        cout << answer[i] << " ";
    }
    
    cout << "\n";
    return 0;
}
