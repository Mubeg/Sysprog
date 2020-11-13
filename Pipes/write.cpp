#include "const.cpp"

int main(){

	char buff[BUFFLEN] = {"My name is Hello and surname is World\n"};

	int response = creat(FILENAME, 0777);
	if(!response){	
		printf("Unsuccesfull creation of file \"%s\" in dir %s\n", FILENAME, get_current_dir_name());
	}

	int file_d = open(FILENAME, O_WRONLY);
	
	if(file_d < 0){
		printf("Not able to open file %s\n", FILENAME);
	}
	
	if(write(file_d, buff, strlen(buff)) < strlen(buff)){
		printf("Not able to write to %s properly\n", FILENAME);
	}
	
	if(close(file_d) < 0){
		printf("Not able to close %s properly\n", FILENAME);
	}
	
	return 0;

}
