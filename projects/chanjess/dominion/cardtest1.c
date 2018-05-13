/********************************
 * TESTING SMITHY CARD
********************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int fail=0;

//my own assertTrue function
void assertTrue(int a, int b)
{
    if (a == b)
    {
        printf("TEST: PASSED\n");
    }
    else
    {
        printf("TEST: FAILED\n");
        fail++;
    }
}

int main() 
{
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int bonus = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, G2;
    int handpos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;

    printf("TESTING ----- SMITHY CARD()\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    memset(&G2, 23,sizeof(struct gameState));
    initializeGame(numPlayer, k, seed, &G2); // initialize a new game

    memcpy(&G, &G2, sizeof(struct gameState));

    printf("Number of cards in hand: %d\n", G2.handCount[0]);
    printf("Playing...Smithy Card\n");
    cardEffect(smithy, choice1, choice2, choice3, &G2, handpos, &bonus);
    printf("TESTING ***** Player 1 gaining 3 cards *****\n");
    printf("Number of cards in hand: %d\n", G2.handCount[0]);
    printf("actual = %d, expected = 7\n", G2.handCount[0]);
    assertTrue(G2.handCount[0], 7);

    printf("TESTING ***** Player 1 gains 3 cards from own pile ***** \n");
    assertTrue(G2.deckCount[0], G.deckCount[0]-3);

    printf("TESTING ***** No change to victory card piles ***** \n");
    printf("Province Pile\n");
    assertTrue(G2.supplyCount[province], G.supplyCount[province]);
    printf("Duchy Pile\n");
    assertTrue(G2.supplyCount[duchy], G.supplyCount[duchy]);
    printf("Estate Pile\n");
    assertTrue(G2.supplyCount[estate], G.supplyCount[estate]);

    printf("TESTING ***** No change to kingdom card piles\n");
    for (i = 0; i < 10; i++) 
    {
        assertTrue(G2.supplyCount[k[i]], G.supplyCount[k[i]]);
    }

    printf("TESTING ***** No change to Player 2's Hand and Deck\n");
    printf("TESTING Player 2's Hand Count\n");
    assertTrue(G2.handCount[1], G.handCount[1]);
    printf("TESTING Player 2's Deck Count\n");
    assertTrue(G2.deckCount[1], G.deckCount[1]);


    if (fail == 0)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    return 0;
}