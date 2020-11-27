#include "const.cpp"

const char* FILENAME 			= "file.txt";
const char* FIFO_FILENAME 		= "1.fifo";


void print_stat(char filename[]){

	if(filename == nullptr){
		return;
	}

	struct stat answer = {};

	int response = stat(filename, &answer);

	char buff[BUFFLEN] = {};

	if(response){
		printf("Not able to get stat of file %s\n from %s\n", filename, get_current_dir_name());
		return;
	}
	
	
	printf("\n"
	       "Stats of file %s:\n\n"
	       "ID of device containing file:   	%lu\n"
	       "Inode number:             		%lu\n"
	       "File type and mode:       		%d\n"
	       "Number of hard links:     		%lu\n"
	       "User ID of owner:         		%d\n"
	       "Group ID of owner:        		%d\n"
	       "Device ID:                		%lu\n"
	       "Total size, in bytes:           	%li\n"
	       "block size for filesystem I/O: 	 	%li\n"
	       "Number of 512B blocks allocated:	%li\n"
	       "Time of last access:                    %s.%09ld\n"
	       "Time of last modification:              %s.%09ld\n"
	       "Time of last status change:             %s.%09ld\n\n"
		, filename, answer.st_dev, answer.st_ino, answer.st_mode, answer.st_nlink, answer.st_uid, answer.st_gid, answer.st_rdev, answer.st_size, answer.st_blksize, answer.st_blocks,  (strftime(buff, BUFFLEN, "%D %T", gmtime(&answer.st_atim.tv_sec)), buff), answer.st_atim.tv_nsec, 
(strftime(buff, BUFFLEN, "%D %T", gmtime(&answer.st_mtim.tv_sec)), buff), answer.st_mtim.tv_nsec, 
(strftime(buff, BUFFLEN, "%D %T", gmtime(&answer.st_ctim.tv_sec)), buff), answer.st_ctim.tv_nsec);
	
	return;

}


int get_file_length(int file){

	if(file < 0){
		return -1;	
	}

	struct stat answer = {};

	int response = fstat(file, &answer);

	if(response){
		fprintf(stderr, "Not able to get stat of file %d\n from %s\n", file, get_current_dir_name());
		return 0;
	}
	
	
	return answer.st_size;
}

