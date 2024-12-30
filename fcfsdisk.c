#include <stdio.h>
int main()
{
    int queue[20], n, head, i, j, k, seek = 0, max, diff;
    float avg;
    printf("Enter the max range of disk\n");
    scanf("%d", &max);
    printf("Enter the size of queue request\n");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read\n");
    for (i = 1; i <= n; i++){
        scanf("%d", &queue[i]);}
    printf("Enter the initial head position\n");
    scanf("%d", &head);
    queue[0] = head;
    for (j = 0; j <= n - 1; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
    }
    printf("Total seek time is %d\n", seek);
    avg = seek / n;
    printf("Average seek time is %f\n", avg);
    return 0;
}
/*OUTPUT
Enter the max range of disk
200
Enter the size of queue request
8
Enter the queue of disk positions to be read
90 120 35 122 38 128 65 68
Enter the initial head position
50
Disk head moves from 50 to 90 with seek
40
Disk head moves from 90 to 120 with seek
30
Disk head moves from 120 to 35 with seek
85
Disk head moves from 35 to 122 with seek
87
Disk head moves from 122 to 38 with seek
84
Disk head moves from 38 to 128 with seek
90
Disk head moves from 128 to 65 with seek
63
Disk head moves from 65 to 68 with seek
3
Total seek time is 482
Average seek time is 60.250000 */