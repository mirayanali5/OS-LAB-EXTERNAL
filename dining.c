#include <stdio.h>
#include <stdlib.h>
// Global variables
int totalPhilosophers, philosopherNames[20], status[20], numberOfHungry, hungry[20], choice;
// Function to handle one philosopher eating at a time
void one() {
    printf("\nAllow one philosopher to eat at a time\n");
    for (int i = 0; i < numberOfHungry; i++) {
        // Grant the current philosopher to eat
        printf("\nP %d is granted to eat\n", philosopherNames[hungry[i]]);
        // Other hungry philosophers are waiting
        for (int j = i + 1; j < numberOfHungry; j++) {
            printf("P %d is waiting\n", philosopherNames[hungry[j]]);
        }
    }
}
// Function to handle two philosophers eating at the same time
void two() {
    printf("\nAllow two philosophers to eat at the same time\n");
    for (int i = 0; i < numberOfHungry; i++) {
        for (int j = i + 1; j < numberOfHungry; j++) {
            // Check if the philosophers are not adjacent to avoid deadlock
            if (abs(hungry[i] - hungry[j]) > 1 && abs(hungry[i] - hungry[j]) < totalPhilosophers - 1) {
                // Grant the two philosophers to eat
                printf("\nP %d and P %d are granted to eat\n", philosopherNames[hungry[i]], philosopherNames[hungry[j]]);
                // Other hungry philosophers are waiting
                for (int k = 0; k < numberOfHungry; k++) {
                    if (k != i && k != j) {
                        printf("P %d is waiting\n", philosopherNames[hungry[k]]);
                    }
                }
                return; // Exit after finding the first valid pair
            }
        }
    }
}

// Main function
int main() {
    printf("\nDINING PHILOSOPHER PROBLEM");
    // Input the total number of philosophers
    printf("\nEnter the total number of philosophers: ");
    scanf("%d", &totalPhilosophers);
    // Initialize philosophers' names and their status (thinking)
    for (int i = 0; i < totalPhilosophers; i++) {
        philosopherNames[i] = i + 1;
        status[i] = 1; // 1 means thinking
    }
    // Input the number of hungry philosophers
    printf("How many are hungry: ");
    scanf("%d", &numberOfHungry);
    // Check for deadlock condition
    if (numberOfHungry == totalPhilosophers) {
        printf("\nAll are hungry.. Deadlock stage will occur");
        printf("\nExiting..");
        return 0;
    }
    // Input the positions of hungry philosophers
    for (int i = 0; i < numberOfHungry; i++) {
        printf("Enter philosopher %d position: ", i + 1);
        scanf("%d", &hungry[i]);
        status[hungry[i]] = 2; // 2 means hungry
    }
    // Loop to handle user choices
    do {
        printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Handle one philosopher eating at a time
                one();
                break;
            case 2:
                // Handle two philosophers eating at the same time
                two();
                break;
            case 3:
                // Exit the program
                exit(0);
            default:
                // Handle invalid option
                printf("\nInvalid option..");
        }
    } while (1);
    return 0;
}


/*OUTPUT:
DINING PHILOSOPHER PROBLEM
Enter the total no. of philosophers: 5
How many are hungry : 3
Enter philosopher 1 position: 2
Enter philosopher 2 position: 4
Enter philosopher 3 position: 5
1.One can eat at a time 2.Two can eat at a time 3.Exit
Enter your choice: 1
Allow one philosopher to eat at any time
P 3 is granted to eat
P 3 is waiting
P 5 is waiting
P 0 is waiting
P 5 is granted to eat
P 5 is waiting
P 0 is waiting
P 0 is granted to eat
P 0 is waiting
1.One can eat at a time 2.Two can eat at a time 3.Exit
Enter your choice: 2
Allow two philosophers to eat at same time
combination 1
P 3 and P 5 are granted to eat
P 0 is waiting
combination 2
P 3 and P 0 are granted to eat
P 5 is waiting
combination 3
P 5 and P 0 are granted to eat
P 3 is waiting
1.One can eat at a time 2.Two can eat at a time 3.Exit
Enter your choice: 3*/