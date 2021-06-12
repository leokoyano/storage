//Monty Hall simulator 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
        char name[20];
        int identity;
        int content;
        int bet;
        int openness;
    } Door;

    Door one   = {"Door 1", 1, 0, 0, 0};
    Door two   = {"Door 2", 2, 0, 0, 0};
    Door three = {"Door 3", 3, 0, 0, 0};
    
int Contents(void)
{
    srand((unsigned int)time(NULL));
    int randnum = rand() % 3 + 1;

    if (one.identity == randnum) {
        one.content = 1;
    } else if (two.identity== randnum) {
        two.content = 1;
    } else {
        three.content = 1;
    }
}

int choice_0;
int choice_1;

int Choice_0(void)
{
    do {
        
        printf("Choose the door.<Door 1 ... 1, Door 2... 2, Door 3... 3> : ");
        scanf("%d", &choice_0);
        if (choice_0 < 1 || choice_0 > 3) {
            puts("Invalid number.");
        }
    } while (choice_0 < 1 || choice_0 > 3);
    
    if (one.identity == choice_0) {
        one.bet = 1;
    } else if (two.identity == choice_0) {
        two.bet = 1;
    } else {
        three.bet = 1;
    }
}

int Choice_1(void)
{
    srand((unsigned int)time(NULL));
    int shuffle; 

    if (one.content * one.bet == 1) {
        shuffle = rand() % 2; 
        switch (shuffle == 0) {
            case 0  : printf("Let me open Door 2.\nThere's a goat instead of a car here.\n");
                      two.openness = 1; break;
            case 1  : printf("Let me open Door 3.\nThere's a goat instead of a car here.\n");
                      three.openness = 1; break;
        }
    } else if (one.bet == 1 && two.content == 1) {
        printf("Let me open Door 3.\nThere's a goat instead of a car here.\n");
        three.openness = 1;
    } else if (one.bet == 1 && three.content == 1) {
        printf("Let me open Door 2.\nThere's a goat instead of a car here.\n");
        two.openness = 1;
    } else if (two.content * two.bet == 1) {
        shuffle = rand () % 2;
        switch (shuffle == 0) {
            case 0 : printf("Let me open Door 1.\nThere's a goat instead of a car here.\n");
                     one.openness = 1; break;
            case 1 : printf("Let me open Door 3.\nThere's a goat instead of a car here.\n");
                     three.openness = 1; break;
        } 
    } else if (two.bet == 1 && one.content == 1) {
        printf("Let me open Door 3.\nThere's a goat instead of a car here.\n");
        three.openness = 3;
    } else if (two.bet == 1 && three.content == 1) {
        printf("Let me open Door 1.\nThere's a goat instead of a car here.\n");
        one.openness = 1;
    } else if (three.content * three.bet == 1) {
        shuffle = rand () % 2;
        switch (shuffle == 0) {
            case 0 : printf("Let me open Door 1.\nThere's a goat instead of a car here.\n");
                     one.openness = 1; break;
            case 1 : printf("Let me open Door 2.\nThere's a goat instead of a car here.\n");
                     two.openness = 1; break;
        } 
    } else if (three.bet == 1 && one.content == 1) {
        printf("Let me open Door 2.\nThere's a goat instead of a car here.\n");
        two.openness = 1;
    } else {
        printf("Let me open Door 1.\nThere's a goat instead of a car here.\n");
        one.openness = 1;
    }

    do {
        printf("Would you like to change your choice? <Yes...0/No...1> : ");
        scanf("%d", &choice_1);
        if (choice_1 < 0 || choice_1 > 1) {
            puts("Invalid number.");
        }
    } while(choice_1 < 0 || choice_1 > 1);
}

int Judgement(void)
{
    if (choice_1 == 0) {
        if (one.bet == 1) {
            if (two.openness == 1) {
                three.bet = 1;
            } else if (three.openness == 1) {
                two.bet = 1;
            }
            one.bet = 0;
        } else if (two.bet == 1) {
            if (one.openness == 1) {
                three.bet = 1;
            } else if (three.openness == 1) {
                one.bet = 1;
            }
            two.bet = 0;
        } else {
            if (one.openness == 1) {
                two.bet = 1;
            } else {
                one.bet = 1;
            }
            three.bet = 0;
        }
    } 

    if (one.bet == 1) {
        puts("You selected Door 1. Let you see it.");
    } else if (two.bet == 1) {
        puts("You selected Door 2.　Let you see it.");
    } else {
        puts("You selected Door 3.　Let you see it.");
    }

    switch (one.content * one.bet == 1 || two.content * two.bet == 1 || three.content * three.bet == 1) {
        case 0 : puts("You almost did it!"); break;
        case 1 : puts("Congratulations! You won the car!"); break;
    }
}

int main(void)
{
    Contents();
    
    Choice_0();

    Choice_1();

    Judgement();

    return 0;
}