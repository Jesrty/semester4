#include <arduino.h>
#include <stdio.h>
#include "Slotmachine.h"

slotM mySlotM = {
                {111, 010, 001, 110, 000, 000, 011, 100, 101, 100}, //wheel 1
                {111, 010, 010, 001, 001, 110, 000, 011, 101, 100}, //wheel 2
                {111, 010, 010, 010, 001, 110, 000, 011, 101, 101}, //wheel 3
                100,                                                //money (start amound)
                1,                                                  //price per spin 
                0};                                                 //number of spins
                
//a pointer to eatch weel
char *wheel1_ptr = &mySlotM.wheel1[0];
char *wheel2_ptr = &mySlotM.wheel2[0];
char *wheel3_ptr = &mySlotM.wheel3[0];

//money getter
int getMySlotMMoney(){
  return mySlotM.money;
}

//returns the winning amount for the 3 chars the methord takes
int rollCheck(char char1, char char2, char char3){
  if((char1 == 111) && (char2 == 111) && (char3 == 111)){return 50;}
  if((char1 == 011) && (char2 == 011) && (char3 == 011)){return 24;}
  if((char1 == 110) && (char2 == 110) && (char3 == 110)){return 24;}
  if((char1 == 000) && (char2 == 000) && (char3 == 000)){return 18;}
  if((char1 == 101) && (char2 == 101) && (char3 == 101)){return 10;}
  if((char1 == 001) && (char2 == 001) && (char3 == 001)){return 16;}
  if((char2 == 001) && (char3 == 001)){return 8;}
  if((char1 == 010) && (char2 == 010) && (char3 == 010)){return 12;}
  if((char2 == 010) && (char3 == 010)){return 8;}
  if((char3 == 010)){return 2;}
  return 0; 
}

//just a little welcome message
void welcomeSMG(){
  Serial.println("Welcome to Jesper's one armed bandit!");
  Serial.println((String)"You start with: " + mySlotM.money + " credit. " + mySlotM.price + " credit per spin.");
  Serial.println("_________________________________________________\n\n");    
}
//convert the byte "char" to the print out char 
char toCharConverter(char c){
  if(c == 000){return 'A';}
  else if(c == 001){return 'B';}
  else if(c == 010){return 'C';}
  else if(c == 011){return 'G';}
  else if(c == 100){return 'L';}
  else if(c == 101){return 'O';}
  else if(c == 110){return 'P';}
  else if(c == 111){return 'R';}  //NOTE if you want to use "BAR" insted of R, you could make the method return a String and change all the ' to "
}

//wheel position holder
int wheel1position = 0;
int wheel2position = 0;
int wheel3position = 0;

volatile byte state = LOW;
int wheelUserInput = 0;

void wheelInterrupt(){
  state = !state;  
}


//here is what most happens it prins and handle the numbers
int delayTimer = 200;
void roll(){
  //info text
  Serial.println("Press a number and the wheel will stop after a few spins");
  
  //give a new seed to the random fucktion based on the time the program have been running
  randomSeed(millis());

  //the wheels spins from 0-9 random 
  int wheel1SpinRandom = random(10);
  int spin1Counter = 0;
  int wheel2SpinRandom = random(10);
  int spin2Counter = 0;
  int wheel3SpinRandom = random(10);
  int spin3Counter = 0;

  //wheel 3 print untill stop
  state = LOW;
  while(spin3Counter < wheel3SpinRandom){
      Serial.println("\t\t_____________");
      Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+wheel1position))+" | "+toCharConverter(*(wheel2_ptr+wheel2position))+" | "+toCharConverter(*(wheel3_ptr+wheel3position))+" |");
      Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
      delay(delayTimer);

      //interrupt her
      wheelUserInput = Serial.parseInt();
      if(wheelUserInput != 0){
        wheelInterrupt();
      }
      wheelUserInput = 0;
      if(state != LOW){
        spin3Counter++;
      }
      else{
        spin3Counter = 0;
      }
      
      wheel1position++;
      wheel2position++;
      wheel3position++;
      if(wheel1position == (wheelLength)){
        wheel1position = 0;
      }
      if(wheel2position == (wheelLength)){
        wheel2position = 0;
      }
      if(wheel3position == (wheelLength)){
        wheel3position = 0;
      }    
  }
  Serial.println("First wheel stopped:");

  //wheel 2 print untill stop
  state = LOW;
  while(spin2Counter < wheel2SpinRandom){
      Serial.println("\t\t_____________");
      Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+wheel1position))+" | "+toCharConverter(*(wheel2_ptr+wheel2position))+" | "+toCharConverter(*(wheel3_ptr+wheel3position))+" |");
      Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
      delay(delayTimer);

      //interrupt her
      wheelUserInput = Serial.parseInt();
      if(wheelUserInput != 0){
        wheelInterrupt();
      }
      wheelUserInput = 0;
      if(state != LOW){
        spin2Counter++;
      }
      else{
        spin2Counter = 0;
      }
      
      wheel1position++;
      wheel2position++;
      if(wheel1position == (wheelLength)){
        wheel1position = 0;
      }
      if(wheel2position == (wheelLength)){
        wheel2position = 0;
      }  
  }
  Serial.println("Second wheel stopped:");

  //wheel 1 print untill stop
  state = LOW;
  while(spin1Counter < wheel1SpinRandom){
      Serial.println("\t\t_____________");
      Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+wheel1position))+" | "+toCharConverter(*(wheel2_ptr+wheel2position))+" | "+toCharConverter(*(wheel3_ptr+wheel3position))+" |");
      Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
      delay(delayTimer);

      //interrupt her
      wheelUserInput = Serial.parseInt();
      if(wheelUserInput != 0){
        wheelInterrupt();
      }
      wheelUserInput = 0;
      if(state != LOW){
        spin1Counter++;
      }
      else{
        spin1Counter = 0;
      }
      
      wheel1position++;
      if(wheel1position == (wheelLength)){
        wheel1position = 0;
      } 
  }
  Serial.println("All wheels stopped.");

  //print the final wheel result
  Serial.println("Your final result is: ");
  Serial.println("\t\t_____________");
  Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+wheel1position))+" | "+toCharConverter(*(wheel2_ptr+wheel2position))+" | "+toCharConverter(*(wheel3_ptr+wheel3position))+" |");
  Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"); 

  //update the money amound
  moneyHandler((*(wheel1_ptr+wheel1position)), (*(wheel2_ptr+wheel2position)), (*(wheel3_ptr+wheel3position)));

  //add the result to the statistiks
  statsHandler((*(wheel1_ptr+wheel1position)), (*(wheel2_ptr+wheel2position)), (*(wheel3_ptr+wheel3position)));
}



