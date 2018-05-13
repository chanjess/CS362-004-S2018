/********************************
 * RANDOMLY TESTING SMITHY CARD
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

int fail=0;
int drawCardFail=0;
int discardFail=0;
int cardEffectFail=0;

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

//code inspired by lecture (test oracle)
void checkSmithy(int p, struct gameState *post)
{
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    int i, a, b, c;

    struct gameState pre;

    //copy post to pre
    memcpy(&pre, post, sizeof(struct gameState));

    //player gain 3 cards for pre
    for(i = 0; i < 3; i++)
    {
        //check if drawCard failed
        a = drawCard(p, &pre);

        if (a != 0)
        {
            drawCardFail++;
        }
    }
    //player discard card for pre
    b = discardCard(0, p, &pre, 0);

    //playing smithy card for post
    c = cardEffect(smithy, choice1, choice2, choice3, post, handPos, &bonus);

    //check if discardCard or cardEffect failed
    if(b != 0)
    {
        discardFail++;
    }
    if(c != 0)
    {
        cardEffectFail++;
    }

    int preHandCount = pre.handCount[p];
    int preDeckCount = pre.deckCount[p];
    int postHandCount = post->handCount[p];
    int postDeckCount = post->deckCount[p];
    
    printf("TESTING ***** Player 1 gains 3 cards ***** \n");
    printf("actual = %d, expected = %d\n", postHandCount, preHandCount);
    assertTrue(postHandCount, preHandCount);

    printf("TESTING ***** Player 1 gains 3 cards from own pile ***** \n");
    printf("actual = %d, expected = %d\n", postDeckCount, preDeckCount);
    assertTrue(postDeckCount, preDeckCount);
    
}



int main() 
{
    int n, i, player;
 
    srand(time(NULL));

    struct gameState G;

    printf("TESTING RANDOMLY ----- SMITHY CARD\n");
   
    //code inspired by lecture
    for (n = 0; n < 2000; n++)
    {   
        for (i = 0; i < sizeof(struct gameState); i++)
        {
            //creating gameState G filled with random bytes
            ((char*)&G)[i] = floor(Random() * 256);
        }
        
        
        //randoming to get player number
        player = floor(Random() * MAX_PLAYERS);

        //randomizing parameters for player0
        G.deckCount[player] = floor(Random() * MAX_DECK);
        G.discardCount[player] = floor(Random() * MAX_DECK);
        G.handCount[player] = floor(Random() * MAX_HAND);
        G.playedCardCount = floor(Random() * MAX_DECK - 1);
        G.whoseTurn = player;

        //calling Test Oracle with these inputs
        checkSmithy(player, &G);
    }

    if (fail == 0 && drawCardFail == 0 && discardFail == 0 && cardEffectFail == 0)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    else
    {
        printf("TEST FAILED\n");
        printf("***** DISPLAYING TEST RESULTS OF DRAW CARD ***** \n");
        printf("Number of failed drawCard: = %d\n", drawCardFail);

        printf("***** DISPLAYING TEST RESULTS OF DISCARD CARD FUNCTION ***** \n");
        printf("Number of failed discardCard: %d\n", discardFail);

        printf("***** DISPLAYING TEST RESULTS OF CARD EFFECT ***** \n");
        printf("Number of failed cardEffect: %d\n", cardEffectFail);
    }

    return 0;
}