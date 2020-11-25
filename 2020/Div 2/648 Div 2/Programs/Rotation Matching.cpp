#include <iostream>
#include <vector>

using namespace std;

int calculate_left_shifts(int source, int target, int no_of_elements)
{
    if(target < source)
    {
        return (source - target);
    }
    
    return (source + (no_of_elements - target));
}

int calculate_right_shifts(int source, int target, int no_of_elements)
{
    if(source < target)
    {
        return (target - source);
    }
    
    return ((no_of_elements - source) + target);
}

int get_matches(vector <int> &A, vector <int> &B)
{
    int no_of_elements = A.size() - 1;
    vector <int> B_index(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        B_index[B[i]] = i;
    }
    
    vector <int> mismatches_after_left_shift(no_of_elements + 1, no_of_elements);
    vector <int> mismatches_after_right_shift(no_of_elements + 1, no_of_elements);
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        int j = B_index[A[i]];
        
        int left_shifts = calculate_left_shifts(i, j, no_of_elements);
        int right_shifts = calculate_right_shifts(i, j, no_of_elements);
        
        mismatches_after_left_shift[left_shifts]--;
        mismatches_after_right_shift[right_shifts]--;
    }
    
    vector <int> matches_after_left_shift(no_of_elements + 1, 0);
    vector <int> matches_after_right_shift(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        matches_after_left_shift[i] = no_of_elements - mismatches_after_left_shift[i];
        matches_after_right_shift[i] = no_of_elements - mismatches_after_right_shift[i];
    }
    
    int maximum_matches = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        maximum_matches = max(maximum_matches, matches_after_left_shift[i]);
        maximum_matches = max(maximum_matches, matches_after_right_shift[i]);
    }
    
    return maximum_matches;
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
    
    vector <int> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
    }
    
    int maximum_matches = max(get_matches(A, B), get_matches(B, A));
    
    cout << maximum_matches << "\n";
    
    return 0;
}
