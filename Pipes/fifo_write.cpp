#include "const.cpp"

int main(){

	char buff[BUFFLEN] = {"My name is Hello and surname is World\n"};

	int file_d = open(FIFO_FILENAME, O_WRONLY|O_CREAT, 0777);
	
	if(file_d < 0){
		printf("Not able to open file %s\n", FIFO_FILENAME);
	}
	
	if(write(file_d, buff, strlen(buff)) < strlen(buff)){
		printf("Not able to write to %s properly\n", FIFO_FILENAME);
	}
	
	if(close(file_d) < 0){
		printf("Not able to close %s properly\n", FIFO_FILENAME);
	}
	
	return 0;

}
