#include <iostream>

using namespace std;

void solve()
{
    string word_1, word_2;
    cin >> word_1 >> word_2;
    
    for(int i = 0; i < word_1.size(); i++)
    {
        char minimum = word_1[i];
        int position = i;
        
        for(int j = i + 1; j < word_1.size(); j++)
        {
            if(word_1[j] <= minimum)
            {
                minimum = word_1[j];
                position = j;
            }
        }
        
        if(minimum < word_1[i])
        {
            swap(word_1[i], word_1[position]);
            break;
        }
    }
    
    cout << (word_1 < word_2 ? word_1 : "---") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
