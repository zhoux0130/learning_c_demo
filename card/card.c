#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct card {
    int suit;
    int number;
};

//struct card *addCardInSort(struct card *list, int suit, int number) {
//    struct card *cur, *prev, *head;
//
//    struct card *newNode = malloc(sizeof(struct card));
//    newNode->suit = suit;
//    newNode->numbers = number;
//    newNode->next = NULL;
//
//    if (list == NULL ) {
//        return newNode;
//    }
//
//    cur = list;
//    head = list;
//    prev = NULL;
//    while(cur != NULL &&
//          (cur->numbers < number || (cur->numbers == number && cur->suit < suit))){
//        prev = cur;
//        cur = cur->next;
//    }
//
//    if(prev == NULL){
//        head = newNode;
//    }else{
//        prev->next = newNode;
//    }
//    newNode->next = cur;
//
//    return head;
//}


void initCard(struct card **cardList){
    int cardNum = 0;
    for (int j = 0; j < 4; ++j) {
        for (int i = 1; i <= 13; ++i) {
            struct card *theCard = malloc(sizeof(struct card));
            theCard->suit = j;
            theCard->number = i;
            cardList[cardNum] = theCard;
            cardNum ++;
        }
    }

    struct card *jokerSmall = malloc(sizeof(struct card));
    jokerSmall->number = 14;
    jokerSmall->suit = 4;
    cardList[52] = jokerSmall;

    struct card *jokerBig = malloc(sizeof(struct card));
    jokerBig->number = 15;
    jokerBig->suit = 4;
    cardList[53] = jokerSmall;
}

void showCard(struct card **cardList, int length){
    char *card = malloc(sizeof(char));

    for (int i = 0; i < length; ++i) {
        struct card *theCard = cardList[i];
        switch (theCard->suit){
            case 0:
                strcpy(card, "♦");
                break;
            case 1:
                strcpy(card, "♣");
                break;
            case 2:
                strcpy(card, "♥");
                break;
            case 3:
                strcpy(card, "♠");
                break;
            default:
                strcpy(card, "Joker");
                break;
        }
        char buffer[3];
        itoa(theCard->number, buffer, 10);
        strcat(card, buffer);
        strcat(card, " ");
    }

    printf("%s", card);
}

int main(void) {

    initCard();

}

