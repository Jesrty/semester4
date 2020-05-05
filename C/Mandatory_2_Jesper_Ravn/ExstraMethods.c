#include <windows.h>
#include <stdbool.h>

bool newSeed = false;
//RNG = RandomNumberGenerator
int RNG(int lower, int upper){
    //s�tter et nyt seed til random efter tiden og g�r det kun f�rste gang pga booleanen
    if(newSeed){
        srand(time(0));
        newSeed = true;
    }
    //giver en random int fra lower number til ubber number
    int temp = (rand() % (upper - lower + 1) + lower);
    return temp;
}

//s�tter p� pause
void wheelSlepp(){
    Sleep(1200);
}
