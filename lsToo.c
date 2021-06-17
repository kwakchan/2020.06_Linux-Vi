#include <sys/types.h> 
#include <sys/stat.h>
#include <sys/time.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*,char*, struct stat*);
int main(int argc, char **argv) 
{
   DIR *dp;
   char *dir;
   struct dirent *d;
   struct stat st;
   char path[BUFSIZ+1];

   dir = ".";    

   if(argc == 1) { 
      if ((dp = opendir(dir)) == 0) {  
         exit(1);
      }
      while ((d = readdir(dp)) != 0)   
         if(strcmp(d->d_name,".") == 0 || strcmp(d->d_name,"..") == 0)
            continue; 
         else
            printf("%s  ", d->d_name); 
      closedir(dp);
      printf("\n");
   }
   else if(strcmp(argv[1],"-a") == 0){ 
   
      if ((dp = opendir(dir)) == 0)  
         perror(dir);
   
      while ((d = readdir(dp)) != 0)  
         printf("%s  ", d->d_name);   
   
      closedir(dp);
      printf("\n");
   }
   else if(strcmp(argv[1],"-l") == 0){
   
      if ((dp = opendir(dir)) == 0) 
         perror(dir);

      while ((d = readdir(dp)) != 0) {
         sprintf(path, "%s/%s", dir, d->d_name);
         if (lstat(path, &st) < 0) 
            perror(path);
         else if(strcmp(d->d_name,".") == 0 || strcmp(d->d_name,"..") == 0)
            continue;
         else 
            printStat(path, d->d_name, &st);
      }
      closedir(dp);
   }
   else if(strcmp(argv[1],"-al") == 0){
   
      if ((dp = opendir(dir)) == 0)
         perror(dir);

      while ((d = readdir(dp)) != 0) {
         sprintf(path, "%s/%s", dir, d->d_name);
         if(lstat(path, &st) < 0)   
            perror(path);
         printStat(path, d->d_name, &st);
      }
      closedir(dp);
   }
   else {
      printf("%s\n","dl\ndl -a\ndl -l\ndl -al\n위 명령들만 사용가능합니다.");
   }
   exit(0);
}

void printStat(char *pathname, char *file, struct stat *st) {

   printf("%c%s", type(st->st_mode), perm(st->st_mode));
   printf("%3ld ", st->st_nlink);
   printf("%s %s ", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
   printf("%9ld ", st->st_size);
   printf("%.12s ", ctime(&st->st_mtime)+4);
   printf("%s\n", file);
}

char type(mode_t mode) {
   
   if (S_ISREG(mode)) 
      return('-');
   if (S_ISDIR(mode)) 
      return('d');
   if (S_ISCHR(mode)) 
      return('c');
   if (S_ISBLK(mode)) 
      return('b');
   if (S_ISLNK(mode)) 
      return('l');
   if (S_ISFIFO(mode)) 
      return('p');
   if (S_ISSOCK(mode)) 
      return('s');
}

char* perm(mode_t mode) {
   int i;
   static char perms[10]; 

   strcpy(perms, "---------");
   
   for (i=0; i < 3; i++) {
      if (mode & (S_IREAD >> i*3)) 
         perms[i*3] = 'r';
      if (mode & (S_IWRITE >> i*3)) 
         perms[i*3+1] = 'w';
      if (mode & (S_IEXEC >> i*3)) 
         perms[i*3+2] = 'x';
   }
   return(perms);
}
