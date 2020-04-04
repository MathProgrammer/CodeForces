#include <iostream>
#include <vector>

using namespace std;

const int NO_OF_ALPHABETS = 26;
struct DSU
{
    int parent[NO_OF_ALPHABETS];
    int no_of_components = NO_OF_ALPHABETS;
    
    DSU() {}

    DSU(int n)
    {
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }

    }

    int get_parent(int n)
    {
        while(n != parent[n])
        {
            parent[n] = parent[parent[n]];

            n = parent[n];
        }

        return n;
    }

    void unite(int x, int y)
    {
        int parent_x = get_parent(x), parent_y = get_parent(y);

        if(parent_x == parent_y)
            return;

        parent[parent_x] = parent[parent_y];
        
        no_of_components--;
    }
};

int is_set(long long n, int bit)
{
    return ((n&(1 << bit)) != 0);
}

int main()
{
    int no_of_words;
    cin >> no_of_words;
    
    vector <int> used(NO_OF_ALPHABETS, false);
    DSU dsu(NO_OF_ALPHABETS);
    
    for(int i = 1; i <= no_of_words; i++)
    {
        string word;
        cin >> word;
        
        int mask = 0;
        for(int j = 0; j < word.size(); j++)
        {
            mask |= (1 << (word[j] - 'a'));
            
            used[word[j] - 'a'] = true;
        }
        
        for(int bit_1 = 0; bit_1 < NO_OF_ALPHABETS; bit_1++)
        {
            for(int bit_2 = 0; bit_2 < NO_OF_ALPHABETS; bit_2++)
            {
                if(!is_set(mask, bit_1) || !is_set(mask, bit_2) || dsu.get_parent(bit_1) == dsu.get_parent(bit_2))
                {
                    continue;
                }
                
                dsu.unite(bit_1, bit_2);
            }
        }
    }
    
    int unused_alphabets = 0;
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        if(!used[alpha])
        {
            unused_alphabets++;
        }
    }
    
    int actual_components = dsu.no_of_components - unused_alphabets;
    
    cout << actual_components << "\n";
    return 0;
}
