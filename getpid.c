#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/* 나의 프로세스 번호를 출력한다. */
int main()
{ 
  int pid;
  printf("%d \n", getpid());
}
