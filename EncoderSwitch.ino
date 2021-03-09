/*     Encoder Switch Example
 *     by Scott Kildall for the ESP32
 *     
 *     Uses the ESP32Encoder libraries:
 *     https://github.com/madhephaestus/ESP32Encoder
 *     
 *     This is for an single-step encoder that is also a switch
 *     
 */

// lib from the github link
#include <ESP32Encoder.h>

// Encoder class from the lib
ESP32Encoder encoder;

// our pins
const int switchPin = 15;
const int encoderAPin = 13;
const int encoderBPin = 12;

void setup(){
	Serial.begin(115200);    // 
	
  // Enable the weak pull down resistors
  // (Don't know if this is needed)
	ESP32Encoder::useInternalWeakPullResistors=UP;

  // This is a single edge encoder
	encoder.attachSingleEdge(encoderAPin, encoderBPin);
	
	// set starting count value after attaching
	encoder.setCount(0);

  pinMode(switchPin,INPUT);
	Serial.println("Encoder Start = " + String((int32_t)encoder.getCount()));
}

// Display encoder count OR switch down
void loop(){
  if( digitalRead(switchPin) == true ) {
    Serial.println("DOWN");
    return;
  }
  else {
    Serial.println("Encoder count = " + String((int32_t)encoder.getCount()));// + " " + String((int32_t)encoder2.getCount()));
  }
	delay(100);
}
