#include <stdio.h>
#include <stdlib.h>

// Global variables for the producer-consumer problem
int mutex = 1, full = 0, empty = 10, x = 0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces item %d\n", x);
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumed item %d\n", x);
    x--;
    ++mutex;
}

int main()
{
    int n;
    while (1)
    {
        printf("\nEnter 1 for Producer\nEnter 2 for Consumer\nEnter 3 to Exit\nYour choice: ");
        scanf("%d", &n); // Corrected input handling

        switch (n)
        {
        case 1: // Producer
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("Buffer is full!\n");
            }
            break;

        case 2: // Consumer
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty!\n");
            }
            break;

        case 3: // Exit
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}

/*Enter 1 for Producer
Enter 2 for Consumer
Enter 3 to Exit
Your choice: 1
Producer produces item 1

Enter 1 for Producer
Enter 2 for Consumer
Enter 3 to Exit
Your choice: 1
Producer produces item 2

Enter 1 for Producer
Enter 2 for Consumer
Enter 3 to Exit
Your choice: 2
Consumer consumed item 2

Enter 1 for Producer
Enter 2 for Consumer
Enter 3 to Exit
Your choice: 3
Exiting program...
*/
