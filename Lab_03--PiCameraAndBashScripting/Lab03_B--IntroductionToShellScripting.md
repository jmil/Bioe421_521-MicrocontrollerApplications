# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Madeleine Gomel<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

## Lab 3B. Introduction to Shell Scripting
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

Do you remember how to pull down this file using `wget`? You might want to use a URL shortener.

Grab the template file and run it. You will have to change permissions on the file in order to execute it:

	$ chmod +x bash-script.sh
	$ ./bash-script.sh

What happened when you ran the script?

	: 
	
### Your `$PATH` to Success

If you look at the sample `bash-script.sh` you will notice a lot is going on:

	$ cat bash-script.sh | more

Some variables are built-in to the **shell** already, such as `$USER` and `$PATH` (they don't have to be defined in your script). You can check with:

	$ echo $USER
	$ echo $PATH

Other variables can be set with simple assignment using the **`=`** character as you did when editing your prompt. You can also have variable variables, which are not set until the script is run. Recall: these are set with the backtick **``` ` ```** character to escape you to a temporary **shell** to run the command and set its **STDOUT** as input to the variable. This allows you to, for example, set a variable for the exact time the script was run and splice that output into your commands as plain text. Check the `bash-script.sh` carefully to find this section.

### More Input
Another useful part of the shell -- you can take user input as text to be used directly in your script. But how can you use user input **from the future** in a script you are writing right now? Instead of using variables with the `$` prefix on the command prompt, we can use them in our script.

User input options will be assigned to integer variables in numerical order. We will use `nano` to write a `bash` script that takes three user-input text strings at the command prompt and outputs them in reverse order. The syntax we want to achieve should be:

		$ ./user_input.sh value1 value2 value3
		OUTPUT:
		value3, value2, value1

Let's begin.

1. Generate the `scripts` folder to contain everything:

		$ cd ~
		$ mkdir scripts
		$ cd scripts

1. Create a new file `user_input.sh` and edit it with `nano`:

		$ nano user_input.sh
	
	Make the file contents to be the following:
	
		#! /bin/bash
		
		echo "$3, $2, $1"

1. Save and exit.

	Now try it out!

		$ chmod +x user-input.sh
		$ ./user-input.sh value1 value2 value3

	What was the script output?

		:

	How did that happen? The magic happens at this line of your script:
	
		echo "$3, $2, $1"

	The bash shell **automagically** creates variables for you when you run a script, and assigns the first word to `$1`, the second to `$2`, and the third to `$3`. It's ***as if*** your script actually read as:
		
		#! /bin/bash
		
		1="value1"
		2="value2"
		3="value3"
		echo "$3, $2, $1"
	
	But it happens dynamically, and takes the user input as the value to assign to the numbered variables.

## Assignment: Generate the following Scripts

Make sure you are working inside your `scripts` folder:

	$ cd ~/scripts

#### make_script.sh
Let's start by making a script that will help you make more scripts: you want it to create a new file based on an online template, write out the template into a new user-specified file, and `chmod +x` this new file so it will immediately be executable.

Given that the **next** assignment below will be to make a `weather.sh` script, it would be great if we could automatically pull down the Bioe421/521 script template, name it what we want, and make it executable. So for this `make_script.sh`, we want the user to be able to run:

	$ ./make_script.sh weather

And have it generate `weather.sh` ready to be edited and then immediately executed.


We will be making a bunch of scripts, so the workflow will be:

1. make a script
1. make a script, then get a file
1. make a script, then get a file, then make the script executable within itself
1. make a script, then get a file, then make the script executable within itself, then allow for user input



Let's get started. I put a script template you should use at:

		https://github.com/jmil/Bioe421_521-MicrocontrollerApplications/raw/master/Attachments/bash-script.sh

1. Write a one-line program to put the contents of the file at this URL into a new file named `make-script.sh`. Write the program (after you're sure it works!) here:

		$ 


1. Use `nano` to edit `make-script.sh` to, itself, grab the `bash-script.sh` template from github and output it to `STDOUT`. Of course, you will have to `chmod +x` this script to make it executable. Once you have done so, this is a good time to test your script. Modularization and testing on a line-by-line basis is the way to go. What happens when you run:

		$ ./make_script.sh
	Describe the output:
	
		:
 
1. Modify your script to take input from the user, and use this user input to set the filename of a new script file on your hard drive that will be generated from a live copy of the `bash-script.sh` file on github. What happens when you now run:

		$ ./make_script.sh weather

	Describe the result:

		:

1. Next, modify `make-script.sh` to also run the command `chmod +x` on your newly created `weather.sh` script file to make it executable right after it's created. Describe the result and how you checked it if the new `weather.sh` was executable:

		:

1. Finally, we don't want to have to delete all those extra lines each time we make a new script. So, edit the `make-script.sh` file to grab **ONLY** the 15 lines of the `bash_script.sh` file to use as a template. Describe your modifications:

		:


### weather.sh
1. Use `nano` to write a `bash` script that grabs the current local weather. 

Using the airport code location for Houston Hobby Airport you can run something like:

		$ weather KHOU
		Searching via airport...
		[caching result Houston Hobby Airport, TX, United States]
		Current conditions at Houston Hobby Airport, TX
		Last updated Aug 29, 2016 - 01:53 PM EDT / 2016.08.29 1753 UTC
		   Temperature: 77.0 F (25.0 C)
		   Relative Humidity: 87%
		   Wind: from the E (100 degrees) at 12 MPH (10 KT)
		   Weather: Lightning observed
		   Sky conditions: mostly cloudy
		   Precipitation last hour: A trace

	This may take some time. Be patient! Recall that you can use `grep` to parse this text a bit (remember that text given to `grep` is case-sensitive):
	
		$ weather KHOU | grep Temperature
		   Temperature: 77.0 F (25.0 C)
	
	
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
1. Use `nano` to write a `bash` script that uses the skicam to take a picture of the slopes. Name the image something creative (like a pun!). You will want to hardcode the location where images should be stored to be `/home/pi/raspicam/`.
	**HINT:** You likely want to use the `-p` flag of the `mkdir` command.
1. To have good camera functionality, you won't want to overwrite your previous images every time a photo is taken. Modify your `skipics.sh` script to append the current timestamp to your filename so they won't be overwritten.



### Homework Submission

1. move all of your scripts, pics, and weather info into a folder following the demonstrated naming convention for `Team09`. **Make sure there are no spaces in your team name identifier**. And, the trailing `/` characters here have specific meaning... don't forget them!

		$ cd ~
		$ mkdir Team09-Lab03
		$ mv raspicam Team09-Lab03/
		$ mv scripts Team09-Lab03/
		$ mv weather Team09-Lab03/
		
1. Zip up the folder to make a single .zip file

		$ sudo apt-get update
		$ sudo apt-get install zip
		$ zip -r Team09-Lab03.zip Team09-Lab03

1. `scp` your team's homework .zip file to your Instructor's RaspberryPi. Your Instructor will provide you with the value to enter for **IP_ADDRESS**. Use your same `raspberry` password (note that you are logging in as user `student`):

		$ man scp
		$ scp Team09-Lab03.zip student@IP_ADDRESS:/home/student/

## Shutdown Procedure

1. Shutdown your Pi properly:

		$ sudo shutdown -h now

 Unplug everthing and restore the Windows desktop computer to a working state.
