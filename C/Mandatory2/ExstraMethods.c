#include <windows.h>

//RNG = RandomNumberGenerator

int RNG(int lower, int upper){
    int temp = (rand() % (upper - lower + 1) + lower);
    return temp;
}

void wheelSlepp(){
    Sleep(1200);
}
