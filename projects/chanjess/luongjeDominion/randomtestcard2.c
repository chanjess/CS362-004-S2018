/********************************
 * RANDOMLY TESTING COUNCIL ROOM CARD
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
int numBuysFail=0;
int otherPlayerHandFail=0;

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
void checkCouncil(int p, struct gameState *post)
{
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;
    int i, a, b, c, d;

    struct gameState pre;

    //copy post to pre
    memcpy(&pre, post, sizeof(struct gameState));
    
    //PRE
    //player gain 4 cards for pre
    for(i = 0; i < 4; i++)
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

    //increase number of buys for pre
    pre.numBuys++;


    //POST
    //playing council card for post
    c = cardEffect(council_room, choice1, choice2, choice3, post, handPos, &bonus);


    //check if discardCard, numBuys, cardEffect failed
    if(b != 0)
    {
        discardFail++;
    }
    if(c != 0)
    {
        cardEffectFail++;
    }
    if(pre.numBuys != post->numBuys)
    {
        numBuysFail++;
    }

    int preHandCount = pre.handCount[p];
    int preDeckCount = pre.deckCount[p];
    int postHandCount = post->handCount[p];
    int postDeckCount = post->deckCount[p];
    
    printf("TESTING ***** Player 1 gains 4 cards ***** \n");
    printf("actual = %d, expected = %d\n", postHandCount, preHandCount);
    assertTrue(postHandCount, preHandCount);

    printf("TESTING ***** Player 1 gains 4 cards from own pile ***** \n");
    printf("actual = %d, expected = %d\n", postDeckCount, preDeckCount);
    assertTrue(postDeckCount, preDeckCount);


    //checking other players; have other players draw 1 card each
    for(i = 0; i < pre.numPlayers; i++) 
    {
        if (i != p) 
        {
            d = drawCard(i, &pre);
            discardCard(0, i, &pre, 0);

            if (d != 0) 
            {
                drawCardFail++;
            }
        }
    }

    for (i = 0; i < pre.numPlayers; i++) 
    {
        if (i != p) 
        {
            if((pre.handCount[i] != post->handCount[i]) && (pre.deckCount[i] != post->deckCount[i]))
            {
                otherPlayerHandFail++;
            }
        }
    }
}



int main() 
{
    int n, i, player, deckCount, discardCount, handCount;
 
    srand(time(NULL));

    struct gameState G;

    printf("TESTING RANDOMLY ----- COUNCIL ROOM CARD\n");
   
    
    //code inspired by lecture
    for (n = 0; n < 100; n++)
    {   
        for (i = 0; i < sizeof(struct gameState); i++)
        {
            //creating gameState G filled with random bytes
            ((char*)&G)[i] = floor(Random() * 256);
        }

        //randomizing parameters 
        //randomizing number of players using the formula: rand() % (HIGH - LOW + 1) + LOW;
        G.numPlayers = rand() % (4 - 2 + 1) + 2;
        G.numBuys = 1;

        //determining which player we testing for
        player = G.numPlayers - 2;

        //randomizing played card count
        G.playedCardCount = floor(Random() * MAX_DECK - 1);

        //randomizing parameters
        deckCount = floor(Random() * MAX_DECK);
        discardCount = floor(Random() * MAX_DECK);
        handCount = floor(Random() * MAX_HAND);

        G.whoseTurn = player;

        //randomizing values for all players
        for(i = 0; i < G.numPlayers; i++)
        {
            G.deckCount[i] = deckCount;
            G.discardCount[i] = discardCount;
            G.handCount[i] = handCount;
        }

        //calling Test Oracle with these inputs
        checkCouncil(player, &G);
    }
    
    
    if (fail == 0 && drawCardFail == 0 && discardFail == 0 && cardEffectFail == 0 && numBuysFail == 0)
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

        printf("***** DISPLAYING TEST RESULTS OF BUY NUMS ***** \n");
        printf("Number of failed buy nums: %d\n", numBuysFail);

        printf("***** DISPLAYING TEST RESULTS OF OTHER PLAYER'S HAND ***** \n");
        printf("Number of failed other player's hand: %d\n", otherPlayerHandFail);
    }
    

    return 0;
}