#define outputPin 4
unsigned char trainNumber = 7;
unsigned char preample1 = 255;
unsigned char preample2 = 255;
unsigned char input;

void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin, OUTPUT);

  delay(500);
  //stopper alle lyder og lys
  sendFrame(128);
}



void sendBit(char i) {
  if (i ==0){
    digitalWrite(outputPin, HIGH);
    delayMicroseconds(116);
    digitalWrite(outputPin, LOW);
    delayMicroseconds(116);
  }
  if (i == 1){
    digitalWrite(outputPin, HIGH);
    delayMicroseconds(58);
    digitalWrite(outputPin, LOW);
    delayMicroseconds(58);
  }
}

void sendByte( char j ){
  int l = 0;
  for (int k = 128; k > 0; k = k / 2){
    l = j & k;
    if (l != 0){
      sendBit(1);
    }else{
      sendBit(0);
    }
    
  }
}


void sendFrame(unsigned char trainCommando){
  sendByte(preample1);
  sendByte(preample2);
  sendBit(0);
  sendByte(trainNumber);
  sendBit(0);
  sendByte(trainCommando);
  sendBit(0);
  sendByte(trainNumber^trainCommando);
  sendBit(1);
}

void loop() {
  //starter toget med en hastighed på 5 ud af 0-F
  sendFrame(0x65);
}
