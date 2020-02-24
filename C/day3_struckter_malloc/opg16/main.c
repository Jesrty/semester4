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
    msg[2].data[1] = msg[0].data[1];
    printf("%u %u %u", msg[2].data[0], msg[2].data[1], msg[2].data[2]);
    return 0;
}
