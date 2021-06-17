#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  FILE* readFile;
  unsigned char buf[2] = "";
  long lSize;
  int totalLine = 0;

    //인자의 개수가 맞지 않을때
    if (argc != 2) {
        
        fprintf(stdout, "usage:인자의 개수가 잘못되었습니다. \n %s  test.txt 또는  test.txt 형식입니다. \n" , argv[0]);
    }
    
    
    //argv[2]에 파일명이 일 때
    readFile = fopen(argv[1], "r");
       
    //파일 열기 오류 처리
    if (readFile == NULL) {
           fprintf(stdout, "%s 오류가 발생했습니다." , argv[2]);
           exit(1);
    }  

    //파일 읽기 - 파일의 전체 행 개수 구하기
    for (; ; ) {

        int readByteNum = fread(buf, sizeof(char) , 1 , readFile);

        //파일 다읽으면 빠져나오기
        if (readByteNum == 0) {
            break;
        }    
	
	int retN = strcmp((const char *)buf, "\n");    // \n 문자열 비교

        //개행 체크
        if(retN == 0){
            totalLine += 1;
        }
    }

    printf("tatal line : %d \n" , totalLine);	
}
