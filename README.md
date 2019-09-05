# BackPackApp
BackPack Application using C++


README

Backpack Application implemented in C++
Author: Kitiara See

Added: 
- Backpack.h		//Header file for the Backpack App
- BackpackMain.cpp	//Main Console for the Backpack App
- Backpack.cpp		//Implementation of the control functions for the Backpack App


Original Problem:
	Design and implement the class structure for a backpack.
	The user must be able to Add (), Remove () and find () a specific item from the backpack.  
	The user must also be able to list all the available items in the backpack. 
	Item can be assumed to be a string (ex. “Apple”). 
	Please provide the test cases that the class structure would need to have as well. 


Assumptions:
- The user is only entering single word answers. 
	- The functions only read one word answers. 
		- This is relatively easy to change by changing the cin to getline() and
		  adjusting the checkItem() function to account for spaces.
	
- There is an unlimited amount of items in the backpack.
	- It was implemented using Linked lists so items can easily be places and 
	  removed in the backpack.
		- Therefore, additional implementation will be needed to sort the backpack 
		  items.
		 
Test Cases:
	The Application checks for the User's input:
		- It allows for both upper and lower case choices.
		- Items are not case sensitive.
	It also has a functionality to check the tail of the backpack lists:
		- This makes sure items are being added to the backpack properly.
