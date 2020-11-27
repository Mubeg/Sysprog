#include "const.cpp"

#define USAGE_PROMPT "%s %%your_filename%%\n"
#define USAGE_ARGS   argv[0]

void print_stat(char filename[]);

main(int argc, char *argv[]){ //Выв на экр аттр файла

	START_PARCE_START_STRING("This programm prints file attributes in pretty form into output stream\n", "\t-h - Prints this help\n", USAGE_PROMPT, USAGE_ARGS)
	END_PARCE_KEYS()
	END_PARCE_PARAMS()
	PARCE_EXTRA_COND(argc >= 2, parcebale = true;)
	END_PARCE(USAGE_PROMPT, USAGE_ARGS)

	print_stat(argv[1]);

}

