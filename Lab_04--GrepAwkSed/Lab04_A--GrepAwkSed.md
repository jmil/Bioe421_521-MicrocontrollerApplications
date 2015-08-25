#Bioe 421/521: Microcontroller Applications
####Instructor: Jordan Miller<br>TA: Jacob Albritton<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

##Lab 4A. Grep, Sed, and Awk


### Tutorial from Matt Probert, University of New York
Work through the tutorials on Grep, Sed and Awk handed out to you and available here:
http://www-users.york.ac.uk/~mijp1/teaching/2nd_year_Comp_Lab/guides/grep_awk_sed.pdf

You will want to create the 'a_file' he mentions at the beginning of the tutorial. Here's the source text:

	boot
	book
	booze
	machine
	boots
	bungie
	bark
	aardvark
	broken$tuff
	robots



### Awk-ward

1. Let's apply what you've learned from Matt's awesome tutorial by working with the NIH Pubmed Database. NIH allows you to query their servers for specific formats of scientific publication data that you can then process via command line.

		$ mkdir Team09-LambdaFTW_Lab04
		$ cd Team09-LambdaFTW_Lab04
		$ wget -O tsien.txt "http://www.ncbi.nlm.nih.gov/pubmed/16299475,15558047,18454154,19423828?report=medline&format=text" 
		$ cat tsien.txt | more

	You should see the following file:

		<?xml version="1.0" encoding="utf-8"?>
		<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
		<pre>
		PMID- 16299475
		OWN - NLM
		STAT- MEDLINE
		...
		SO  - Nat Methods. 2005 Dec;2(12):905-9.
		</pre>


1. Next, write a piped command line program to process `tsien.txt` and output a new file `PMIDs.txt` which contains a list of the PMID contained in this file. When you're done, the contents of your file should be:

		16299475
		15558047
		18454154
		19423828

1. Next, create a function inside a new bash script titled `parsePMIDs.sh` to help us process lists of PMIDs. Don't forget to modify the file to make it executable.

		$ chmod +x parsePMIDs.sh

1. You want to use a `while` function like this:

		#! /bin/bash
		
		while read line           
		do           
		echo "$line"
		done <PMIDs.txt

1. Modify this function to pull down the article data for every PMID listed in your PMIDs.txt file.

1. Now you should see where we are going with this... Pubmed allows us to query they database and return a list of PMIDs. Use the following syntax:

		http://eutils.ncbi.nlm.nih.gov/entrez/eutils/esearch.fcgi?db=pubmed&term=cancer&reldate=60&datetype=edat
	
	Your returned PMIDs will have to be parsed out from between the `<Id>` `</Id>` tags.
	
1. Now generate a final script called `PMID_query.sh` that will take user input on the command line as input to a PMID query. Format the output `PMID_result.txt` to be the following:
	
	AUTHORS
	Nat Methods. 2005 Dec;2(12):905-9.
	ABSTRACT
	
	
1. Now generate several output files for the following querys:
	1. All citations for 'GFP' in the last year
	1. All citations for '3D Print' in each of the last year 5 years
	
1. Zip and SSH your results to your Instructor's Raspberry Pi using the instructions from last time.


## Shutdown Procedure

1. Shutdown your Pi properly:

		$ sudo shutdown -h now

 Unplug everthing and restore the Windows desktop computer to a working state.
