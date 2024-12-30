/* Implementing a program using thread */
#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 3

int je = 0, jo = 0, evensum = 0, sumn = 0, oddsum = 0, evenarr[50], oddarr[50],i,n;

void *Even(void *threadid) {
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            evenarr[je++] = i;
            evensum += i;
        }
    }
    pthread_exit(NULL);
}

void *Odd(void *threadid) {

    for (i = 0; i <= n; i++) {
        if (i % 2 != 0) {
            oddarr[jo++] = i;
            oddsum += i;
        }
    }
    pthread_exit(NULL);
}

void *SumN(void *threadid) {
    for (i = 1; i <= n; i++) {
        sumn += i;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    printf("Enter a number : ");
    scanf("%d", &n);

    pthread_create(&threads[0], NULL, Even, NULL);
    pthread_create(&threads[1], NULL, Odd, NULL);
    pthread_create(&threads[2], NULL, SumN, NULL);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The sum of first %d natural nos is %d\n", n,sumn);
    printf("The sum of first %d even natural nos is %d\n",n, evensum);
    printf("The sum of first %d odd natural nos is %d\n",n, oddsum);

    printf("The first %d even natural nos are----\n",n);
    for (i = 0; i < je; i++) {
        printf("%d ", evenarr[i]);
    }

    printf("\nThe first %d odd natural nos are----\n",n);
    for (i = 0; i < jo; i++) {
        printf("%d ", oddarr[i]);
    }

    printf("\nThe first %d natural nos are----\n",n);
    for (i = 1; i < n; i++) {
        printf("%d ", i);
    }
    pthread_exit(NULL);

return 0;
}


/*OUTPUT:
$ vi threadf.c
$ cc threadf.c -pthread
$ ./a.out
Enter a number
12
The sum of first N natural nos is 78
The sum of first N even natural nos is 42
The sum of first N odd natural nos is 36
The first N even natural nos is----
2
4
6
8
10
12
The first N odd natural nos is----
1
3
5
7
9
11
*/
