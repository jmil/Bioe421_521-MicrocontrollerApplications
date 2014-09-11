#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: John Sexton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 3B. Introduction to Shell Scripting
So far, we've learned about the command-line terminal (a.k.a. the **shell**), and how to run basic commands like `cp` and `pwd` (you remember what those stand for, right? How could you look them up?). We've also covered using the **pipe** character (**`|`**) to make more complicated logical programs by passing **STDOUT** from one command as **STDIN** to the next one. However, what's the point of having a computer if we have to manually type each program each time we want to run it?

It would be **MUCH** better if we had a way to save our most cleverly devised commands and single-line programs. Even better, we'd like to be able to save programs in a way that makes it easy to re-use our programs later and run them without much hassle.

If you think about it carefully, we already have a solution. As we learned in lecture, each character of each command you type at the command prompt may appear to be English to you, but the computer understands things at the most fundamental, binary level (remember learning about the **ASCII** text format?). And... you already know how to create and save text files using the `nano` command.

So, all we need to do is create a text file in `nano` with a list of your commands, and then have your **shell** call that list of commands, in order. You want to start a **dialogue** between the computer and your text file. Thus, this type of file is conventionally known as a **script**. A carriage-return at the command-prompt is akin to a newline in a text file. So if we have one command per line, then each command will be executed in order from top to bottom of our **script**.

As we learned in class, the best command-line programs are *narrow* in task or goal, allowing for easy testing and debugging, as well as maximal modularity and re-use.

So today we will learn how to write a **script** to store our programs.

But first we need to say a bit about syntax.

### The Bang! The Bash! The Whole Shebang!

You already saw hints of shell scripting in the previous Lab, where we had to edit the `.bashrc` file. There were lots of commands in there! Let's take a look again:

	$ cat ~/.bashrc | more

So, our **script** will be a flat list of commands written in plain **ASCII** text. But how will the computer know what text files on our computer are just text and which are commands? It would take a long time to run the `web2` file as a **script**! We need to make it easy for the computer to notice that our file is a **script** and not strictly a text file. We want our **script** to be *interpreted as a program*. 

To do this, we use what's called the **shebang** at the very beginning of our text file:
http://en.wikipedia.org/wiki/Shebang_(Unix)
>In computing, a shebang is the character sequence consisting of the characters number sign and exclamation mark (that is, **`#!`**) at the beginning of a script.

>Under Unix-like operating systems, when a script with a shebang is run as a program, the program loader parses the rest of the script's initial line as an interpreter directive; the specified interpreter program is run instead, passing to it as an argument the path that was initially used when attempting to run the script.

So... you start a text file (usually given the file extension `.sh` to denote a **sh**ell script) with the following line:
		
		#! /bin/bash
The **`#`** sign denotes the line is a comment, **BUT** the **"bang"** (**`!`**) indicates to the shell interpreter that the file should be processed as a series of commands, in this case interpreted by the `bash` shell. Together, the **`#!`** is called the **shebang**.

Read this carefully, it can be confusing. An advantage of putting the whole **shebang** at the beginning of your file is that it communicates to other people, as well as to computers, exactly the syntax that will be followed in your script. There is more than one type of **shell**, so we need to know which one to use to run our **script**.

Let's learn by example. A `bash` script you should use as a template is available here:
https://github.com/jmil/Bioe421_521-MicrocontrollerApplications/raw/master/Attachments/bash-script.sh

Do you remember how to pull down this file using `wget`?

Grab the template file and run it. You will have to change permissions on the file in order to execute it:

	$ chmod +x bash-script.sh
	$ ./bash-script.sh

What happened when you ran the script?

### Your \$PATH to Success

If you look at the sample `bash-script.sh` you will notice a lot is going on:

	$ cat bash-script.sh | more

