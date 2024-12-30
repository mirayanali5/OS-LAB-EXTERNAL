/* fork system call */
#include<stdio.h>
#include <unistd.h>
#include<sys/types.h>
int main()
{
int id,childid;
id=getpid();
if((childid=fork())>0)
{
printf("\n i am in the parent process %d",id);
printf("\n i am in the parent process %d",getpid());
printf("\n i am in the parent process %d\n",getppid());
}
else
{
printf("\n i am in child process %d",id);
printf("\n i am in the child process %d",getpid());
printf("\n i am in the child process %d",getppid());
}
}
/*OUTPUT:
$ vi fork.c
$ cc fork.c
$ ./a.out
i am in child process 3765
i am in the child process 3766
i am in the child process 3765
i am in the parent process 3765
i am in the parent process 3765
i am in the parent process 3680*/
