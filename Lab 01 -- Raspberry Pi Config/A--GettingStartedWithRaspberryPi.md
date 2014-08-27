#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: John Sexton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 1A. Getting Started with Raspberry Pi

######We will use Raspberry Pi Model B+ 512MB RAM: http://www.adafruit.com/product/1914

#####Raspberry Pi is a complete computer system under $40. It uses a processor similar to what is found in early smartphones (Broadcom SoC with 700 MHz ARM1176JZF-S core). It can run many OSs and is perfect for lightweight input/output tasks. Raspberry Pi's low cost and extremely low power usage (600 mA, 3 W) make it a perfect choice for always-on internet-connected computing. It also has a rudimentary graphics card allowing us to run a full graphical user interface, which we will do later in the semester.

####Raspberry Pi, like many microcontrollers, are sensitive to static. Avoid charging yourself up with static as it could damage your device (not usually a huge problem in Houston, but be careful). Let's get started.

1. Plug in the Keyboard and Mouse to the Raspberry Pi

1. Plug in the HDMI cable to the Raspberry Pi, disconnect the DVI video cable from your computer display, and use the HDMI->DVI converter to plug the Raspberry Pi into the computer monitor.

1. **CAREFULLY** plug in the microSD card. Make sure you interface the metal contacts on the microSD card properly to the metal contacts on the Raspberry Pi. Press in to lock: the card holder on the Raspberry Pi has a nice press-to-lock and press-to-release click functionality (like many retractable ballpoint pens) to keep the microSD card locked in place. **Be careful**, this microSD card ***is your hard drive***.

1. Finally, plug in Raspberry Pi power supply to AC power, and use the micro USB cable to give power to your Pi. The screen should become live and your computer should now be booting up.

	#####After successfully booting, you will be greeted with a blue screen and the Raspberry Pi Software Configuration Tool (raspi-config). This is a keyboard-based navigation menu (arrow keys and \<tab> key to navigate, \<enter> to select).

1. The Operating System (OS) on Raspberry Pi assumes we have a 4 GB microSD card. Our card is 32 GB, so the first thing we need to do is expand the Raspberry Pi hard drive partition to fill up our whole card:
	1. Navigate to and select option 1 Expand Filesystem
	1. You should get a prompt telling you the file system will be expanded on next reboot
	1. Select \<OK>


1. Raspberry Pi is designed in UK. Therefore, all defaults are for Britain (and you may notice some British spelling and grammar here and there). Here, we will reconfigure Raspberry Pi to fit us here in Houston TX with US Keyboard layout.

	1.  The default is a British Keyboard Layout. We need to change this to US Keyboard Layout so that everything will match our hardware.

	1. Navigate to and select option 4 Internationalisation Options
	1. Select 13 Change Keyboard Layout, and select the following on successive menus:

			Generic 104-key PC
			Other
			English (US)
			English (US) 			(NOTE: this option is all the way at the top)
			The default for the keyboard layout
			No compose key
			Select <YES> for Use Control+Alt+Backspace to terminate the X server
			
		You will be taken back to the main raspi-config menu.


	1. Select option 4 Internationalisation Options ---> configure option 12 Change Timezone; select the following on successive menus:

			US
			Central
				
	1. Under Internationalisation Options, configure option 11 Change Locale

		You will see a LONG list of Locales to be generated, with mostly empty brackets such as:
		
				[ ] All locales
				[ ] aa.DJ ISO-8859-1
				...
				
		 Use the arrow keys to navigate, and use the \<spacebar> to enable individual locales. Here we need to do **two Steps together**:
		 
		1. \<SELECT> the en_US.UTF-8 UTF-8 option using the \<spacebar>

		 		[*] en_US.UTF-8 UTF-8
		 		
		1. \<DESELECT> the en_GB.UTF-8 UTF-8 option containing the asterisk using the \<spacebar>

		 		[ ] en_US.UTF-8 UTF-8

		1. Select \<Ok>
		1. On the next screen, select your new config en_US.UTF-8 as the Default locale for the system environment
		
		You will be taken back to the main raspi-config menu.


1. You will be taken back to the main raspi-config menu.

1. Select option 8 Advanced Options ---> A4 SSH.
	1. Select \<Enable> to enable the SSH server.
	1. When completed, Select \<Ok>

	You will be taken back to the main raspi-config menu.

1. Now we are ready to reboot.

		Select <Finish>
		Select <Yes> when asked if you would like to reboot now
		
1. You will now be booted into the command-line interface. You may now notice lines of text streaming by, such as:

		...
		[ ok ] Setting preliminary keymap...done.
		...

1. You will be taken to a login menu prompt:

		Raspbian GNU/Linux 7 raspberrypi tty1
		
		raspberrypi login: _

	login with the default Raspian OS admin user:
		
		raspberrypi login: pi
		Password: raspberry   (NOTE: text will not show up as you type a password)
		
1. The OS will welcome you, give a warranty disclaimer, and put you at a command prompt:

		pi@raspberrypi ~ $ _
		
1. Confirm your localization worked correctly by seeing if you can type an "@" symbol.

1. If you ever need to get back to the raspi-config menu, here's how to do it:

		pi@raspberrypi ~ $ sudo raspi-config

###Congrats! You are now ready to use your Raspberry Pi.