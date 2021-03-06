#include "const.cpp"

#define USAGE_PROMPT "%s %%your_filename%% %%n_bytes%%\n"
#define USAGE_ARGS   argv[0]

int get_file_length(int file);

main(int argc, char *argv[]){ //Программа читает файл с n-ого символа

	START_PARCE_START_STRING("This programm reads a file from n-th byte and prints it's content into output stream\n", "\t-h - Prints this help\n", USAGE_PROMPT, USAGE_ARGS)
	END_PARCE_KEYS()
	END_PARCE_PARAMS()

	PARCE_EXTRA_COND(argc >= 3, bool digit = true; size_t len = strlen(argv[2]); for(int i = 0; i < len; i++){if(!digit){break;} digit = isdigit(argv[2][i])? true : false;} parcebale = digit;)

	END_PARCE(USAGE_PROMPT, USAGE_ARGS)

	char buff[BUFFLEN] = {};

	int file_d = open(argv[1], O_RDONLY);
	
	if(file_d < 0){
		fprintf(stderr, "Not able to open file %s\n", argv[1]);
		exit(NOT_OPENED_FILE);
	}

	int num = std::stoll(argv[2], 0, 10);
	int file_length = get_file_length(file_d);

	if(file_length <= num){
		fprintf(stderr, "Read from byte #%d is not available in file with size of %d\n", num, file_length);
		exit(OUT_OF_BOUNDS);	
	}

	file_length -= num;

	if(file_length >= BUFFLEN){
		fprintf(stderr, "Not enough space to read from %s properly\n", argv[1]);
		exit(NOT_OPENED_FILE);	
	}
	else if((lseek(file_d, num, SEEK_SET), read(file_d, buff, file_length)) < 0){
		fprintf(stderr, "Not able to read from %s properly\n", argv[1]);
		exit(FAILED_READING_FILE);
	}
	else{
		printf("Your file from byte #%d contains:\n---\n", num);
		write(1, buff, file_length);
		printf("\n");
	}

	if(close(file_d) < 0){
		fprintf(stderr, "Not able to close %s properly\n", argv[1]);
		exit(NOT_CLOSED_FILE);
	}

	return 0;

}
