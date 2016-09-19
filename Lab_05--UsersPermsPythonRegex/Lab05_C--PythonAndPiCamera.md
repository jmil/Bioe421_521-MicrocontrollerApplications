#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Dan Sazer<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 5C. Python and the Raspberry Pi Camera

We've previously used the Raspberry Pi Camera by calling the `raspistill` command to take pictures and `raspivid` command to take a video. We could add these into bash shell scripts for more automated handling. However, `python` on Raspberry Pi has some special constructs which allow more flexible use of the Raspberry Pi Camera. Let's take a look.

### Installation

We want to install the `python-picamera` command. Run `apt-get` as the superuser with `sudo`:

	$ sudo apt-get update
	$ sudo apt-get dist-upgrade
	$ sudo apt-get install python-picamera
	$ sudo apt-get install python-imaging     # this includes PIL
	$ sudo apt-get install python-setuptools     

We are using v1.10 of python-picamera. Let's check to make sure, with code from here:
https://picamera.readthedocs.org/en/release-1.10/faq.html#how-can-i-tell-what-version-of-picamera-i-have-installed

We will do this in the interactive CLI `python` interface, which has three angle brackets `>>>` as the python command prompt, so type what you see below after the `>>>`. Note it has familiar and very similar behavior to the `bash` shell's **STDIN** and **STDOUT**.

	$ python --version
	Python 2.7.3
	$ python
	Python 2.7.3 .....
	...
	>>> from pkg_resources import require
	>>> require('picamera')
	[picamera 1.10 (/usr/lib/lib/python2.7/dist-packages)]
	>>> require('picamera')[0].version
	'1.10'

To exit the CLI python interface, you will need to use `exit()` or `<CTRL-D>` as shown by the following error message. Either of these will take you back to your `bash` shell:

	>>> exit
	Use exit() or Ctrl-D (i.e. EOF) to exit
	>>> exit()
	$


### External Tutorial

We will be using a selection of the tutorials here:
http://picamera.readthedocs.io/en/release-1.12/recipes1.html

Create and run the following files based on the sample code provided on the webpage:
`capture-file.py`
`capture-PIL.py`
`capture-resized.py`
`capture-consistent.py`
`capture-timelapse.py`
`capture-lowlight.py`
`record-video-file.py`
`overlay-image.py`
`overlay-text.py`
`control-LED.py`


Feel free to add your own modifications and demonstrate to your Instructor! Make sure you use the correct **shebang** and commented header for each of your files:

	#! /usr/bin/python
	# Team09-LambdaFTW
	# TEAM MEMBER NAMES


Check your work before you submit! Recall -- you may want to use `fbi` and `omxplayer` to look at the images and videos you've saved.


### System Scheduling

Read the tutorial for `cron` on Raspberry Pi:

http://www.raspberrypi.org/documentation/linux/usage/cron.md

Schedule `capture-file.py` to snap every minute. Make sure you change the name of the saved file to have the timestamp, so that you don't overwrite your previously saved file. What is your crontab entry?

	$ crontab -l > mycrontab.txt


Why might you want to run a timelapse capture via a system `cron` job instead of just having a `sleep` directive in a single python file?

	:
	:
	:
	:
	:

####Congratulations, you're now an über professional geek videographer!

### Optional/Bonus: Try some more of the Tutorials

We will be using a selection of the tutorials here:
http://picamera.readthedocs.org/en/release-1.10/recipes1.html

Create and run the following files based on the sample code provided on that webpage:
`capture-stream.py`
`capture-openCV-object.py`
`record-circular-stream.py`


## Turn in Homework

1. Zip up the folder for Today's lab to make a single .zip file

		$ zip -r Team09-LambdaFTW_Lab05.zip Team09-LambdaFTW_Lab05

1. `scp` your team's homework .zip file to your Instructor's RaspberryPi. Your Instructor will provide you with the value to enter for **IP_ADDRESS**. Use your same `raspberry` password (note that you are logging in as user `student`):

		$ scp Team09-LambdaFTW_Lab05.zip student@IP_ADDRESS:/home/student/



## Shutdown Procedure

1. Shutdown your Pi properly:

		$ sudo shutdown -h now

 Unplug everthing and restore the Windows desktop computer to a working state.
