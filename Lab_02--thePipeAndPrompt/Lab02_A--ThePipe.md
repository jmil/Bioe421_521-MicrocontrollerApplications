# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Madeleine Gomel<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

## Lab 2A. Redirecting Streams of Data

The command prompt serves as a source of standard input **(STDIN)**, and your computer monitor serves as the stream for standard output **(STDOUT)**. It's a data stream because the output happens a chunk at a time (another flowing river analogy) instead of all at once. This makes redirecting data streams very efficient -- you don't need to read a whole file into memory, you just start streaming the file from the beginning and you can process things as you go. Let's take a look.

### Data Streams

	$ echo 'Hello World!'
	
What was the output to your screen?


We can send the streamed output directly to a new file, instead of to the computer screen, using the **`>`** operator. Think of this bracket as an arrow pointing the stream on the left to a new file where you want **STDOUT** to go.

	$ echo 'Hello World!' > hi.txt
	$ cat hi.txt

Check out the `man` page for the `wc` command. Please add this command to your team's `man` page descriptions.

	$ man wc

Let's check how many bytes are in the `hi.txt` file.

	$ wc -c hi.txt
	
Can you count the bytes based on our discussion in class? How many bytes do you count in this file:

	:


The **`>`** directive functions by writing an entire file, so it will overwrite whatever file is already there (you can use the `ls` command to see what files are there in your current working directory).

Another useful **STDOUT** redirector is the **`>>`** operator. If a file doesn't exist yet, it will be created. If the file already exists, it will **append** your output to that file.

	$ echo 'Hi!' > hi2.txt
	$ echo 'Hi!' >> hi2.txt
	$ echo 'Hi!' >> hi2.txt
	$ cat hi2.txt
	$ wc -c hi2.txt

How many bytes did you get in this `hi2.txt` file? Explain:

	:
	
Let's do another example:	

	$ echo 'The stream editor works' >> stream.txt
	$ echo 'by allowing you to process' >> stream.txt
	$ echo 'and redirect STDIN and STDOUT streams' >> stream.txt
	$ cat stream.txt


### Looking at Long Streams


Grab the `dict.zip` dictionary file. NOTE: you may want to use a URL shortener on a different computer to avoid having to type out the entire URL:

	$ cd ~
	$ mkdir Lab02
	$ cd Lab02
	$ wget https://github.com/jmil/Bioe421_521-MicrocontrollerApplications/raw/master/Attachments/dict.zip
	$ unzip dict.zip
	$ cd dict
	$ ls
	$ cat README
	
This package was written for FreeBSD in 1993. The `web2` file is an ASCII text file containing 234,936 words from Webster's Second International dictionary.

Pay careful attention to the note in the `README` file:
	
	The wordlist makes a dandy 'grep' victim.
	
What wordlist are they talking about? Let's see what's there:

	$ ls -la

You will see a formatted list of everything in this directory. The `.` and `..` entries refer to the current directory, and the parent directory, respectively. You can use this fact to navigate up one directory:
	
	$ pwd
	$ cd ..
	$ pwd
	$ cd dict
	$ pwd	
	$ ls -la

Next to the filenames in the directory, you will also see the last date the file was modified, and a column of integers showing how many bytes are in each file. The `web2` file shows 2493109 bytes! That is ~2.5 MB.

Let's look at the contents of the `web2` file.
	
	$ cat web2
	
You will see all 234,936 words scroll by (it will take a while!). Type **`<ctrl-C>`** to halt and get back to the command prompt.

You can view a file a small portion at a time, making it especially easy to check the first few lines or last few lines of a file without having to read everything into memory or dump it to the monitor:

	$ head web2
	$ tail web2

What was your output?

	:

It would also be nice to look in detail at this file, similar to the functionality we saw when using `man` pages. We might want to be able to inspect the file live, one screen at a time.

	$ more web2
	
You can use the **`<spacebar>`** to go down one screen at a time, and the **`<b>`** key to go 'back' a page at a time. The **`<q>`** key will 'quit' you back to the command prompt.


### Using the Pipe

The `web2` file is being read out on the standard output stream, which is going to stream everything to your monitor. Streaming the data to render as text on your monitor is slow, so it will take a while.

It would be helpful if we could process this datastream **as it's going by**. This is exactly what the **pipe** (**`|`**) is for. The pipe is located immediately under the **`<backspace>`** key on your keyboard, and you have to hold down the **`<shift>`** key to type it.

Think of the **pipe** as a very simple way of connecting two commands together, and sending a datastream through this connection. Mario would be proud of you.

We can **pipe** the output of the `cat` command to the `more` command, like so:

	$ cat web2 | more
	
This is a simple variation on when we used the more command directly, above. Remember the mantra "there's more than one way to do it". There are many ways to achieve the same task.

#### Grep
Let's add `grep` into the mix. Recall what `grep` is for:

	$ man grep
	
We can use `grep` to take the output from `cat` as its input stream. It will then output via **STDOUT** to your screen.

Show all the words in the `web2` file that have the text string "dog" in them:

	$ cat web2 | grep dog
	
That went by really fast. Take this **STDOUT** and pass it as **STDIN** to the `more` command:

	$ cat web2 | grep dog | more
	
Now `more` is the last command in the chain. So it's output gets sent to **STDOUT** which is still, of course, the computer screen.

Let's output this shortened list to a new file:

	$ cat web2 | grep dog > some_dog_words.txt
	
Check your work:

	$ cat some_dog_words.txt | more
	
It would be better if we had some line numbers auto-incrementing with each line, so that we have an easier way to count this list.

	$ cat web2 | grep dog | cat -n

Let's write that to the file:

	$ cat web2 | grep dog | cat -n > some_dog_words.txt
	$ cat some_dog_words.txt

What's the last line of this file?

	$ cat some_dog_words.txt | tail -1
	
So, now it should make sense how **on a single line** we can search through a giant text file and rapidly output the answer to our question: how many words in the dictionary contain the text string **dog**. There's more than one way to do it... if you just want a number output, you can use the `wc` command in your pipe. Write out your single line command here:

	$ 
	
And what is the output of this command:

	:


You can also grab files from the internet and process them via pipe without having to save any data files on your hard drive. This is great for large files you want to process on a small hard drive. Just edit the stream, you don't need to go through the hassle of saving it all to hard drive, then opening the file again for processing.
**NOTE:** we use the capital letter **`O`** below as a flag. Remember you can check the `wget` `man` page if you aren't sure what each flag does.


	$ wget -qO- http://www.google.com/robots.txt


#### Crossing the Streams

Often it's helpful to have a way to save some of these data streams along the way. The `tee` command helps us do that. Think of the `tee` command functioning like, well, the letter **T**... one input stream, but **TWO** output streams (one of which can be written directly to a file without interrupting the other output).

	$ man tee

 
#### Assignments

1. Add the `tee` command to your team command-line manual.

1. Write a single-line program to output a line of text which tells you the line number where **`palm`** is Disallowed in Google's `robots.txt` file:

		$
		
	What was the output?
		
		:
	

1. Making use of `ifconfig`, write a single-line program to output a line of text containing your "inet addr" (this is your **i**nter**net** **addr**ess, or IP (**I**nternet **P**rotocol) address). **Hint:** use quotes to pass a longer search string to the `grep` command.
	
		$

	What was the output?
		
		:
	



1. Insert the `tee` command into some of your single-line commands. How can you check if your file was created? What were its contents?

		$

