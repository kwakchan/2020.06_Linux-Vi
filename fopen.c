#include <stdio.h>
 
int main(int argc, char **argv)
{
    if(argc != 3)
    {   
        fprintf(stderr, "Usage:%s <new file> <mode>\n",argv[0]);
        fprintf(stderr, "mode is r or w or a \n");
        return 1;
    }   
 
    FILE *fp = fopen(argv[1],argv[2]);
    if(fp)
    {   
        printf("succeed\n");
        fclose(fp);
    }   
    else
    {   
        printf("failed\n");
    }   
 
    return 0;
}
