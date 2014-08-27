#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: John Sexton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 1C. Understanding the Shell



######Wikipedia: A shell manages the user–system interaction by prompting users for input, interpreting their input, and then handling an output from the underlying operating system.

#####The text-only command-line interface (CLI), commonly shortened to "command-line", is the simplest shell we will use in class. Command-line utilizes a keyboard as the human-computer interface: You get a blinking prompt where you can enter commands, you submit the commands by typing \<enter>. Often you will get text sent back to you by the shell, as the output of your command.

### How to get help


One of the most important aspects of the shell, especially for new users, is that it has built in help files. You access help files for a given command using the 'man' command. As an 'argument' to this command, you need to submit the name of the command whose manual pages you would like to lookup. Thankfully, the 'man' command has it's own helpfiles. Let's read them.

1. Boot up your Pi and login

1. Read the manual pages (often abbreviated as the 'man pages') for the man command:

		$ man man

	The screen will be cleared and you will be presented with the manual. Note that the manual continues off the screen. For getting help on using man pages, use the \<h> key ('h' for 'help'). To scroll down one line at a time, use the \<enter> key. To scroll down one entire page at a time, use the \<space bar>. To go to the previous page, press the \<b> key ('b' for 'back'). To exit out of the man pages, press the \<q> key ('q' for 'quit').
	
	
### TASK LIST


1. We will be reading more man pages and taking detailed notes. We will take notes using Markdown format since it can be read easily by humans and easily converted into HTML by computers for nice rendered viewing online.

	On the Windows computer next to your Raspberry Pi, have your lab partner use the free editor with live rendering at:
	http://dillinger.io
	You can link it to google drive, dropbox, and github. Or you can edit and download the file.
	###IMPORTANT NOTE: Anything you save to the desktop on the Windows computer will be deleted after you logout (Rice IT default setup for the Windows computers). So it's best to use online text editing to save your file. Email it to yourself for now so that you have a backup.


	As you read, write down some general and specific usage notes about each command using Markdown format (*.md). This will help you figure out which commands can help you complete assigned tasks:

		man

		whoami
		hostname
		passwd
		sudo
		su
		
		sh
		ssh
		clear
		
		pwd
		mkdir
		cd
		ls
		dir
		
		touch
		nano
		
		mv
		rm
		
		which
		
		cat
		grep
		more
		less
		head
		tail
		
		ifconfig
		hostname
		mount
		


1. 



