#include"GetUID_greeting.h"

int main(){	
	
	int buff_size = 0;
	Buff_elem_t *buff = read_file_to_created_buff(USERS_FILE, &buff_size);

	int text_size = 0;
	str_ptr text = make_text_must_free(buff, buff_size, &text_size);

	Elem_t *text_parced = parce_text_man_changed_to_new_text(text, text_size);

	int key = getuid();
	
	Elem_t person = find_by_key_in_text(text_parced, text_size, key);

	char local_buff[BUFF_SIZE] = {};

	if(person.key == POISON){
		
		printf("Я не знаю твоего имени, пожалуйста, представься\n");	
		scanf("%" BUFF_SIZE_S "s", local_buff);
		
		Elem_t temp = {};
		temp.data = local_buff;
		temp.key  = key;
		
		text_parced[text_size] = temp;
		text_size += 1;
		
		write_parced_text_to_file(USERS_FILE, text_parced, text_size);
		
		free(text_parced);
		free(buff);

		return 0;
		
	}
	else{
		printf("Привет, %s!\n", person.data);	
	}

	write_parced_text_to_file(USERS_FILE, text_parced, text_size);
	free(text_parced);
	free(buff);
	
	return 0;	
}


Elem_t find_by_key_in_text(Elem_t *text, int text_size, int key){
	
	Elem_t temp = {};
	bool found = false;
	
	for(int i = 0; i < text_size; i++){
	
		if(text[i].key == key){
			found = true;
			temp = text[i];
			break;
		}
	}
	if(!found){
		temp.key = POISON;
	}
	
	return temp;
}


Elem_t *parce_text_man_changed_to_new_text(str_ptr text, int text_size){

	Elem_t *new_text = (Elem_t *) calloc (text_size + 1, sizeof(Elem_t));
	
	for(int i = 0; i < text_size; i++){
	
		Elem_t temp = {};
		int strlen = 0;

		sscanf(text[i].str, "%*s%n", &strlen);
		sscanf(text[i].str + strlen, "%d", &temp.key);

		temp.data = text[i].str;
		temp.data[strlen - 1] = '\0';
		
		new_text[i] = temp;
	
	}
	
	free(text);
	return new_text;
}



void write_parced_text_to_file(const char file_name[], Elem_t * text, int text_size){

	FILE *file = fopen(file_name, "w");
	if(!file){
		fprintf(stderr, "Cannot open file %s\n", file_name);
		return ;
	}

	for(int i = 0; i < text_size; i++){
		fprintf(file, "%s, %d\n", text[i].data, text[i].key);
	}
	
	fclose(file);
	
	return;
}





















