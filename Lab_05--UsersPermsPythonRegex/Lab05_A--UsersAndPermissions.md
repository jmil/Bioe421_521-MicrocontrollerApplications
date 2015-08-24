#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Jacob Albritton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 5A. Users and Permissions

As we learned in class, programs are files on the computer that get read and loaded into memory by launching them as "processes". Processes are single instance self-encapsulated copies of the program loaded in memory (one program can have multiple instances running). And there are tons of processes running on your computer all the time. The computer uses two major conventions to decide which processes to run, and when. The first is order of operations, where programs are run as soon as they can be after they are launched. The second is based on a hierarchy of users and permissions on your system.


###Change your Password!

Right now, you and the entire Internets have your username and password, because they are still the default set for the Pi:

	username: pi
	password: raspberry

The first thing we need to do is to change your password. We do this using the `passwd` command. Let's see what this command can do:

	$ man passwd

Carefully choose a new password with your partner. If you forget this password, your Instructor may not be able to help you get access to your system again. Let's now set your password. You will be asked to enter your current password, and then enter the new password twice (for confirmation). You typed password characters will not show up on the display (this is a security feature):

	$ passwd
	Changing password for pi.
	(current) UNIX password: 
	Enter new UNIX password: 
	Retype new UNIX password:
	passwd: password updated successfully
	
Phew! Now hopefully only you and your partner will have your password.

Let's see more about user groups, using the `id` command:

	$ man id
	$ id
	uid=1000(pi) gid=1000(pi) groups=1000(pi),4(adm),20(dialout),24(cdrom),27(sudo),29(audio),44(video),46(plugdev),60(games),100(users),105(netdev),999(input),1002(spi),1003(gpio)

Wow, that's a lot of stuff! We can understand more about this output. your `uid` is the unique integer for your userID (with your human-readable username shown in parentheses), and your `gid` is the default groupID for your user account. Your `pi` acount is also a member of the `adm` group (for administration), `dialout` (for using the emulated serial communication hardware connection), `cdrom` (able to access and control hardware like CD-ROMs [do you know what a CD-ROM is?]), and `sudo` (as we learned about in class, a member allowed to become the `root` user, a.k.a. the superuser). The other groups can be learned about online, generally they have to do with hardware access, which you might want to allocate to specific groups of users, but not others.


Let's see what commands are related to user accounts. It would be great if there were a way to search all `man` pages for a particular text string, kind of like running `grep` on all of them. We can do this with the `apropos` command.

	$ man apropos
	$ apropos user

Now we will add a new group of your choosing to the groups database, and then add your user account to that group. Use a name of your choice (or you can use my suggestion):

	$ man addgroup
	$ addgroup awesometown
	addgroup: Only root may add a user or group to the system.
	$ sudo addgroup awesometown
	[sudo] password for pi:
	Adding group `awesometown` (GID 1005) ...
	Done.
	$ adduser pi awesometown
	adduser: Only root may add a user or group to the system.
	$ sudo adduser pi awesometown
	Adding user `pi` to group `awesometown` ...
	Adding user pi to group awesometown
	Done.

Logout and login again to update the user info.

	$ exit

What is your new group name? What is your new group ID (hint: it should be an integer)?

<br \><br \><br \>


###Collaborate
Now that your user account is locked down with a unique password, it will be safe to create a new user account for your neighboring lab group on each of your respective Pis. While logged in as your `pi` account, you can add a new user account with username of their choice. Allow them to also set their password, and enter information as appropriate when prompted.

	$ sudo adduser friendly-neighbor
	Adding user `friendly-neighbor`
	...

If you don't like their choice of username, you can delete their account with:

	$ man userdel
	$ userdel friendly-neighbor
	userdel: Permission denied.
	userdel: cannot lock /etc/passwd; try again later.
	$ sudo userdel friendly-neighbor
	$ _
	
Wow, that was almost too easy! Now, add your `friendly-neighbor` user account to the new group you created above.

Why might you want to create and then join a group between two user accounts?

<br /> <br /> <br />

###Connect Remotely
Now with each group being given a working user account on another Pi, you can ssh into your neighbor's Pi to get **shell access**. Make sure you trade IP address info too (recall this is your `inet addr` for the wireless receiver):
	
	$ ifconfig wlan0

Now you can login to your neighbor's Pi using their IP address:

	$ ssh friendly-neighbor@IP_ADDRESS
	$ whoami
	$ pwd
	$ cd /home
	$ ls -la
	$ id

What are the permissions for the /home account? What is your `uid` and `gid` for your neighbor's Pi? What groups is this user in? You can disconnect from your neighbor's pi using:
	
	$ exit


####We are running the Raspian OS, which is a **Rasp**berry Pi customized version of Deb**ian** Linux. So, you can learn more about how users and permissions work on your Raspberry Pi by visiting here:
 
####http://wiki.debian.org/Permissions

####And you can learn more about Debian policies for Users and Groups by vising here:

####http://www.debian.org/doc/debian-policy/ch-opersys.html

