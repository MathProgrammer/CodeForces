#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_grass, no_of_cows;
    cin >> no_of_grass >> no_of_cows;
    
    vector <int> sweetness(no_of_grass + 1);
    for(int i = 1; i <= no_of_grass; i++)
    {
        cin >> sweetness[i];
    }
    
    vector <vector <int> > cows(no_of_grass + 1);
    for(int i = 1; i <= no_of_cows; i++)
    {
        int sweet, hunger;
        cin >> sweet >> hunger;
        
        cows[sweet].push_back(hunger);
    }
    
    for(int i = 1; i <= no_of_grass; i++)
    {
        sort(cows[i].begin(), cows[i].end());
    }
    
    const int MOD = 1e9 + 7;
    int happy_cows = 0;
    long long no_of_ways = 1;
    
    for(int cut = 0; cut <= no_of_grass; cut++)
    {
        vector <int> left(no_of_grass + 1, 0);
        vector <int> right(no_of_grass + 1, 0);
        for(int i = 1; i <= cut; i++)
        {
            left[sweetness[i]]++;
        }
        
        for(int i = cut + 1; i <= no_of_grass; i++)
        {
            right[sweetness[i]]++;
        }
        
        int left_ending = (cut == 0 ? -1 : sweetness[cut]);
        
        int happy_cows_here = 0;
        long long no_of_ways_here = 1;
        
        for(int i = 1; i <= no_of_grass; i++)
        {
            if(i == left_ending)
            {
                if(binary_search(cows[i].begin(), cows[i].end(), left[i]))
                {
                    happy_cows_here++;
                }
                else
                {
                    happy_cows_here = 0;
                    break;
                }
                
                int right_choices = 0;
                
                for(int j = 0; j < cows[i].size(); j++)
                {
                    if(cows[i][j] != left[i] && cows[i][j] <= right[i])
                    {
                        right_choices++;
                    }
                }
                
                if(right_choices >= 1)
                {   //cout << "Left = " << left[i] << "\n";
                    //cout << "Right Choices = " << right_choices << "\n";
                    happy_cows_here++;
                    no_of_ways_here *= right_choices;
                }
            }
            else
            {
                int left_choices = 0, right_choices = 0;
                
                for(int j = 0; j < cows[i].size(); j++)
                {
                    if(cows[i][j] <= left[i])
                    {
                        left_choices++;
                    }
                    if(cows[i][j] <= right[i])
                    {
                        right_choices++;
                    }
                }
                
                //cout << "Sweetness = " << i << " L = " << left_choices << " R = " << right_choices << "\n";
                int no_of_pairs = (left_choices*right_choices) - min(left_choices, right_choices);
                
                if(no_of_pairs > 0)
                {
                    happy_cows_here += 2;
                    
                    no_of_ways_here *= no_of_pairs;
                }
                else if(left_choices > 0 || right_choices > 0)
                {
                    happy_cows_here++;
                    
                    no_of_ways_here *= (left_choices + right_choices);
                    
                    //cout << "Reached and No of Ways = " << no_of_ways_here << "\n";
                }
            }
            
            no_of_ways_here %= MOD;
        }
        
        if(happy_cows_here > happy_cows)
        {
            happy_cows = happy_cows_here;
            no_of_ways = no_of_ways_here;
        }
        else if(happy_cows_here == happy_cows && happy_cows_here > 0)
        {
            no_of_ways += no_of_ways_here;
            
            no_of_ways %= MOD;
        }
        
        //cout << "Cut = " << cut << " Maximum = " << happy_cows << " No of ways = " << no_of_ways << "\n";
    }
    
    cout << happy_cows << " " << no_of_ways << "\n";
    return 0;
}
