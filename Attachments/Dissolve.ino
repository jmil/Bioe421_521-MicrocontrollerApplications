

/*
 * Dissolve
 *
 * A variation on Blink, the the basic Arduino example.  Turns on an LED on for one second,  then off for one second, then on for a little less than a second, then off for a little less, and then speeds it up a little faster each time...  
 * We use pin 13 because,
 * depending on your Arduino board, it has either a built-in LED
 * or a built-in resistor so that you need only an LED.
 *
 * http://www.arduino.cc/en/Tutorial/Blink
 */

int ledPin = 13;                // LED connected to digital pin 13

int delayTime = 1000;          // starts just like Blink does, but this will decrease over time

float multiplyByFactor = 0.95;   // each cycle, multiply delay time by this factor

void setup()                    // run once, when the sketch starts
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

void loop()                     // run over and over again
{
  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(delayTime);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(delayTime);                  // waits for a second

  // For each blink cycle, mutiple delay by factor:  1000, 950, 902, 856, 813, 772, ...
  // until delayTime is just one millisecond   
  if (delayTime > 1) {
    delayTime= delayTime * multiplyByFactor;
  }
}
