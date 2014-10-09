#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: John Sexton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 6B. Serial Communication with Arduino

Although currently connected by USB, Arduino is an independent computer. So we can actively communicate with Arduino to find out the state of variables in our running program. Let's take a look.

1. Make a new directory to work in:

		$ cd ~
		$ mkdir -p arduino/ascii
		$ cd arduino/ascii
	

1. Use `ino` to make a default sketch based on the blink template. We'd like to replace the contents of the `sketch.ino` with the program available here: http://arduino.cc/en/Tutorial/ASCIITable
	
1. Use wget to grab this file and replace the contents of `~/arduino/ascii/src/sketch.ino`:
 
	http://arduino.cc/en/Tutorial/ASCIITable?action=sourceblock&num=1

1. Use `ino` to build and upload your sketch. But after successful upload, you won't notice anything observable on your Arduino or Raspberry Pi. Take a look at the program in detail. The output from this program is sent to the serial link (via `Serial.println` for "serial, print line"). But the serial link is disconnected after the `.hex` upload.

1. Fear not! We can use `python` to establish a new serial link, reboot your Arduino, and then monitor the output from the Arduino's running program. This is a pattern we will utilize often.

	Find the ttyACM* setting for your Arduino:
	
			$ dmesg | grep tty
			...
			...
			... ttyACM0: USB ACM device
	You should see a message with ttyACM0 or something like it.

1. Make a new python script `~/arduino/ascii/python-arduino-read.py` with the following contents (making sure you match your `ACM0` to what `dmesg` gave you):

		#! /usr/bin/python
		# from http://playground.arduino.cc/interfacing/python
		import serial

		ser = serial.Serial('/dev/ttyACM0', 9600)
		while True:
    		print ser.readline()

1. Execute your `python` script with the Arduino connected. You can use **`<ctrl-C>`** to quit the program. What is your output? <br /><br /><br />

1. It would be more helpful if we could dump the output from the Arduino into a text file on the Raspberry Pi. To do this, we modify the program:


		ser = serial.Serial('/dev/ttyACM0', 9600)
		f = open('output.txt','w')
		while True:
			output_line = ser.readline()
			print output_line
    		f.write(output_line)

1. Now take a closer look at what you got for the output:

		$ cat output.txt | more

#### Show the contents of your output.txt file to your instructor


