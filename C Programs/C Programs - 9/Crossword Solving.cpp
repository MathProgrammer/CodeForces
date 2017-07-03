#include <cstdio>
#include <vector>

#define MAX_LENGTH 1000 + 1

using namespace std;

int main()
{
    int key_length, text_length;
    char key[MAX_LENGTH], text[MAX_LENGTH];
    scanf("%d %d %s %s", &key_length, &text_length, key, text);

    vector <int> change(key_length + 1);
    vector <int> current_change;

    for(int i = 0; i + key_length <= text_length ; i++)
    {
        current_change.clear();

        for(int j = 0; j < key_length; j++)
        {
            if(key[j] != text[i + j])
            {
                current_change.push_back(j);
            }
        }

        if(current_change.size() < change.size())
        {
            change = current_change;
        }
    }

    printf("%u\n", change.size());

    if(change.size() > 0)
    {
        for(unsigned int i = 0; i < change.size(); i++)
            printf("%d ", change[i] + 1);
    }

    return 0;
}
