# Bioe 421/521: Microcontroller Applications
#### Instructor: Jordan Miller<br>TA: Adam Farsheed<br>github.com/jmil/Bioe421_521-MicrocontrollerApplications

## Lab 4. Parsing with `Grep`, `Awk`, and `Sed`

From [Wikipedia, Parsing:](https://en.wikipedia.org/wiki/Parsing)
> Parsing or syntactic analysis is the process of analysing a string of symbols, either in natural language or in computer languages, conforming to the rules of a formal grammar.

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

Let's apply what you've learned from Matt's awesome tutorial by working with the National Institutes of Health (NIH) Pubmed Database. NIH allows you to query their servers for specific formats of scientific publication data that you can then process via command line. Each publication in their database has a unique ID number (in the form of an integer), called a **PMID** (PubMed ID). We can use the **PMID**, or **multiple PMIDs delimited by a `,`**, as the search string in a URL to request the data on the **PMID**(s).


From [Wikipedia, Roger Y. Tsien:](https://en.wikipedia.org/wiki/Roger_Y._Tsien) 
>[Roger Tsien] was awarded the 2008 Nobel Prize in Chemistry "for his discovery and development of the Green Fluorescent Protein (GFP)..."

1. Sounds interesting. Let's learn some more about his work. Make a new directory for today, and query the NIH database for some of Roger Tsien's publications, identified here by specific **PMIDs**.
	
		$ mkdir Team09-Lab04
		$ cd Team09-Lab04
		$ wget -O tsien.txt "https://pubmed.ncbi.nlm.nih.gov/?term=16299475%2C15558047%2C18454154%2C19423828&format=pubmed" 


Let's look at the file you created:
	
	$ cat tsien.txt | less


Towards the end of the file you should see the following:

			<pre class="search-results-chunk">PMID- 16299475
		OWN - NLM
		...
		AID - 324/5928/804 [pii]
		AID - 10.1126/science.1168683 [doi]
		PST - ppublish
		SO  - Science. 2009 May 8;324(5928):804-7. doi: 10.1126/science.1168683.

1. Next, write a piped command line program to process `tsien.txt` and output a new file `tsien_PMIDs.txt` which contains a list of the PMID contained in this file. You will probably want to use what you learned about `grep`, `awk`, and/or `sed`. Just like most things we've learned so far, there is more than one way to do it ([TIMTOWTDI, pronounced *Tim Toady*](https://en.wikipedia.org/wiki/There%27s_more_than_one_way_to_do_it))!

	**Hint:** You may want to start by doing a simple `grep` for "PMID":
	
		$ cat tsien.txt | grep "PMID"
		PMID- 16299475
		PMID- 15558047
		CIN - Nat Biotechnol. 2004 Dec;22(12):1524-5. PMID: 15583657
		PMID- 18454154
		CIN - Nat Methods. 2008 Jun;5(6):472-3. PMID: 18511915
		PMID- 19423828

	When you're done, the contents of your file should be:

		16299475
		15558047
		18454154
		19423828
	
	What was the one-line program you wrote to do this?
	
		$

1. Next, create a function inside a new bash script titled `parsePMIDs.sh` to help us process lists of PMIDs. You want to use a `while` function like this:

		#! /bin/bash
		
		while read line           
		do           
		echo "$line"
		done <tsien_PMIDs.txt

1. Do you remember how to modify `parsePMIDs.sh` to make it executable? Write the command you used here:

		:

1. Let's modify this script to be more useful. Given a file that contains a list of PMIDs, it would be ideal if, for each PMID, you could go to pubmed and download the article information. You will want to use the URL of the following form, where you will substitute each unique PMID, line by line, for the "########" section. Note that the report format here is `MEDLINE`:

		https://pubmed.ncbi.nlm.nih.gov/########/?format=pubmed
		(multiple PMIDs: https://pubmed.ncbi.nlm.nih.gov/?term=########%2C########%2C########&format=pubmed)
		
	The `xml` report format can also be useful for the rest of the lab, so be sure to look at that one too:
	
		https://pubmed.ncbi.nlm.nih.gov/########/


	So your `parsePMIDs.sh` file  should read your `PMIDs.txt` file, grab the article information for each PMID, and append it to a new file, `Tsien_result.txt`.

### Fetch, Parse, Repeat

Now you should see where we are going with this... Pubmed allows us to query the database with a search term, such as "cancer", and return a list of PMIDs. Retrieve text from the following link into a new file `cancer_refs.txt`:

> https://eutils.ncbi.nlm.nih.gov/entrez/eutils/esearch.fcgi?db=pubmed&term=cancer&reldate=60&datetype=edat&retmode=text	

**NOTE:** You will likely need to put this URL within quotes to get it to download correctly. Or a URL shortener website could help you.

What command did you run to do this?

	$ 
	
Check the contents of your file:

	$ cat cancer_refs.txt | less

What's going on here? Let's look at the syntax for the URL fields defined for NIH e-utilities: [http://www.ncbi.nlm.nih.gov/books/NBK25499/](http://www.ncbi.nlm.nih.gov/books/NBK25499/)

>**term**
>Entrez text query. All special characters must be URL encoded. Spaces may be replaced by '+' signs. For very long queries (more than several hundred characters long), consider using an HTTP POST call. See the PubMed or Entrez help for information about search field descriptions and tags. Search fields and tags are database specific.

>**reldate**
>When reldate is set to an integer n, the search returns only those items that have a date specified by datetype within the last n days.

>**mindate, maxdate**
>Date range used to limit a search result by the date specified by datetype. These two parameters (mindate, maxdate) must be used together to specify an arbitrary date range. The general date format is YYYY/MM/DD, and these variants are also allowed: YYYY, YYYY/MM.

>**retmax**
>Total number of UIDs from the retrieved set to be shown in the XML output (default=20). By default, ESearch only includes the first 20 UIDs retrieved in the XML output. If usehistory is set to 'y', the remainder of the retrieved set will be stored on the History server; otherwise these UIDs are lost. Increasing retmax allows more of the retrieved UIDs to be included in the XML output, up to a maximum of 100,000 records. To retrieve more than 100,000 UIDs, submit multiple esearch requests while incrementing the value of retstart (see Application 3).

Can you identify the delimiter for these fields in the URL? Write it here:

	: 

	
You will want to take this `cancer_refs.txt` result file, and parse out the PMIDs into a new file, `cancer_PMIDs.txt`. Note that the PMIDs will have to be parsed out from between the `<Id>` and `</Id>` tags. You could also think about using a clever "find/replace" scheme – which command did we learn today that's great at find/replace?
	
1. (CHALLENGE PROBLEM try to get as close as possible to this end goal): Generate a script called `PMID_query.sh`. We want the **use case** to be:

		$ ./PMID_query.sh cancer_PMIDs.txt cancer_bibliography.txt

	The first user-input value `cancer_PMIDs.txt` should be processed line by line to generate a PMID query, and **append** a formatted bibliography for that PMID to a new `cancer_bibliography.txt` file using the style:

		AUTHORS LIST
		Nat Methods. 2005 Dec;2(12):905-9.
		ABSTRACT
		
	Recall: the `MEDLINE` and `xml` formats might each be useful for part of this formatting.
	
1. Now, get it working for your `cancer_PMIDs.txt` file.

 
### Now, Let's apply this file for the following query: GFP (Green Fluorescent Protein)

> via wikipedia.org:
> The green fluorescent protein (GFP) is a protein composed of 238 amino acid residues (26.9 kDa) that exhibits bright green fluorescence when exposed to light in the blue to ultraviolet range ...
> GFP can be introduced into animals or other species through transgenic techniques, and maintained in their genome and that of their offspring. To date, GFP has been expressed in many species, including bacteria, yeasts, fungi, fish and mammals, including in human cells. Scientists Roger Y. Tsien, Osamu Shimomura, and Martin Chalfie were awarded the 2008 Nobel Prize in Chemistry on 10 October 2008 for their discovery and development of the green fluorescent protein.

1. Design a URL to get the PMIDs of up to 100 publications for 'GFP' in the last year. What URL did you come up with?
	
		:
	
1. Put the PMID results from this query into the file `GFP-PMIDs.txt` such that it can be called by `PMID_query.sh`. So, as above your results will need to be parsed for the PMIDs that are between the `<Id>` and `</Id>` tags.

1. Get a timer ready. Use your `PMID_query.sh` file to create formatted citations about 'GFP' in `GFP_bibliography.txt`. While the script is running, time how long it takes to get each citation:

		____ seconds per citation
		
	What is placing the speed limit on this script? How do you think you could you speed it up? Explain.
	
		:
		:
		:
		
1. Try some of these options to speed up your script:

		Now: ____ seconds per citation
		
	Explain what you determined was slowing down your script:
	
		:
		:
		:

	
### Homework Submission

		
1. Zip up your folder from today to make a single .zip file

		$ cd ~
		$ zip -r Team09-Lab04.zip Team09-Lab04

1. Access the zip file via filezilla and upload to canvas along with an MD/word/text file with your answers to this lab.


## Shutdown Procedure

1. Shutdown your Pi properly:

		$ sudo shutdown -h now
		
