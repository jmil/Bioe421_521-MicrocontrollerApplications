#! /bin/bash

# Bioe 421/521 Microcontroller Applications
# http://github.com/jmil/Bioe421_521-MicrocontrollerApplications

# Awesome help on bash shell scripting here:
# http://tldp.org/LDP/Bash-Beginners-Guide/html/

########### Purpose ############
# You should write a description here about what this script can do
# and why you wrote it. Make sure to use "#" to set each comment line as a comment!

################################
##### Your Code Goes Below #####
################################


# Adapted from: http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_02_02.html
# This script clears the terminal, displays a greeting and gives information
# about currently connected users.  The two example variables are set and displayed.

clear				# clear terminal window
echo "Hello World!"
echo "You can edit this file to write a bash script."

echo "I will now fetch you a list of connected users:"
echo							
w				# show who is logged on and
echo				# what they are doing

echo "I'm setting two variables now."
COLOUR="purple"					# set a local shell variable
VALUE="96"					# set a local shell variable
echo "This is a string: $COLOUR"		# display content of variable 
echo "And this is a number: $VALUE"		# display content of variable
echo


echo "Let's figure out who you are:"
echo "Oh, hi, $USER!"		# dollar sign is used to get content of variable
echo

echo "We can also do this by nesting commands with the backtick:"
myName=`whoami`
echo "I've just run 'whoami' to determine that you are the user '$myName'"
echo

echo "Let's figure out what date and time it is:"
DATE=`date +"%Y-%m-%d @ %I:%M%p"`
echo "Oh, it's currently $DATE"
echo

echo "This script was run from the `pwd` directory."
echo
cd /usr/bin
echo "Now I'm in the `pwd` directory."
echo

cd ~
echo "And now I'm in the `pwd` directory."
echo "Let's see what's in here:"
ls -l
echo
echo

echo "Ok, I'm giving you back your prompt now."
echo
