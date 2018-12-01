#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARD_COUNT 54

typedef struct {
    int suit;
    int number;
} card;

card *initCard(int suit, int number) {
    card *theCard = malloc(sizeof(card));
    theCard->number = number;
    theCard->suit = suit;
    return theCard;
}

void initCardList(card *cards[]) {
    int cardNum = 0;
    for (int j = 0; j < 4; ++j) {
        for (int i = 1; i <= 13; ++i) {
            cards[cardNum] = initCard(j, i);
            cardNum++;
        }
    }

    card *jokerSmall = initCard(4, 14);//小王
    card *jokerBig = initCard(4, 15);//大王
    cards[52] = jokerSmall;
    cards[53] = jokerBig;
}

void showCard(card *cardList[], int length) {
    char *cardContent = malloc(sizeof(char));

    for (int i = 0; i < length; ++i) {
        card *theCard = cardList[i];
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
        switch (theCard->number) {
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
                sprintf(str, "%d", theCard->number);
                strcat(cardContent, str);
                break;
        }

        strcat(cardContent, " ");
        printf("%s", cardContent);
    }

}

int main(void) {
    card *cards[CARD_COUNT];
    initCardList(cards);
    showCard(cards, CARD_COUNT);

    for (int i = 0; i < CARD_COUNT; ++i) {
        free(cards[i]);
    }
}

