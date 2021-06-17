#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
char *ptr;
ptr = getenv("SHELL");
printf("SHELL = %s \n", ptr);
exit(0);
}
