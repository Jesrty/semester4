#include <windows.h>
#include <stdbool.h>

bool newSeed = false;
//RNG = RandomNumberGenerator
int RNG(int lower, int upper){
    //sætter et nyt seed til random efter tiden og gør det kun færste gang pga booleanen
    if(newSeed){
        srand(time(0));
        newSeed = true;
    }
    //giver en random int fra lower number til ubber number
    int temp = (rand() % (upper - lower + 1) + lower);
    return temp;
}

//sætter på pause
void wheelSlepp(){
    Sleep(1200);
}
