#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

const char* FILENAME = "file.txt";
const char* FIFO_FILENAME = "1.fifo";
const size_t BUFFLEN = 100;
