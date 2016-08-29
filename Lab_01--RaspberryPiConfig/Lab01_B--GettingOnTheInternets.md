#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Dan Sazer<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 1B. Getting Raspberry Pi on the Internets

### Ethernet Access


1. Check that you do not currently have network access. You should **NOT** see an entry for `inet addr` on the second line of output:

			$ ifconfig eth0
			eth0      Link encap:Ethernet  HWaddr b8:27:eb:01:49:dd  
			          inet6 addr: fe80::35cf:e506:60c2:1e7b/64 Scope:Link
			          UP BROADCAST MULTICAST  MTU:1500  Metric:1
			          RX packets:0 errors:0 dropped:0 overruns:0 frame:0
			          TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
			          collisions:0 txqueuelen:1000 
			          RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)



Ask your Instructor for help disconnecting ethernet from a desktop computer in OEDK classroom, connect the female-to-female coupler and ethernet extension cord, and plug the ethernet cord into the ethernet port on your Raspberry Pi. 

Once connected, you should see the LED on the Ethernet port light up. Your Pi should have auto-requested an IP address from the network. Check that you now have an `inet addr` on the second line:

			$ ifconfig eth0
			eth0      Link encap:Ethernet  HWaddr b8:27:eb:01:49:dd  
			          inet addr:10.69.51.159  Bcast:10.69.51.255  Mask:255.255.255.0
			          inet6 addr: fe80::35cf:e506:60c2:1e7b/64 Scope:Link
			          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
			          RX packets:63 errors:0 dropped:0 overruns:0 frame:0
			          TX packets:90 errors:0 dropped:0 overruns:0 carrier:0
			          collisions:0 txqueuelen:1000 
			          RX bytes:8762 (8.5 KiB)  TX bytes:15212 (14.8 KiB)

1. To check if you are on the Internet, see if you can `ping` internet servers. **NOTE:** use **`<ctrl-C>`** to cancel the `ping`.

		$ ping rice.edu
		PING rice.edu (128.42.204.44) 56(84) bytes of data.
		64 bytes from 128.42.204.44: icmp_req=1 tt1=244 time=30.7 ms
		...



###Welcome to the Internet!


1. ####Let's upgrade your system and all its software to the latest OS version.

	Grab the complete list of all the latest software programs and packages:

		$ sudo apt-get update
		Hit http://archive.raspberrypi.org jessie InRelease
		Hit http://mirrordirector.raspbian.org jessie InRelease
		...
		Reading package lists... Done                                                                                                                                                                                                          

1. Upgrade your system.

		$ sudo apt-get dist-upgrade
		Reading package lists... Done
		Building dependency tree
		Reading state information... Done
		Calculating upgrade... Done
		The following packages will be upgraded:
		...
		Need to get 38.8 MB of archives.
		After this operation, 151 kB of additional disk space will be used.
		Do you want to continue [Y/n]?
		
	Note that we will use `dist-upgrade` as the recommended upgrade command instead of simply `upgrade` to make sure that we have an intelligently loaded set of software that is known to work well together. From the manual:
			
			dist-upgrade in addition to performing the function of upgrade,
			also intelligently handles changing dependencies with new versions
			of packages; apt-get has a "smart" conflict resolution system, and
			it will attempt to upgrade the most important packages at the
			expense of less important ones if necessary. So, dist-upgrade
			command may remove some packages. The /etc/apt/sources.list file
			contains a list of locations from which to retrieve desired package
			files. See also apt_preferences(5) for a mechanism for overriding
			the general settings for individual packages. 
			
	This will take some time. Raspberry Pi is pulling down all the newest versions of software packages, authenticating their checksums, expanding and installing the new packages. When it has completed, you will be back at the command prompt. Check for any errors in the upgrade text being printed.
	
	Re-run the `update` and `dist-upgrade` commands until you see the successful completion results reported as follows:
	
		$ sudo apt-get dist-upgrade
		Reading package lists... Done
		Building dependency tree       
		Reading state information... Done
		Calculating upgrade... Done
		0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.


	
	
	**TROUBLESHOOTING:** It's possible that the Raspberry Pi may crash during this process (sometimes during the update of `raspberrypi-kernel`). Symptoms: you may see some errors when you try to do anything that reference nothing being found (e.g. `EXT4-fs error` is about the hard drive). If this happens, you will need to force reboot by disconnecting power and reconnecting power to the Pi. Upon fresh reboot, your update will be in a broken state. Test this by re-running the `update` and `dist-upgrade` commands above. The error will state:
	
		E: dpkg was interrupted, you must manually run `sudo dpkg --configure -a` to correct the problem.
	
	To fix, just follow these instructions:
		
		$ sudo dpkg --configure -a
	
	If this completes successfully, re-run the `update` and `dist-upgrade` commands again until you see the successful completion notice describe above.	

1. Install some games:

		$ sudo apt-get install bsdgames

1. Install the Arduino environment:

		$ sudo apt-get install arduino


1. Your new software should be loaded and ready to go. But let's reboot just to be safe:

		$ sudo shutdown -r now


1. Move on to **Lab 1C**. **NOTE:** WiFi instructions below will **NOT** work yet with Rice University's WiFi network (and so we will need to use hardwired ethernet connections for this semester). I've put the instructions below for you to use to get on unencrypted or encrypted WiFi networks you might have at home or at your lab.



___

### WiFi Access

**NOTE:** WiFi instructions below will **NOT** work (as we will use hardwired ethernet connections as described above), but there are here for you to use to get on unencrypted or encrypted WiFi networks you might have at home or at your lab.

1. Plug in your USB WiFi module
1. Check that you do not currently have network access:

			$ ifconfig wlan0


1. Edit the `wpa_supplicant.conf` file:

		$ sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
		

1. Make the contents of your file to be this exactly:

		ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
		update_config=1

		network={
			ssid="BIOE_421_521"
			key_mgmt=NONE
			auth_alg=OPEN
		}


1. Save the file and exit. To do this, you can try to exit with **`<ctrl-X>`**, at which point you will be asked if you want to save the modified buffer (you do! press **`<y>`** then **`<enter>`**). You will be asked to name the file. You want to overwrite the previous file, so you can just press **`<enter>`** again when you see this.
1. Reboot the computer
		
		$ sudo shutdown -r now

1. During reboot, you should notice some lines of text referencing the USB wireless LAN (WLAN) adapter:

		...
		[     4.485488] usb 1-1.5: Product: 802.11n WLAN Adapter
		[     4.506962] usb 1-1.5: Manufacturer: Realtex
		...


1. Login, and check if you have an IP address (look for `inet addr`, your Internet Address):

		$ ifconfig wlan0
		wlan0     Link encap:Ethernet  HWaddr 00:5F:21:98:6C:5B  
          inet addr:192.168.2.7  Bcast:192.168.2.255  Mask:255.255.255.0
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:196 errors:0 dropped:39 overruns:0 frame:0
          TX packets:71 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:38054 (37.1 KiB)  TX bytes:7976 (7.7 KiB)


1. To check if you are on the Internet, see if you can `ping` internet servers. **NOTE:** use **`<ctrl-C>`** to cancel the `ping`.

		$ ping rice.edu
		PING rice.edu (128.42.204.44) 56(84) bytes of data.
		64 bytes from 128.42.204.44: icmp_req=1 tt1=244 time=30.7 ms
		...
