#include "const.cpp"


int main(){

	char buff[BUFFSIZE] = {};

	int file_d1[2] = {};
	int file_d2[2] = {};
	
	int res = pipe(file_d1);
	if(res < 0){
		printf("Not able to open pipe\n");
	}
	
	res = pipe(file_d2);
	if(res < 0){
		printf("Not able to open pipe\n");
	}
	
	res = fork();
	
	if(res < 0){
		printf("Unable to fork\n");
	}
	else if(res == 0){
		
		char buff[BUFFSIZE] = {"I am child lalala secret code is 1874629187346932187"};
		
		
		close(file_d1[0]);
		int out = file_d1[1];
		
		close(file_d2[1]);
		int in  = file_d2[0];
		
		printf("I am child, lalala, I dont know any secret code\n");
		write(out, buff, strlen(buff) + 1);
		
		read(in, buff, BUFFSIZE);

		printf("Oh, my parent says:%s\n", buff);
		
		close(file_d2[0]);
		close(file_d1[1]);

	}
	else{
	
		char buff[BUFFSIZE] = {};
	
		close(file_d1[1]);
		int in = file_d1[0];
		
		close(file_d2[0]);
		int out  = file_d2[1];
		
		read(in, buff, BUFFSIZE);
		printf("I am parent, my child says: %s\n", buff);

		strcpy(buff, "Dont tell anyone your secret code!\n");
		write(out, buff, strlen(buff) + 1);
		
		close(file_d2[1]);
		close(file_d1[0]);
	}
	

	
	return 0;

}
