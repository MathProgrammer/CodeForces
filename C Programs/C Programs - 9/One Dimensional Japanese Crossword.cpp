#include <cstdio>
#include <vector>

#define MAX_LENGTH 100 + 1
using namespace std;

int main()
{
    int no_of_blocks, segment_length;
    char crossword[MAX_LENGTH];

    scanf("%d %s", &no_of_blocks, crossword);

    vector <int> black_segment_length;
    for(int i = 0; i < no_of_blocks; i += segment_length + 1)
    {
        segment_length = 0;
        while(crossword[i + segment_length] == 'B')
        {
             segment_length++;
        }

        if(segment_length > 0)
            black_segment_length.push_back(segment_length);
    }

    printf("%u\n", black_segment_length.size());
    for(unsigned int i = 0; i < black_segment_length.size(); i++)
        printf("%d ",black_segment_length[i]);
    return 0;
}
