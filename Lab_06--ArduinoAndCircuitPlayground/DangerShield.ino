/*
 Danger Shield Example Sketch
 Written by Chris Taylor 3-3-2010
 Tweaked by Nathan Seidle 10-22-2012
 Spark Fun Electronics
 
 This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 The project is OSHW and the schematic is released under Creative Commons Share Alike w/ Attribution v3.0
 
 This is the example code, created in Arduino v1.0.1 for the Danger Shield product by SparkFun Electronics. 
 It demonstrates each feature of the shield. Move one of the sliders to get a different sound out of the buzzer. 
 Move another slider to change the digit being displayed on the seven segment display. Move the last slider to 
 change the brightness of one of the two status LEDs. Press one of the large buttons to toggle on/off the status LED. 
 Cover the light sensor to 'scare' the unit. Open a terminal window at 9600bps if you'd like to see the
 values change over the serial connection.
 
 This code works best with product SKU 10115: https://www.sparkfun.com/products/10115
 
 Knock sensor, new temp sensor: https://www.sparkfun.com/products/10115
 Cap touch sensor: https://www.sparkfun.com/products/10570
 
 The idea of a Danger Shield was originally created by Zach Hoeken (http://www.zachhoeken.com/) released CC-SA.
 
 */

// Shift register bit values to display 0-9 on the seven-segment display
const byte ledCharSet[10] = {
  B00111111, 
  B00000110, 
  B01011011, 
  B01001111, 
  B01100110, 
  B01101101, 
  B01111101, 
  B00000111, 
  B01111111, 
  B01101111
};

// Pin definitions

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//These pin definitions are for v1.6 of the board
/*
#define SLIDER1  A0
 #define SLIDER2  A1
 #define SLIDER3  A2
 #define LIGHT    A3
 #define TEMP     A4
 #define KNOCK    A5
 
 #define DATA     4
 #define LED1     5
 #define LED2     6
 #define LATCH    7
 #define CLOCK    8
 #define BUZZER   9
 #define BUTTON1  10
 #define BUTTON2  11
 #define BUTTON3  12
 //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 */

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//These pin definitions are for v1.7 of the board
#define SLIDER1  A2 //Matches button 1
#define SLIDER2  A1 
#define SLIDER3  A0 //Matches button 3
#define LIGHT    A3
#define TEMP     A4

#define BUZZER   3
#define DATA     4
#define LED1     5
#define LED2     6
#define LATCH    7
#define CLOCK    8
#define BUTTON1  10
#define BUTTON2  11
#define BUTTON3  12
//v1.7 uses CapSense
//This relies on the Capactive Sensor library here: http://playground.arduino.cc/Main/CapacitiveSensor
#include <CapacitiveSensor.h>

CapacitiveSensor capPadOn92 = CapacitiveSensor(9, 2);   //Use digital pins 2 and 9,
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

int avgLightLevel;

void setup()
{
  Serial.begin(9600);

  //Initialize inputs and outputs
  pinMode(SLIDER1, INPUT);
  pinMode(SLIDER2, INPUT);
  pinMode(SLIDER3, INPUT);
  pinMode(LIGHT, INPUT);
  pinMode(TEMP, INPUT);

  //Enable internal pullups
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);

  //Initialize the capsense
  capPadOn92.set_CS_AutocaL_Millis(0xFFFFFFFF); // Turn off autocalibrate on channel 1 - From Capacitive Sensor example sketch

  Serial.println("Danger Shield Component Test");  

  //Take 16 readings from the light sensor and average them together
  avgLightLevel = 0;
  for(int x = 0 ; x < 16 ; x++)
    avgLightLevel += analogRead(LIGHT);
  avgLightLevel /= 16;
  Serial.print("Avg: ");
  Serial.println(avgLightLevel);

}

void loop()
{
  //Read inputs
  int val1 = analogRead(SLIDER1);
  int val2 = analogRead(SLIDER2);
  int val3 = analogRead(SLIDER3);
  int lightLevel = analogRead(LIGHT);
  long temperature = analogRead(TEMP);

  //Read the cap sense pad
  long capLevel = capPadOn92.capacitiveSensor(30);
  
  //Do conversion of temp from analog value to digital
  temperature *= 5000; //5V is the same as 1023 from the ADC (12-bit) - example, the ADC returns 153 * 5000 = 765,000
  temperature /= 1023; //It's now in mV - 765,000 / 1023 = 747
  //The TMP36 reports 500mV at 0C so let's subtract off the 500mV offset
  temperature -= 500; //747 - 500 = 247
  //Temp is now in C where 247 = 24.7

  //Display values
  //sprintf is a great way to combine a bunch of variables and strings together into one print statement
  char tempString[200];
  sprintf(tempString, "Sliders: %04d %04d %04d Light: %04d Capsense: %04d", val1, val2, val3, lightLevel, capLevel);
  Serial.print(tempString); 
  sprintf(tempString, " Temp: %03d.%01dC", (int)temperature/10, (int)temperature%10);
  Serial.print(tempString); 

  //If user is hitting button 1, turn on LED 1
  if(digitalRead(BUTTON1) == LOW)
  {
    Serial.print(" Button 1!");
    digitalWrite(LED1, HIGH);
  }
  else
    digitalWrite(LED1, LOW);

  Serial.println();

  //Set the brightness on LED #2 (D6) based on slider 1
  int ledLevel = map(val1, 0, 1020, 0, 255); //Map the slider level to a value we can set on the LED
  analogWrite(LED2, ledLevel); //Set LED brightness

  //Set 7 segment display based on the 2nd slider
  int numToDisplay = map(val2, 0, 1020, 0, 9); //Map the slider value to a displayable value
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, ~(ledCharSet[numToDisplay]));
  digitalWrite(LATCH, HIGH);

  //Set the sound based on the 3rd slider
  long buzSound = map(val3, 0, 1020, 1000, 10000); //Map the slider value to an audible frequency
  if(buzSound > 1100)
    tone(BUZZER, buzSound); //Set sound value
  else
    noTone(BUZZER);

  //If light sensor is less than 3/4 of the average (covered up) then freak out
  while(lightLevel < (avgLightLevel * 3 / 4))
  {
    //Blink the status LEDs back and forth
    if(digitalRead(LED1) == LOW)
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
    }
    else {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
    }

    //Display an increasing number on the 7-segment display
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, ~(ledCharSet[numToDisplay]));
    digitalWrite(LATCH, HIGH);
    numToDisplay++; //Goto next number
    if(numToDisplay > 9) numToDisplay = 0; //Loop number

    //Play a horrendously annoying sound
    //Frequency increases with each loop
    tone(BUZZER, buzSound);
    buzSound += 100;
    if(buzSound > 3000) buzSound = 1000;

    delay(25);

    lightLevel = analogRead(LIGHT); //We need to take another reading to be able to exit the while loop
  }
}
