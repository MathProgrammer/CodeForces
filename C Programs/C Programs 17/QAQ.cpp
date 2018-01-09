#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    const int N = 101;
    char input[N];
    scanf("%s", input);

    int length = strlen(input);

    int no_of_Q_till[length] = {0};
    no_of_Q_till[0] = (input[0] == 'Q');
    for(int i = 1; i < length; i++)
        no_of_Q_till[i] = no_of_Q_till[i - 1] + (input[i] == 'Q');

    int no_of_Q_after[length] = {0};
    no_of_Q_after[length - 1] = (input[length - 1] == 'Q');
    for(int i = length - 2; i >= 0; i--)
        no_of_Q_after[i] = no_of_Q_after[i + 1] + (input[i] == 'Q');

    int no_of_QAQ = 0;
    for(int i = 0; i < length; i++)
        if(input[i] == 'A')
            no_of_QAQ += no_of_Q_till[i]*no_of_Q_after[i];

    //for(int i = 0; i < length; i++) printf("%d %d\n", no_of_Q_till[i], no_of_Q_after[i]);

    printf("%d\n", no_of_QAQ);
    return 0;
}
