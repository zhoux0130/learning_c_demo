#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
    int id;
    char *brand;
    char *name;
    double originPrice;
    double price;
    int quantity;
} product;

void initList(char *itemList[], char *str) {

}

int m1ain() {

    FILE *fp = fopen("../data.txt", "r+");
    char *tmp = malloc(sizeof(char));

    while (fgets(tmp, 100, fp)) {
        if (tmp[0] == '\n') {
            break;
        }
        // 解析每一行数据，按照"逗号"隔开
        char *itemList[7];
        char *itemStr = strtok(tmp, ",");
        int i = 0;
        itemList[i] = itemStr;
        while (itemStr != NULL) {
            itemStr = strtok(NULL, ",");
            i++;
            itemList[i] = itemStr;
        }

        printf("%s | %s | %s| 原价：￥%s | 促销价：￥%s\n", itemList[0], itemList[1], itemList[2],
               itemList[3], itemList[4]);
    }


    fclose(fp);
    return 0;
}


