/********************************
 * TESTING isGameOver()
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
    int numPlayer = 2;
    int seed = 1000;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    int testVariable;
    struct gameState G;

    printf ("TESTING ----- isGameOver()\n");
    printf ("***** TESTING IF STACK OF PROVINCE CARDS IS EMPTY *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.supplyCount[province] = 0; //setting province cards to empty
    testVariable = isGameOver(&G); //setting testVariable to result
    assertTrue(testVariable, 1); //if testVariable equals to 1, then game is over

    printf ("***** TESTING IF THREE SUPPLY DECKS ARE EMPTY *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.supplyCount[0] = 0; //setting supply decks to empty
    G.supplyCount[1] = 0;
    G.supplyCount[2] = 0;
    testVariable = isGameOver(&G); //setting testVariable to result
    assertTrue(testVariable, 1); //if testVariable equals to 1, then game is over

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
