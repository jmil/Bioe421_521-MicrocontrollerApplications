# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Madeleine Gomel<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

## Lab 3A. The Raspberry Pi Camera
###### Adapted from http://www.raspberrypi.org/documentation/usage/camera/README.md

### Hardware: Connecting your Raspberry Pi Camera

****
**NOTE: BEFORE giving any power to your Raspberry Pi computer:**
****
On the PC, watch the video and follow the instructions to plug in your Raspberry Pi Camera module. You only need to watch the video here to understand how the plug works:
http://www.raspberrypi.org/documentation/usage/camera/README.md

**NOTE:** you probably want to use the extra 24" ribbon cable in your hardware crate for the camera so you have an easier time manuevering the camera where you want. Disconnect the ribbon cable that came with the camera **CAREFULLY**.


From http://RaspberryPi.org/:
>**Warning**: Cameras are static sensitive. Earth yourself prior to handling the PCB. A sink tap or similar should suffice if you don’t have an earthing strap.

>The camera board attaches to the Raspberry Pi via a 15-way ribbon cable. There are only two connections to make: the ribbon cable needs to be attached to the camera PCB, and to the Raspberry Pi itself. You need to get the cable the right way round, or the camera will not work. On the camera PCB, the blue backing on the cable should face away from the PCB, and on the Raspberry Pi it should face towards the Ethernet connection (or where the Ethernet connector would be if you are using a model A).

>Although the connectors on the PCB and the Pi are different, they work in a similar way. On the Raspberry Pi itself, pull up the tabs on each end of the connector. It should slide up easily, and be able to pivot around slightly. Fully insert the ribbon cable into the slot, ensuring it is set straight, then gently press down the tabs to clip it into place. The camera PCB connector also requires you to pull the tabs away from the board, gently insert the cable, then push the tabs back. The PCB connector can be a little more awkward than the one on the Pi itself. 


### Software: Enable your Raspberry Pi Camera
1. Once your camera is plugged in, boot up your RaspberryPi and login.
1. Open the `raspi-config` tool from the Terminal:

		$ sudo raspi-config

	Select `Interfacing Options` -> `P1 Camera` and hit the **`<enter>`** key. Select `<Enable>`, then on the main `raspi-config` page select `<Finish>` and choose `<Yes>` to reboot.
	
	From http://RaspberryPi.org/:

	>The enable option will ensure that on reboot the correct GPU firmware will be running (with the camera driver and tuning), and the GPU memory split is sufficient to allow the camera to acquire enough memory to run correctly.

### Using the Camera

We will utilize the `raspistill` command. Unfortunately, as of this writing there is no `man` page for it.

	$ man raspistill
	No manual entry for raspistill
	...

You can learn more at:
http://www.raspberrypi.org/documentation/usage/camera/raspicam/raspistill.md

Instead of using `man`, you can also see a list of all commands by running `raspistill` with no options. It will scroll by fast, and you won't be able to **pipe** it to `more`:

	$ raspistill | more

What's going on? `raspistill` returns an error if you run it with no options, and by default `raspistill` is setup to print it's helpfile *as* the error message. Error messages are pretty necessary, as you might imagine. So this is actully known as **STDERR** (**st**an**d**ard **err**or). We need to redirect **STDERR** (called simply with the integer `2`) to **STDOUT** (called simply with the integer `1`) before we can **pipe** it to `more`:

	$ raspistill 2>&1 | more

Test if the camera is working by snapping a pic via command-line:

	$ cd ~
	$ mkdir raspicam
	$ cd raspicam
	$ raspistill -v -o smile.jpg

What do the `-v` and `-o` options do?

Was an image file generated? How many bytes is it?

	$ ls -la

It's fine to take an image, but how do we know if it was a good one? The `raspistill` command follows our stated convention of being a single-purpose utility -- it only takes pictures, it can't view or edit them. Kinda dissapointing in this case...

To view the picture you just took, you need a command line frame buffer image viewer. Enter the Linux **F**rame**B**uffer **I**mageviewer... let's install `fbi` on your Raspberry Pi:
>hat-tip to http://claychaplin.com/workshop-lecture-demo/raspberry-pi-image-viewer/
	
	$ sudo apt-get update
	$ sudo apt-get install fbi


Let's look at what the `fbi` can do for us:

	$ man fbi

You can display an image simply by passing your filename as input to `fbi`:

	$ fbi -a smile.jpg

Type  **`<h>`** to show keyboard commands (noting that **`<q>`** or **`<esc>`** will quit `fbi`). Test out some of these options.

If you happen to be remotely connected to your Raspberry Pi, like through SSH, you may need to enter which framebuffer you want to display the image on (with `-d`). Let's say you also want to autoscale the image (with `-a`), and suppress the textual display. You might enter something like:

	$ sudo fbi -noverbose -d /dev/fb0 -a -T 2 smile.jpg

Snap a few more pics. You can display a slideshow of all your `.jpg` files in this directory (simply entered as `*.jpg`) with a 5 sec delay between images with:

	$ fbi -a -t 5 *.jpg

If your image is upside down, consider utilizing the `-vf` and `-hf` options of `raspistill`. What do they do?

	$ raspistill -v -vf -hf -o smile2.jpg


#### Congratulations, you're now a professional geek photographer!

### Recording a Video

We will utilize the `raspivid` command. Unfortunately, there is no `man` page.

	$ man raspivid
	No manual entry for raspivid
	...

 You can learn more at:
http://www.raspberrypi.org/documentation/usage/camera/raspicam/raspivid.md

You can also see a list of all commands by running `raspivid` with no options. Best to **pipe** it to `more` so you can scroll the long list:

	$ raspivid 2>&1 | more

Make a test video by running:

	$ raspivid -o video.h264

Just like `raspistill` could only take a pic and couldn't view it, `raspivid` cannot playback the video we just took. Instead we use `omxplayer` which should already be installed.

	$ man omxplayer
	
Try to playback your video file with:

	$ omxplayer video.h264

If that doesn't work, try the more complete:

	$ omxplayer -o hdmi video.h264


#### Congratulations, you're now a professional geek videographer!

### Kiosk Assignment

Make your Raspberry Pi into a kiosk which cycles through a series of images you snap with the camera or pull down from the internet. Topics like XKCD, imgur, lolcats, and doge are fair game, as long as you use good taste. You will want to use the `-noverbose` and `-a` flags of `fbi`.

Call over your Instructor to show off your kiosk.
