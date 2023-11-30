/*
THIS FUNCTION WILL GIVE THE PROPABILITY OF EACH POINTS IN POKER 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum {
    Heart,
    Club,
    Diamond,
    Spade
} Color;

const int colorSize = Spade - Heart;

typedef enum {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Guard, Queen, King, Ace
} CardValue;

const int cardValueSize = Ace - Two + 1; // Include Jack

typedef struct {
    Color color;
    CardValue cardValue;
} Card;

const int deckSize = cardValueSize * colorSize;


//this function will just swap two cards, this is used in shuffle deck and sort 
void swap(Card *a, Card *b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

//this function will sort the hand from the lowest to the highest based on the cardValue only
void sort(Card hand[], int handSize){
    for (int i = 0; i < handSize; i++){
        for (int j = i + 1; j < handSize; j++){
            if (hand[i].cardValue > hand[j].cardValue){
                swap(&hand[i], &hand[j]);
            }
        }
    }
}

// this function will mix the 52 cards randomly 
void shuffleDeck(Card deck[], int deckSize) {
    srand(time(NULL));
    for (int i = deckSize - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&deck[i], &deck[j]);
    }
}

//Generate hand 
// this funcion will generate a hand with a given card numbers which will pe propably 7 since there is 2 cards on hand and 5 on the table
void generateHand(Card deck[], Card hand[], int handSize) {
    for (int i = 0; i < handSize; i++) {
        hand[i] = deck[i];
    }
}

//checking for Flush
int isFlush(const Card hand[], int handSize) {
    Color firstColor = hand[0].color;
    for (int i = 1; i < handSize; i++) {
        if (hand[i].color != firstColor) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a hand is a straight
int isStraight(Card hand[], int handSize) {
    // Sort the hand based on card values
    sort(hand, handSize);
    int cnt = 1;
    // Check for consecutive card values
    for (int i = 0; i < handSize - 1; i++) {
        if (hand[i].cardValue + 1 == hand[i + 1].cardValue) {
            cnt++;
        }
        else if(hand[i].cardValue == hand[i + 1].cardValue){}
        else cnt = 1;
        if (cnt == 5) return 1;
    }

    return 0; // Straight
}

//checking for Royal flush
int isRoyalFlush(Card hand[], int handSize) {
    sort(hand, handSize);
    for (int i = 0; i < handSize; i++){
        if (hand[i].cardValue == Ten && isStraight && handSize - i >= 5 && hand[6].cardValue == Ace && (hand[5].cardValue == Ace || hand[5].cardValue == King))
            return 1;
    }
    return 0;
}


//checking for straight Flush
int isStraightFlush(Card hand[], int handSize) {
    sort(hand, handSize);
    for (int i = 0; i < handSize - 2; i++){
        if (isFlush(hand, handSize) && isStraight(hand, handSize) && hand[i].color == hand[i + 1].color && hand[i].color == hand[i + 2].color) 
            return 1;
    }
    return 0;
}


//checking for four of kind
int isFourOfAKind(Card hand[], int handSize) {
    sort(hand, handSize);
    for (int i = 0; i < handSize - 3; i++) {
        if (hand[i].cardValue == hand[i + 1].cardValue &&
            hand[i + 1].cardValue == hand[i + 2].cardValue &&
            hand[i + 2].cardValue == hand[i + 3].cardValue) {
            return 1;
        }
    }
    return 0;
}


//checking for full house
int isFullHouse(Card hand[], int handSize) {
    sort(hand, handSize);
    for (int i = 0; i < handSize - 4; i++){
        if ((hand[i].cardValue == hand[i + 1].cardValue && hand[i + 1].cardValue == hand[i + 2].cardValue &&
            hand[i + 3].cardValue == hand[i + 4].cardValue) ||
           (hand[i].cardValue == hand[i + 1].cardValue && hand[i + 2].cardValue == hand[i + 3].cardValue &&
            hand[i + 2].cardValue == hand[i + 4].cardValue))
            return 1;

    }
    return 0;
}

//checking for thee of kind
int isThreeOfAKind(Card hand[], int handSize) {
    sort(hand, handSize);
    for (int i = 0; i < handSize - 2; i++) {
        if (hand[i].cardValue == hand[i + 1].cardValue && hand[i + 1].cardValue == hand[i + 2].cardValue) {
            return 1;
        }
    }
    return 0;
}

//checking for two pair
int isTwoPair(Card hand[], int handSize) {
    int pairCount = 0;
    sort(hand, handSize);
    for (int i = 0; i < handSize - 1; i++) {
        if (hand[i].cardValue == hand[i + 1].cardValue) {
            pairCount++;
        }
    }
    return pairCount >= 2;
}

//checking for pair
int isPair(Card hand[], int handSize) {
    sort(hand, handSize);
    for (int i = 0; i < handSize - 1; i++) {
        if (hand[i].cardValue == hand[i + 1].cardValue) {
            return 1;
        }
    }
    return 0;
}
//checking Ace high or less
int isAceHighOrLess(Card hand[], int handSize) {
    //checking Ace high or less
    // This is just a placeholder; I couldn't understand how to get Ace High Or less, I never played poker and I am not intending to, to be honest.
    return 0;
}

int main() {
    const int nombreMains = 1000000; // Number of hands to generate

    Card deck[deckSize]; // A standard deck of cards
    Card hand[7]; // Assuming a poker hand consists of 5 cards

    int flushCount = 0;
    int straightCount = 0;
    int royalFlushCount = 0;
    int straightFlushCount = 0;
    int fourOfAKindCount = 0;
    int fullHouseCount = 0;
    int threeOfAKindCount = 0;
    int twoPairCount = 0;
    int pairCount = 0;
    int aceHighOrLessCount = 0;

    // Initialize the deck
    for (int i = 0; i < deckSize; i++) {
        deck[i].color = i % colorSize;
        deck[i].cardValue = (i / colorSize) + 2;
    }

    // Generate hands and calculate probabilities
    for (int i = 0; i < nombreMains; i++) {
        printf("Itération : %d\n", i);
        shuffleDeck(deck, deckSize);
        generateHand(deck, hand, 7);



        // Check for other hands
        if (isRoyalFlush(hand, 7)) {
            royalFlushCount++;
            continue;
        }

        if (isStraightFlush(hand, 7)) {
            straightFlushCount++;
            continue;
        }

        // Check for flush
        if (isFlush(hand, 7)) {
            flushCount++;
            continue;
        }

        // Check for straight
        if (isStraight(hand, 7)) {
            straightCount++;
            continue;
        }
        
        // Check for four of kind
        if (isFourOfAKind(hand, 7)) {
            fourOfAKindCount++;
            continue;
        }

        // Check for Full House
        if (isFullHouse(hand, 7)) {
            fullHouseCount++;
            continue;
        }

        // Check for three of kind
        if (isThreeOfAKind(hand, 7)) {
            threeOfAKindCount++;
            continue;
        }

        // Check for two pair
        if (isTwoPair(hand, 7)) {
            twoPairCount++;
            continue;
        }

        // Check for one pair
        if (isPair(hand, 7)) {
            pairCount++;
            continue;
        }

        
    }

    // Calculate approximate probabilities
    double probFlush = (double) flushCount / nombreMains;
    double probStraight = (double) straightCount / nombreMains;
    double probRoyalFlush = (double) royalFlushCount / nombreMains;
    double probStraightFlush = (double) straightFlushCount / nombreMains;
    double probFourOfAKind = (double) fourOfAKindCount / nombreMains;
    double probFullHouse = (double) fullHouseCount / nombreMains;
    double probThreeOfAKind = (double) threeOfAKindCount / nombreMains;
    double probTwoPair = (double) twoPairCount / nombreMains;
    double probPair = (double) pairCount / nombreMains;

    // Print the probabilities
    printf("Probability of a flush: %lf\n", probFlush);
    printf("Probability of a straight: %lf\n", probStraight);
    printf("Probability of a royal flush: %lf\n", probRoyalFlush);
    printf("Probability of a straight flush: %lf\n", probStraightFlush);
    printf("Probability of four of a kind: %lf\n", probFourOfAKind);
    printf("Probability of a full house: %lf\n", probFullHouse);
    printf("Probability of three of a kind: %lf\n", probThreeOfAKind);
    printf("Probability of two pair: %lf\n", probTwoPair);
    printf("Probability of a pair: %lf\n", probPair);

    return 0;
}
