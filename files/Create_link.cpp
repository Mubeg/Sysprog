#include "const.cpp"


main(int argc, char *argv[]){ //Создает жесткую\мягкую связь

	char buff[BUFFLEN] = {};

	int file_d = open(FILENAME, O_RDONLY);
	
	if(file_d < 0){
		printf("Not able to open file %s\n", FILENAME);
	}
	
	if(read(file_d, buff, BUFFLEN) <= 0){
		printf("Not able to read from %s properly\n", FILENAME);
	}
	
	if(close(file_d) < 0){
		printf("Not able to close %s properly\n", FILENAME);
	}
	
	printf("Your read of size [%lu] is: `%s`\n", strlen(buff), buff);
	
	return 0;

}
