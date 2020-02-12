#include <iostream>
#include <vector>

using namespace std;

const int NO_OF_ALPHABETS = 26;
vector <int> degree(NO_OF_ALPHABETS, 0);
vector <int> graph[NO_OF_ALPHABETS];
vector <int> component_no(NO_OF_ALPHABETS, 0);

void dfs(int v, int parent_v, int c)
{
    //cout << "V = " << v << " C = " << c << "\n";
    component_no[v] = c;
    
    for(int i = 0; i < graph[v].size(); i++)
    {
        int child_v = graph[v][i];
        
        if(child_v == parent_v || component_no[child_v] == c)
        {
            continue;
        }
        
        dfs(child_v, v, c);
    }
}

void solve()
{
    string password;
    cin >> password;
    
    const int NO_OF_ALPHABETS = 26;
    vector <vector <int> > adjacency(NO_OF_ALPHABETS,
                                     vector <int> (NO_OF_ALPHABETS, false));
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        degree[alpha] = 0;
        
        graph[alpha].clear();
        
        component_no[alpha] = 0;
    }
    
    for(int i = 1; i < password.size(); i++)
    {
        if(adjacency[password[i] - 'a'][password[i - 1] - 'a'] == false)
        {
            adjacency[password[i] - 'a'][password[i - 1] - 'a'] = true;
            adjacency[password[i - 1] - 'a'][password[i] - 'a'] = true;
                                         
            graph[password[i] - 'a'].push_back(password[i - 1] - 'a');
            graph[password[i - 1] - 'a'].push_back(password[i] - 'a');
            
            degree[password[i] - 'a']++;
            degree[password[i - 1] - 'a']++;
        }
        
    }
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        if(degree[alpha] > 2)
        {   
            cout << "NO\n";
            return;
        }
    }
    
    int component = 1;
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        if(component_no[alpha] == 0)
        {
            dfs(alpha, -1, component++);
        }
    }
    
    string keyboard;
    vector <int> components;
    vector <int> used(NO_OF_ALPHABETS, false);
    for(int c = 1; c < component; c++)
    {
        vector <int> this_component;
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            if(component_no[alpha] == c)
            {
                this_component.push_back(alpha);
            }
        }
        
        if(this_component.size() == 1)
        {
            keyboard += (char)('a' + this_component[0]);
            used[this_component[0]] = true;
            continue;
        }
        
        int border_1 = -1, border_2 = -1;
        for(int i = 0; i < this_component.size(); i++)
        {
            if(degree[this_component[i]] == 1)
            {
                if(border_1 == -1)
                    border_1 = this_component[i];
                else
                    border_2 = this_component[i];
            }
        }
        
        if(border_1 == -1 || border_2 == -1)
        {
            cout << "NO\n";
            
            return;
        }
        
        keyboard += (char)('a' + border_1);
        used[border_1] = true;
        
        while(keyboard.back() - 'a' != border_2)
        {
            for(int i = 0; i < graph[keyboard.back() - 'a'].size(); i++)
            {
                if(!used[graph[keyboard.back() - 'a'][i]])
                {
                    int next = graph[keyboard.back() - 'a'][i];
                    
                    keyboard += (char)('a' + next);
                    
                    used[next] = true;
                    
                    break;
                }
            }
        }
        
    }
   
    cout << "YES\n";
    cout << keyboard << "\n";
    return;
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
