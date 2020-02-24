#include <stdio.h>
#include <stdlib.h>

#define MAXMSG  3

typedef struct Message             // buffer for command
{
    unsigned int trainNumber;                           // number of train
    unsigned int postNow;     // number of now positions
    unsigned int postNext;   // number of next position
} trainMsg;

trainMsg msg[MAXMSG]=
{
    { 1, 1, 16},
    { 2, 1, 16},
    { 3, 1, 16},
};

int main()
{

    msg[1].postNext = rand() % (16-1+1)+1;


    int *iptr = NULL;
    iptr = malloc(40 * sizeof(int));
    free(iptr);

    int *iptr2 = NULL;
    iptr2 = malloc(15 * sizeof(int));
    free(iptr2);


    return 0;
}
