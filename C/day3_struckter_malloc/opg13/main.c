#include <stdio.h>
#include <stdlib.h>

#define MAXMSG  2
struct Message             // buffer for command
{
    unsigned char data[7];// number of possible
    unsigned char len;// number of positions in use
};

struct Message msg[MAXMSG]=
{
    { { 0xFF,0,0xFF, 0, 0, 0, 0}, 3},   // idle msg
    { { 0, 0, 0, 0, 0, 0, 0}, 3},   // locoMsg
};


int main()
{
    printf("%u, %u, %u", msg[1].data[0], msg[1].data[1], msg[1].data[2]);

    return 0;
}
