// C++ code
#include <Servo.h>
// Declarations
const int potentiometerPin = 0;
const int rgbLED01_pins[] = {9,10,11};
const int switchPin = 2;

// Declare servos
Servo servo_5; // Attached to pin 5
Servo servo_6; // Attached to pin 6

int switchState = 0; // Read button state
bool useControlArmBase = true;

float lastPotValue = 0;
bool switchPositionChanged = false;
bool isStart = true;

void setup()
{
	// Initialize the LED pin as an output:
  	pinMode(rgbLED01_pins[0], OUTPUT);
  	pinMode(rgbLED01_pins[1], OUTPUT);
  	pinMode(rgbLED01_pins[2], OUTPUT);
  	pinMode(switchPin, INPUT);
  
  	// Instantiate servos
  	// Pin, Min (0 deg), Max (180 deg)
  	servo_5.attach(5, 500, 2500);
  	servo_6.attach(6, 500, 2500);
  
  	Serial.begin(9600); // Initialize serial communication
  	Serial.print("--START--");
}

void loop()
{
    // read the state of the pushbutton value:
  	switchState = digitalRead(switchPin);
  
  	// Set color to white
   	analogWrite(rgbLED01_pins[0], 255);
  	analogWrite(rgbLED01_pins[1], 255);
  	analogWrite(rgbLED01_pins[2], 255);
  
  	// Button Trigger and Light Control
    if (switchState == HIGH) {
        // Set color to red when button is pushed
        analogWrite(rgbLED01_pins[0], 0);
        analogWrite(rgbLED01_pins[1], 0);
        analogWrite(rgbLED01_pins[2], 255);
        useControlArmBase = false;
      	delay(1000);
    }else{
        // Set color to blue when button is pushed
        analogWrite(rgbLED01_pins[0], 255);
        analogWrite(rgbLED01_pins[1], 0);
        analogWrite(rgbLED01_pins[2], 0);
        useControlArmBase = true;
      	delay(1000);
    }
  
    // Read Potentiometer
	int potValue = analogRead(potentiometerPin);
  	float potPosition = potValue * (180.0 / 1023.0); // 5V Arduino
  
    if (isStart == true){
      lastPotValue = potPosition;
      isStart = false;
    }
  
  	// Control Servos based on Potentiometer input
  	if(lastPotValue != potPosition){
      if(useControlArmBase == true){
          servo_5.write(potPosition);
      }else{
          servo_6.write(potPosition);
      }
      lastPotValue = potPosition;
    }
  
  	// Debug
	//Serial.print("\n Button State: "+digitalRead(2));
}