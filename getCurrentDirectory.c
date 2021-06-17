#include <linux/limits.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char name[PATH_MAX];
    printf("Before Current Directory:%s\n",getcwd(name,PATH_MAX));
    return 0;
}
