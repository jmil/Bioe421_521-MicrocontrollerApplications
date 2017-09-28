# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Madeleine Gomel<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

## Lab 6C. Use the Mouse

Upt until now, we have only used a keyboard as the human-machine interface. You've now mastered a huge swath of skills and knowledge behind the core of how UNIX-like machines work and how to do lots of tasks. Today let's plug into the graphical user interface **(GUI)** and mouse. We held back doing this until now for three reasons: **1)** As we learned in class, the keyboard is the most *expressive* human-machine interface, **2)** it's still often faster to use the keyboard in a terminal for most things, and **3)** when things go wrong in the GUI, you might often need a keyboard and the **CLI** to diagnose or fix problems (remember `killall`?).

Note that the **GUI** is just another program (albeit much more complicated than the ones we've used so far). The entire interface is a single shell instance that you will be interfacing with using the keyboard **AND** the mouse.


1. Let's set the Desktop environment to be the default login on your Pi:

		$ sudo raspi-config

	Select option `Boot Options`, then `Desktop / CLI`, then `Desktop Autologin`, which tells you it will be `Desktop GUI, automatically logged in as 'pi' user`. Then select **`<Finish>`** and then **`<Yes>`** to Reboot.

	You should now boot into the Desktop environment with mouse control.

1. **Troubleshooting:** If this doesn't auto-login for you, you can just login via command-line and issue the following command to launch the GUI:

		$ startx


## Assignments

1. Change your desktop background. Make sure the image you choose off the web has a legal, free open access license. I recommend:
http://pixabay.com/


1. Open an instance of LXTerminal (remember the `<control-alt-T>` key combo?). This is your handy bash shell! You can do everything here we have done in class so far. Check what directory you are in. What command did you run to check the current directory?

		$ 

1. Install `arduino` via:

		$ sudo apt-get update
		$ sudo apt-get dist-upgrade
		$ sudo apt-get install arduino 
		
1. Let's install `processing`, which is now compatible with Raspberry Pi but hasn't yet made it into the official Raspbian repository (so you cannot yet install it with `sudo apt-get install processing`). However, we can install `processing` via the script located at it's webpage for linux systems with the ARM architecture:
https://processing.org/download/install-arm.sh

	First let's take a look at this script:
	
		$ wget -qO- https://processing.org/download/install-arm.sh | more
		
	What command will we need to use to run this script?
	
		: 
		
	Where is this command located on your hard drive? How do you know?
	
		command: $ 
		location:
		explanation: 
	
	We can run this script by piping the output from `wget` directly to the `sudo` version of the command needed to run this script. So what is your single-line program to install `processing`?
	
		$ 
		
	
	Explain the security risks with piping a script you download over the internet to the `sudo` version of this command:
	
		:
		:
		:
		:
		:
		:
		:
		:
		:
		: 
	
1. Check that everything is installed correctly. What command should you run to find where `arduino` and `processing` were installed? And what location did you find:

		command: $ 
		output: 
		command: $
		output: 
		
1. Finally, we need to uninstall `libgles2-mesa` because it can cause problems with `processing`:

		$ sudo apt-get remove libgles2-mesa
	
1. If everything is installed correctly, let's reboot:

		$ reboot


#### Processing

1. In the GUI, open `Processing` (`Start Menu` -> `Programming` -> `Processing`), and get familiar with the GUI version of the application. Try out some of the example programs via `File` -> `Examples...`. Run and play with the following demos. You can quit a running processing program using the `<esc>` key.


	• `Graphics` -> `Wiggling`
	Make sure you press the `<w>` key after the program has launched to see an even more dynamic animation. 
	
	• `Graphics` -> `Ribbons`
	Use the mouse to rotate the 3D protein structure.
		
	• `Graphics` -> `Particles`
	Move the mouse to dynamically set the location of particle emissions.


	**NOTE:** We will come back to `processing` later in the semester, and you may want to use it for your final project.

#### Arduino

1. Next, in the GUI, open `Arduino` (`Start Menu` -> `Programming` -> `Arduino IDE`), and get familiar with the GUI version of the application. With your Arduino Uno plugged in, you need to make sure you correctly setup your Arduino board:

	`Tools` -> `Board` -> `Arduino Uno` 

	`Tools` -> `Programmer` -> `AVRISP mkII`
	
	`Tools` -> `Serial Port` -> probably the `ACM0` setting we used in last couple classes
	
1. Check that the bottom right of the Arduino window now says something like:

		Arduino Uno on /dev/ttyACM0


1. Identify the `Verify` and `Upload` buttons. `Verify` will try to compile the current sketch for the Board you have selected in the menus.

1. Try to verify and upload the `Blink` tutorial which is available via `File` -> `Examples` -> `01.Basics` -> `Blink`. That should upload fine.

### You are now ready to program all kinds of Arduino's and their derivatives using your Raspberry Pi and its GUI!
	

