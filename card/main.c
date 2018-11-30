#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
  struct card *newNode;

  newNode = malloc(sizeof(struct card));
  newNode->suit = suit;
  newNode->numbers = number;
  newNode->next = list;

  return newNode;
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

void printCard(struct card *cardList){
  struct card *cur;
  for(cur = cardList; cur != NULL;cur = cur->next){
    printf("花色：%d, 数值：%d\n", cur->suit, cur->numbers);
  }
}

int length(struct card *cardList){
  struct card *card = cardList;
  int len = 0;
  while(card != NULL){
    ++len;
    card = card->next;
  }
  return len;
}


int main() {
  srand(time(NULL));

  struct card *cardList = initCard();
  // 模拟出3个人，给每个人发牌
  struct card *personalCardList[3] = { NULL };

  int cardNum = 54;
  // 一共有3个人要分牌
  for(int i = 0; i < 3; i++){
    // 每个人分17张牌
    for(int j = 0; j < 17; j++){
      int rand_n = rand() % cardNum;
      struct card *cardNode = getNthNode(cardList, rand_n);
      personalCardList[i] = add2List(personalCardList[i], cardNode->suit, cardNode->numbers);

      cardNum--;
      cardList = deleteNode(cardList, cardNode->suit,cardNode->numbers);
    }
    printf("当前这个人拿了%d张牌\n", length(personalCardList[i]));
  }

  printCard(personalCardList[0]);
  printf("第二个人的牌\n");
  printCard(personalCardList[1]);
  printf("第3个人的牌\n");
  printCard(personalCardList[2]);

  return 0;
}
