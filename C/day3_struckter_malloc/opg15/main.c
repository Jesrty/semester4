#include <stdio.h>
#include <stdlib.h>

#define MAXMSG  5
typedef struct Message             // buffer for command
{
    unsigned char data[7];// number of possible
    unsigned char len;// number of positions in use
} trainMsg;

trainMsg msg[MAXMSG]=
{
    { { 0xFF,0,0xFF, 0, 0, 0, 0}, 3},   // idle msg
    { { 1, 128, 0, 0, 0, 0, 0}, 3},   // locoMsg1
    { { 2, 128, 0, 0, 0, 0, 0}, 3},   // locoMsg2
    { { 3, 128, 0, 0, 0, 0, 0}, 3},   // locoMsg3
    { { 4, 128, 0, 0, 0, 0, 0}, 3},   // locoMsg4
};

int main()
{
    int test = 0;
    for(int i = 0; i < MAXMSG; i++){
        printf("%u, %u, %u\n", msg[i].data[0], msg[i].data[1], msg[i].data[2]);

        if(msg[i].data[1] == 128){
           msg[i].data[1] = 129;
        }
        else if(msg[i].data[1] == 129){
           msg[i].data[1] = 128;
        }

        if(i == MAXMSG-1 && test < 5){
            i = -1;
            test++;
        }
    }
    return 0;
}
