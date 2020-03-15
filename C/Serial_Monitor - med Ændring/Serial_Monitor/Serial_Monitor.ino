// programmet testet 27012020 virker ikke fra serial henter andre data end der sendes, prøv evt uden ringbufferen
// programmet skal testes
// dette program virker, kan resette alle lyssignaler 

#include "ringb.h"
#include "int.h"

#define DCC_PIN     4                         // DCC out
#define PREAMBLE    0                         // definitions for state machine
#define SEPERATOR   1                         // definitions for state machine
#define SENDBYTE    2                         // definitions for state machine
#define MAXMSG      2

bool test = false; //false
unsigned char preample1;                      // global variabel for preample part 1
unsigned char preample2;                      // global variabel for preample part 2
unsigned char addr;                           // global variabel adresse
unsigned char data;                           // global variabel kommando
unsigned char addr2 = 255;                    // global variabel adresse 2
unsigned char data2 = 0;                      // global variabel kommando 2
unsigned char checksum;                       // global variabel for checksum 
unsigned char inputType;
unsigned char locoAddr  = 8;
unsigned char locoSpeed = 96;
unsigned char locoDir;
unsigned char locoType;
unsigned char locoCmd;
unsigned int  accAddr;
unsigned char accData;

unsigned int getUserInput(unsigned int max, const char message[]);


void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(DCC_PIN,OUTPUT);       // enable styrepin som output
    //pinMode(dirpin,INPUT_PULLUP);// dirpin som input
    SetupTimer2();

    addr      = locoAddr;          // default lokoadresse
    data      = locoSpeed;         // default hastighed og retning, rew speed = 4
    addr2     = 0xFF;              // default for idle
    data2     = 0;                 // default for idle
 
    clearringb();

}

void loop() 
{
        // Get the address, direction and speed, to create a packet to send. The bytes are set to decimal, not binary
        locoAddr      = 7;
        locoType      = getUserInput(1,   "Vælg: 0 for Speed og Direction - 1 for Command.");
        if(locoType == 1)
        {
          locoCmd     = getUserInput(10,  "Vælg: 0=All off - 1=Light 2=sound - 3=Horn1 - 4=Horn2 - 5=Bell.");
          if(locoCmd == 0 ) toloco(locoAddr,128);
          if(locoCmd == 1 ) toloco(locoAddr,128+16); // Light
          if(locoCmd == 2 ) toloco(locoAddr,128+1);  // Sound
          if(locoCmd == 3 ) toloco(locoAddr,128+2);  // Horn1
          if(locoCmd == 4 ) toloco(locoAddr,128+4);  // Horn2
          if(locoCmd == 5 ) toloco(locoAddr,128+8);  // Bell
          if((locoCmd == 3)||(locoCmd == 4))
          {
            delay(2000);
            toloco(locoAddr,128);
          }
        }
        else
        {
          locoDir       = getUserInput(1,   "Vælg hvilken vej du vil køre: (1=forward 0=backward).");
          locoSpeed     = getUserInput(31,  "Vælg hastighed: (0-15), Stop: (0), Emergency Stop: (1).");
          locoSpeed += 64;
          if(locoDir==1)
            locoSpeed += 32;
          Serial.print("putdata ");
          Serial.print(locoAddr);
          Serial.print("  ");
          Serial.println(locoSpeed);
          toloco(locoAddr,locoSpeed);
        }
} 

unsigned int getUserInput(unsigned int max, const char message[]) 
{
    unsigned int userInput = 0xFFFF;
    Serial.println(message);
    while (userInput > max)
    {
        if (Serial.available() > 0)            // Check if something is typed
        {
           userInput = Serial.parseInt();      // Get the int from input
           Serial.print("Received  ");         // Tell the user what he typed
           Serial.println(userInput, DEC);
        }
    }
    return userInput;
}
