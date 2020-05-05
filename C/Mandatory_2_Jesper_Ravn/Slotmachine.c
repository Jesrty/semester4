#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Slotmachine.h"
#include "ExstraMethods.c"




//bogstavs beskrivelse --- A = APPLE   B = BELL    C = CHERRY  G = GRAPE   L = LEMON   O = ORANGE  P = PLUM    R = BAR
slotM mySlotM = {
    {
    {'R', 'C', 'B', 'P', 'A', 'A', 'G', 'L', 'O', 'L'},
    {'R', 'C', 'C', 'B', 'B', 'P', 'A', 'G', 'O', 'L'},
    {'R', 'C', 'C', 'C', 'B', 'P', 'A', 'G', 'O', 'O'}
    },      //de 3 wheels fra opgaven
    10,     //start penge beløv
    1,      //pris per spin
    0};     //antal spins
//en pointer til double arrayet over
char *ptr_ar = &mySlotM.ar[0][0];

/* winner conditions + amount
Left    Center  Right   Win
                C       2
        C       C       8
C       C       C       12
        B       B       8
B       B       B       16
O       O       O       10
A       A       A       18
P       P       P       24
G       G       G       24
BAR     BAR     BAR     50      */
//tjekker om 3 bogstaver giver en af situationerne over og returnere beløbet
int rollCheck(char char1, char char2, char char3){
    int tempPrice = 0;
    if((char3 == 'C')){
        tempPrice = 2;
    }
    if((char2 == 'C') && (char3 == 'C')){
        tempPrice = 8;
    }
    if((char1 == 'C') && (char2 == 'C') && (char3 == 'C')){
        tempPrice = 12;
    }
    if((char2 == 'B') && (char3 == 'B')){
        tempPrice = 8;
    }
    if((char1 == 'B') && (char2 == 'B') && (char3 == 'B')){
        tempPrice = 16;
    }
    if((char1 == 'O') && (char2 == 'O') && (char3 == 'O')){
        tempPrice = 10;
    }
    if((char1 == 'A') && (char2 == 'A') && (char3 == 'A')){
        tempPrice = 18;
    }
    if((char1 == 'P') && (char2 == 'P') && (char3 == 'P')){
        tempPrice = 24;
    }
    if((char1 == 'G') && (char2 == 'G') && (char3 == 'G')){
        tempPrice = 24;
    }
    if((char1 == 'R') && (char2 == 'R') && (char3 == 'R')){
        tempPrice = 50;
    }

    if(tempPrice != 0){
        printf(">>>>>>>>>>>>>> you won - %d credit's <<<<<<<<<<<<<<\n", tempPrice);
    }
    return tempPrice;
}
//bare en tekst der bliver printet i starten
void welcomeSMG(){
    printf("Welcome to Jesper's one armed bandit! \n");
    printf("your credit is: %d - %d credit per spin, have fun!\n", mySlotM.money, mySlotM.price);
    printf("__________________________________________________\n\n\n");
}

//printet af selve rolne
void printRoll(char tempChar1, char tempChar2, char tempChar3){
    //start wheels
    printf("\t\t-------------\n");
    printf("\t\t| $ | $ | $ |\n");
    printf("\t\t-------------\n");
    wheelSlepp();

    //show first wheel
    printf("\t\t-------------\n");
    printf("\t\t| %c | $ | $ |\n", tempChar1);
    printf("\t\t-------------\n");
    wheelSlepp();

    //show second wheel
    printf("\t\t-------------\n");
    printf("\t\t| %c | %c | $ |\n", tempChar1, tempChar2);
    printf("\t\t-------------\n");
    wheelSlepp();

    //show final wheel
    printf("\t\t-------------\n");
    printf("\t\t| %c | %c | %c |\n", tempChar1, tempChar2, tempChar3);
    printf("\t\t-------------\n");
    Sleep(200);
}

//tæller antal spins
void spinCounter(){
    mySlotM.spinNumber++;
    printf("You have spined %d times\n", mySlotM.spinNumber);
}

//lægger præmie til og træker prisen per spin fra
void monnyHandler(char tempChar1, char tempChar2, char tempChar3){
    mySlotM.money -= mySlotM.price;
    mySlotM.money += rollCheck(tempChar1, tempChar2, tempChar3);
    printf("You now have %d credit left\n", mySlotM.money);
}

