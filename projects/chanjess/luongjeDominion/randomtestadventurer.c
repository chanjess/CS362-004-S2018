/********************************
 * RANDOMLY TESTING ADVENTURER CARD
********************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>


//my own assertTrue function
void assertTrue(int a, int b)
{
    if (a != b)
    {
        printf("TEST: FAILED\n");
    }
}


int main() 
{
    int n;
    int seed = rand();
    int bonus = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handpos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handCount, deckCount, postHandCount, postDeckCount;
    int player, numPlayer;

    srand(time(NULL));

    printf("TESTING RANDOMLY ----- ADVENTURER CARD\n");
   
    
    //code inspired by lecture
    for (n = 0; n < 10; n++)
    {   
        //randoming to get player number
        player = floor(Random() * MAX_PLAYERS);
        numPlayer = rand() % (4 - 2 + 1) + 2;
        initializeGame(numPlayer, k, seed, &G);

        //randomizing parameters for player0
        G.deckCount[player] = floor(Random() * MAX_DECK);
        G.discardCount[player] = floor(Random() * MAX_DECK);
        G.handCount[player] = floor(Random() * MAX_HAND);
        G.whoseTurn = player;

        handCount = G.handCount[player];
        deckCount = G.deckCount[player];

        cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);

        postHandCount = G.handCount[player];
        postDeckCount = G.deckCount[player];

        printf("TESTING ***** Player 1 gaining up to 2 treasure cards (if in deck) *****\n");
        printf("actual = %d, expected = %d\n", postHandCount, handCount+2);
        assertTrue(postHandCount, handCount+2);

    }

    return 0;
}