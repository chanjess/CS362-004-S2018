/********************************
 * TESTING ADVENTURER CARD
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
    int card;
    int treasureCount = 0;
    int treasureCountBefore = 0;

    printf("TESTING ----- ADVENTURER CARD()\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    memset(&G2, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G2); // initialize a new game

    memcpy(&G, &G2, sizeof(struct gameState));

    printf("Number of cards in hand: %d\n", G2.handCount[0]);
    printf("Playing...Adventurer Card\n");
    cardEffect(adventurer, choice1, choice2, choice3, &G2, handpos, &bonus);
    printf("TESTING ***** Player 1 gaining up to 2 treasure cards (if in deck) *****\n");
    printf("actual = %d, expected = 7\n", G2.handCount[0]);
    assertTrue(G2.handCount[0], G.handCount[0]+2);

    printf("TESTING ***** How many treasure cards are in Player 1's hand before playing Adventurer\n");
    for (i = 0; i < G.handCount[0]; i++)
    {
        card = G.hand[0][i];
        if (card == copper || card == silver || card == gold)
        {
            treasureCountBefore++;
        }
    }

    printf("TESTING ***** How many treasure cards are in Player 1's hand after playing Adventurer\n");
    for (i = 0; i < G2.handCount[0]; i++)
    {
        card = G2.hand[0][i];
        if (card == copper || card == silver || card == gold)
        {
            treasureCount++;
        }
    }

    printf("TESTING ***** Comparing the two treasure counts: before and after playing Adventurer\n");
    assertTrue(treasureCountBefore + 2, treasureCount);

    printf("TESTING ***** No change to victory card piles ***** \n");
    printf("Province Pile\n");
    assertTrue(G2.supplyCount[province], G.supplyCount[province]);
    printf("Duchy Pile\n");
    assertTrue(G2.supplyCount[duchy], G.supplyCount[duchy]);
    printf("Estate Pile\n");
    assertTrue(G2.supplyCount[estate], G.supplyCount[estate]);

    printf("TESTING ***** No change to kingdom card piles ***** \n");
    for (i = 0; i < 10; i++) 
    {
        assertTrue(G2.supplyCount[k[i]], G.supplyCount[k[i]]);
    }

    printf("TESTING ***** No change to Player 2's Hand and Deck ***** \n");
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