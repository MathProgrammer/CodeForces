#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_PARTIES = 3333;
vector <vector <int> > votes;

long long cost_if_final_count(int n)
{
    int additional_votes = 0;
    
    long long cost = 0;
    vector <long long> extra_votes;
    
    for(int i = 2; i < votes.size(); i++)
    {
        for(int j = 0; j < votes[i].size(); j++)
        {   //cout << "Party = " << i << " Person = " << j << "\n";
            if(j + n <= votes[i].size())
            {
                additional_votes++;
                cost += votes[i][j];
            }
            else
            {   //cout << "Extra \n";
                extra_votes.push_back(votes[i][j]);
            }
        }
    }
    
    int remaining = n - votes[1].size() - additional_votes;
    //cout << "Remaining = " << remaining << "\n";
    if(remaining <= 0)
    {
        return cost;
    }
    
    sort(extra_votes.begin(), extra_votes.end());
    
    for(int i = 0; i < remaining && i < extra_votes.size(); i++)
    {
        cost += extra_votes[i];
    }
    
    return cost;
}

int main()
{
    int no_of_voters, no_of_parties;
    cin >> no_of_voters >> no_of_parties;
    
    votes.resize(no_of_parties + 1);
    
    for(int i = 1; i <= no_of_voters; i++)
    {
        int party, cost;
        cin >> party >> cost;
        
        votes[party].push_back(cost);
    }
    
    for(int i = 2; i <= no_of_parties; i++)
    {
        sort(votes[i].begin(), votes[i].end());
    }
    
    long long answer = 1e18;
    for(int i = 1; i <= no_of_voters; i++)
    {   //cout << "cost " << i << " = " << cost_if_final_count(i) << "\n";
        answer = min(answer, cost_if_final_count(i));
    }
    
    cout << answer << "\n";
    
    return 0;
}
