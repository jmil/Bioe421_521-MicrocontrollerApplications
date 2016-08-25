// Pin definitions
#define SLIDER3  0
#define SLIDER2  1
#define SLIDER1  2

//#define KNOCK    5
//
//#define CAP1  2
//#define CAP1  9

#define BUTTON1  10
#define BUTTON2  11
#define BUTTON3  12

#define LED1  5
#define LED2  6

#define BUZZER   3

#define TEMP  4

#define LIGHT  3

#define LATCH 7
#define CLOCK 8
#define DATA 4


//char START_BYTE = '*';
char DELIMITER = ',';
//char END_BYTE = '#';
int val;

// Shift register bit values to display 0-9 on the seven-segment display
const byte ledCharSet[10] = {

  B00111111,B00000110,B01011011,B01001111,B01100110,B01101101,B01111101,B00000111,B01111111,B01101111
};

void setup()
{

  pinMode(BUZZER, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA,OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  Serial.begin(9600); 
  establishContact();
}

void loop(){
      

  //Serial.print(START_BYTE, BYTE);
  
  val = analogRead(SLIDER1); //read slider1
  Serial.print(val, DEC);
  Serial.print(DELIMITER);
  
  val = digitalRead(BUTTON1);//read button1
  Serial.print(val, DEC);
  Serial.print(DELIMITER);
  
  val = analogRead(SLIDER2); //read slider2
  Serial.print(val, DEC);
  Serial.print(DELIMITER);
 
  val = digitalRead(BUTTON2); //read button2
  Serial.print(val, DEC);
  Serial.print(DELIMITER);
  
  val = analogRead(SLIDER3); //read slider3

  Serial.print(val, DEC);
  Serial.print(DELIMITER);
  
  val = digitalRead(BUTTON3);//read button3
  Serial.print(val, DEC);
  Serial.print(DELIMITER);
  
  val = analogRead(TEMP);
  Serial.print(val, DEC);
  Serial.print(DELIMITER);  
 
  val = analogRead(LIGHT);

  Serial.print(val, DEC);
  Serial.print(DELIMITER);
  
  
  int sevenSeg = (int)map(val, 400, 900, 1, 3);
  Serial.println(sevenSeg);
  
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, ~(ledCharSet[sevenSeg]));
  digitalWrite(LATCH, HIGH);
  
  //Serial.println(END_BYTE, BYTE);
}


void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("Hello");   // send a starting message
    delay(300);
  }
}

