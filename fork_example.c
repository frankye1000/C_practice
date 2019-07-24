#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid = fork(); /*fork a child process*/
    if(pid<0)
    {
        fprintf(stderr,"Fork Failed");
	exit(-1);
    }
    else if(pid==0)
    {
        execlp("/bin/ls","ls",NULL);
    }
    else
    {
        wait(NULL);
	printf("NOT yet\n");
    	printf("Child Complete \n");
	exit(0);
    }
    return 0;
}
