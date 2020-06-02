#ifndef SLOTMACHINE_H_INCLUDED
#define SLOTMACHINE_H_INCLUDED

#define wheelLength 10

typedef struct slotM{
    char wheel1[wheelLength];
    char wheel2[wheelLength];
    char wheel3[wheelLength];
    int money;
    int price;
    int spinNumber;
} slotM;

int getMySlotMMoney();
int rollCheck(char char1, char char2, char char3);
void welcomeSMG();
void roll();
void rollMore();
void moneyHandler(char char1, char char2, char char3);
void statsHandler(char char1, char char2, char char3);
void stats();
void wheelInterrupt();




#endif // SLOTMACHINE_H_INCLUDED
