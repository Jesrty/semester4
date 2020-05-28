//VARIABLER --------------------------------------
#define wheelNumber 3
#define wheelLength 10
//A = APPLE   B = BELL    C = CHERRY  G = GRAPE   L = LEMON   O = ORANGE  P = PLUM    R = BAR
char wheel[wheelNumber][wheelLength] = {{'R', 'C', 'B', 'P', 'A', 'A', 'G', 'L', 'O', 'L'},
                                        {'R', 'C', 'C', 'B', 'B', 'P', 'A', 'G', 'O', 'L'},
                                        {'R', 'C', 'C', 'C', 'B', 'P', 'A', 'G', 'O', 'O'}};
int userInput;

int money = 10;
int price = 1;
int spinNumber = 0;


//stat number
int c = 0;
int cc = 0;
int ccc = 0;
int bb = 0;
int bbb = 0;
int ooo = 0;
int aaa = 0;
int ppp = 0;
int ggg = 0;
int rrr = 0;



//SETUP --------------------------------------
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Welcome to Jesper's one armed bandit!\n");
  
  
  
}
//LOOP --------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println("Press: 1 = manually -- 2 = a number of times -- 3 = statistics run");
  userInput = getUserInput();
  Serial.print("You have selected: ");
  Serial.println(userInput);
  randomSeed(millis());
  if(userInput == 1){
    while(true){
      Serial.println("Press: 1 to roll the bandit -- 2 to exsit");
      userInput = getUserInput();
      if(userInput == 1){
        spinNumber++;

        char charTemp1 = wheel[0][random(wheelLength)];
        char charTemp2 = wheel[1][random(wheelLength)];
        char charTemp3 = wheel[2][random(wheelLength)];

        printRoll(charTemp1, charTemp2, charTemp3);

        money = money - price + rollCheck(charTemp1, charTemp2, charTemp3);

        Serial.println((String)"you now have "+money+"$ left and you have spinned "+spinNumber+" times");
      }
      else if(userInput == 2){
        break;
      }
      else if(money <= 0){
          Serial.println("you have no money left");
      }
    }
  }
  else if(userInput == 2){
    Serial.println("Press: the number of times you wanna spin");
    userInput = getUserInput();
    if(money <= 0){
      Serial.println("you have no money left. Insert more.");
    }
    else{
      for(int i = 0; i < userInput; i++){
        spinNumber++;
  
        char charTemp1 = wheel[0][random(wheelLength)];
        char charTemp2 = wheel[1][random(wheelLength)];
        char charTemp3 = wheel[2][random(wheelLength)];
  
        money = money - price + rollCheck(charTemp1, charTemp2, charTemp3);
        
        if(money == 0){
          Serial.println((String)"you ran out of monny at spin: "+spinNumber);
          break;
        }
      }
    }
    Serial.println((String)"You now have: "+money+"$ left");
  }
  else if(userInput == 3){
    while(spinNumber < 9999){
      spinNumber++;
  
      char charTemp1 = wheel[0][random(wheelLength)];
      char charTemp2 = wheel[1][random(wheelLength)];
      char charTemp3 = wheel[2][random(wheelLength)];
  
      money = money - price + rollCheck(charTemp1, charTemp2, charTemp3);
      stat(charTemp1, charTemp2, charTemp3);
    }
    statPrint();
  }

}
//METODER --------------------------------------
unsigned int getUserInput(){
  int userInput = 0;
  while(userInput == 0){
      userInput = Serial.parseInt();
    }  
  return userInput;
}

/*
Left    Center  Right   Win
                C       2
        C       C       8
C       C       C       12
        B       B       8
B       B       B       16
O       O       O       10
A       A       A       18
P       P       P       24
G       G       G       24
BAR     BAR     BAR     50      */
int rollCheck(char char1, char char2, char char3){
    if((char1 == 'R') && (char2 == 'R') && (char3 == 'R')){return 50;}
    if((char1 == 'G') && (char2 == 'G') && (char3 == 'G')){return 24;}
    if((char1 == 'P') && (char2 == 'P') && (char3 == 'P')){return 24;}
    if((char1 == 'A') && (char2 == 'A') && (char3 == 'A')){return 18;}
    if((char1 == 'O') && (char2 == 'O') && (char3 == 'O')){return 10;}
    if((char1 == 'B') && (char2 == 'B') && (char3 == 'B')){return 16;}
    if((char2 == 'B') && (char3 == 'B')){return 8;}
    if((char1 == 'C') && (char2 == 'C') && (char3 == 'C')){return 12;}
    if((char2 == 'C') && (char3 == 'C')){return 8;}
    if((char3 == 'C')){return 2;}
    return 0;
}

void printRoll(char tempChar1, char tempChar2, char tempChar3){
    //start wheels
    Serial.println("\t\t_____________");
    Serial.println("\t\t| $ | $ | $ |");
    Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
    delay(1200);

    //show first wheel
    Serial.println("\t\t_____________");
    Serial.println((String)"\t\t| "+tempChar1+" | $ | $ |");
    Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
    delay(1200);

    //show second wheel

    Serial.println("\t\t_____________");
    Serial.println((String)"\t\t| "+tempChar1+" | "+tempChar2+" | $ |");
    Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
    delay(1200);

    //show final wheel
    Serial.println("\t\t_____________");
    Serial.println((String)"\t\t| "+tempChar1+" | "+tempChar2+" | "+tempChar3+" |");
    Serial.println("\t\t‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
    delay(200);
}

void stat(char char1, char char2, char char3){
    if((char1 == 'R') && (char2 == 'R') && (char3 == 'R')){rrr++;}
    if((char1 == 'G') && (char2 == 'G') && (char3 == 'G')){ggg++;}
    if((char1 == 'P') && (char2 == 'P') && (char3 == 'P')){ppp++;}
    if((char1 == 'A') && (char2 == 'A') && (char3 == 'A')){aaa++;}
    if((char1 == 'O') && (char2 == 'O') && (char3 == 'O')){ooo++;}
    if((char1 == 'B') && (char2 == 'B') && (char3 == 'B')){bbb++;}
    if((char2 == 'B') && (char3 == 'B')){bb++;}
    if((char1 == 'C') && (char2 == 'C') && (char3 == 'C')){ccc++;}
    if((char2 == 'C') && (char3 == 'C')){cc++;}
    if((char3 == 'C')){c++;}
}

void statPrint(){
  Serial.println((String)"You spinned: "+spinNumber+" times");
  Serial.println((String)"RRR: "+(double)rrr/spinNumber*100+"%");
  Serial.println((String)"GGG: "+(double)ggg/spinNumber*100+"%");
  Serial.println((String)"PPP: "+(double)ppp/spinNumber*100+"%");
  Serial.println((String)"AAA: "+(double)aaa/spinNumber*100+"%");
  Serial.println((String)"OOO: "+(double)ooo/spinNumber*100+"%");
  Serial.println((String)"BBB: "+(double)bbb/spinNumber*100+"%");
  Serial.println((String)"BB: "+(double)bb/spinNumber*100+"%");
  Serial.println((String)"CCC: "+(double)ccc/spinNumber*100+"%");
  Serial.println((String)"CC: "+(double)cc/spinNumber*100+"%");
  Serial.println((String)"C: "+(double)c/spinNumber*100+"%");
  Serial.println((String)"no win: "+(double)(spinNumber-(rrr+ggg+ppp+aaa+ooo+bbb+bb+ccc+cc+c))/spinNumber*100+"%");
}
  
  
  
