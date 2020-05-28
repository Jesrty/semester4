#include <arduino.h>
#include <stdio.h>
#include "Slotmachine.h"

slotM mySlotM = {
                {111, 010, 001, 110, 000, 000, 011, 100, 101, 100},
                {111, 010, 010, 001, 001, 110, 000, 011, 101, 100},
                {111, 010, 010, 010, 001, 110, 000, 011, 101, 101},
                100,
                1,
                0};


char *wheel1_ptr = &mySlotM.wheel1[0];
char *wheel2_ptr = &mySlotM.wheel2[0];
char *wheel3_ptr = &mySlotM.wheel3[0];

int getMySlotMMoney(){
  return mySlotM.money;
}

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

void welcomeSMG(){
  Serial.println("Welcome to Jesper's one armed bandit!");
  Serial.println((String)"You start with: " + mySlotM.money + " credit. " + mySlotM.price + " credit per spin.");
  Serial.println("_________________________________________________\n\n");    
}

char toCharConverter(char c){
  if(c == 000){
    return 'A';  
  }
  else if(c == 001){
    return 'B';
  }
  else if(c == 010){
    return 'C';
  }
  else if(c == 011){
    return 'G';
  }
  else if(c == 100){
    return 'L';
  }
  else if(c == 101){
    return 'O';
  }
  else if(c == 110){
    return 'P';
  }
  else if(c == 111){
    return 'R';
  }
}

int test1 = 0;
int test2 = 0;
int test3 = 0;
void roll(int delayTimer){
  //without the interrupt???
  randomSeed(millis());
  
  int testRandom1 = random(10, 20);
  int testRandom2 = random(10, 20);
  int testRandom3 = random(10, 20);

  int counter = 0;
  //wheel 3 stop
  while(counter < testRandom3){
      Serial.println("\t\t_____________");
      Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+test1))+" | "+toCharConverter(*(wheel2_ptr+test2))+" | "+toCharConverter(*(wheel3_ptr+test3))+" |");
      Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
      delay(delayTimer);

      counter++;
      test1++;
      test2++;
      test3++;
      if(test1 == (wheelLength)){
        test1 = 0;
      }
      if(test2 == (wheelLength)){
        test2 = 0;
      }
      if(test3 == (wheelLength)){
        test3 = 0;
      }    
  }

  Serial.println("First wheel stopped:");

  //wheel 2 stop
  counter = 0;
  while(counter < testRandom2){
      Serial.println("\t\t_____________");
      Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+test1))+" | "+toCharConverter(*(wheel2_ptr+test2))+" | "+toCharConverter(*(wheel3_ptr+test3))+" |");
      Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
      delay(delayTimer);

      counter++;
      test1++;
      test2++;
      if(test1 == (wheelLength)){
        test1 = 0;
      }
      if(test2 == (wheelLength)){
        test2 = 0;
      }  
  }

  Serial.println("Second wheel stopped:");

  //wheel 1 stop
  counter = 0;
  while(counter < testRandom1){
      Serial.println("\t\t_____________");
      Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+test1))+" | "+toCharConverter(*(wheel2_ptr+test2))+" | "+toCharConverter(*(wheel3_ptr+test3))+" |");
      Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
      delay(delayTimer);

      counter++;
      test1++;
      if(test1 == (wheelLength)){
        test1 = 0;
      } 
  }

  Serial.println("All wheels stopped.");
  Serial.println("Your final result is: ");

  Serial.println("\t\t_____________");
  Serial.println((String)"\t\t| "+toCharConverter(*(wheel1_ptr+test1))+" | "+toCharConverter(*(wheel2_ptr+test2))+" | "+toCharConverter(*(wheel3_ptr+test3))+" |");
  Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"); 

   moneyHandler((*(wheel1_ptr+test1)), (*(wheel2_ptr+test2)), (*(wheel3_ptr+test3)));
   statsHandler((*(wheel1_ptr+test1)), (*(wheel2_ptr+test2)), (*(wheel3_ptr+test3)));
}

void moneyHandler(char char1, char char2, char char3){
  mySlotM.money = mySlotM.money - mySlotM.price + rollCheck(char1, char2, char3);
  Serial.println((String)"You now have " + mySlotM.money + "credits left");
  
}
int c = 0, cc = 0, ccc = 0, bb = 0, bbb = 0, ooo = 0, aaa = 0, ppp = 0, ggg = 0, rrr = 0;
void statsHandler(char char1, char char2, char char3){
  if((char1 == 111) && (char2 == 111) && (char3 == 111)){rrr++;}
  if((char1 == 011) && (char2 == 011) && (char3 == 011)){ggg++;}
  if((char1 == 110) && (char2 == 110) && (char3 == 110)){ppp++;}
  if((char1 == 000) && (char2 == 000) && (char3 == 000)){aaa++;}
  if((char1 == 101) && (char2 == 101) && (char3 == 101)){ooo++;}
  if((char1 == 001) && (char2 == 001) && (char3 == 001)){bbb++;}
  if((char2 == 001) && (char3 == 001)){bb++;}
  if((char1 == 010) && (char2 == 010) && (char3 == 010)){ccc++;}
  if((char2 == 010) && (char3 == 010)){cc++;}
  if((char3 == 010)){c++;}
  mySlotM.spinNumber++; 

}

void stats(){
  //her skal være noget ofc  

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
