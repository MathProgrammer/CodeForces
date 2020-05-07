#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int ODD = 1, EVEN = 0, oo = 1e9, MAX_N = 2e5 + 5;

vector <int> graph[MAX_N];

void bfs(vector <int> &A, vector <int> &answer, int parity)
{
    vector <int> distance(A.size() + 1, oo);
    queue <int> Q;
    
    for(int i = 1; i < A.size(); i++)
    {
        if(A[i]%2 != parity)
        {
            distance[i] = 0;
            
            Q.push(i);
        }
    }
    
    while(!Q.empty())
    {
        int index = Q.front();
        Q.pop();
        
        for(int v = 0; v < graph[index].size(); v++)
        {
            int next = graph[index][v];
            
            if(1 + distance[index] < distance[next])
            {
                distance[next] = 1 + distance[index];
                
                Q.push(next);
            }
        }
    }
                                                 
     for(int i = 1; i < A.size(); i++)
     {
         if(A[i]%2 == parity)
         {
            answer[i] = (distance[i] == oo ? -1 : distance[i]);
         }
     }
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        if(1 <= i - A[i])
        {
            graph[i - A[i]].push_back(i);
        }
        
        if(i + A[i] <= no_of_elements)
        {
            graph[i + A[i]].push_back(i);
        }
    }
    
    vector <int> answer(no_of_elements + 1, oo);
    bfs(A, answer, EVEN);
    bfs(A, answer, ODD);
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << answer[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
