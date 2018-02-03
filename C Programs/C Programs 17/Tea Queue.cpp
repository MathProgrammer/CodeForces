#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int number_of_students;
    scanf("%d", &number_of_students);

    vector <int> left(number_of_students + 1);
    vector <int> right(number_of_students + 1);
    for(int i = 1; i <= number_of_students; i++)
        scanf("%d %d", &left[i], &right[i]);

    vector <int> served_time(number_of_students + 1, 0);

    for(int current_time = left[1], student = 1; student <= number_of_students; student++)
    {
            current_time = max(current_time, left[student]);

            if(current_time <= right[student])
            {
                served_time[student] = current_time++;
            }
    }

    for(int i = 1; i <= number_of_students; i++)
        printf("%d ", served_time[i]);

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
