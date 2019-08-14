#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int value = 0;
void *runner(void *param){
	value = 10;
        pthread_exit(0);
}

int main(void){
	int pid;
	pthread_t tid;
	pthread_attr_t attr;
	pid = fork();
	if(pid == 0){
		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, runner, NULL);
		pthread_join(tid, NULL);
		printf("Child=%d\n", value);
	}
	
	else if(pid > 0){
		wait(NULL);
		printf("Parent=%d\n",value);
	}

}

