import processing.serial.*;
Serial usbPort;
int [ ] sensorData;
PImage img01;
PImage img02;
PImage img03;
int redValueB4;
int greenValueB4;
int blueValueB4;
float redValue = 0;
float greenValue = 0;
float blueValue = 0;
int backgnd;

int[] sensors = null;
boolean firstContact = false;  


void setup () {
  size(700, 500);
  img01 = loadImage("Image.png");
  img02 = loadImage("Image02.png");
  img03 = loadImage("Image03.png");
  usbPort = new Serial (this, Serial.list( ) [0], 9600);
  usbPort.bufferUntil ('\n');
  
}

void draw () {
  simpleImage(backgnd, redValueB4, greenValueB4, blueValueB4);
}

void serialEvent ( Serial usbPort ) {
  String usbString = usbPort.readStringUntil ('\n');
  if (usbString != null) {
    usbString = trim(usbString);

    if (firstContact == false) {
      if (usbString.equals("Hello")) {
        usbPort.clear();
        firstContact = true;
        usbPort.write('A');
        println("contact");
      }
    }
    else {

      int sensors[ ] = int(split(usbString, ','));
      for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
      }
      
      int slider1 = sensors[0];
      int button1 = sensors[1];
      int slider2 = sensors[2];
      int button2 = sensors[3];
      int slider3 = sensors[4];
      int button3 = sensors[5];
      int photoCell = sensors[7];
      backgnd = int (map ( photoCell, 1, 950, 1, 3 ));
      redValueB4 = int (map (slider1, 0, 1023, 0, 255));
      greenValueB4 = int (map (slider2, 0, 1023, 0, 255));
      blueValueB4 = int (map (slider3, 0, 1023, 0, 255));
      if (button1 == 0) {
        redValue = redValueB4;
      }
      if (button2 == 0) {
        greenValue = greenValueB4;
      }
      if (button3 == 0) {
        blueValue = blueValueB4;
      }
      //println(backgnd + " " + redValueB4 + " " + greenValueB4 + " " + blueValueB4);
      //simpleImage(backgnd, redValueB4, greenValueB4, blueValueB4);

      usbPort.write("A");
    }
  }
}

