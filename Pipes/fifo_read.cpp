#include "const.cpp"


int main(){

	char buff[BUFFLEN] = {};

	int file_d = open(FIFO_FILENAME, O_RDONLY);
	
	if(file_d < 0){
		printf("Not able to open file %s\n", FIFO_FILENAME);
	}
	
	if(read(file_d, buff, BUFFLEN) <= 0){
		printf("Not able to read from %s properly\n", FIFO_FILENAME);
	}
	
	if(close(file_d) < 0){
		printf("Not able to close %s properly\n", FIFO_FILENAME);
	}
	
	printf("Your read of size [%d] is: `%s`\n", strlen(buff), buff);
	
	return 0;

}
