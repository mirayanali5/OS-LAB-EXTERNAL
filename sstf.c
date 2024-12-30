#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int queue[100], t[100], head, seek = 0, n, i, j, temp;
    float avg;
    // clrscr();
    printf("*** SSTF Disk Scheduling Algorithm ***\n");
    printf("Enter the size of Queue\t");
    scanf("%d", &n);
    printf("Enter the Queue\t");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position\t");
    scanf("%d", &head);
    for (i = 1; i < n; i++)
        t[i] = abs(head - queue[i]);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (t[i] > t[j])
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    for (i = 1; i < n - 1; i++)
    {
        seek = seek + abs(head - queue[i]);
        head = queue[i];
    }
    printf("\nTotal Seek Time is%d\t", seek);
    avg = seek / (float)n;
    printf("\nAverage Seek Time is %f\t", avg);
    return 0;
}
/*OUTPUT:
*** SSTF Disk Scheduling Algorithm ***
Enter the size of Queue 5
Enter the Queue 10 17 2 15 4
Enter the initial head position 3
Total Seek Time is14
Average Seek Time is 2.800000 */