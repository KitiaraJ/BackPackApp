//==============================================================================
// Author: Kitiara See
// File:   BackpackMain.cpp: Main Console for the Backpack App
//==============================================================================

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "Backpack.h"

using namespace std;

// Prototypes for functions "below main"
void helpMe();
void quitMe(int exitStatus);
string checkItem(string prompt);
void testingTail();

const int SUCCESS = 0; // return code for SUCCESS
const int FAILURE = 1; // return code for FAILURE

int main()
{	
	// Create an instance of a backpack called list
	Backpack list;
	
	// Local variables for 'main function
	char choice;		// Function Input by user
	string dataValue;   // prompt for checkItem() which returns the item input by user
	char emptyYes;		//Checks for deletion of the bag

	while (true) 
	{
		// Gives the opening speech and prompts for action
		cout << "Hello! I am your backpack inventory app. "
			<< "What would you like to do today? \n"
			<< "(Please press 'H' for a list of all commands.)"
			<< endl;
		cin >> choice;
        cout << fixed << setprecision(2);

        switch (choice) 
		{
        
        case 'a':
			 //Adds an item into the backpack
			 dataValue = checkItem("What item would you like to put into your backpack?: " );
			 list.addItem(dataValue);
			 break;
        case 'A':
			 //Adds an item into the backpack
             dataValue = checkItem("What item would you like to put into your backpack?: " );
			 list.addItem(dataValue);
			 break;
		case 'd':
			 // Clear the backpack
             cout << "This will empty your backpack. Are you sure?";
			 cin >> emptyYes;
			 if (emptyYes == 'y' || emptyYes == 'Y')
			 {
				 list.deleteAll();
				break;
			 }
			 else if (emptyYes == 'n' || emptyYes == 'N')
			 {
				 cout << "Okay! Cancelling that command.";
				 break;
			 }
			 else
			 {
				 cout << "Invalid command.";
				 break;
			 }
		case 'D':
             // Clear the backpack
             cout << "This will empty your backpack. Are you sure?";
			 cin >> emptyYes;
			 if (emptyYes == 'y' || emptyYes == 'Y')
			 {
				 list.deleteAll();
				break;
			 }
			 else if (emptyYes == 'n' || emptyYes == 'N')
			 {
				 cout << "Okay! Cancelling that command.";
				 break;
			 }
			 else
			 {
				 cout << "Invalid command.";
				 break;
			 }
        case 'f':
			 //Finds a specific item in the backpack
			 dataValue = checkItem("What item would you like to take out of your backpack?: " );
			 list.findItem(dataValue);
			 break;
        case 'F':
            //Finds a specific item in the backpack
			 dataValue = checkItem("What item would you like to take out of your backpack?: " );
			 list.findItem(dataValue);
             break;
        case 'h':
             // Output help text
             helpMe();
             break;
		case 'H':
             // Output help text
             helpMe();
             break;	 
        case 'p':
			 //List all of the items in the backpack
             list.itemList();
             break;
        case 'P':
			 //List all of the items in the backpack
             list.itemList();
             break;
        case 'q':
             // Quit program
             quitMe(SUCCESS);
             break;
		case 'Q':
             // Quit program
             quitMe(SUCCESS);
             break;	 
        case 'r':
             //Removes a specific item in the backpack
			 dataValue = checkItem("What item would you like to take out of your backpack?: " );
			 list.removeItem(dataValue);
             break;
		case 'R':
             //Removes a specific item in the backpack
			 dataValue = checkItem("What item would you like to take out of your backpack?: " );
			 list.removeItem(dataValue);
             break;	 
		case 't':
             //Tests the tail
			 testingTail();
             break;
		case 'T':
             //Tests the Tail
			 testingTail();
             break;
		default:
            cout << "Invalid command:  " << choice << endl;
			
			// Prompt for command input.
			cout << "What would you like to do today?: ";
			cin >> choice;
        } // end switch
    } // end while

    return 0;
} // end main

//=============================================================================
//	Function: helpMe - Gives a list of available commands
//	Inputs:   none
//	Outputs:  Displays help text to the cout stream
//	Description:
//		Output (to the screen) a short description of each interactive command
//      supported by the program.
//-----------------------------------------------------------------------------
void helpMe() 
{
	// Help text.
	cout << "Supported commands: \n"
            << "	a     ADD a value to the list.\n"
            << "	d     DELETE ALL items from your backpack.\n"
			<< "	f	  FIND an item in your backpack. \n"
            << "	h     print this HELP text.\n"
            << "	p     PRINT the contents of your backpack.\n"
            << "	q     QUIT (end the program).\n"
			<< "	r	  REMOVE an item from your backpack. \n"
            << "	t     test TAIL changes.\n"
            << endl;
	return;
} // end helpMe()

//=============================================================================
//	Function:   quitMe     -   Exit the program, returning status from caller
//	Inputs:		exitStatus =   Exit code to be returned to operating system.
//	Outputs:	exits the program, passing status value from caller
//	Description:
// 		Exit the program
//-----------------------------------------------------------------------------
void quitMe(int exitStatus) 
{
    cout << "Exiting program with status = " << exitStatus << endl;
    exit(exitStatus);

} // end quitMe

//=============================================================================
//   Function: 		checkItem					
//   Inputs:   		requests input from the user
//   Outputs:  		returns string item given by user if valid or returns a 
//					prompt to try again
// 	 Description: 	Input a line of text and checks to make sure it's a valid
//					item
//  ---------------------------------------------------------------------------
string checkItem(string prompt)
{
	string userItem;			// String to hold the user input
	bool inputIsItem = false;	// Defaults to false for the Do-While loop checking the string
	
	do
	{
		cout << prompt;
		cin >> userItem;

		for (int i = 0; i < userItem.length(); i++)
		{
			if (userItem[i] < 65 && userItem[i] < 97  			//Checks to see if there are any 
				&& userItem[i] > 90 && userItem[i] > 122)		//ASCII Characters in the input	
			{
				cout << userItem << " is an invalid item."
					<< "You can't put that into your backpack." << endl
					<< "Please input a proper item." << endl;
				break;
			}

			else
			{
				inputIsItem = true;
			}
		}
	} while (inputIsItem == false);
	
	return userItem;
} // end checkItem(string prompt)

//=============================================================================
//    Function: 	testingTail					
//    Inputs:   	none
//    Outputs:  	print function within tests
//	  Description: 	Checks for tail functionality to make sure backpack app  
//					is working properly
//  ---------------------------------------------------------------------------
void testingTail() 
{
    // Create an instance of BagList
    Backpack * pList = new Backpack;
               
    pList->itemList();					// should be empty
                

    pList->addItem("notebook");		// append to empty list
    pList->addItem("pencil");		
    pList->addItem("apple");		
    pList->addItem("folder");		
    pList->addItem("binder");		

    pList->itemList();					// should see notebook - pencil - apple - folder - binder

    pList->removeItem("notebook");
    pList->removeItem("binder");
    pList->removeItem("apple");	
    pList->removeItem("eraser");	// delete something not on list

    pList->itemList();					// should see pencil->folder

    pList->removeItem("pencil");	// delete the pencil
    pList->removeItem("folder");	// after delete list should be empty
    pList->removeItem("apple");		// try delete against empty list

    pList->itemList();

    pList->addItem("eraser");		// insert into empty list

    pList->itemList();					// should see eraser
    
    delete pList;					// test destructor
    
    return;
} // end testingTail()