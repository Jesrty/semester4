#include <stdio.h>
#include <stdlib.h>
#include "Slotmachine.c"

int main()
{
    welcomeSMG();

    //loop der k�re indtil du ikke har flere penge eller har mere end 200
    while(mySlotM.money >= 0 && mySlotM.money <= 200){
        //bare lidt tid s� man kan f�gle med
        Sleep(2000);

        //bruger RNG og array pointeren til at finde 3 tilf�ldige spins
        char tempChar1 = *(ptr_ar+RNG(0, 9));
        char tempChar2 = *(ptr_ar+RNG(10, 19));
        char tempChar3 = *(ptr_ar+RNG(20, 29));

        printRoll(tempChar1, tempChar2, tempChar3);

        spinCounter();

        monnyHandler(tempChar1, tempChar2, tempChar3);

        //bare for at g�re det p�nt
        printf("__________________________________________________\n\n\n");
    }
    return 0;
}
