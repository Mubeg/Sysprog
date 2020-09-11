#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

	FILE *usernames = fopen("/env/passwd", "r");
	
	pid_t my_pid = getpid();
	pid_t my_fork_pid = fork();
	pid_t my_new_pid = getpid();
	
	if(my_fork_pid == 0){
		printf("[Child] I am child process, I was %d, my parent is %d, I am %d\n", my_pid, getppid(), my_new_pid);
	}
	else if (my_fork_pid == - 1){
		fprintf(stderr, "Error, no child created\n");
	}
	else{
		printf("[Parent] I am parent process, I was %d, my child is %d, I am %d\n", my_pid, my_fork_pid, my_new_pid);
	}
	
	return 0;
}
