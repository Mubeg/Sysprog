#include "const.cpp"



int main(){

	mkfifo(FIFO_FILENAME, S_IFIFO | 0777);
	
	return 0;

}
