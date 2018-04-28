/********************************
 * TESTING getCost()
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

    printf ("TESTING ----- getCost()\n");
    printf ("***** TESTING ***** CURSE CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    testVariable = getCost(curse); //setting testVariable to result
    printf("card cost = %d, expected = 0\n", testVariable);
    assertTrue(testVariable, 0); 

    printf ("***** TESTING ***** ESTATE CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(estate); //setting testVariable to result
    printf("card cost = %d, expected = 2\n", testVariable);
    assertTrue(testVariable, 2); 

    printf ("***** TESTING ***** DUCHY CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(duchy); //setting testVariable to result
    printf("card cost = %d, expected = 5\n", testVariable);
    assertTrue(testVariable, 5);

    printf ("***** TESTING ***** PROVINCE CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(province); //setting testVariable to result
    printf("card cost = %d, expected = 8\n", testVariable);
    assertTrue(testVariable, 8);

    printf ("***** TESTING ***** COPPER CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(copper); //setting testVariable to result
    printf("card cost = %d, expected = 0\n", testVariable);
    assertTrue(testVariable, 0);

    printf ("***** TESTING ***** SILVER CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(silver); //setting testVariable to result
    printf("card cost = %d, expected = 3\n", testVariable);
    assertTrue(testVariable, 3);

    printf ("***** TESTING ***** GOLD CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(gold); //setting testVariable to result
    printf("card cost = %d, expected = 6\n", testVariable);
    assertTrue(testVariable, 6);

    printf ("***** TESTING ***** ADVENTURER CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(adventurer); //setting testVariable to result
    printf("card cost = %d, expected = 6\n", testVariable);
    assertTrue(testVariable, 6);

    printf ("***** TESTING ***** COUNCIL ROOM CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(council_room); //setting testVariable to result
    printf("card cost = %d, expected = 5\n", testVariable);
    assertTrue(testVariable, 5);

    printf ("***** TESTING ***** FEAST CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(feast); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** GARDENS CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(gardens); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** MINE CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(mine); //setting testVariable to result
    printf("card cost = %d, expected = 5\n", testVariable);
    assertTrue(testVariable, 5);

    printf ("***** TESTING ***** REMODEL CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(remodel); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** SMITHY CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(smithy); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** GARDENS CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(gardens); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** VILLAGE CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(village); //setting testVariable to result
    printf("card cost = %d, expected = 3\n", testVariable);
    assertTrue(testVariable, 3);

    printf ("***** TESTING ***** BARON CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(baron); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** GREAT HALL CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(great_hall); //setting testVariable to result
    printf("card cost = %d, expected = 3\n", testVariable);
    assertTrue(testVariable, 3);

    printf ("***** TESTING ***** MINION CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(minion); //setting testVariable to result
    printf("card cost = %d, expected = 5\n", testVariable);
    assertTrue(testVariable, 5);

    printf ("***** TESTING ***** STEWARD CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(steward); //setting testVariable to result
    printf("card cost = %d, expected = 3\n", testVariable);
    assertTrue(testVariable, 3);

    printf ("***** TESTING ***** TRIBUTE CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(tribute); //setting testVariable to result
    printf("card cost = %d, expected = 5\n", testVariable);
    assertTrue(testVariable, 5);

    printf ("***** TESTING ***** AMBASSADOR CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(ambassador); //setting testVariable to result
    printf("card cost = %d, expected = 3\n", testVariable);
    assertTrue(testVariable, 3);

    printf ("***** TESTING ***** CUTPURSE CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(cutpurse); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** EMBARGO CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(embargo); //setting testVariable to result
    printf("card cost = %d, expected = 2\n", testVariable);
    assertTrue(testVariable, 2);

    printf ("***** TESTING ***** OUTPOST CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(outpost); //setting testVariable to result
    printf("card cost = %d, expected = 5\n", testVariable);
    assertTrue(testVariable, 5);

    printf ("***** TESTING ***** SALVAGER CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(salvager); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** SEA HAG CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(sea_hag); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);

    printf ("***** TESTING ***** SALVAGER CARD *****\n");
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    testVariable = getCost(treasure_map); //setting testVariable to result
    printf("card cost = %d, expected = 4\n", testVariable);
    assertTrue(testVariable, 4);
	
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