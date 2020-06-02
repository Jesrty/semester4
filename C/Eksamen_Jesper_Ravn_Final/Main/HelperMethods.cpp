#include <arduino.h>
#include <stdio.h>
#include "HelperMethods.h"

//Gets user int user input that is diffrent from 0
unsigned int getUserInput(){
  int userInput = 0;
  while(userInput == 0){
      userInput = Serial.parseInt();
  }  
  return userInput;
}
