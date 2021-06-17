#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  char buf[30];
  if(argc<2){
    fprintf(stderr, "usage: ./unistd_Chdir path\n");
    exit(1);
  }
  if(chdir(argv[1])==0){
    getcwd(buf, 30);
    printf("path: %s\n", buf);    
  }
  else{
    fprintf(stderr, "path error\n");
    exit(1);
  }
}  

