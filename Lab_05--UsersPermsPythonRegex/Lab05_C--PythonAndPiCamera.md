#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Jacob Albritton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 5C. Python and the Raspberry Pi Camera

We've previously used the Raspberry Pi Camera by calling the `raspistill` command to take pictures and `raspivid` command to take a video. We could add these into bash shell scripts for more automated handling. However, `python` on Raspberry Pi has some special constructs which allow more flexible use of the Raspberry Pi Camera. Let's take a look.

### Installation

We want to install the `python-picamera` command. Run `apt-get` as the superuser with `sudo`:

	$ sudo apt-get install python-picamera
	$ sudo apt-get install python-imaging     # this includes PIL

We are using v1.8-1 of python-picamera.

### External Tutorial

Follow the tutorials here:
http://picamera.readthedocs.org/en/release-1.8/recipes1.html

Create and run the following files:
capture-file.py
capture-stream.py
capture-resized.py
capture-consistent.py
capture-timelapse.py
capture-lowlight.py
record-video.py

Make sure you use the header for each of your files:

	#! /usr/bin/python
	# TEAM-INFO-HERE


Recall -- you may want to use `fbi` to look at the images you've saved.


### System Scheduling

Read the tutorial for `cron` on Raspberry Pi:

http://www.raspberrypi.org/documentation/linux/usage/cron.md

Schedule `capture-file.py` to snap every minute. Make sure you change the name of the saved file to have the timestamp, so that you don't overwrite your previously saved file. What is your crontab entry?

	$ crontab -l > mycrontab.txt


Why might you want to run a timelapse capture via a system `cron` job instead of just having a `sleep` directive in a single python file?


####Congratulations, you're now an über professional geek videographer!


1. Zip up the folder for Today's lab to make a single .zip file

		$ zip -r Team09-LambdaFTW_Lab05.zip Team09-LambdaFTW_Lab05

1. `scp` your team's homework .zip file to your Instructor's RaspberryPi. Your Instructor will provide you with the value to enter for **IP_ADDRESS**. Use your same `raspberry` password (note that you are logging in as user `student`):

		$ man scp
		$ scp Team09-LambdaFTW_Lab05.zip student@IP_ADDRESS:/home/student/



## Shutdown Procedure

1. Shutdown your Pi properly:

		$ sudo shutdown -h now

 Unplug everthing and restore the Windows desktop computer to a working state.
