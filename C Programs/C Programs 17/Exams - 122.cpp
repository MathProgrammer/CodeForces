#include <cstdio>

int main()
{
    int no_of_exams, minimum_marks;
    scanf("%d %d", &no_of_exams, &minimum_marks);

    int marks_scored = 2*no_of_exams;
    int remaining_marks = minimum_marks - marks_scored;

    int exams_with_2_marks = (remaining_marks >= no_of_exams ? 0 : no_of_exams - remaining_marks);

    printf("%d\n", exams_with_2_marks);
    return 0;
}
