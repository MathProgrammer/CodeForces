#include <iostream>
#include <map>
#include <vector>

using namespace std;

char get_third(char a, char b)
{
    switch(a)
    {
        case 'S' : return (b == 'E' ? 'T' : 'E');
        case 'E' : return (b == 'T' ? 'S' : 'T');
        case 'T' : return (b == 'S' ? 'E' : 'S');
    }
    
    return 0;
}

long  long choose_3(long long n)
{
    long long numerator = n*(n - 1)*(n - 2);
    long long denominator = 3*2*1;
    
    return numerator/denominator;
}

int main()
{
    int no_of_cards, no_of_features;
    cin >> no_of_cards >> no_of_features;
    
    vector <string> card(no_of_cards + 1);
    map <string, int> frequency;
    for(int i = 1; i <= no_of_cards; i++)
    {
        cin >> card[i];
        
        frequency[card[i]]++;
    }
    
    long long same_triplets = 0;
    for(auto it = frequency.begin(); it != frequency.end(); it++)
    {
        same_triplets += choose_3(it->second);
    }
    
    long long different_triplets = 0;
    for(int i = 1; i <= no_of_cards; i++)
    {
        for(int j = i + 1; j <= no_of_cards; j++)
        {
            if(card[i] == card[j])
            {
                continue;
            }
            
            string complement;
            
            for(int k = 0; k < no_of_features; k++)
            {
                if(card[i][k] == card[j][k])
                {
                    complement += card[i][k];
                }
                else
                {
                    complement += get_third(card[i][k], card[j][k]);
                }
            }
            
            different_triplets += frequency[complement];
        }
    }
    
    different_triplets /= 3;
    
    long long no_of_triplets = same_triplets + different_triplets;
    
    cout << no_of_triplets << "\n";
    return 0;
}
