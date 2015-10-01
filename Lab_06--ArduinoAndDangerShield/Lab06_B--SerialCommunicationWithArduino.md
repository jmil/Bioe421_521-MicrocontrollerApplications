#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Jacob Albritton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 6B. Serial Communication with Arduino

Although currently connected by USB, Arduino is an independent computer. So we can actively communicate with Arduino to find out the state of variables in our running program. Let's take a look.

1. Make a new directory to work in:

		$ cd ~
		$ mkdir -p arduino/ascii
		$ cd arduino/ascii
	
	What does the `-p` option of `mkdir` do?
	
		:

1. Use `ino` to make a default sketch based on the blink template. We'd like to replace the contents of the `sketch.ino` with the program available here: http://arduino.cc/en/Tutorial/ASCIITable
	
1. Use `wget` to grab this file and replace the contents of `~/arduino/ascii/src/sketch.ino`:
 
	http://arduino.cc/en/Tutorial/ASCIITable?action=sourceblock&num=1
	
	What is the command you used to download this text file and overwrite your `sketch.ino` file?
	
		$ 

1. Take a quick look at the program to check that it was updated:
		
		$ nano ~/arduino/ascii/src/sketch.ino

1. Exit `nano`.

1. Use `ino` to build and upload your sketch. What commands did you run to build and upload your sketch?

		$ 
		$ 
		
	Was your upload successful? You should now notice that the LED you previously programmed to blink is no longer blinking.


1. Look in more detail at the program to check that it was updated:
		
		$ nano ~/arduino/ascii/src/sketch.ino
		
	The output from this program is sent to the serial link (via `Serial.println` for "serial, print line"). But the serial link is disconnected after the `.hex` upload.

1. Fear not! We can use `python` to establish a new serial link, reboot your Arduino, and then monitor the output from the Arduino's running program. This is a pattern we will utilize often.

	Find the ttyA* setting for your Arduino as we did for Lab 6A:
	
			$ dmesg | grep tty
			...
			...
			... ttyACM0: USB ACM device
	Recall that you should see a message with ttyACM0 or something like it.

1. Make a new python script `~/arduino/ascii/python-arduino-read.py` with the following contents (making sure you match your specific `ttyACM0` string (from above) to what `dmesg` gave you):

		#! /usr/bin/python
		# from http://playground.arduino.cc/interfacing/python
		import serial

		ser = serial.Serial('/dev/ttyACM0', 9600)
		while True:
    		print ser.readline()

1. Execute your `python` script with the Arduino connected. What command(s) can you use to execute your `python` script?

		$
		$
		
	You can use **`<ctrl-C>`** to quit the program. Describe the output from your python script:
	
		:		

1. It would be more helpful if we could dump the output from the Arduino into a text file on the Raspberry Pi. To do this, we modify the program:


		ser = serial.Serial('/dev/ttyACM0', 9600)
		f = open('output.txt','w')
		while True:
			output_line = ser.readline()
			print output_line
    		f.write(output_line)

1. Execute this modified `python` script. Now take a closer look at what you got for the output:

		$ cat output.txt | more

	Describe the contents of your output.txt file and show it to your Instructor:
	
	:
	:
	:
	:

### `ino` serial

1. Finally, `ino` itself has it's own serial mode which you can use to directly dump serial prints to the monitor. Try this out with:

		$ ino serial
		
	Use `<CTRL-A><CTRL-X>` to exit back to the command prompt.
