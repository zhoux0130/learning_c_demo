#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int suit;
    int number;
} card;

char *itoa(int i, char b[]) {
    char const digit[] = "0123456789";
    char *p = b;
    if (i < 0) {
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do { //Move to where representation ends
        ++p;
        shifter = shifter / 10;
    } while (shifter);
    *p = '\0';
    do { //Move back, inserting digits as u go
        *--p = digit[i % 10];
        i = i / 10;
    } while (i);
    return b;
}

void initCard(card *cards) {
    int cardNum = 0;
    for (int j = 0; j < 4; ++j) {
        for (int i = 1; i <= 13; ++i) {
            card theCard = {.suit=j, .number=i};
            cards[cardNum] = theCard;
            cardNum++;
        }
    }

    card jokerSmall = {.suit=4, .number=14};
    card jokerBig = {.suit=4, .number=15};
    cards[52] = jokerSmall;
    cards[53] = jokerBig;
}

void showCard(card *cardList, int length) {
    char *cardContent = malloc(sizeof(char));

    for (int i = 0; i < length; ++i) {
        card theCard = cardList[i];
        switch (theCard.suit) {
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
        switch (theCard.number) {
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
                itoa(theCard.number, str);
                strcat(cardContent, str);
                break;
        }

        strcat(cardContent, " ");
        printf("%s", cardContent);
    }

}

int main(void) {

    card *cards = malloc(54 * sizeof *cards);
    initCard(cards);
    showCard(cards, 54);

}

