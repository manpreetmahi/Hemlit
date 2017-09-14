
//left signal
int left1 = 2;
int left2 = 3;
int left3 = 4;

//mid signal
int mid1 = 5;
int mid2 = 6;
int mid3 = 7;

//right signal
int right1 = 8;
int right2 = 9;
int right3 = 10;

//input buttons (ACTIVE LOW)
int buttonLeft = 11;
int buttonRight = 12;
int buttonLeftVal = 0;
int buttonRightVal = 0;

//current system state
int stateValue = 0;


 
void setup() {
  
  Serial.begin( 9600 );    // 9600 is the default baud rate for the serial Bluetooth module
  
  pinMode(left1, OUTPUT); //initializes blinker outputs
  pinMode(left2, OUTPUT);
  pinMode(left3, OUTPUT);
  pinMode(mid1, OUTPUT);
  pinMode(mid2, OUTPUT);
  pinMode(mid3, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(right3, OUTPUT);

  pinMode(buttonLeft, INPUT); //initializes button inputs 
  pinMode(buttonRight, INPUT);

  
}
 
void loop() {
  
  buttonLeftVal = digitalRead(buttonLeft); //reads the digital value of each button (which are active low)
  buttonRightVal = digitalRead(buttonRight);

  
  if(buttonLeftVal == LOW){ //if left button is pressed, change state accordingly
    if(stateValue == 0){
      stateValue = 1;
    }
    else{
      stateValue = 0;
    }
    delay(1000); //delay to account for mechanical debouncing
  }

  if(buttonRightVal == LOW){ //if right button is pressed, change state accordingly
    if(stateValue == 0){
      stateValue = 2;
    }
    else{
      stateValue = 0;
    }
    delay(1000); //delay to account for mechanical debouncing
  }


  
  if(stateValue == 1){ //blinks group of LED's depending on current system state
  threeWayBlink(left1, left2, left3,100);
  }
  else if(stateValue == 2){
    threeWayBlink(right1, right2, right3,100);
  }
  else{
    threeWayBlink(mid1, mid2, mid3,1);
  }
 
}


 void threeWayBlink(int i, int j, int k, int timeDelay){ //performs 3 way blink and time delay
   digitalWrite(i, HIGH);
  delay(timeDelay);
  digitalWrite(i,LOW);
  digitalWrite(j,HIGH);
  delay(timeDelay);
  digitalWrite(j,LOW);
  digitalWrite(k,HIGH);
  delay(timeDelay);
  digitalWrite(k,LOW);
 }

