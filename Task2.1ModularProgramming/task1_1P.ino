//pins go here
int switchPin = 2;
int porchLED = 3;
int hallLED = 4;

//timing
unsigned long startTime = 0;
bool lightsOn = false;

void setup() {
  pinMode (switchPin, INPUT_PULLUP); //im using INPUT_PULLUP for the switch so i could use arduino's internal pull-up resistor.
  pinMode (porchLED, OUTPUT);
  pinMode (hallLED, OUTPUT);
}

void loop(){
  checkSwitch();
  controlLights();
}

void checkSwitch(){
  if (digitalRead(switchPin) == LOW && lightsOn == false) {
    lightsOn = true;
    startTime = millis (); //using millis instead of delay to control the timing of the lights together.
  }
}

void controlLights() //control both lights 
{

  if (lightsOn == true) {
      //porch light (30 secs)
      if (millis() - startTime <30000){
        digitalWrite(porchLED, HIGH);
      } else {
        digitalWrite(porchLED, LOW);
      }

      //hallway light (60 secs)
      if (millis() - startTime <60000){
        digitalWrite(hallLED, HIGH);
      } else {
        digitalWrite(hallLED, LOW);
        lightsOn = false;  //reset system
      }
    
  }
}
