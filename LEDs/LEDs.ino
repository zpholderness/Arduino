//This will not work on its own but is what needs to be integrated into the Phasic 18.edited

void setup() {
  // put your setup code here, to run once:
//LED Lights on Feedback Device
//Pin to hook LED's to, need to use an PWM Pin for Fade
const int ledPin = 5;
pinMode(ledPin, OUTPUT); // set as an output
int howbright = 0; //determines the brightness of the LED set from 0 to 255
int fadeFactor = 51; //constant to multiply number associated with flow type by. 
// States of Flow type- number associated with eact type to multiply fade factor by
 // Off, 0
 // VeryLow, 1
 // Low, 2 
 // Medium, 3
 // High, 4
 // VeryHigh 5
 int endbright = 0; //The end level of brightness its transitioning too when going to a new state, eventually howbright is set equal to this
  unsigned long currentMilli = millis();
  unsigned long previousMilli = 0;
}
//either looking at flow or flowNow
//if ActionType == Hello set to very low .5(fadeFactor)

void loop() {
  // put your main code here, to run repeatedly:
  //These methods should be called anytime you want to check if you need to change the status of the light. 
setBrightness();
turnOnLights();
}

//turns light to dimmness scale 1-5 based on flow rate. 
//while it is increasing or decreasing to desired brightness, arduino will not be reading in data because it will be in these loops 
// to avoid this simply take these out of the function calls and put them in the void loop(); and change while statements to if statements
//each increase in brightness degree is 10 ms, so from off to full on (0 to 255) takes 2.55 seconds 
void turnOnLights() { 

    while(howBright < endbright)  {
      if (previousMilli + 10) > currentMilli) {
        howBright= howBright+1;
        analogWrite(ledPin, howBright); //sets the Led light to that brighness every loop. 
        previousMilli = currentMilli;
      }
    }
    while (howBright > endbright) {
      if ((previousMilli + 100) > currentMilli) {
      howBright = howBright-1;
      analogWrite(ledPin, howBright);
    
    }
};

void setBrightness() {
  case (flow) {
    case Off:
      if (ActionType == Hello) {
          endbright = .5*fadeFactor;
      } else {
        endbright = 0;
      }
      break;
    case VeryLow:
      endbright = 1*fadeFactor;
      break;
    case Low:
      endbright = 2*fadeFactor;
      break;
    case Medium:
      endbright = 3*fadeFactor;
      break;
    case High:
      endbright = 4*fadeFactor;
      break;
    case VeryHigh:
      endbright = 5*fadeFactor;
      break;
  }
};

