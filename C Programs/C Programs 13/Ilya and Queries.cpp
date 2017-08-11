#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_LENGTH 100000 + 2

int main()
{
    char string[MAX_LENGTH];
    scanf("%s", string);

    int length = strlen(string);
    vector <int> answer_till_here(length + 1, 0);
    for(unsigned int i = 0; string[i] != '\0'; i++)
    {
        answer_till_here[i] = (i == 0 ? 0 : answer_till_here[i - 1]);

        if(string[i] != '\0' && string[i] == string[i + 1])
            answer_till_here[i]++;
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int left_i, right_i;
        scanf("%d %d", &left_i, &right_i);

        left_i--, right_i--; //1-indexed

        int answer = (left_i == 0 ? answer_till_here[right_i - 1] : answer_till_here[right_i - 1] - answer_till_here[left_i - 1]);

        printf("%d\n", answer);
    }
    return 0;
}
