# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Madeleine Gomel<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications


## Lab 9. Computer Vision with Raspberry Pi Camera

Oftentimes, to execute a particular plan it might be more efficient to make an analogy between your current task and what someone else has already achieved and posted online. If they posted their ideas and their code under a liberal, legal, free and open-source license, you might be able to both benefit from and become a potential benefactor of a source project or success story you find online.

Here, we will install and utilize `OpenCV`, an excellent image processing toolbox of efficient yet easy to access algorithms. Indeed, Matlab can interface with `OpenCV`. Wikipedia:

> OpenCV (Open Source Computer Vision) is a library of programming functions mainly aimed at real-time computer vision, developed by Intel Russia research center in Nizhny Novgorod, and now supported by Willow Garage and Itseez. It is free for use under the open source BSD license. The library is cross-platform. It focuses mainly on real-time image processing. If the library finds Intel's Integrated Performance Primitives on the system, it will use these proprietary optimized routines to accelerate itself.


The reason why `python` is such an excellent language to use is that you don't have to explicitly define the type of variable you want to use (remember `C++` and `Arduino` programming?). The program live-interprets what type of data you have, and does the appropriate lookups for you. However, video streams have so much data that computational overhead required to verify the data structure could cause your computer to crash. Because the data stream is larger and faster than the computational abilities of your Raspberry Pi, you need to explicitly describe how the data is structured to make sure that all processing algorithms read it correctly.

Video files can be a fairly regular format, but the Raspberry Pi Camera has a unique video format (remember how you connected it very close to the CPU so that the video could be read efficiently?). So we need to modify these files to work with your Pi Camera.

### Install `OpenCV`

1. Install the image processor `OpenCV` for `Camera.py`:

		$ sudo -s
		# apt-get update
		# apt-get install libopencv-dev
		# apt-get install python-opencv

1. The image classifier can tell the difference between arrays of pixels. Install Skykit for `classifier.py` and `find_shortest_path.py`:

		# apt-get install build-essential python-dev python-numpy python-setuptools python-scipy 
		# apt-get install python-matplotlib
		# apt-get install python-pip
		# exit
		
		

1. Now we are just about ready. Let's make the `computer_vision` directory for us to work in.

		$ cd ~
		$ mkdir -p computer_vision
		$ cd computer_vision
		
	Use `wget` to pull down the relevant attachments from github:
	
		https://raw.githubusercontent.com/jmil/Bioe421_521-MicrocontrollerApplications/master/Attachments/vids.zip
		
		https://raw.githubusercontent.com/jmil/Bioe421_521-MicrocontrollerApplications/master/Attachments/face-detect.zip
	
	Unzip these zip files:
	
		$ which unzip
		$ man unzip
		$ unzip vids.zip
		$ unzip face-detect.zip
			

## Analyze a Video

Let's take a look at a sample video we'd like to analyze. Recall `omxplayer` can help us here.

		$ cd vids
		$ which omxplayer
		$ omxplayer vid1.mov

There's motion, there's a person(!), there's a shoe, there are sunglasses. Think about the features of a human face that make it straightforward to you to recognize people. We will need to provide our computer with instructions of how to do the same thing.
		
Wikipedia:
http://en.wikipedia.org/wiki/Haar-like_features
> Haar-like features are digital image features used in object recognition. They owe their name to their intuitive similarity with Haar wavelets and were used in the first real-time face detector.

> Historically, working with only image intensities (i.e., the RGB pixel values at each and every pixel of image) made the task of feature calculation computationally expensive. A publication by Papageorgiou et al. discussed working with an alternate feature set based on Haar wavelets instead of the usual image intensities. Viola and Jones adapted the idea of using Haar wavelets and developed the so-called Haar-like features. A Haar-like feature considers adjacent rectangular regions at a specific location in a detection window, sums up the pixel intensities in each region and calculates the difference between these sums. This difference is then used to categorize subsections of an image. For example, let us say we have an image database with human faces. It is a common observation that among all faces the region of the eyes is darker than the region of the cheeks. Therefore a common haar feature for face detection is a set of two adjacent rectangles that lie above the eye and the cheek region. The position of these rectangles is defined relative to a detection window that acts like a bounding box to the target object (the face in this case).

`OpenCV` which you have just installed, comes with **haarcascades**, a set of statistical data taken of photos of many, many human faces. So, most human faces you see will be similar to these, and therefore can be computationally compared to the statistical data you already have pulled down. These data are located in, no surprise, the `data` folder.

1. Let's check out the readme:

		$ cd ../face-detect/
		$ cd data/
		$ cat readme.txt

1. Ok, we're almost ready to run the **haarcascade** on the video. Let's try to understand what it's going to do, first though.

		$ cd ../src
		$ nano analyze_video.py

1. Notice near the top you should set the name of the video you want to analyze:

		video_file_name = '../sample.mov'

1. Set this variable correctly:

		video_file_name = '../../vids/vid1.mov'

