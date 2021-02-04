# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Adam Farsheed<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

## Lab 3A. The Ski Resort Camera

Usually you would be using a physical camera attached to a Raspberry Pi board, but in this assignment I found a fun workaround to learn the same concepts. The Kelly Canyon Ski Resort provides a website that when visited, take a picture at a location on the mountain. 

Before we start downloading these pictures lets create a directory to store the images in:

	$ cd ~
	$ mkdir skicam
	$ cd skicam

What command can you use to save an image from the website: https://www.skikelly.com/sf/liveview/?rand=1234556789 and save it as a file called ski.jpeg?

    $ 

Was an image file generated? How many bytes is it?

	$ ls -la

It's fine to take an image, but how do we know if it was a good one?

To view the picture you just took, you need a command line frame buffer image viewer. Enter the Linux **F**rame**B**uffer **I**mageviewer... let's install `fbi` on your Raspberry Pi:
>hat-tip to http://claychaplin.com/workshop-lecture-demo/raspberry-pi-image-viewer/
	
	$ sudo apt-get update
	$ sudo apt-get install fbi


Let's look at what the `fbi` can do for us:

	$ man fbi

You can display an image simply by passing your filename as input to `fbi`:

	$ fbi -a ski.jpg

Type  **`<h>`** to show keyboard commands (noting that **`<q>`** or **`<esc>`** will quit `fbi`). Test out some of these options.

Snap a few more pics. You can display a slideshow of all your `.jpg` files in this directory (simply entered as `*.jpg`) with a 5 sec delay between images with:

	$ fbi -a -t 5 *.jpg

#### Congratulations, you're now a professional geek photographer!

### Kiosk Assignment

Make your Raspberry Pi into a kiosk which cycles through a series of images you snap with the camera or pull down from the internet. Topics like XKCD, imgur, lolcats, and doge are fair game, as long as you use good taste. You will want to use the `-noverbose` and `-a` flags of `fbi`.

Call over your Instructor to show off your kiosk.
