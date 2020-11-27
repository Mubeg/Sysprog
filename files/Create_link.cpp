#include "const.cpp"

#define USAGE_PROMPT "%s OPTIONAL[-s] %%filename_of_original%% %%filename_of_link%%\n"
#define USAGE_ARGS   argv[0]

const int 	HARD_MODE 	= 0;
const int 	SOFT_MODE 	= 1;

main(int argc, char *argv[]){ //Создает жесткую\мягкую связь

	int mode = HARD_MODE;
	int file_baseline = 0;

	START_PARCE_START_STRING("This programm links a link file to an original file\n", "\t-h - Prints this help\n" "\t-s - Make symbolic link\n" "\tNO KEY - Make hard link\n", USAGE_PROMPT, USAGE_ARGS)
	PARCE_EXTRA_KEY(argv[i][1] == 's' && argv[i][2] == '\0', mode = SOFT_MODE; file_baseline+=1;)
	END_PARCE_KEYS()
	END_PARCE_PARAMS()

	PARCE_EXTRA_COND(argc >= 3, parcebale = true)	// if the new file does not exist and old does

	END_PARCE(USAGE_PROMPT, USAGE_ARGS)

	int ans = -1;

	char * original = argv[file_baseline + 1];
	char * link_file 	= argv[file_baseline + 2];

	int old_path_clear = access(original, F_OK);
	int new_path_clear = access(link_file, F_OK);

	if(old_path_clear){
		fprintf(stderr, "File %s does not exist\n", original);
		exit(FILE_DOES_NOT_EXIST);	
	}
	else if(!new_path_clear){
		fprintf(stderr, "File %s already exists\n", link_file);
		exit(FILE_EXISTS);
	}

	if(mode == HARD_MODE){
		ans = link(original, link_file);
	}
	else if(mode == SOFT_MODE){
		ans = symlink(original, link_file);
	}

	if(ans){
		fprintf(stderr, "Not able to establish link between file %s and %s properly\n", original, link_file);
		exit(LINK_CREATION_ERROR);
	}
	
	return 0;

}