Some variables are built-in to the **shell** already, such as `$USER` and `$PATH` (they don't have to be defined in your script). You can check with:

	$ echo $USER
	$ echo $PATH

Other variables can be set with simple assignment using the **`=`** character as you did when editing your prompt. You can also have variable variables, which are not set until the script is run. Recall: these are set with the backtick **``` ` ```** character to escape you to a temporary **shell** to run the command and set its **STDOUT** as input to the variable. This allows you to, for example, set a variable for the exact time the script was run and splice that output into your commands as plain text. Check the `bash-script.sh` carefully to find this section.

### More Input
Another useful part of the shell -- you can take user input as text to be used in your script. User input options will be assigned to integer variables in numerical order. So if you ran the script:

	$ ./user-input.sh value1 value2

Then the text could be accessed within your script by calling `$1` and `$2` to access "value1" and "value2", respectively.



## Assignment: Generate the following Scripts

### Generate the `scripts` folder to contain everything

	$ cd ~
	$ mkdir scripts
	$ cd scripts


#### get_script.sh
1. Use `nano` to write a `bash` script to grab the `bash-script.sh` template file located at:

		https://github.com/jmil/Bioe421_521-MicrocontrollerApplications/raw/master/Attachments/bash-script.sh
		
	**NOTE:** You probably only need the first 15 lines of this file to use as a template.
	
1. Modify your script to take input from the user, and use this user input to set the filename of a new script file on your hard drive.
1. Modify your script to run the command `chmod +x` on your new script file to make it executable right after it's created. This will save you some gotchas later.

#### user_input.sh
1. Use `nano` to write a `bash` script that takes three user-input text strings at the command prompt and outputs them in reverse order. The syntax should be:

		$ ./user_input.sh value1 value2 value3
		OUTPUT:
		value3, value2, value1


### weather.sh
1. Use `nano` to write a `bash` script that grabs the current local weather. You will need to install the `weather-util` command:

		$ sudo apt-get install weather-util

	Using the `KHOU` location you can run something like:

		$ weather -i KHOU
	This will take some time. Be patient!
1. Modify your script to have the weather data saved to a file named with the current time and located at `/home/pi/weather/`.
	**Hints:** You will want to use the `date` command and look at it's formatting options:
		
		$ man date
	You likely also want to use the `-p` flag of the `mkdir` command.

1. You might get a warning when running `weather -i`. Modify your script to suppress this **STDERR** by sending it to **STDOUT** and then using a piped `tail` to show output starting at the 4th line. You will want to check the man page for `tail` to see how to show output relative to the beginning of the input.


### robots.sh
1. Use `nano` to write a `bash` script that grabs the `http://www.google.com/robots.txt` file and sends the output to **STDOUT**.
1. Modify your script to take input from the user, and use this user input to constrain the output (**hint:** think about constraining which line numbers are output).

### word.sh
1. Use `nano` to write a `bash` script to `grep` the `web2` dictionary for the string `wow`.
2. Modify your script to take input from the user, and use this user input as the pattern used by the `grep` command to find a match.

### selfie.sh
1. Use `nano` to write a `bash` script that uses the RaspberryPi Camera to take a selfie of you and your teammate. Name the image after your team name. You will want to hardcode the location where images should be stored to be `/home/pi/raspicam/`.
	**HINT:** You likely want to use the `-p` flag of the `mkdir` command.
1. To have good camera functionality, you won't want to overwrite your previous images every time a photo is taken. Modify your `selfie.sh` script to append the current timestamp to your filename so they won't be overwritten.



### Homework Submission

1. move all of your scripts, pics, and weather info into a folder following the demonstrated naming convention. Note the trailing `/` characters here have specific meaning... don't forget them!

		$ cd ~
		$ mkdir team01-LightBender_Lab03
		$ mv raspicam team-01-LightBender_Lab03/
		$ mv scripts team01-LightBender_Lab03/
		$ mv weather team01-LightBender_Lab03/
		
1. Zip up the folder to make a single .zip file

		$ sudo apt-get update
		$ sudo apt-get install zip
		$ zip -r team01-LightBender_Lab03.zip team01-LightBender_Lab03

1. `scp` your team's homework .zip file to your Instructor's RaspberryPi. Your Instructor will provide you with the value to enter for **IP_ADDRESS**. Use your same `raspberry` password (note that you are logging in as user `student`):

		$ man scp
		$ scp team01-LightBender_Lab03.zip student@IP_ADDRESS:/home/student/

##Cleanup
###After you shut down your RaspberryPi for the day, be sure you securely reconnect your computer monitor to the PC at your station.