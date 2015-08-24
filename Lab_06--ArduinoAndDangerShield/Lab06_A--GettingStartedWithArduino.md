#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Jacob Albritton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 6A. Getting Started with Arduino

Today we add the **Arduino**  microcontroller (pronounced `Ar du ween Oh`), to our hardware setup. It was developed by an awesome hardware/software team in Italy. Wikipedia has a concise overview:

> Arduino is a single-board microcontroller, intended to make building interactive objects or environments more accessible. The hardware consists of an open-source hardware board designed around an 8-bit Atmel AVR microcontroller, or a 32-bit Atmel ARM. Current models feature a USB interface, 6 analog input pins, as well as 14 digital I/O pins that accommodate various extension boards.

> Introduced in 2005, the Arduino's designers sought to provide an inexpensive and easy way for hobbyists, students, and professionals to create devices that interact with their environment using sensors and actuators. Common examples for beginner hobbyists include simple robots, thermostats and motion detectors. It comes with a simple integrated development environment (IDE) that runs on regular personal computers and allows users to write programs for Arduino using C or C++.

Arduino almost immediately became a favorite among tinkerers and hobbyists for the ease with which you can rapidly prototyping integrated devices. It's programmed with an open-source and cross-platform (Linux, Mac, Windows) software kit. And it's an extremely extensible system. In fact, Arduino microcontrollers power most of the open-source 3D printers you can buy today. You can read all about Arduino and see it's amazingly vibrant community here:
http://www.arduino.cc/


### Plugging It In

We are using **Arduino UNO R3**. Arduino by default gets its power over USB. This is great, because we have a spare USB port on our Raspberry Pi! Look for your **Arduino Starter Pack** inside your crate. Inside it, carefully find the smaller box labeled **Arduino UNO**, and take out the device. It looks like this:

<img src="ArduinoUno_R3_Front.png" alt="Arduino UNO" style="width:300px">**Arduino UNO**

Use the included USB A->B cable to connect Arduino UNO to your Raspberry Pi. You should see some LEDs light up, especially the green power LED.

### Update the Software

1. We need to make sure we have the latest Arduino software updated on our Pi. Did you previously install the `arduino	` program correctly (back in **Lab1B**)? Do you remember **`which`** command you can use to check if it's installed correctly?

		$ which arduino
		/usr/bin/arduino

1. Let's update our known list of programs and version numbers and make sure we have the latest versions of everything.

		$ sudo apt-get update
		$ sudo apt-get dist-upgrade

	This will take a little while. In the meantime, learn more about Arduino and start talking with your lab partner about what you might want to do for your final project:
	http://blog.arduino.cc/

	And... we're back. Let's cleanup deprecated programs too:

		$ sudo apt-get autoremove

1. We need to have the ability to program the Arduino and upload software via command line.

		$ sudo apt-get install arduino-core arduino-mk

1. We need to make sure that our user account is a member of the `dialout` group so that we are authorized by the OS to communicate with the Arduino:
	
		$ id
		$ man usermod
		$ sudo usermod -a -G dialout pi

1. Logout and then login again to make sure the changes took effect. Verify it worked:

		$ id

	Is your user account now a member of the `dialout` group?