1. Look for this region later in the code:

		if __name__ == '__main__':
		
			...
	    	cascade_fn = args.get('--cascade', "../data/haarcascades/haarcascade_frontalface_alt.xml")
	    	nested_fn  = args.get('--nested-cascade', "../data/haarcascades/haarcascade_eye.xml")
	    
			cascade = cv2.CascadeClassifier(cascade_fn)
    		nested = cv2.CascadeClassifier(nested_fn)


	At the beginning of the run, the video file is loaded and you have two cascade identifiers that are loaded. `cascade_fn` refers to `frontalface` and will be scanning your image for a person's face. `nested_fn` is a nested cascade... only if a `frontalface` object is found will `nested_fn` look for eyes within that face.

	This section loads the video and figures out it's dimensions and notifies the user:

		cap = cv2.VideoCapture(video_file_name)
		width= cap.get(3)
		height = cap.get(4)
		print width

1. Later on, we have the processing loop, which runs while `cap` is being read, which is to say when a video file is being read. It turns the picture into a grayscale value, starts detecting the cascade, and makes a new cropped image to be displayed and highlighted for the user (`imshow`):

    	while(cap.isOpened()):
        	ret, frame = cap.read()
        	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        	gray = cv2.equalizeHist(gray)

        	t = clock()
        	rects = detect(gray, cascade)
        	vis = frame.copy()
        	draw_rects(vis, rects, (0, 255, 0))
        	for x1, y1, x2, y2 in rects:
            	roi = gray[y1:y2, x1:x2]
            	vis_roi = vis[y1:y2, x1:x2]
            	cv2.imshow('subregion', vis_roi)
            	subrects = detect(roi.copy(), nested)
            	draw_rects(vis_roi, subrects, (255, 0, 0))
        	dt = clock() - t
        
        	draw_str(vis, (20, 20), 'time: %.1f ms' % (dt*1000))
        	cv2.imshow('facedetect', vis)
        	captured_frame_number=captured_frame_number+1


1. Finally, note that the files will be output to the following location:

		cv2.imwrite("../data/saved_images/{0:d}.png".format(captured_frame_number),vis)

1. Save and exit this. Let's run it:

		$ python analyze_video.py

	You can use the `q` key to quit the program. What happens when you run this program? 
	
		:
		:
		:
		:
		:


1. Let's look at the recorded slideshow of the processed images that you made. Remember the `fbi` command?:

		$ cd ../data/saved_images
		$ ls -la
		$ man fbi
		$ sudo fbi -d /dev/fb0 -a -T 2 -t 3 *.png

	Use **`<shift-Q>`** to terminate.


1. Show your instructor the `fbi` slideshow of the facial recognition images of your newly recorded video.


## Analyze Another Video

1. Purge the contents of the `saved_images` folder (make sure you keep the folder itself!).

1. Examine the other video, `vid2.mov` in the `vids` folder, using `omxplayer`.

1. Analyze `vid2.mov` for facial recognition. Describe what in this video makes the challenge more difficult:

		:


1. Make an `fbi` slideshow of these new images and show your Instructor. Describe the commands and procedures you used to accomplish this task:


		:
		:
		:
		:
		:
		:
		:
		:
		:
		:
		:
		:
		:
		:
		:
		:




## Record and Analyze your Own Video

Now let's make your own video to analyze and find your faces.

1. Recall the `raspivid` command. We will take a video that's lower resolution than HD so it's faster to process by the Pi when searching for faces:

		$ cd ~/computer_vision/
		$ raspivid -o find_our_faces.h264 -w 640 -h 480

1. We need to wrap this raw `.h264` file into a more standard `.mp4` or `.avi` container so that `OpenCV` can process it:

		$ sudo apt-get install -y gpac
		$ which MP4Box
		$ MP4Box -fps 30 -add find_our_faces.h264 find_our_faces.mp4
		$ omxplayer find_our_faces.mp4


	If the `.mp4` doesn't work, you could try:

		$ sudo apt-get install ffmpeg
		$ which ffmpeg
		$ ffmpeg -i find_our_faces.h264 -vcodec mjpeg -qscale 1 -an find_our_faces.avi
	
1. Analyze your newly recorded video for faces.

1. Show your instructor an `fbi` slideshow of the facial recognition images of your newly recorded video. **HINT:** You will want to purge the previously saved facial recognition images so you have a clean slideshow.

## Learn More

The Raspberry Pi Camera docs are excellent, and have a huge range of sample code (called **recipes!**) for you to explore and potentially use for your final project.

1. Work through at least five of the example python recipes given:

http://picamera.readthedocs.io/en/release-1.12/recipes1.html




### Upload your work from today

1. Zip up the arduino folder for Today's lab to make a single .zip file

		$ cd ~
		$ zip -r Team09-Lab09.zip computer_vision

1. `scp` your team's homework .zip file to your Instructor's RaspberryPi. Your Instructor will provide you with the value to enter for **IP_ADDRESS**. Use your same `raspberry` password (note that you are logging in as user `student`):

		$ man scp
		$ scp Team09-Lab09.zip student@IP_ADDRESS:/home/student/



## Shutdown Procedure

1. Shutdown your Pi properly:

		$ sudo shutdown -h now

 Unplug everthing and restore the Windows desktop computer to a working state.



