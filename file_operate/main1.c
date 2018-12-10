#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m3ain(int args, char *argv[]){

    printf("1. 文件的类型及读写基础"
           "2. 文件读写的应用"
           "3. 多个文件引用的支持");

    int i = 10;
    FILE *f1 = fopen("../file", "wb");
    fwrite(&i, sizeof(int), 1, f1);
    fclose(f1);

    FILE *f2 = fopen("../file.txt", "w");
    fprintf(f2, "%d", i);
    fclose(f2);

 //    int number = 32767;
//    putc(number, fpWriter);
//
//    FILE *fpReader = fopen("../binary_number.bin","rb");
//    int ch;
//    while( (ch = getc(fpReader)) != EOF){
//        printf("%d ", ch);
//    }
//    int a;
//    int b;
//    int c;
//
//    char str[30] = "我是中文，试试";
//
//    char str1[10];
//
//    while(fgets(str1, sizeof(str1), fpReader)){
//        char *lineList[10];
//        int i = 0;
//
//        char *token = strtok(str1, ",");
//        while(token) {
//            lineList[i] = token;
//            token = strtok(NULL, ",");
//            i++;
//        }
//    }
//
////    fseek(fpReader,0L, SEEK_END);
//    rewind(fpReader);
//    fwrite(str, 1, strlen(str), fpReader);
//
////    char *a1 = "abc";
////    char *a2 = "def";
////
////    printf("%s, %d", concat(a1, a2), strlen(concat(a1, a2)));
//
//    free_test();

}

