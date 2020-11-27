#include "const.cpp"

#define USAGE_PROMPT "%s %%your_filename%% %%new_length%%\n"
#define USAGE_ARGS   argv[0]

int get_file_length(int file);


main(int argc, char *argv[]){  //Программа изменяет длмну файла и выводит его содержимое

	START_PARCE_START_STRING("This programm truncates a file and prints it's content before truncation into output stream\n", "\t-h - Prints this help\n", USAGE_PROMPT, USAGE_ARGS)
	END_PARCE_KEYS()
	END_PARCE_PARAMS()

	PARCE_EXTRA_COND(argc >= 3, bool digit = true; size_t len = strlen(argv[2]); for(int i = 0; i < len; i++){if(!digit){break;} digit = isdigit(argv[2][i])? true : false;} parcebale = digit;)

	END_PARCE(USAGE_PROMPT, USAGE_ARGS)

	char buff[BUFFLEN] = {};

	int file_d = open(argv[1], O_RDWR);
	
	if(file_d < 0){
		fprintf(stderr, "Not able to open file %s\n", argv[1]);
		exit(NOT_OPENED_FILE);
	}
	
	int file_length = get_file_length(file_d);

	if(file_length >= BUFFLEN){
		fprintf(stderr, "Not enough space to read from %s properly\n", argv[1]);
		exit(NOT_OPENED_FILE);	
	}
	else if(read(file_d, buff, file_length) < 0){
		fprintf(stderr, "Not able to read from %s properly\n", argv[1]);
		exit(NOT_OPENED_FILE);
	}
	else{
		printf("Your file contains:\n---\n");
		write(1, buff, file_length);
		printf("\n");
	}

	if(ftruncate(file_d, std::stoll(argv[2], 0, 10)) < 0){
		fprintf(stderr, "Not able to truncate file %s to size %lli properly\n", argv[1], std::stoll(argv[2], 0, 10));
	}
	
	printf("Your new size is %d\n", get_file_length(file_d));
	

	if(close(file_d) < 0){
		fprintf(stderr, "Not able to close %s properly\n", argv[1]);
		exit(NOT_CLOSED_FILE);
	}

	return 0;

}

