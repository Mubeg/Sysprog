#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

typedef long unsigned int my_error_t;

const size_t 		BUFFLEN 		= 100;
extern const char* 	FILENAME		;// in lib.c

const my_error_t	ERROR_CONST_START_LINE	= __LINE__;
const my_error_t 	WRONG_USAGE		= __LINE__ - ERROR_CONST_START_LINE;
const my_error_t 	HELP_TRIGGERED  	= __LINE__ - ERROR_CONST_START_LINE;
const my_error_t 	NOT_OPENED_FILE  	= __LINE__ - ERROR_CONST_START_LINE;
const my_error_t 	NOT_CLOSED_FILE  	= __LINE__ - ERROR_CONST_START_LINE;

//pretty when prints
#define MUBEG_SIGNATURE "\n\n\t\t\t\t\t\t\t\t      -Mubeg.inc\n"


// *OLD
// [1, num) - ok
#define CHECK_ARGC_LESS(num, prompt, ...) \
					if(argc >= num){\
						fprintf(stderr, prompt, ##__VA_ARGS__);\
						exit(WRONG_USAGE);\
					}

// *OLD
// [num_l, num_h) - ok
#define CHECK_ARGC_RANGE(num_l, num_h, prompt, ...) \
					if(argc < num_l || argc >= num_h){\
						fprintf(stderr, prompt, ##__VA_ARGS__);\
						exit(WRONG_USAGE);\
					}

//parcing cycle, which checks for argc and keys and allows for !SPECIFIC! extra code
//NEEDS END_PARCE_START_STRING() to wrap the extras
//HARD CODED help 
//extra code is NEEDED for successfull parcing of coming arguments
#define START_PARCE_START_STRING(help, keys, usage_prompt, ...) \
			bool parcebale = true;\
			for(int i = 1; i < argc; i++){\
				if(argv[i][0] == '-'){\
					if(argv[i][1] == 'h' && argv[i][2] == '\0'){\
						printf(help "\nKeys:\n" keys "\n" "\nUsage: " usage_prompt "\n" MUBEG_SIGNATURE, ##__VA_ARGS__);\
						exit(HELP_TRIGGERED);\
					}

//cond on key, strting with '-' in argv[i]
#define PARCE_EXTRA_KEY(cond, code) \
				if(cond){\
					code;\
				}

//cond on argv[i]
#define PARCE_EXTRA_PARAM(cond, code) \
				if(cond){\
					code;\
				}

//cond on argc or argv
#define PARCE_EXTRA_COND(cond, code) \
				if(cond){\
					code;\
				}\
				else{\
					parcebale = false;\
				}
					
//Ender of key_parcer
#define END_PARCE_KEYS() }

//Ender of Param parcer
#define END_PARCE_PARAMS() \
				else{\
					parcebale = false;\
					break;\
				}}
//Ender of Parcer
#define END_PARCE(usage_prompt, ...) \
				if(!parcebale){\
					printf("Correct usage: " usage_prompt "\nFor help use with key \'-h\'\n", ##__VA_ARGS__);\
					exit(WRONG_USAGE);\
				}












