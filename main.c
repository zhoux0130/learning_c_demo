#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>

#define STLEN 1000

void initItemList(char *line,char *itemList[]);

struct product {
    // 产品id
    int id;
    // 产品品牌名称
    char brand[100];
    // 产品名称
    char productName[100];
    // 产品原价
    double originPrice;
    // 产品打折价
    double price;
    // 产品的品类
    char category[100];
    // 产品当前销量
    int quantity;
};

int main() {

    // 通过data文件，读入对应的数据（读文件操作）
    // 每一行的数据对应结构体
    // 将其进行展示
    // 可以从控制台输入对应的编号，表示选择购买的产品
    // 完成对应的产品的库存数据更新，同步到库存信息文件中（写文件操作）
    FILE *fpReader = fopen("../data.txt", "r");
    char lines[STLEN];

    struct product productList[STLEN];
    int productCount = 0;

    while (fgets(lines, STLEN, fpReader)) {
        if( lines[0] == '\n'){
            break;
        }
        struct product item = {};
        char *itemList[7];
        initItemList(lines, itemList);

        item.id = (int) strtol(itemList[0], NULL, 10);
        strcpy(item.brand, itemList[1]);
        strcpy(item.productName,itemList[2]);
        item.originPrice = (float) strtod(itemList[3], NULL);
        item.price = (float) strtod(itemList[4], NULL);
        strcpy(item.category,itemList[5]);
        item.quantity = (int) strtol(itemList[6], NULL, 10);

        printf("%d | %s | %s| 原价：￥%.2f | 促销价：￥%.2f\n", item.id, item.brand, item.productName,
               item.originPrice, item.price);

        productList[productCount] = item;
        productCount++;
    }

    printf("你想要购买哪一件呢？请输入编号吧\n");
    int productId;
    scanf("%d", &productId);
    productList[productId - 1].quantity++;

    printf("TEST");
    FILE *fpWriter = fopen("../data.txt", "w+");
    ftruncate(fpWriter, 0);

    for (int j = 0; j < productCount; ++j) {
        struct product item = productList[j];
        fprintf(fpWriter, "%d,%s,%s,%.2f,%.2f,%s,%d\n", item.id, item.brand, item.productName, item.originPrice,
                item.price, item.category,
                item.quantity);
    }

    return 0;
}

void initItemList(char *lines,char *itemList[]){
    char *itemStr = strtok(lines, ",");
    int i = 0;
    itemList[i] = itemStr;
    while (itemStr != NULL) {
        itemStr = strtok(NULL, ",");
        i++;
        itemList[i] = itemStr;
    }
}

