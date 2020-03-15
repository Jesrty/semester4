#include "ringb.h"
#include "int.h"
#include <arduino.h>
#include <stdio.h>


int maxdata = 64;
unsigned char arraydata[2][64];
int put_index     = 0;
int get_index     = 0;
bool test2 = false; // true for testprint



int get0(void)
{
  if(test2)
    Serial.println("get0 ");
  return (arraydata[0][get_index]);
  
}

int get1(void)
{
  if(test2)
    Serial.println("get1 ");
  return (arraydata[1][get_index]);
}

void getindex(void)
{
  get_index = (get_index + 1) % maxdata;
}


void clearringb(void)
{
    for (int i=0; i<maxdata; i++)
    {
        arraydata[0][i] = 0;
        arraydata[1][i] = 0;
    }
}

void toloco(unsigned char a, unsigned char b)
{
  putdata(a,b);
  assemble_dcc_msg();
}

void putdata(unsigned char a, unsigned char b)
{
    arraydata[0][put_index] = a; 
    arraydata[1][put_index] = b; 
    put_index = (put_index+1) % maxdata;
    if(test2)
    {
      Serial.println("putdata ");
      Serial.println(a);
      Serial.println(b);
    }
}

void getdata(void)
{
    unsigned char a = arraydata[0][get_index];
    unsigned char b = arraydata[1][get_index];
    get_index = (get_index + 1) % maxdata;
    if(test2)
      Serial.println("getdata ");
}

bool full(void)
{
    if(put_index - get_index == maxdata-1) //-1
    {
        return true;
    }
    else
    {
        return false;
    }  
}

bool empty(void)
{
    if(put_index - get_index == 0)
        return true;
    else
        return false;  
}

void toacc(unsigned char a, unsigned char b)
{
  calculateaddr(a,b);
}

void calculateaddr(unsigned int a, unsigned char b)
{
    unsigned int address, x, y;
    unsigned char reg, byte1, byte2;
    if((a%4)==0)
    {
        address=a/4;
        reg=3;   
    }
    else
    {
      address = (a/4)+1;
      reg = (a%4)-1; // -1 jkp 2311
    }
    byte1   = address & 63;
    byte1   = byte1 + 128;
    if(test2)
    {
      Serial.print("device addr : ");
      Serial.println(a);
      Serial.print("addr : ");
      Serial.println(byte1);
    }
    byte2   = 128;
    x       = 0;
    y       = address & 64;
    if(y==0) x += 64;
    y       = address & 128;
    if(y==0) x += 128;
    y       = address & 256;
    if(y==0) x += 256;
    x = x >> 2;
    byte2 += x;
    byte2 = byte2 + (reg << 1);

    if(b==1)
    {
        if(test2)
        {
            Serial.print(" b=1 byte 2 : ");
            Serial.println(byte2);
        }
        byte2 += 9;
        putdata(byte1,byte2);
        assemble_dcc_msg();
        delay(70);
        if(test2)
        {
            Serial.print("addr - data : ");
            Serial.print(byte1);
            Serial.print("  ");
            Serial.println(byte2);
        }
        
        byte2=byte2-8;
        putdata(byte1,byte2);
        assemble_dcc_msg();
        delay(70);
        if(test2)
        {
            Serial.print("addr - data : ");
            Serial.print(byte1);
            Serial.print("  ");
            Serial.println(byte2);
        }
    }
    else
    {
        if(test2)
        {
            Serial.print(" b=0 byte 2 : ");
            Serial.println(byte2);
        }
        byte2 += 8;
        putdata(byte1,byte2);
        assemble_dcc_msg();
        delay(70);
        if(test2)
        {
            Serial.print("addr - data : ");
            Serial.print(byte1);
            Serial.print("  ");
            Serial.println(byte2);
        }
        byte2=byte2-8;
        putdata(byte1,byte2);
        assemble_dcc_msg();
        delay(70);
        if(test2)
        {
            Serial.print("addr - data : ");
            Serial.print(byte1);
            Serial.print("  ");
            Serial.println(byte2);
        }

    }
}
