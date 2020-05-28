#include "Slotmachine.h"
#include "HelperMethods.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  welcomeSMG();
}

int userInput;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Press: 1 = manually -- 2 = a number of times -- 3 = get statistics");
  userInput = getUserInput();
  if(userInput == 1){
    while(true){
      Serial.println("Press: 1 to roll the bandit -- 2 to exsit");
      userInput = getUserInput();
      if(getMySlotMMoney <= 0){
        Serial.println("You have 0 credit left.");
        break;
      }
      if(userInput == 1){
        roll(800);
      }
      else if(userInput == 2){
        break;
      }
    }
  }
  else if(userInput == 2){
    if(getMySlotMMoney <= 0){
      Serial.println("You have 0 credit left.");
    }
    else{
      Serial.println("Press: the number of times you wanna spin");
      userInput = getUserInput();
      
      for(int i = 0; i < userInput; i++){
        roll(0);
        if(getMySlotMMoney <= 0){
          Serial.println("You have 0 credit left.");
          break;
        }
      }
    }
  }
  else if(userInput == 3){
    stats();
  }
}
