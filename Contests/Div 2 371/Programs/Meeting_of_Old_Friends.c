#include <stdio.h>

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
int main()
{
    long long sonya_start, sonya_end, filya_start, filya_end, no_of_minutes, prinking_minute, meeting_start, meeting_end;
    scanf("%I64d %I64d %I64d %I64d %I64d",&sonya_start, &sonya_end, &filya_start, &filya_end, &prinking_minute);

    meeting_start = max(sonya_start, filya_start);
    meeting_end = min(sonya_end, filya_end);

    no_of_minutes = (meeting_end >= meeting_start) ? (meeting_end - meeting_start + 1) : 0; //Inclusive of starting and ending time
    no_of_minutes -= (prinking_minute >= meeting_start) && (prinking_minute <= meeting_end)? 1 : 0; //Decrement 1 if k is in the meeting time
    printf("%I64d\n",no_of_minutes);
    return 0;
}
