#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>

int main(int argc, char *argv[]){
  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s <path name>\n", argv[0]);
    return 1;
  }	  
  mkdir(argv[1], 0777);
  exit(0);
}
