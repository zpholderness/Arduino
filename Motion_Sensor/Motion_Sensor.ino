//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 1;       
 
//the time when the sensor outputs a low impulse
long unsigned int lowIn;        
 
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000; 
 
boolean lockLow = true;
boolean takeLowTime; 
 
int pirPin = 31;    //the digital pin connected to the PIR sensor's output
//int ledPin = 13; we don't have LED's
int pwm13 = 13;
int pwm12 = 12;
int pwm11 = 11;
int pwm10 = 10;
int pwm9 = 9;
int pwm8 = 8;
int pwm7 = 7;
int pwm6 = 6;
int dig51 = 51;
int dig50 = 50;
int dig49 = 49;
int dig48 = 48;





void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  //pinMode(ledPin, OUTPUT);

//Set up all the pins that we need to turn on to power the board
  pinMode(pwm13, OUTPUT);
  pinMode(pwm12, OUTPUT);
  pinMode(pwm11, OUTPUT);
  pinMode(pwm10, OUTPUT);
  pinMode(pwm9, OUTPUT);
  pinMode(pwm8, OUTPUT);
  pinMode(pwm7, OUTPUT);
  pinMode(pwm6, OUTPUT);
  pinMode(dig51, OUTPUT);
  pinMode(dig50, OUTPUT);
  pinMode(dig49, OUTPUT);
  pinMode(dig48, OUTPUT);

//I think a0 and a15 are just taking things in from the board so don't need to be turned on or anything

  
  
  digitalWrite(pirPin, LOW); // Turn it on
  

  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }

void loop(){
 
     if(digitalRead(pirPin) == HIGH){
        digitalWrite(pwm13, LOW);
       digitalWrite(pwm12, LOW);
       digitalWrite(pwm11, LOW);
       digitalWrite(pwm10, LOW);
       digitalWrite(pwm9, LOW);
       digitalWrite(pwm8, LOW);
       digitalWrite(pwm7, LOW);
       digitalWrite(pwm6, LOW);
       digitalWrite(dig51, LOW);
       digitalWrite(dig50, LOW);
       digitalWrite(dig49, LOW);
       digitalWrite(dig48, LOW);
      
       
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(5);
         }        
         takeLowTime = true;
       }
 
     if(digitalRead(pirPin) == LOW){      
       //digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state
      
       digitalWrite(pwm13, HIGH);
       digitalWrite(pwm12, HIGH);
       digitalWrite(pwm11, HIGH);
       digitalWrite(pwm10, HIGH);
       digitalWrite(pwm9, HIGH);
       digitalWrite(pwm8, HIGH);
       digitalWrite(pwm7, HIGH);
       digitalWrite(pwm6, HIGH);
       digitalWrite(dig51, HIGH);
       digitalWrite(dig50, HIGH);
       digitalWrite(dig49, HIGH);
       digitalWrite(dig48, HIGH);

       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       if(!lockLow && millis() - lowIn > pause){ 
           //makes sure this block of code is only executed again after
           //a new motion sequence has been detected
           lockLow = true;                       
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
  }
