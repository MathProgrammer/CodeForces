#include <iostream>
#include <vector>

using namespace std;

int possible(vector <int> &A, int x, int parity, int total_subsequence_length)
{
    int subsequence_length = 0;
    
    for(int i = 1; i < A.size() && subsequence_length < total_subsequence_length; i++)
    {
        if((subsequence_length + 1)%2 != parity)
        {   //cout << "Subsequence = " << subsequence_length << " i = " << i << "\n";
            subsequence_length++;
        }
        else
        {
            if(A[i] <= x)
            {   //cout << "Subsequence = " << subsequence_length << " i = " << i << "\n";
                subsequence_length++;
            }
        }
    }
    
    return (subsequence_length == total_subsequence_length);
}

int main()
{
    int no_of_elements, subsequence_length;
    cin >> no_of_elements >> subsequence_length;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int oo = 1e9 + 9;
    long long left = 0, right = oo;
    
    while(right - left > 1)
    {
        long long mid = (left + right)/2; //cout << "L = " << left << " R = " << right << "\n";
        
        if(possible(A, mid, 0, subsequence_length) || possible(A, mid, 1, subsequence_length))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    
    cout << right << "\n";
    
    return 0;
}
