Austin Layne
Nathaniel Moreno

CSCI 41 - NFL Project

Project 2 (Solo) Requirements:
1.) Choice of Struct - 	Decided to implement a struct that held the win/loss records for each team. A dynamic
				array of structs is then implemented in the teammenu.cpp file.

2.) Struct Design - 	The struct contains 4 different elements with a total of 2 types.
				3 ints (win, loss, tie) and 1 string (teamName)

3.) Input/Output Interface - 	A user menu is implemented to allow users to edit a teams record. There is no
					ability to add or remove a team element as that would be counterproductive to
					what this code is for. However, a user can manually edit the wins, losses, or 
					ties of individual team. This changes are then stored to an external file.

4.) Readability -	Removed excessive white space from the program. Defined what the teammenu.cpp file is used 
			for. 

5.) Handles Erroneous Input -	A series of loops or switch statements prevent erroneous selections within menus.

6.) Effective Processing - 	Not really applicable to the problem that this code is used for. I do suppose that
					functionality to calculate a teams win percentage could be implemented.

7.) Updates from previous feedback - 	Removed excessive white space in some files. Also fixed bug that 
							wouldn't allow deletion of elements of the player rosters.
						

****************************************************************************************************************
****************************************************************************************************************
Project 1 Requirements:
1.) List of members implemented - 	This should be accomplished with the use of entire player rosters
						of NFL football teams. The members are contained within .txt
						files, and are accessed while creating the dynamic arrays.

2.) Creates a proper base class - 	This is accomplished with the "person.h" header file. As expected this
						class just contains the basic information needed to identify a 
						person such as name and age.

3.) Properly utilizes inheritance - "player.h" is inherited from "person.h". This class creates the players 
						of the team, and contains extra data like the players number and position.

4.) Properly overrides a function - the "display()" function within player.h overrides the "display()" function 
						for person.h

5.) Input validation - 	Erroneous input is handled at each selections point within the 
			     	program. Accomplished with simple do-while loops. If a users 
			    	enters an option outside of the allowed range the program just
			     	loops back until an acceptible option is chosen.

6.) Addresses previous concerns - 	When a user enters an invalid entry for player number they are now presented with 
						an option to continue or not.
						
						Moved files from "external dependencies" to source files.

						Renamed the Explore Rosters file to Roster Menus to more accurately describe
						its purpose.
						

****************************************************************************************************************
****************************************************************************************************************
Project 0 Requirements:

1.) Dynamic Array - 	Dynamic arrays are included in this project via the rosters.cpp file.
				They are used in conjuction with reading in files. A loop will read the 
				file input and set the size of the arrays based on how many lines are 
				counted in the file. The arrays are created and deleted within the same
				function after the data of the array has been written to the output file.

2.) Handling Erroneous Input - 	Erroneous input is handled at each selections point within the 
						program. Accomplished with simple do-while loops. If a users 
						enters an option outside of the allowed range the program just
						loops back until an acceptible option is chosen.

3.) Documentation - 	Names included. Comments are used to describe functionality of included 
				functions.

4.) User Interface - 	User interface is handled with simple switch statements and entering 
				integer numbers for selecting options within the program. Printing large
				lists of data is paused to allow users to continue through without scrolling.


5.) Output Reporting - 	Output is formatted with <iomanip> functions. Again, printing large amounts
				of text is mitigated using system("pause") every 20 lines to avoid scrolling. 
				System("cls") is also used to clear the screen at the start of a new function.

6.) Input Data - 	Data is read from two separate files, mainly in the rosters.cpp file. One for each 
			team included in this build of the project. Each file contains over 50 entries with 
			3 input items each. This can be scaled up as the project grows.

7.) Add or Remove Items - 	Functions to add/or remove items is included in the rosters.cpp file. This is 
					accomplished by creating arrays based on the amount of lines in the files. 
					Then creating additional arrays with either 1 more or 1 less index. The contents
					of the original array are the copied into the new array. The old array is deleted 
					upon completion of the copy.