1. To do a test upload of software to our Arduino board, we will need to use a combination of `git`, `python`, and `ino` *(hat-tip http://openenergymonitor.blogspot.com/2013/12/developing-for-arduino-remotely-on.html)*.

		$ man git
	
	`git` is an extremely powerful tool... but for right now, you can think of `git` simply as a a way to store and track all changes to files and easily transmit them over the Internet (it has compression, version control, and internet protocols all built-in). It's a convenient way to download and install software from other people. Here, we use `git` to download the software, and a `python` script will help us install it in the system.
	
	#### SECURITY NOTE: we will be downloading software over the internet, then running these installation programs as the root user. Raspberry Pi is easy enough to reinstall, but be aware of where you download software from, and which scripts you choose to give root access to as you progress in class.

		$ sudo apt-get install python-dev
		$ sudo apt-get install python-setuptools
		$ cd ~
		$ mkdir -p github
		$ cd github
		$ git clone git://github.com/amperka/ino.git
		$ cd ino
		$ ls -la 			# WOW, that's a lot of stuff!
		$ sudo python setup.py install
		
	Check if your software was installed correctly:
	
		$ which ino
		/usr/local/bin/ino

	We also need to have command-line serial communication (this is a serial communication protocol emulated over USB):

		$ sudo apt-get install picocom
		$ which picocom
		/usr/bin/picocom
	
### Blink!
	
Ok, it's time to create and install your first Arduino program, called a **sketch**. Arduino is written in it's own programming language, which is C-like but has some abbreviations and conventions we will learn about.

1. We will use the `ino` command to generate a lot of the template files for us, and compile the ASCII-based **sketch** into a binary `.hex` file that the Arduino can natively use. `ino` will call the `picocom` program in the background to actually do the upload of the `.hex` file to the Arduino over the emulated USB-serial connection.

		$ cd ~
		$ mkdir -p arduino/blink
		$ cd arduino/blink
		
1. Arduino comes with a set of templates we can learn from... and the `ino` program already knows how to copy them into your current directory to get ready for compilation. Here, we will grab the `blink` templates, build them, then upload them.

	Since `ino` wasn't installed in the conventional way, it doesn't have a man page:
	
		$ man ino
		No manual entry for ino
	
	Instead, `ino` has a brief help file, accessed with the `-h` flag:
	
		$ ino -h
	
	Ok, let's make a **sketch** patterned off the **blink** templates:
	
		$ ino init -t blink
		$ ls -la
	
	You should see two directories, a `lib` and a `src`. Inside `src` you will find the contents of the sketch. Let's see what's in there:
		
		$ cd src
		$ ls -la
		$ cat sketch.ino
		
		#define LED_PIN 13
		
		void setup()
		{
			pinmode(LED_PIN, OUTPUT);
		}
		
		void loop()
		{
			digitalWrite(LED_PIN, HIGH);
			delay(100);
			digitalWrite(LED_PIN, LOW);
			delay(900);
		}
	
	That's all there is to a basic Arduino **sketch**. The `#define` command sets a global variable `LED_PIN` to the integer `13`. Next, the `setup()` loop gets called once immediately after the Arduino is powered on. You use the `setup()` loop to, you guessed it, setup your variables. Here we set the `LED_PIN` to respond to our commands with an output. The `loop()` is continously run as long as the Arduino has power. Inside this loop, we successively set the `LED_PIN` to be `HIGH` or `LOW`, corresponding to on and off in this case. We also have to insert delays in milliseconds between the on/off switches so that we can observe a change with our eyes. Although the Arduino might be considered "slow" by the standard of modern computers, it's now slouch! With the processor running at 16 MHz, if we don't pause the LED light, we won't see a change.
	
1. Let's build the **sketch** into a binary file:
		
		$ cd ~/arduino/blink/
		$ ino build
		Searching for Board description file ...
		...
		Converting to firmware.hex

1. Check what was done; there should be a new `.build` directory:
		
		$ ls -la
		$ cd .build
		$ ls -la
		$ cd uno
		$ ls -la
		$ cat firmware.hex
	
	Describe the contents of the firmware.hex file:<br /><br /><br />
	
1. Upload the firmware to your Arduino. Make sure the Arduino is connected to Raspberry Pi via the USB A->B cable.
	
		$ cd ~/arduino/blink/
		$ ino upload
		Guessing serial port ... /dev/ttpACM0
		
		avrdude: AVR device initialized and ready to accept instructions
		...
		
		avrdude done.   Thank you.
	
	Your Arduino UNO should now have a heartbeat. Is your LED blinking?
	
	#### NOTE: Arduino has a tiny amount of solid-state memory, meaning that even if you disconnect it, your uploaded `.hex` file will be saved and immediately run again (as if it were being run for the first time) when power is restored.
	
	#### NOTE: If you have trouble connecting, check that the USB ACM device is recognized by the system:
	
			$ dmesg | grep tty
			...
			...
			... ttyACM0: USB ACM device
	You should see a message with ttyACM0 or something like it.
	

### Assignments

Now you should see how we can modify your program to blink at different frequencies. You can edit the `sketch.ino` file using `nano`, save changes, then use `ino` to build and upload your **sketch**.

For each Assignment below, make a new directory sketch based on the **blink** template.

#### ~/arduino/strobe 
1. Experiment with different frequencies for blinking LED (try very long and very short durations). Find one that you like. Note that very short durations of the LED set `HIGH` will appear, to your eye, to be a very dim LED.

#### ~/arduino/pulse
1. Upload a **sketch** where the LED will appear to slowly and smoothly brighten over 5 seconds, then dim again over 5 seconds.

	#### Show your Arduino's pulse to your Instructor.
	
