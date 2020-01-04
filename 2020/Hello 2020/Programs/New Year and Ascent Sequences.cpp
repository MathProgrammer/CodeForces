#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_sequences;
    cin >> no_of_sequences;
    
    const int oo = 1e6;
    vector <int> minimum, maximum;
    
    long long ascent_sequences = 0, non_ascent_sequences = 0;
    for(int i = 1; i <= no_of_sequences; i++)
    {
        int length;
        cin >> length;
        
        vector <int> A(length + 1);
        for(int j = 1; j <= length; j++)
        {
            cin >> A[j];
        }
        
        int has_ascent = false;
        for(int j = 2; j <= length; j++)
        {
            if(A[j - 1] < A[j])
            {
                has_ascent = true;
                break;
            }
        }
        
        if(has_ascent)
        {
            ascent_sequences++;
        }
        else
        {
            non_ascent_sequences++;
            maximum.push_back(A[1]);
            minimum.push_back(A[length]);
        }
    }
    
    vector <int> maximum_frequency(oo + 5, 0);
    for(int i = 0; i < non_ascent_sequences; i++)
    {
        maximum_frequency[maximum[i]]++;
    }
    
    vector <int> maximum_suffix_sum(oo + 5, 0);
    for(int i = oo; i >= 0; i--)
    {
        maximum_suffix_sum[i] = maximum_frequency[i] + maximum_suffix_sum[i + 1];
    }
   
    long long no_of_pairs = ascent_sequences +
                            ascent_sequences*(ascent_sequences - 1) + 2*ascent_sequences*non_ascent_sequences;
    
    for(int i = 0; i < non_ascent_sequences; i++)
    {
        no_of_pairs += maximum_suffix_sum[minimum[i] + 1];
    }
    
    cout << no_of_pairs << "\n";
    return 0;
}
