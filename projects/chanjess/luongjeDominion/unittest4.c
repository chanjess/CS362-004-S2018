/********************************
 * TESTING supplyCount()
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
    int numPlayer;
    int maxPlayer = 4;
    int seed = 1000;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    int testVariable, testVariable1, testVariable2, testVariable3;
    struct gameState G;

    printf ("TESTING ----- supplyCount()\n");
    printf ("***** TESTING NUMBER OF CURSE CARDS WITH TWO PLAYERS*****\n");  
    
    for (numPlayer = 2; numPlayer <= maxPlayer; numPlayer++)
    {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, &G); // initialize a new game
        testVariable = supplyCount(curse, &G); //setting testVariable to result
        if (numPlayer == 2)
        {
            printf("Results for two players:\n");
            printf("test = %d, expected = %d\n", testVariable, supplyCount(curse, &G));
            assertTrue(testVariable, 10); //when there are two players, there should be 10 curse cards
        }
        else if (numPlayer == 3)
        {
            printf("Results for three players:\n");
            printf("test = %d, expected = %d\n", testVariable, supplyCount(curse, &G));
            assertTrue(testVariable, 20); //when there are three players, there should be 20 curse cards
        }
        else
        {
            printf("Results for four players:\n");
            printf("test = %d, expected = %d\n", testVariable, supplyCount(curse, &G));
            assertTrue(testVariable, 30); // when there are four players, there should be 30 curse cards
        }
    }

    printf ("***** TESTING NUMBER OF ESTATE, DUCHY, PROVINCE WITH TWO PLAYERS*****\n");
    for (numPlayer = 2; numPlayer <= maxPlayer; numPlayer++)
    {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, &G); // initialize a new game
        testVariable1 = supplyCount(estate, &G); //setting testVariable to result
        testVariable2 = supplyCount(duchy, &G); //setting testVariable to result
        testVariable3 = supplyCount(province, &G); //setting testVariable to result

        if (numPlayer == 2)
        {
            printf("Results for two players:\n");
            printf("estate test = %d, expected = 8\n", testVariable1);
            assertTrue(testVariable1, 8); 
            printf("duchy test = %d, expected = 8\n", testVariable2);
            assertTrue(testVariable2, 8); 
            printf("province test = %d, expected = 8\n", testVariable3);
            assertTrue(testVariable3, 8); 
        }
        else if (numPlayer == 3)
        {
            printf("Results for three players:\n");
            printf("estate test = %d, expected = 12\n", testVariable1);
            assertTrue(testVariable1, 12); 
            printf("duchy test = %d, expected = 12\n", testVariable2);
            assertTrue(testVariable2, 12); 
            printf("province test = %d, expected = 12\n", testVariable3);
            assertTrue(testVariable3, 12); 
        }
        else
        {
            printf("Results for four players:\n");
            printf("estate test = %d, expected = 12\n", testVariable1);
            assertTrue(testVariable1, 12); 
            printf("duchy test = %d, expected = 12\n", testVariable2);
            assertTrue(testVariable2, 12); 
            printf("province test = %d, expected = 12\n", testVariable3);
            assertTrue(testVariable3, 12); 
        }
    }

    printf ("***** TESTING NUMBER OF COPPER, SILVER, GOLD *****\n");
    for (numPlayer = 2; numPlayer <= maxPlayer; numPlayer++)
    {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, &G); // initialize a new game
        testVariable1 = supplyCount(copper, &G); //setting testVariable to result
        testVariable2 = supplyCount(silver, &G); //setting testVariable to result
        testVariable3 = supplyCount(gold, &G); //setting testVariable to result
        if(numPlayer == 2)
        { 
            printf("Results for two players:\n");
            printf("copper test = %d, expected = 46\n", testVariable1);
            assertTrue(testVariable1, 46); 
            printf("silver test = %d, expected = 40\n", testVariable2);
            assertTrue(testVariable2, 40); 
            printf("gold test = %d, expected = 30\n", testVariable3);
            assertTrue(testVariable3, 30); 
            
        }
        else if (numPlayer == 3)
        {
            printf("Results for three players:\n");
            printf("copper test = %d, expected = 39\n", testVariable1);
            assertTrue(testVariable1, 39); 
            printf("silver test = %d, expected = 40\n", testVariable2);
            assertTrue(testVariable2, 40); 
            printf("gold test = %d, expected = 30\n", testVariable3);
            assertTrue(testVariable3, 30); 
        }
        else
        {
            printf("Results for four players:\n");
            printf("copper test = %d, expected = 32\n", testVariable1);
            assertTrue(testVariable1, 32); 
            printf("silver test = %d, expected = 40\n", testVariable2);
            assertTrue(testVariable2, 40); 
            printf("gold test = %d, expected = 30\n", testVariable3);
            assertTrue(testVariable3, 30); 
        }

    }
    
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