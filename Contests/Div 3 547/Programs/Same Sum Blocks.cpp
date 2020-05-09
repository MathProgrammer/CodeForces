#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct segment
{
    int left, right;
    
    segment(){}
    
    segment(int L, int R)
    {
        left = L; right = R;
    }
};

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> prefix_sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_sum[i] = A[i] + prefix_sum[i - 1];
    }
    
    map <int, vector <segment> > sum_blocks;
    for(int r = 1; r <= no_of_elements; r++)
    {
        for(int l = 1; l <= r; l++)
        {
            int sum = prefix_sum[r] - prefix_sum[l - 1];
            
            sum_blocks[sum].push_back(segment(l, r));
        }
    }
    
    vector <segment> answer;
    for(auto it = sum_blocks.begin(); it != sum_blocks.end(); it++)
    {
        int sum = it->first;
        
        vector <segment> answer_here;
        
        int last_right = -1;                                ;
        
        for(int i = 0; i < sum_blocks[sum].size(); i++)
        {
            if(sum_blocks[sum][i].left > last_right)
            {
                answer_here.push_back(sum_blocks[sum][i]);
                
                last_right = sum_blocks[sum][i].right;
            }
        }
        
        if(answer_here.size() > answer.size())
        {
            answer = answer_here;
        }
    }
    
    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i].left << " " << answer[i].right << "\n";
    }
    
    return 0;
}
