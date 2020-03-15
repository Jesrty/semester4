#ifndef ringb_h
#define ringb_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"

#endif

  extern int get0(void);
  extern int get1(void);
  extern void getindex(void);
  extern void clearringb(void);
  extern void toloco(unsigned char a, unsigned char b);
  extern void putdata(unsigned char a, unsigned char b);
  extern void getdata(void);
  extern bool full(void);
  extern bool empty(void);
  extern void toacc(unsigned char a, unsigned char b);
  extern void calculateaddr(unsigned int a, unsigned char b);
#endif
