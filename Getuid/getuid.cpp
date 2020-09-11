#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pwd.h>

int main(){

	FILE *usernames = fopen("/env/passwd", "r");
	
	size_t my_uid = getuid();
	printf("Hello, %s\n", getpwuid(my_uid)->pw_name);
	
	return 0;
}
