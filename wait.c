#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
//Linux based library #include <sys/wait.h>

 int main() {
 pid_t pid;
 int rv;
 
 switch (pid = fork()) {
 
 case -1: // Error case
 perror("fork");
 exit(1);
 
 case 0: // Child process
 printf("\nCHILD: This is the child process!\n");
 printf("CHILD: My PID is %d\n", getpid());
 printf("CHILD: My parent's PID is %d\n", getppid());
 printf("CHILD: Enter my exit status (make it small): ");
 scanf("%d", &rv);
 printf("CHILD: I'm outta here!\n");
 exit(rv);
 
 default: // Parent process
 printf("\nPARENT: This is the parent process!\n");
 printf("PARENT: My PID is %d\n", getpid());
 wait(&rv);
 printf("PARENT: My child's PID is %d\n", pid);
 printf("PARENT: I'm now waiting for my child to exit()...\n");
 printf("PARENT: My child's exit status is: %d\n",WEXITSTATUS(rv));
 printf("PARENT: I'm outta here!\n");
 }
 return 0;
 }