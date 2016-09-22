/*
 * Throb
 *
 * A variation on Blink.  This sketch presents the concept of PWM or
 * Pulse Width Modulation. It "throbs" the brightness of an LED, making it 
 * gradually brighter and dimmer.
 * 
 * From Blink: We use pin 13 because,
 * depending on your Arduino board, it has either a built-in LED
 * or a built-in resistor so that you need only an LED.
 *
 */

int ledPin = 13;                // LED connected to digital pin 13

// once this is working, reprogram with a cycle time of 100 to see more clearly how the throbbing works
int cycleTime = 30;             // the total duration of a PWM cycle

int changeSpeed = 1;            // throb speed, or the number of milliseconds to change the onTimePerCycle per Cycle

boolean brightnessGoingUp = true;     // whether the brightness is going up or down
int onTimePerCycle = 0;      // the number of milliseconds to turn the LED within a cycle

void setup()                    // run once, when the sketch starts
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

void loop()                     // run over and over again
{

  digitalWrite(ledPin, HIGH);        // sets the LED on
  delay(onTimePerCycle);             // wait for onTimePerCycle milliseconds
  digitalWrite(ledPin, LOW);         // sets the LED off
  delay(cycleTime - onTimePerCycle); // waitfor the rest of the complete cycle              

  // Now adjust the brightness up or down depending the the current state
  if (brightnessGoingUp) {  
    onTimePerCycle += changeSpeed;
  } 
  else {
    onTimePerCycle -= changeSpeed;
  }   

  // if we are at full brightness, where the LED is on for the complete cycle
  if (onTimePerCycle >= cycleTime) {
    brightnessGoingUp = false;       // switch mode to brightness going down
    onTimePerCycle = cycleTime;      // make sure brightness did not go over
  }
  // if we are at zero brightness, where the LED is not on at all in a cycle 
  if (onTimePerCycle <= 0) {        
    brightnessGoingUp = true;      // switch mode to brightness going up
    onTimePerCycle = 0;            // make sure the onTime didn't go bellow zero         
  }

}
