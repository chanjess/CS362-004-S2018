/********************************
 * TESTING updateCoins()
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
    int maxBonus = 10;
    int p, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf("TESTING ----- updateCoins()\n");
    printf("********** TESTING ********** COPPER ********** FOR PLAYER 1 **********\n");

    //testing when player 1 has copper only
    for (handCount = 1; handCount <= maxHandCount; handCount++)
    {
        for(bonus = 0; bonus <= maxBonus; bonus++)
        {
            //testing for only player 1
            p=0;

            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.handCount[p] = handCount;                 // set the number of cards on hand
            memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
            updateCoins(p, &G, bonus);
            
            printf("Test player %d with %d treasure card(s) and %d bonus\n", p, handCount, bonus);
            printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);

            assertTrue(G.coins, handCount * 1 + bonus);
        }
    }

    //testing when player 1 has silver only
    printf("********** TESTING ********** SILVER ********** FOR PLAYER 1 **********\n");
    for (handCount = 1; handCount <= maxHandCount; handCount++)
    {
        for(bonus = 0; bonus <= maxBonus; bonus++)
        {
            //testing for only player 1
            p=0;

            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.handCount[p] = handCount;                 // set the number of cards on hand
            memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silvers
            updateCoins(p, &G, bonus);
            
            printf("Test player %d with %d treasure card(s) and %d bonus\n", p, handCount, bonus);
            printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);

            assertTrue(G.coins, handCount * 2 + bonus);
        }
    }

    //testing when player 1 has gold only
    printf("********** TESTING ********** GOLD ********** FOR PLAYER 1 **********\n");
    for (handCount = 1; handCount <= maxHandCount; handCount++)
    {
        for(bonus = 0; bonus <= maxBonus; bonus++)
        {
            //testing for only player 1
            p=0;

            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.handCount[p] = handCount;                 // set the number of cards on hand
            memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
            updateCoins(p, &G, bonus);
            
            printf("Test player %d with %d treasure card(s) and %d bonus\n", p, handCount, bonus);
            printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);

            assertTrue(G.coins, handCount * 3 + bonus);
        }
    }

    printf("********** TESTING ********** COPPER ********** FOR PLAYER 2 **********\n");
    //testing when player 2 has copper only
    for (handCount = 1; handCount <= maxHandCount; handCount++)
    {
        for(bonus = 0; bonus <= maxBonus; bonus++)
        {
            //testing for only player 1
            p=1;

            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.handCount[p] = handCount;                 // set the number of cards on hand
            memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
            updateCoins(p, &G, bonus);
            
            printf("Test player %d with %d treasure card(s) and %d bonus\n", p, handCount, bonus);
            printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);

            assertTrue(G.coins, handCount * 1 + bonus);
        }
    }

    //testing when player 2 has silver only
    printf("********** TESTING ********** SILVER ********** FOR PLAYER 2 **********\n");
    for (handCount = 1; handCount <= maxHandCount; handCount++)
    {
        for(bonus = 0; bonus <= maxBonus; bonus++)
        {
            //testing for only player 1
            p=1;

            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.handCount[p] = handCount;                 // set the number of cards on hand
            memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silvers
            updateCoins(p, &G, bonus);
            
            printf("Test player %d with %d treasure card(s) and %d bonus\n", p, handCount, bonus);
            printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);

            assertTrue(G.coins, handCount * 2 + bonus);
        }
    }

    //testing when player 2 has gold only
    printf("********** TESTING ********** GOLD ********** FOR PLAYER 2 **********\n");
    for (handCount = 1; handCount <= maxHandCount; handCount++)
    {
        for(bonus = 0; bonus <= maxBonus; bonus++)
        {
            //testing for only player 1
            p=1;

            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.handCount[p] = handCount;                 // set the number of cards on hand
            memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
            updateCoins(p, &G, bonus);
            
            printf("Test player %d with %d treasure card(s) and %d bonus\n", p, handCount, bonus);
            printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);

            assertTrue(G.coins, handCount * 3 + bonus);
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