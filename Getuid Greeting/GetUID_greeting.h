#include"ionegin"
#include<unistd.h>
#include<sys/types.h>

const char USERS_FILE[] = "users.txt";
const int  POISON	= -1;
#define BUFF_SIZE_S "100"
const int  BUFF_SIZE    = 100;
 
typedef int Key_t; 

struct Elem_t{
	char * data;
	Key_t key;
};




Elem_t find_by_key_in_text(Elem_t *text, int text_size, int key);


Elem_t *parce_text_man_changed_to_new_text(str_ptr text, int text_size);


void write_parced_text_to_file(const char file_name[], Elem_t * text, int text_size);