void rollMore(){
  //give a new seed to the random fucktion based on the time the program have been running
  randomSeed(millis());

  //random number for the char selection
  int wheel1SpinRandom = random(1, 11);
  int wheel2SpinRandom = random(1, 11);
  int wheel3SpinRandom = random(1, 11);

  //change the wheel positions
  for(int i = 0; i < wheel1SpinRandom; i++){
    wheel1position++;
    if(wheel1position == (wheelLength)){wheel1position = 0;}
  }
  for(int i = 0; i < wheel2SpinRandom; i++){
    wheel2position++;
    if(wheel2position == (wheelLength)){wheel2position = 0;}
  }
  for(int i = 0; i < wheel3SpinRandom; i++){
    wheel3position++;
    if(wheel3position == (wheelLength)){wheel3position = 0;}
  } 

  //print the final wheel result
  Serial.println("Your final result is: ");
  Serial.println("\t\t_____________");
  Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+wheel1position))+" | "+toCharConverter(*(wheel2_ptr+wheel2position))+" | "+toCharConverter(*(wheel3_ptr+wheel3position))+" |");
  Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"); 

  //update the money amound
  moneyHandler((*(wheel1_ptr+wheel1position)), (*(wheel2_ptr+wheel2position)), (*(wheel3_ptr+wheel3position)));

  //add the result to the statistiks
  statsHandler((*(wheel1_ptr+wheel1position)), (*(wheel2_ptr+wheel2position)), (*(wheel3_ptr+wheel3position)));
}

//update the money amound
void moneyHandler(char char1, char char2, char char3){
  mySlotM.money = mySlotM.money - mySlotM.price + rollCheck(char1, char2, char3);
  Serial.println((String)"You now have " + mySlotM.money + "credits left");
}

//the counters on the diffrent win senarios 
int c = 0, cc = 0, ccc = 0, bb = 0, bbb = 0, ooo = 0, aaa = 0, ppp = 0, ggg = 0, rrr = 0;

//add the 1 to the win counters and the total of spins
void statsHandler(char char1, char char2, char char3){
  if((char1 == 111) && (char2 == 111) && (char3 == 111)){rrr++;}
  else if((char1 == 011) && (char2 == 011) && (char3 == 011)){ggg++;}
  else if((char1 == 110) && (char2 == 110) && (char3 == 110)){ppp++;}
  else if((char1 == 000) && (char2 == 000) && (char3 == 000)){aaa++;}
  else if((char1 == 101) && (char2 == 101) && (char3 == 101)){ooo++;}
  else if((char1 == 001) && (char2 == 001) && (char3 == 001)){bbb++;}
  else if((char2 == 001) && (char3 == 001)){bb++;}
  else if((char1 == 010) && (char2 == 010) && (char3 == 010)){ccc++;}
  else if((char2 == 010) && (char3 == 010)){cc++;}
  else if((char3 == 010)){c++;}
  mySlotM.spinNumber++; 
}

// print the % of the diffrent wins and the % of now wins
void stats(){
  Serial.println((String)"You spinned: "+mySlotM.spinNumber+" times");
  Serial.println((String)"RRR: "+(double)rrr/mySlotM.spinNumber*100+"%");
  Serial.println((String)"GGG: "+(double)ggg/mySlotM.spinNumber*100+"%");
  Serial.println((String)"PPP: "+(double)ppp/mySlotM.spinNumber*100+"%");
  Serial.println((String)"AAA: "+(double)aaa/mySlotM.spinNumber*100+"%");
  Serial.println((String)"OOO: "+(double)ooo/mySlotM.spinNumber*100+"%");
  Serial.println((String)"BBB: "+(double)bbb/mySlotM.spinNumber*100+"%");
  Serial.println((String)"BB: "+(double)bb/mySlotM.spinNumber*100+"%");
  Serial.println((String)"CCC: "+(double)ccc/mySlotM.spinNumber*100+"%");
  Serial.println((String)"CC: "+(double)cc/mySlotM.spinNumber*100+"%");
  Serial.println((String)"C: "+(double)c/mySlotM.spinNumber*100+"%");
  Serial.println((String)"no win: "+(double)(mySlotM.spinNumber-(rrr+ggg+ppp+aaa+ooo+bbb+bb+ccc+cc+c))/mySlotM.spinNumber*100+"%");
}
