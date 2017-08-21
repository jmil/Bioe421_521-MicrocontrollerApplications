# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Madeleine Gomel<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

## Lab 8A. Use the Mouse

Upt until now, we have only used a keyboard as the human-machine interface. You've now mastered a huge swath of skills and knowledge behind the core of how UNIX-like machines work and how to do lots of tasks. Today let's plug into the graphical user interface **(GUI)** and mouse. We held back doing this until now for three reasons: **1)** As we learned in class, the keyboard is the most *expressive* human-machine interface, **2)** it's still often faster to use the keyboard in a terminal for most things, and **3)** when things go wrong in the GUI, you might often need a keyboard and the **CLI** to diagnose or fix problems (remember `killall`?).

Note that the **GUI** is just another program (albeit much more complicated than the ones we've used so far). The entire interface is a single shell instance that you will be interfacing with using the keyboard **AND** the mouse.


1. Let's set the Desktop environment to be the default login on your Pi:

		$ sudo raspi-config

	Select option `Boot Options` then `Desktop Autologin Desktop GUI, automatically logged in as 'pi' user`. Then select **`<Finish>`** and then **`<Yes>`** to Reboot.

	You should now boot into the Desktop environment with mouse control.

1. **Troubleshooting:** If this doesn't auto-login for you, you can just login via command-line and issue the following command to launch the GUI:

		$ startx


## Assignments

1. Change your desktop background. Make sure the image you choose off the web has a legal, free open access license. I recommend:
http://pixabay.com/


1. Open an instance of LXTerminal (remember <control-alt-T> key combo). This is your handy bash shell! You can do everything here we have done in class so far. Check what directory you are in. What command did you run to check the current directory?

		$ 

1. Install Processing and Arduino via:

		$ sudo apt-get update
		$ sudo apt-get dist-upgrade
		$ sudo apt-get install arduino processing 

1. Open `Arduino` (`Start Menu` -> `Programming` -> `Arduino IDE`), and get familiar with the GUI version of the application. With your Arduino Uno plugged in, you need to make sure you correctly setup your Arduino board:

	`Tools` -> `Board` -> `Arduino Uno` 

	`Tools` -> `Programmer` -> `AVRISP mkII`
	
	`Tools` -> `Serial Port` -> probably the `ACM0` setting we used in last couple classes


1. Identify the `Verify` and `Upload` buttons. `Verify` will try to compile the current sketch for the Board you have selected in the menus.

1. Try to verify and upload the `Blink` tutorial which is available via `File` -> `Examples` -> `01.Basics` -> `Blink`. That should upload fine.
	
1. Next, try one of your Danger Shield programs. You will probably have problems uploading your Danger Shield sketch. Can you figure out how to install the proper libraries in your Arduino program? **HINT:** Remember when you ran `git clone ...` to grab the CapacitiveSensor library in each `lib` directory created with `ino`? You might try to do this inside the `/usr/share/arduino/libraries/` folder. Do you remember how to address permissions problems to allow you to run this command?

	Show your successful Danger Shield upload to your Instructor.


