# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Adam Farsheed<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

## Lab 1A. Getting Started with Raspberry Pi

###### We will use Raspberry Pi 3 - Model B - ARMv8 with 1G RAM: https://www.adafruit.com/products/3055 and the 2017-07-05 Installation of Raspbian "Jessie" Linux from: https://www.raspberrypi.org/downloads/raspbian/ with a SHA-256 checksum of: 455cb85fb54c73bad07bd3a44db67755912579cd84ecbd42e2ab49565206b65e

##### Raspberry Pi is a complete computer system under $40. It uses an ARM processor similar to what is found in many smartphones. It can run many operating systems (OSes) and is perfect for lightweight input/output tasks. Raspberry Pi's low cost and extremely low power usage make it a perfect choice for always-on internet-connected computing. It also has a rudimentary graphics card allowing us to run a full graphical user interface, which we will do later in the semester.

[Adafruit says](https://www.adafruit.com/products/3055):

> There are two giant upgrades in the Pi 3.  The first is a next generation Quad Core Broadcom BCM2837 64-bit ARMv8 processor, making the processor speed increase from 900 MHz on the Pi 2 to up to 1.2GHz on the Pi 3.

> The second giant upgrade (and this is the one we’re personally most excited about) is the addition of a BCM43143 WiFi chip BUILT-IN to your Raspberry Pi.  No more pesky WiFi adapters - this Pi is WiFi ready.  There’s also Bluetooth Low Energy (BLE) on board making the Pi an excellent IoT solution (BLE support is still in the works, software-wise)

> Lastly, there’s an upgraded switched power source that goes up to 2.5 Amps instead of just 2 Amps - allowing your Pi to power even more powerful devices over USB ports.


##### Hardware: We supply a complete Raspberry Pi, power cable, video cable, keyboard and mouse. We will utilize the computer displays already available at OEDK Computing Classroom and disconnect the desktop Windows PCs from those monitors to work with Raspberry Pi.

##### Raspberry Pi, like many microcontrollers, is sensitive to static. Avoid charging yourself up with static as it could damage your device (not usually a huge problem in Houston, but be careful). Let's get started.

1. Plug in the Keyboard to the Raspberry Pi. **We will not use the mouse** until later in the semester.

1. Plug in the HDMI cable to the Raspberry Pi, disconnect the DVI video cable from your computer display, and use the HDMI->DVI converter to plug the Raspberry Pi into the computer monitor.

1. **CAREFULLY** plug in the microSD card. Make sure you interface the metal contacts on the microSD card properly to the metal contacts on the Raspberry Pi. Press in all the way. **Be careful**, this microSD card ***is your hard drive***. So, be mindful not to bump or disconnect the microSD card, as this is literally disconnecting your hard drive.

1. Finally, plug in Raspberry Pi power supply to AC power, and use the micro USB cable to give power to your Pi. The screen should become live and your computer should now be booting up. You may now notice lines of text streaming by, such as:

		...
		[ ok ] Setting preliminary keymap...done.
		...


1. You booted into a desktop environment, but I asked you not to plug in the mouse. So how do we navigate? For the majority of labs this semester, we will only use the keyboard to operate the Pi. This is for two reasons: 1) it's still often faster to use the keyboard in a terminal for most things, and 2) when things go wrong in the graphical user interface (the **GUI**), you might often need a keyboard to diagnose or fix problems in the command line interface (the **CLI**). So, let's disable the desktop environment for now.

1. Launch an instance of the Terminal program by typing the keyboard combination `<control-alt-T>`. You will find yourself at the command prompt (typically represented by the `$` character) with the Pi awaiting your instructions (called "commands"). The cursor is represented by the `_` character and is where typing will begin.
	
		pi@raspberrypi ~ $ _


