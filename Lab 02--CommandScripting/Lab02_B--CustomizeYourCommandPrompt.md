#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: John Sexton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications


##Lab 2B. Customizing Your Command Prompt

### A Note about Your Shell History

From: http://www.raspberrypi.org/documentation/usage/
		
> HISTORY AND AUTO-COMPLETE
> Rather than type every command, the terminal allows you to scroll through previous commands that you've run by pressing the **\<up>** or **\<down>** keys on your keyboard. If you are writing the name of a file or directory as part of a command then pressing tab will attempt to auto-complete the name of what you are typing. For example, if you have a file in a directory called **_aLongFileName_** then pressing tab after typing **_a_** will allow you to choose from all file and directory names beginning with **_a_** in the current directory, allowing you to choose **_aLongFileName_**.		
		

### The Command Prompt

As we learned last time, when you login you are presented with the command prompt:

		pi@raspberrypi ~ $ _

Here we will see where the instructions for how to display the command prompt are located, and you will work to customize your prompt to be more informative.


Look at the contents of your **.bashrc** file located at /home/pi/.bashrc. This is the configuration file for your login. We can customize your command prompt by editing this file.

	$ cd ~
	$ pwd
	$ ls -la
	$ cat ~/.bashrc
	
The lines that start with a **"#"** are comments, made for humans to read and ignored by the computer. You can make comments for yourself in this file, or append the **"#"** to a line of code to "comment it out", or turn the code into a comment so it will be ignored by the computer, and therefore disabled.

Let's make a backup of this file, in case we make a mistake, hopefully we will be able to revert it.

	$ cp ~/.bashrc ~/.bashrc-BACKUP

Check that your backup file is there, and that it's contents are correct. What commands did you use?

	$
	$

Now we will edit the .bashrc file and change the command prompt.

	$ nano ~/.bashrc

Scroll down to put the cursor just **BETWEEN** these two lines:
	
	...
	esac

	# enable color support of ls and also add handy aliases
	...
	

Insert the following text from an awesome command prompt from:
http://mwholt.blogspot.com/2013/08/how-to-customize-your-terminal-prompt.html

#####HINT: You can use the wget command to grab this file from github, then insert it into your .bashrc file.

	...
	esac

	Decoration1="\[\e[90m\]╔["
	RegularUserPart="\[\e[36m\]\u"
	RootUserPart="\[\e[31;5m\]\u\[\e[m\]"
	Between="\[\e[90m\]@"
	HostPart="\[\e[32m\]\h:"
	PathPart="\[\e[93;1m\]\w"
	Decoration2="\[\e[90m\]]\n╚>\[\e[m\]"
	case `id -u` in
	    0) export PS1="$Decoration1$RootUserPart$Between$HostPart$PathPart$Decoration2# ";;
	    *) export PS1="$Decoration1$RegularUserPart$Between$HostPart$PathPart$Decoration2$ ";;
	esac


	# enable color support of ls and also add handy aliases
	...


 Here we see that variables can be created by starting a line with a variable name, then assigning a value to it with the **=** sign. We later can call the value of this variable by using the "$" sign before the variable name (which you see down where it says "export PS1=").
 
 To see the changes in your command prompt, you need to logout and then login again. This will cause the ~/.bashrc file to be read back in.
 
 What did you get?
 
 Next, edit the command prompt and customize it to show your team name. Look online for a color lookup table and for how to change the colors used in this prompt.
  
 Make backups of your edits in case you type something incorrectly along the way.
 
 Let's do something more complicated -- we want our command prompt to show the current time. So each time **$PS1** is called, we want the current time to be updated.
 
 Here we can use the backtick "`", which is located just under the **\<esc>** key on your keyboard.
 
 See if you can change your PS1 command to include the current time.
 
 Show your new command prompt to your Instructor!
 
 