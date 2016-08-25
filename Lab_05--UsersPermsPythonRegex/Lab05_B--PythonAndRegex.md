#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Dan Sazer<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 5B. `Python` and Regex

Previously in Lab we have done text-based search using the `grep`, `sed`, and `awk` commands. Often text searching can be done with much more complicated logic. We briefly looked at expanding the complexity of text searching that looked at the principles behind regular expressions (often abbreviated `regex` or `regexp`; plurals: `regexes` or `regexps`). We looked at the wonderful handout/explanation behind regular expressions from:
http://www.regular-expressions.info

Here we will take a closer look at regular expressions using a different abstraction layer than basic shell scripting. We will use the `python` language. Just as `bash` has a set of vocabulary and syntax that is required to run commands correctly, so too does the `python` language have its own conventions which must be followed carefully.

`python` has rapidly grown in interest among programmers because of its flexible handling of variables and types, ease of extensibility, ease of modularity and efficiency of program runs. Wikipedia:

> Python is a widely used general-purpose, high-level programming language. Its design philosophy emphasizes code readability, and its syntax allows programmers to express concepts in fewer lines of code than would be possible in languages such as C. The language provides constructs intended to enable clear programs on both a small and large scale.

It's a great language you will want to become familiar with this semester.


###External Tutorial on Python Regex

As the `pi` user back on your team's Raspberry Pi, create a new folder to store python code you generate today:

	$ cd ~
	$ mkdir Team09-LambdaFTW_Lab05
	$ cd Team09-LambdaFTW_Lab05

Let's make a new `python` file that can be processed by the `python` program. This is a very similar process to how we made **shell scripts (\*.sh)** to be processed by the `bash` shell. `Python` scripts should be given the **.py** suffix.


####Assignment
Go to the following webpage (or use the handout):
http://flockhart.virtualave.net/RBIF0100/regexp.html

For each row in the table, generate a new `python` script which follows the example. Let's do the first one together. First we need to find out where `python` is on our hard drive, then make a new `python` file:
	
	$ which python
	/usr/bin/python
	$ nano python-dot.py

I've named the file based on the "Metacharacter(s)" column so we can keep track easily. The basic contents of a python file which can execute regular expression pattern matching is:

	#! /usr/bin/python
	
	import re
	
	string1 = "Hello, world."
	if re.search(r".....", string1):
    	print string1 + " has length >= 5"

Save the file. NOTE: In Python the indentation is **critical** to get correct to emphasize the structure of `for` and `if` statements. If you have incorrect code indentation then you will likely get syntax errors or have the code do things you did not expect.

Why did you need to use the output from `which python` in order to write your python script?

	:

There are a couple ways to run the python script and test if it worked.

You can either pass the file name to `python` as an argument:

	$ python python-dot.py

Or you can use `chmod` to make the file executable, then launch it directly:

	$ ls -la
	$ ./python-dot.py
	$ chmod +x python-dot.py
	$ ./python-dot.py

What result did you get?

	:


Note that this simple example shows you the syntax for printing text to **STDOUT** and for text string concatenation between hard-coded and variable text (using the `+` operand). Note that `python` is also more forgiving of some whitespace here and there, such as between a variable name and the string contents it should be set to contain.

Next, modify your file to take text from user input on the command-line. In `bash` **shell scripting** we did this by calling the **`$1`** variable. `python` has a more structured way to do this, using the `arg` and `sys.argv` variables which will pull out an array of the command-line arguments passed in one at a time in the for loop:

	#! /usr/bin/python
	
	import sys
	import re
	
	for arg in sys.argv:
		print arg
		string1 = arg
		if re.search(r".....", string1):
    		print string1 + " has length >= 5"	

Try running the command again:

	$ python ./python-dot.py 'Hello world!!'

What was your output? Was it different than you expected? How so?

	:


Using this basic structure for `python` regex searching taking text from command-line as the argument, follow the rest of the tutorial by creating a new file for each row in the tutorial.

Figure out a way to suppress the very first `arg` so that the script-name itself is not taken as an input. Explain:

	:

