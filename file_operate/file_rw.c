//#include <stdio.h>
//#include <stdlib.h>
//#include <memory.h>
//
//typedef struct {
//    int id;
//    char brand[100];
//    char name[100];
//    double originPrice;
//    double price;
//    char category[100];
//    int quantity;
//} product;
//
//void initList(char *itemList[], char *str) {
//    char *itemStr = strtok(str, ",");
//    int i = 0;
//    itemList[i] = itemStr;
//    while (itemStr != NULL) {
//        itemStr = strtok(NULL, ",");
//        i++;
//        itemList[i] = itemStr;
//    }
//}
//
//void initProduct(product *item, char *itemList[]){
//    int id = (int) strtol(itemList[0], NULL, 10);
//    double originPrice = (double) strtod(itemList[3], NULL);
//    double price = (double) strtod(itemList[4], NULL);
//    int quantity = (int) strtol(itemList[6], NULL, 10);
//
//    item->id = id;
//    strcpy(item->brand,itemList[1]);
//    strcpy(item->name,itemList[2]);
//    item->originPrice = originPrice;
//    item->price = price;
//    strcpy(item->category,itemList[2]);
//    item->quantity = quantity;
//}
//
//int m1ain() {
//
//    FILE *fp = fopen("../data.txt", "r+");
//    char tmp[100];
//    product *productList[100];
//    int productCount = 0;
//
//    while (fgets(tmp, 100, fp)) {
//        if (tmp[0] == '\n') {
//            break;
//        }
//        // 解析每一行数据，按照"逗号"隔开
//        char *itemList[7];
//        initList(itemList, tmp);
//
//        printf("%s | %s | %s| 原价：￥%s | 促销价：￥%s\n", itemList[0], itemList[1], itemList[2],
//               itemList[3], itemList[4]);
//
//        product *item = malloc(sizeof(product));
//        initProduct(item, itemList);
//        productList[productCount] = item;
//        productCount++;
//    }
//
//    //写入文件的操作
//    int index = 1;
//    productList[index]->quantity ++;
//
//    rewind(fp);
//
//    for (int i = 0; i < productCount; ++i) {
//        product *item = productList[i];
//        fprintf(fp, "%d,%s,%s,%.2f,%.2f,%s,%d\n", item->id, item->brand, item->name, item->originPrice,
//                item->price, item->category,
//                item->quantity);
//    }
//
//    fclose(fp);
//
//    return 0;
//}
//
//
