#include <stdio.h>
#include <stdlib.h>
#include "Slotmachine.c"

int main()
{
    welcomeSMG();

    while(mySlotM.money >= 0 && mySlotM.money <= 200){
        Sleep(2000);
        char tempChar1 = *(ptr_ar+RNG(0, 9));
        char tempChar2 = *(ptr_ar+RNG(10, 19));
        char tempChar3 = *(ptr_ar+RNG(20, 29));

        printRoll(tempChar1, tempChar2, tempChar3);

        spinCounter();

        monnyHandler(tempChar1, tempChar2, tempChar3);

        printf("_________________________________________________\n\n\n");
    }
    return 0;
}
