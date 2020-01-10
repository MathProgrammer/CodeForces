#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int sort_by_frequency(vector <int> &A, vector <int> &B)
{
    const int NO_OF_ALPHABETS = 26;
    
    int a_sum = 0, b_sum = 0;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        a_sum += A[i];
        b_sum += B[i];
    }
    
    return (b_sum > a_sum);
}

int main()
{
    int length;
    cin >> length;
    
    const int NO_OF_ALPHABETS = 26;
    cout << "? 1 " << length << endl;
    
    multiset <vector <int> >subarray;
    for(int i = 1; i <= length; i++)
    {
        for(int j = i; j <= length; j++)
        {
            string S;
            cin >> S;
            
            if(length == 1)
            {
                cout << "! " << S << endl;
                
                return 0;
            }
            
            vector <int> frequency(NO_OF_ALPHABETS, 0);
            for(int k = 0; k < S.size(); k++)
            {
                frequency[S[k] - 'a']++;
            }
            
            subarray.insert(frequency);
        }
    }
    
    cout << "? 2 " << length << endl;
    for(int i = 2; i <= length; i++)
    {
        for(int j = i; j <= length; j++)
        {
            string S;
            cin >> S;
            
            vector <int> frequency(NO_OF_ALPHABETS, 0);
            for(int k = 0; k < S.size(); k++)
            {
                frequency[S[k] - 'a']++;
            }
            
            subarray.erase(subarray.find((frequency)));
        }
    }
    
    vector <vector <int> >subarrays_from_1;
    for(auto it = subarray.begin(); it != subarray.end(); it++)
    {
        subarrays_from_1.push_back(*it);
    }
    
    sort(all(subarrays_from_1), sort_by_frequency);
    
    string answer;
    
    vector <int> current_frequency(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < length; i++)
    {
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            if(subarrays_from_1[i][alpha] > current_frequency[alpha])
            {
                answer += (char)('a' + alpha);
                
                current_frequency[alpha]++;
            }
        }
    }
    
    cout << "! " << answer << endl;
    return 0;
}
