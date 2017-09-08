#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_exams;
    scanf("%d", &no_of_exams);

    vector < pair <int, int> > exam_day(no_of_exams + 1);
    for(int i = 1; i <= no_of_exams; i++)
    {
        scanf("%d %d", &exam_day[i].first, &exam_day[i].second);
    }

    sort(all(exam_day));

    int last_day = 0;
    for(int i = 1; i <= no_of_exams;i++)
    {
        int choice_1 = exam_day[i].first, choice_2 = exam_day[i].second;

        if(choice_1 >= last_day && choice_2 >= last_day)
            last_day = min(choice_1, choice_2);
        else if(choice_1 >= last_day)
            last_day = choice_1;
        else if(choice_2 >= last_day)
            last_day = choice_2;
    }

    printf("%d\n", last_day);
    return 0;
}
