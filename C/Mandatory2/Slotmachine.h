#ifndef SLOTMACHINE_H_INCLUDED
#define SLOTMACHINE_H_INCLUDED

#define wheels 3
#define wheelLength 10


struct test{
int arra[20];
char name[10][10];
};

typedef struct slotM{
    char ar[wheels][wheelLength];
    int money;
    int price;
    int spinNumber;
} slotM;

int rollCheck(char char1, char char2, char char3);
void wheelSlepp();
void welcomeSMG();
void printRoll(char tempChar1, char tempChar2, char tempChar3);
void spinCounter();
void monnyHandler(char tempChar1, char tempChar2, char tempChar3);

#endif // SLOTMACHINE_H_INCLUDED
