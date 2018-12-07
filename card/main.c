#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * 扑克牌的结构体
 */
struct card {
    int suit; // 0:♦， 1：♣ ，2：♥， 3：♠, 4：Joker
    int numbers; //1->13: A,2,3,4,5,6,7,8,9,10,J,Q,K

    struct card *next;
};

/**
 * 在链表的头部插入元素
 */
struct card *add2List(struct card *list, int suit, int number) {
    struct card *newNode = malloc(sizeof(struct card));

    newNode->suit = suit;
    newNode->numbers = number;
    newNode->next = list;

    return newNode;
}


void cleanCardList(struct card *list) {
  while (list) {
    struct card *cur = list;
    list = list->next;
    free(cur);
  }
}


/**
 * 删除链表中的指定元素
 */
struct card *deleteNode(struct card *list, int suit, int number) {
    struct card *cur, *prev = NULL;
    for (cur = list;
         cur != NULL && (cur->suit != suit || cur->numbers != number);
         prev = cur, cur = cur->next);

    if (cur == NULL) {
        return list;
    }

    if (prev == NULL) {
        list = list->next;
    } else {
        prev->next = cur->next;
    }

    free(cur);
    return list;
}

/**
 * 获取链表中的第N个元素
 */
struct card *getNthNode(struct card *list, int n) {
    struct card *cardNode = list;
    for (int i = 0; i < n; i++) {
        cardNode = cardNode->next;
    }
    return cardNode;
}

/**
 * 初始化一套扑克牌
 * @param cardList
 */
struct card *initCard() {
    struct card *cardList = NULL;
    for (int i = 1; i < 14; i++) {
        for (int j = 0; j < 4; j++) {
            cardList = add2List(cardList, j, i);
        }
    }

    // 初始化大小王
    cardList = add2List(cardList, 4, 14);
    cardList = add2List(cardList, 4, 15);
    return cardList;
}

/**
 * 链表的插入排序
 */
struct card *addCardInSort(struct card *list, int suit, int number) {
    struct card *newNode = malloc(sizeof(struct card));
    newNode->suit = suit;
    newNode->numbers = number;
    newNode->next = NULL;

    if (list == NULL) {
        return newNode;
    }

    struct card *cur, *prev, *head;
    cur = list;
    head = list;
    prev = NULL;
    while (cur != NULL &&
           (cur->numbers < number || (cur->numbers == number && cur->suit < suit))) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        head = newNode;
    } else {
        prev->next = newNode;
    }
    newNode->next = cur;

    return head;
}

/**
 * 链表的插入排序
 */
int hasCycle(struct card *list) {
    if (list == NULL) {
        return 0;
    }

    struct card *step = list, *doubleStep = list;
    while (step && doubleStep->next) {
        step = step->next;
        doubleStep = doubleStep->next->next;

        if (NULL == doubleStep) {
            return 0;
        }
        if (step == doubleStep) {
            return 1;
        }
    }
    return 0;
}

void printCard(struct card *cardList) {
    struct card *cur;

    for (cur = cardList; cur != NULL; cur = cur->next) {
        printf("花色：%d, 数值：%d\n", cur->suit, cur->numbers);
    }
}

int length(struct card *cardList) {
    struct card *card = cardList;
    int len = 0;
    while (card != NULL) {
        ++len;
        card = card->next;
    }
    return len;
}

void showCard(struct card *cardList) {
    /* char *cardContent = malloc(sizeof(char)); */
    // 上面的malloc大小不够，直接使用数组即可。
    char cardContent[10];
    struct card *theCard = cardList;

    while (theCard != NULL) {
        switch (theCard->suit) {
            case 0:
                strcpy(cardContent, "♦");
                break;
            case 1:
                strcpy(cardContent, "♣");
                break;
            case 2:
                strcpy(cardContent, "♥");
                break;
            case 3:
                strcpy(cardContent, "♠");
                break;
            default:
                strcpy(cardContent, "Joker");
                break;
        }

        char str[10];
        switch (theCard->numbers) {
            case 1:
                strcat(cardContent, "A");
                break;
            case 11:
                strcat(cardContent, "J");
                break;
            case 12:
                strcat(cardContent, "Q");
                break;
            case 13:
                strcat(cardContent, "K");
                break;
            default:
                sprintf(str, "%d", theCard->numbers);
                strcat(cardContent, str);
                break;
        }

        strcat(cardContent, " ");
        printf("%s", cardContent);
        theCard = theCard->next;
    }
}


int main() {
    srand(time(NULL));

    struct card *cardList = initCard();
    // 模拟出3个人，给每个人发牌
    struct card *personalCardList[3] = {NULL};

    int cardNum = 54;
    // 一共有3个人要分牌
    for (int i = 0; i < 3; i++) {
        // 每个人分17张牌
        for (int j = 0; j < 17; j++) {
            int rand_n = rand() % cardNum;
            struct card *cardNode = getNthNode(cardList, rand_n);
            personalCardList[i] =
                    addCardInSort(personalCardList[i], cardNode->suit, cardNode->numbers);
//                    add2List(personalCardList[i], cardNode->suit, cardNode->numbers);

            cardNum--;
            cardList = deleteNode(cardList, cardNode->suit, cardNode->numbers);
        }
    }

    printf("A拿到的牌\n");
    showCard(personalCardList[0]);
    printf("\nB拿到的牌\n");
    showCard(personalCardList[1]);
    printf("\nC拿到的牌\n");
    showCard(personalCardList[2]);

    printf("\n谁来当地主？\n");
    int index;
    scanf("%d", &index);

    printf("\n底牌为:\n");
    showCard(cardList);

    while (cardList != NULL) {
        struct card *leftCard = cardList;
        personalCardList[index] = addCardInSort(personalCardList[index], leftCard->suit, leftCard->numbers);
        cardList = cardList->next;
    }

    printf("\n地主的牌重新整理:\n");
    showCard(personalCardList[index]);


//    struct card c3 = {.numbers=1, .suit=1};
//    struct card c2 = {.numbers=2, .suit=2, .next=&c3};
//    struct card c1 = {.numbers=3, .suit=3, .next=&c2};
////    c3.next= &c1;
//
//    printf("%d",hasCycle(&c1));

    cleanCardList(cardList);
    for (int i = 0; i < sizeof(personalCardList) / sizeof(personalCardList[0]); i++) {
      cleanCardList(personalCardList[i]);
    }

    return 0;
}
