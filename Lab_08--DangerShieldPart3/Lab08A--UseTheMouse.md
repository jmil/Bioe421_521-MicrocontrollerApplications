#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: John Sexton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 8A. Use the Mouse

Upt until now, we have only used a keyboard as the human-machine interface. You've now mastered a huge swath of skills and knowledge behind the core of how UNIX-like machines work and how to do lots of tasks. Today let's plug into the graphical user interface **(GUI)** and mouse. We held back doing this until now for two reasons: 1) it's still often faster to use the keyboard in a terminal for most things, and 2) when things go wrong in the GUI, you might often need a keyboard to diagnose or fix problems (remember `killall` ?)



		$ sudo raspi-config

Select option `3 Enable Boot to Desktop/Scratch` then `Desktop Log in as user 'pi' at the graphical desktop`. Then select **`<Finish>`** and then **`<Yes>`** to Reboot.


Spend a bit poking around the desktop. Use `Midori` to browse the web. It's been optimized for Raspberry Pi. You can install Chrome, but it's slow. You can install lots of things. But this is a $35 computer, so don't expect too much without heavily optimized code.
		


##Assignments

1. Change your desktop background. Make sure the image you choose off the web has a legal, free open access license. I recommend:
http://pixabay.com/


1. Open an instance of LXTerminal (should be an icon on your desktop). This is your handy bash shell! You can do everything here we have done in class so far.

1. Open `Arduino` (`Start Menu` -> `Programming` -> `Arduino IDE`), and get familiar with the GUI version of the application. You need to make sure you correctly setup your Arduino board:

	`Tools` -> `Board` -> `Arduino Uno` 

	`Tools` -> `Programmer` -> `AVRISP mkII`
	
	`Tools` -> `Serial Port` -> probably the `ACM0` setting we used in last couple classes


	Find the Verify and Upload buttons. First try uploading the `Blink` tutorial available via `File` -> `Examples` -> `01.Basics` -> `Blink`. That should upload fine.
	
	Next, try one of your Danger Shield programs. You will probably have problems uploading your Danger Shield sketch. Can you figure out how to install the proper libraries in your Arduino program? **HINT:** Remember when you ran `git clone ...` to grab the CapacitiveSensor library in each `lib` directory created with `ino`? You might try to do this inside the `/usr/share/arduino/libraries/` folder. Do you remember how to address permissions problems to allow you to run this command?

	Show your successful Danger Shield upload to your Instructor.


