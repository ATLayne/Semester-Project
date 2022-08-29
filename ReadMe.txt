Austin Layne
Nathaniel Moreno

CSCI 41 - NFL Project

Project Requirements:

1.) Dynamic Array - Dynamic arrays are included in this project via the rosters.cpp file.
					They are used in conjuction with reading in files. A loop will read the 
					file input and set the size of the arrays based on how many lines are 
					counted in the file. The arrays are created and deleted within the same
					function after the data of the array has been written to the output file.

2.) Handling Erroneous Input - Erroneous input is handled at each selections point within the 
							   program. Accomplished with simple do-while loops. If a users 
							   enters an option outside of the allowed range the program just
							   loops back until an acceptible option is chosen.

3.) Documentation - Names included. Comments are used to describe functionality of included 
					functions.

4.) User Interface - User interface is handled with simple switch statements and entering 
					 integer numbers for selecting options within the program. Printing large
					 lists of data is paused to allow users to continue through without scrolling.


5.) Output Reporting - Output is formatted with <iomanip> functions. Again, printing large amounts
					   of text is mitigated using system("pause") every 20 lines to avoid scrolling. 
					   System("cls") is also used to clear the screen at the start of a new function.

6.) Input Data - Data is read from two separate files, mainly in the rosters.cpp file. One for each 
				 team included in this build of the project. Each file contains over 50 entries with 
				 3 input items each. This can be scaled up as the project grows.

7.) Add or Remove Items - Functions to add/or remove items is included in the rosters.cpp file. This is 
						  accomplished by creating arrays based on the amount of lines in the files. 
						  Then creating additional arrays with either 1 more or 1 less index. The contents
						  of the original array are the copied into the new array. The old array is deleted 
						  upon completion of the copy.