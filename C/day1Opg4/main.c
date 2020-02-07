#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dage[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //for loop
    /*
    for(int number = 0; number<sizeof(dage)/sizeof(int); number++){
        printf("Month %d contains %d days\n", (number+1), dage[(number)]);
    }
    */

    //while loop
    /*
    int number = 0;
    while(number<sizeof(dage)/sizeof(int)){
        printf("Month %d contains %d days\n", (number+1), dage[(number)]);
        number++;
    }
    */

    //do-while
    /*
    int number = 0;
    do{
        printf("Month %d contains %d days\n", (number+1), dage[(number)]);
        number++;
    }while(number<sizeof(dage)/sizeof(int));
    */
    return 0;
}
