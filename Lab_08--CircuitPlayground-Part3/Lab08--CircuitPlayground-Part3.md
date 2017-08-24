# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Madeleine Gomel<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications


## Lab 8. Circuit Playground Part 3

Use your knowledge of Circuit Playground to complete the following Challenge.


## Assignment

You should save your new or edited `.ino` file(s) in a new directory for today:

		$ cd ~
		$ mkdir -p Team09-Lab08/
		



### Assignment 1: Simon Says

Today you will use Raspberry Pi to design a Simon Says game that can run on your Circuit Playground. You will want to use either `random` or `randomSeed()` to complete this assignment.

http://arduino.cc/en/reference/random
http://arduino.cc/en/Reference/RandomSeed

**Rules:**At boot up, the Circuit Playground should choose one of four tones to play. Then the user can choose one of four capacitive sensors **ON THE OPPOSITE SIDE** to press to match the tone. Make sure that pressing the sensor of interest will also create those tones to give the user feedback. Use a color LED to devise a score-keeping methodology up to 10. Use an error buzzer sound to indicate when the user guessed wrong (and decrement their score to zero, and start over again). Give the user 3 attempts to guess each combination.

Example:

		Round 1:
		Circuit Playground plays Tone A and illuminates to represent Tone A
		Player must play Tone A (and LED illuminates to indicate Tone A played)
		If correct, proceed to Round 2:
		Circuit Playground plays Tone A, B
		Player plays Tone A, B ... etc.

Note that Simon Says is a memory game. The point of Simon Says is that with each progressing round, the tone sequence gets longer and more complicated (it should be a cumulative sequence, though, to help the user remember).

If the user wins, they should get a game winning sound, and an animation of the LEDs.

Finally, for added challenge, make the rate of tone playback for the challenge accelerated based on the position of the slider.

#### You need to be sure to test and debug it on your Circuit Playground hardware!

Remember, with microcontroller projects: test early and often. Each significant change you make to your .ino, you should be uploading it and testing to verify that 1) you didn't introduce syntax errors, 2) the software compiled and built correctly, and 3) the change you think you made actually got made. A common problem here is not properly closing your `for{}` or `while{}` loops with the proper syntax. Get to know the Arduino language reference we discussed in lecture if you have problems: http://arduino.cc/en/Reference/HomePage

#### Do not spend 2 hrs straight editing the file and then upload it once to test. That is not a recommended use case for Circuit Playground programming. Test early and often. You have been warned!!


### Upload your work from today

1. Zip up the arduino folder for Today's lab to make a single .zip file

		$ cd ~
		$ zip -r Team09-Lab08.zip arduino/SimonSays

1. `scp` your team's homework .zip file to your Instructor's RaspberryPi. Your Instructor will provide you with the value to enter for **IP_ADDRESS**. Use your same `raspberry` password (note that you are logging in as user `student`):

		$ man scp
		$ scp Team09-Lab08.zip student@IP_ADDRESS:/home/student/





## Shutdown Procedure

1. Shutdown your Pi properly:

		$ sudo shutdown -h now

 Unplug everthing and restore the Windows desktop computer to a working state.


## APPENDIX

### Troubleshooting Circuit Playground

During our work with Circuit Playground it may eventually get confused and stop being able to connect to a computer. Here's how to fix it:


#### Symptoms:	
* From: [https://forums.adafruit.com/viewtopic.php?f=58&t=102881](https://forums.adafruit.com/viewtopic.php?f=58&t=102881)
	`jfmclaugh` writes:
	> Circuit Playground was working fine until recently- now all I get is a green light, and occasionally the red # 13 pulses when I press reset. It won't install- I get USB Device Not Recognized. I'm using a cable that worked OK before, still works fine on my smart phone. I reinstalled the drivers as well, no help. Please advise, thanks


* Another symptom is that you will no longer see Circuit Playground listed in the output from:

		$ dmesg | grep tty

	Nor will Circuit Playground be available in the `Ports` menu item in the Arduino IDE.


#### Solution 
* `adafruit_support_mike` responds:

	>Connect the Circuit Playground to your computer and open the demo sketch in the Arduino IDE. Select 'Circuit Playground' under Tools->Board, and don't bother with Tools->Serial Port. From the Preferences pane, select verbose output during upload.

	>Click the Upload button, and wait for a series of lines that begin with 'PORTS' to start scrolling past in the console pane.

	>Double-click the Circuit Playground's reset button at that point.

	>The ATmega32u4 handles USB communication within the chip, and sometimes the bootloader's USB code crashes. Double-clicking the reset button restarts the bootloader and forces it to set up a new USB connection exactly when the Arduino IDE is looking for a device to do that.

	> ...

	> It's more of a design tradeoff than a bug.

	> The ATmega32u4 has 32k of Flash memory which is shared by the bootloader and the user code. The USB connection to upload firmware is controlled by the bootloader, and the more protocol checking and fallback code we add there, the less useful the board gets as a development platform.

	> As your students will learn, microcontroller programming is all about making tradeoffs with limited resources.



