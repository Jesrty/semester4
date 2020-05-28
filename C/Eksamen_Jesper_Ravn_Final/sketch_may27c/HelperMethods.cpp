#include <arduino.h>
#include <stdio.h>
#include "HelperMethods.h"

unsigned int getUserInput(){
  int userInput = 0;
  while(userInput == 0){
      userInput = Serial.parseInt();
    }  
  return userInput;
}
