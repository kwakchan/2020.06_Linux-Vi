#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <unistd.h>
/* 사용자 name을 출력한다. */
int main()
{
  int pid;
  printf("%s \n", getpwuid(getuid())->pw_name);
}
