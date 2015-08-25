#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Jacob Albritton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications


##Lab 8B. Danger Shield Part 3

Use your knowledge of Danger Shield to complete the following Assignments.


####Procedure: You may use the GUI or use the command line to complete this assignment. For command line: recall you have used `ino` to setup the proper set of directories and files for each of your Arduino scripts. So, for EACH of the following assignments, you should repeat this setup procedure to create a clean directory to work in:

		$ cd ~
		$ mkdir -p arduino/SimonSays
		$ cd arduino/SimonSays
		$ ino init -t blink
		$ cd lib
		$ git clone https://github.com/PaulStoffregen/CapacitiveSensor
		$ cd ../src
		$ rm sketch.ino
		$ git clone https://github.com/sparkfun/DangerShield
		
####Then	you just edit that particular instance of the DangerShield.ino file, adding what you want and deleting anything you don't want. When editing in `nano`, **`<ctrl-K>`** can be used to delete an entire line at a time.

		$ nano DangerShield/Firmware/DangerShield/DangerShield.ino

####To complete each assignment, you need to be sure to test and debug it on your Danger Shield hardware! So after editing your `.ino` file, you would:
		
		$ cd arduino/SimonSays
		$ ino build
		...
		Converting to firmware.hex
		$ ino upload

###Remember, with microcontroller projects: test early and often. Each significant change you make to your .ino, you should be uploading it and testing to verify that 1) you didn't introduce syntax errors, 2) the software compiled and built correctly, and 3) the change you think you made actually got made. A common problem here is not properly closing your `for{}` or `while{}` loops with the proper syntax. Get to know the Arduino language reference we discussed in lecture if you have problems: http://arduino.cc/en/Reference/HomePage

###Do not spend 2 hrs straight editing the file and then upload it once to test. That is not a recommended use case for Danger Shield programming. Test early and often. You have been warned!!


##Assignments

###Assignment 1: Simon Says

Today you will use Raspberry Pi to design a Simon Says game. You will want to use either `random` or `randomSeed()` to complete this assignment.

http://arduino.cc/en/reference/random
http://arduino.cc/en/Reference/RandomSeed

**Rules:**At boot up, the Danger Shield should choose one of three tones to play. Then the user can choose one of three buttons to press to match the tone. Make sure that pressing the buttons will also create those tones. Use the 7-segment LED to keep score up to 10. Use an error buzzer sound to indicate when the user guessed wrong (and decrement their score to zero, and start over again). Give the user 3 attempts to guess each combination.

If the user wins, they should get a game winning sound.

Finally, for added challenge, make the rate of tone playback for the challenge accelerated based on the position of slider 2.




###Upload your work from today

1. Zip up the arduino folder for Today's lab to make a single .zip file

		$ cd ~
		$ zip -r team01-LightBender_Lab08.zip arduino/SimonSays

1. `scp` your team's homework .zip file to your Instructor's RaspberryPi. Your Instructor will provide you with the value to enter for **IP_ADDRESS**. Use your same `raspberry` password (note that you are logging in as user `student`):

		$ man scp
		$ scp team01-LightBender_Lab08.zip student@IP_ADDRESS:/home/student/





## Shutdown Procedure

1. Shutdown your Pi properly:

		$ sudo shutdown -h now

 Unplug everthing and restore the Windows desktop computer to a working state.
