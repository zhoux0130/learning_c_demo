#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>

#define STLEN 1000

void initItemList(char *line, char *itemList[]);

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

int main(int argc, char **argv) {

    FILE *fpReader = fopen(argv[1], "r+");
    char lines[STLEN];

    struct product productList[STLEN];
    int productCount = 0;

    while (fgets(lines, STLEN, fpReader)) {
        if (lines[0] == '\n') {
            break;
        }
        struct product item = {};
        char *itemList[7];
        initItemList(lines, itemList);

        item.id = (int) strtol(itemList[0], NULL, 10);
        strcpy(item.brand, itemList[1]);
        strcpy(item.productName, itemList[2]);
        item.originPrice = (float) strtod(itemList[3], NULL);
        item.price = (float) strtod(itemList[4], NULL);
        strcpy(item.category, itemList[5]);
        item.quantity = (int) strtol(itemList[6], NULL, 10);

        printf("%d | %s | %s| 原价：￥%.2f | 促销价：￥%.2f\n", item.id, item.brand, item.productName,
               item.originPrice, item.price);

        productList[productCount] = item;
        productCount++;
    }

    printf("您是管理员吗？(Y|N)");
    char str;
    scanf("%c", &str);

    if (str == 'Y') {
        fprintf(fpReader, "%d,%s,%s,%.2f,%.2f,%s,%d\n", 3, "苹果", "iPad Pro 11寸", 6499.0,
                6099.0, "IT",
                4);
    } else {
        printf("你想要购买哪一件呢？请输入编号吧\n");
        int productId;
        scanf("%d", &productId);
        productList[productId - 1].quantity++;

        rewind(fpReader);

        for (int j = 0; j < productCount; ++j) {
            struct product item = productList[j];
            fprintf(fpReader, "%d,%s,%s,%.2f,%.2f,%s,%d\n", item.id, item.brand, item.productName, item.originPrice,
                    item.price, item.category,
                    item.quantity);
        }
    }

    return 0;
}

void initItemList(char *lines, char *itemList[]) {
    char *itemStr = strtok(lines, ",");
    int i = 0;
    itemList[i] = itemStr;
    while (itemStr != NULL) {
        itemStr = strtok(NULL, ",");
        i++;
        itemList[i] = itemStr;
    }
}

