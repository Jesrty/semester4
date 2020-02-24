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
    { 1, 1, 14},
    { 2, 2, 15},
    { 3, 3, 16},
};


int main()
{
    for(int i = 0; i < MAXMSG; i++){
        printf("%d %d %d\n", msg[i].trainNumber, msg[i].postNow, msg[i].postNext);
    }

    return 0;
}
