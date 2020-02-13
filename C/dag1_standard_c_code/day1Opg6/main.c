#include <stdio.h>
#include <stdlib.h>
//includer en klasse som har metoden som er neden under
#include "6a.c"

//metode fra denne fil
/*
int multiplyByItSelf(int a){
    return (a*a);
}
*/

int main()
{
    printf("Type a number you would like to multiply by it self\n");
    int number;
    int numberAgain;
    scanf("%d", &number);

    printf("%d multiplied by itself is %d", number, multiplyByItself(number));

    return 0;
}
