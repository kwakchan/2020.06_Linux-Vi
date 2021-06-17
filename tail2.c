#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//파일의 마지막 10줄 읽기
#define lastTailNum 10

int main(int argc, char *argv[]){    
    FILE* readFile;
    unsigned char buf[2] = "";
    long lSize;
    int totalLine = 0;
    
    //인자의 개수가 맞지 않을때
    if (argc != 2) {
        fprintf(stdout, "usage:인자의 개수가 잘못되었습니다. \n %s  test.txt 또는  test.txt 형식입니다. \n" , argv[0]);
    }
   
    //argv[2]에 파일명이 존재
    //파일열기 - 읽기전용
    readFile = fopen(argv[1], "r");
       
    //파일 열기 오류 처리
    if (readFile == NULL) {
           fprintf(stdout, "%s 오류가 발생했습니다." , argv[2]);
           exit(1);
    }
          
    //파일 크기 구하기
    fseek(readFile, 0 , SEEK_END);
    lSize = ftell(readFile);
    rewind(readFile);
       
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
    
    //파일 읽은 위치 처음으로 되돌리기
     rewind(readFile);
   
    // 마지막 n 번째 줄 까지 출력
    int lastOutLine = 0;
    int nowNum = 0;
    
    lastOutLine = totalLine - lastTailNum;
    
    for (; ; ) {
        
       int readByteNum = fread(buf, sizeof(char) , 1 , readFile);
        
        //파일 다읽으면 빠져나오기
        if (readByteNum == 0) {
            break;
        }
        
        //마지막 n 번째 줄 출력하기
        if(lastTailNum <= totalLine){
            if((lastOutLine <= nowNum) && (nowNum < totalLine)){
                
                //터미널에 표준출력
                fwrite(buf, sizeof(char) , 1 , stdout);
            }
            //개행 체크
            int retN = strcmp((const char *)buf, "\n");    // \n 문자열 비교
            if(retN == 0){  nowNum += 1; }
            
        }else {
        //전체 출력
            //터미널에 표준출력
            fwrite(buf, sizeof(char) , 1 , stdout);   
        }
    } // for - end
    
    fclose(readFile);
    exit(0);
}
