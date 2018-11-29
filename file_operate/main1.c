#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(const char *s1, const char *s2);
void free_test();

int main(int args, char *argv[]){

    FILE *fpReader = fopen("../test.txt","r+");
    int a;
    int b;
    int c;

    char str[30] = "我是中文，试试";

    char str1[10];

    while(fgets(str1, sizeof(str1), fpReader)){
        char *lineList[10];
        int i = 0;

        char *token = strtok(str1, ",");
        while(token) {
            lineList[i] = token;
            token = strtok(NULL, ",");
            i++;
        }
    }

//    fseek(fpReader,0L, SEEK_END);
    rewind(fpReader);
    fwrite(str, 1, strlen(str), fpReader);

//    char *a1 = "abc";
//    char *a2 = "def";
//
//    printf("%s, %d", concat(a1, a2), strlen(concat(a1, a2)));

    free_test();

}

char *concat(const char *s1, const char *s2){
    char *result;
    result = malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

void free_test(){
    int *p;
    p = (int *) malloc(sizeof(int));

    scanf("%d", &p[0]);
    printf("%d\n", p[0]);

    free(p);
    printf("%x\n", p);
    printf("%d\n", p[0]);
}

