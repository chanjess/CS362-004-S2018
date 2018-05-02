#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


//global
char array1[9] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};
char array2[4] = {'r', 'e', 's', 't'};
char str[6];

char inputChar()
{
    // TODO: rewrite this function

    //rand() % (HIGH - LOW + 1) + LOW;
    int random = rand() % (8 - 0 + 1) + 0;

    //printf("%d\n", array1[random]);

    return array1[random];
}

char *inputString()
{
    // TODO: rewrite this function
    int i;
    
    for (i=0; i<5; i++)
    {
      //rand() % (HIGH - LOW + 1) + LOW;
      int random = rand() % (3 - 0 + 1) + 0;

      str[i] = array2[random];
    }

    str[5] = '\0';
    
    // testing by printing values in the array
    //for (int i=0; i<5; i++)
    //{
    //  printf("%c", str[i]);
    //}   
    //printf("\n");

    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
