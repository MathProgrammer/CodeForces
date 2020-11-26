#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int no_of_elements;
vector <int> permutation;
vector <int> position;

int get_count(int left_1, int right_1, int left_2, int right_2, int total_sum)
{
    if(right_2 - left_2 < right_1 - left_1)
    {
        swap(right_1, right_2);
        swap(left_1, left_2);
    }
    
    int count = 0;
    for(int i = left_1; i <= right_1; i++)
    {
        int remaining = total_sum - permutation[i];
        
        if(1 <= remaining && remaining <= no_of_elements &&
           left_2 <= position[remaining] && position[remaining] <= right_2)
        {
            count++;
        }
    }
    
    return count;
}

int main()
{
    cin >> no_of_elements;
    
    permutation.resize(no_of_elements + 1);
    position.resize(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> permutation[i];
        
        position[permutation[i]] = i;
    }
    
    vector <int> left_border(no_of_elements + 1);
    stack <pair <int, int> > left_S;
    left_S.push(make_pair(no_of_elements + 1, 0));
    for(int i = 1; i <= no_of_elements; i++)
    {
        while(left_S.top().first < permutation[i])
        {
            left_S.pop();
        }
        
        left_border[i] = left_S.top().second + 1;
        
        left_S.push(make_pair(permutation[i], i));
    }
    
    stack <pair <int, int> > right_S;
    vector <int> right_border(no_of_elements + 1);
    right_S.push(make_pair(no_of_elements + 1, no_of_elements + 1));
    for(int i = no_of_elements; i >= 1; i--)
    {
        while(right_S.top().first < permutation[i])
        {
            right_S.pop();
        }
        
        right_border[i] = right_S.top().second - 1;
        
        right_S.push(make_pair(permutation[i], i));
    }
    
    int no_of_special_segments = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        no_of_special_segments += get_count(left_border[i], i - 1, i + 1, right_border[i], permutation[i]); 
    }
    
    cout << no_of_special_segments << "\n";
    return 0;
}