1. We need to set the keyboard-only environment (known as the command line interface, or **CLI**) to be the default setup for your Pi, for now. **BY CONVENTION** I will represent the command prompt as the `$` sign. **You should not type this character as part of the command to run.** We need to run `sudo raspi-config`, so type this text and then press `<return>`.

			$ sudo raspi-config
			
	You will now be in a blue screen comprised of the Raspberry Pi Software Configuration Tool (`raspi-config`). This is a keyboard-based navigational menu to adjust settings on the Pi (use the arrow keys and `<tab>` key to navigate, use `<enter>` or `<spacebar>` to select the highlighted option).


1. Select `Boot Options` then `B1 Console.` Then select `<Finish>` and then `<Yes>` to Reboot.

	You should have now successfully booted into the command line environment **without** a Desktop. Don't worry, you will get comfortable with this environment and will be a Linux pro by the end of the semester.
	
1. Once the boot has finished, you should see a login menu prompt awaiting your input:
		
		raspberrypi login: _

	Login with the default Raspian OS admin user:
		
		raspberrypi login: pi
		Password: raspberry   (NOTE: text will not show up as you type a password)
		
	Were you able to login? How do you know? Describe what you see:
	
		:
	
	
1. Now, we need to get back into `raspi-config` and setup a bunch more stuff. What is the command you run to launch the `raspi-config` tool? Write it down here:
	
		$


1. Raspberry Pi is designed in UK. Therefore, all defaults are for Britain (and you may notice some British spelling and grammar here and there). Here, we will reconfigure Raspberry Pi for Houston, TX with US Keyboard layout.

	1. First, launch the `raspi-config` utility. The default is a British Keyboard Layout. We need to change this to US Keyboard Layout so that everything will match our hardware.

	1. Select option `Internationalisation Options` then `Change Keyboard Layout`. Configure successive options as follows:

			Generic 104-key PC
			Other
			English (US)
			English (US) 			(NOTE: this option is all the way at the top)
			The default for the keyboard layout
			No compose key
			Select <YES> for Use Control+Alt+Backspace to terminate the X server
			
		You will be taken back to the main raspi-config menu.


	1. Select option `Internationalisation Options` then `Change Timezone`. configure successive options as follows:

			US
			Central
		
		You will be taken back to the main raspi-config menu.

				
	1. Select option `Internationalisation Options` then `Change Locale`. You will see a LONG list of Locales to be generated, with mostly empty brackets such as:
		
				[ ] All locales
				[ ] aa.DJ ISO-8859-1
				...
				
		 Use the arrow keys to navigate, and use the **`<spacebar>`** to enable individual locales. Here we need to do **two Steps together**:
		 
		1. The `en_US.UTF-8 UTF-8` option is empty. **`<SELECT>`** it using the **`<spacebar>`** so it will show an asterisk:

		 		[*] en_US.UTF-8 UTF-8
		 		
		1. The `en_GB.UTF-8 UTF-8` option contains an asterisk. **`<DESELECT>`** it using the **`<spacebar>`**:

		 		[ ] en_US.UTF-8 UTF-8

		1. Select **`Ok`**.
		1. On the next screen, select your new config `en_US.UTF-8` as the Default locale for the system environment.
	
		You will be taken back to the main raspi-config menu.

1. Select option `Interfacing Options` ---> `SSH`.
	1. Select **`Enable`** to enable the SSH server.
	1. When completed, Select **`Ok`**.

	You will be taken back to the main raspi-config menu.

1. Now we are ready to reboot.

	Select `<Finish>`
	Select `<Yes>` when asked if you would like to reboot now
	
	**Troubleshooting:** If reboot wasn't given as an option for you, you can reboot by issuing the following command:
	
		$ sudo reboot
		
1. Login. Do you remember your username and password?
		
1. The OS will welcome you, give a warranty disclaimer, and put you at a command prompt:

		pi@raspberrypi ~ $ _
		
1. Confirm your localization worked correctly by seeing if you can type an "@" symbol.

1. If you ever need to get back to the raspi-config menu, here's how to do it:

		$ sudo raspi-config

### Congrats! You are now ready to use your Raspberry Pi.
