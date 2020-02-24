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
    { 2, 2, 16},
    { 3, 3, 16},
};

void test(){
    if(msg[0].postNext == msg[1].postNext){
        msg[1].postNext = rand() % (16-1+1)+1;
        test();
    }
    if(msg[0].postNext == msg[2].postNext){
        msg[2].postNext = rand() % (16-1+1)+1;
        test();
    }
    if(msg[1].postNext == msg[2].postNext){
        msg[2].postNext = rand() % (16-1+1)+1;
        test();
    }

}

void change(){
    msg[0].postNow = msg[0].postNext;
    msg[0].postNext = rand() % (16-1+1)+1;

    msg[1].postNow = msg[1].postNext;
    msg[1].postNext = rand() % (16-1+1)+1;

    msg[2].postNow = msg[2].postNext;
    msg[2].postNext = rand() % (16-1+1)+1;
}

int main()
{
    int runStart = 0;
    int runTil = 5;
    while(runStart < runTil){
        test();
        printf("next post check:\n");
        for(int i = 0; i < MAXMSG; i++){
            printf("%d %d %d\n", msg[i].trainNumber, msg[i].postNow, msg[i].postNext);
        }
        change();
        printf("Move to next post (and get new post):\n");
        for(int i = 0; i < MAXMSG; i++){
            printf("%d %d %d\n", msg[i].trainNumber, msg[i].postNow, msg[i].postNext);
        }
        runStart++;
        printf("\n");
    }
    return 0;
}
