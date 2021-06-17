#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
 
int main(int argc,char **argv)
{        
    if(argc != 3)
    {
        fprintf(stderr,"usage: %s <file name> <access mode>\n",argv[0]);
        return 1;
    }
    if(access(argv[1],F_OK)!=0)
    {
        printf("%s is not existed\n",argv[1]);
        return 1;
    }
 
    int mode = 0;
    sscanf(argv[2], "0%o",&mode);
    if(chmod(argv[1],mode)!=0)
    {
        printf("fail change mode\n");
    }
    else
    {
        printf("success change mode\n");
    }
    return 0;    
}
