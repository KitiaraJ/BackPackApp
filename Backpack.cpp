//==============================================================================
// Implementation file for the BackPack class
// Author: Kitiara See
//------------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include "Backpack.h"

using namespace std;

//=============================================================================
//	Function: ~Backpack - deconstructor
//	Inputs:   none
//	Outputs:  none
//	Description:
//			  Destroys every node in the list (empties the backpack)
//-----------------------------------------------------------------------------
Backpack::~Backpack() 
{
	BagList *ptr = head;
	BagList *b4 = nullptr;			//the node before the current: sets to null because it there is nothing before first node

	while(ptr != nullptr)			//goes through the whole list
	{
		if (b4 != nullptr)			
		{
			delete b4;				//remove the previous node
		}

		b4 = ptr;
		ptr = ptr->next;				
	}
	
	if (b4 != nullptr)
	{
		delete b4;
	}

}	//end ~Backpack()

//=============================================================================
//	Function: addItem - adds an item to the backpack
//	Inputs:   user input of a string item
//	Outputs:  cout stream lets the user know that the item was added
//	Description:
//		Adds an item to the backpack that the user inputs
//		using the append ability of C++ lists. Uses the Cout stream to
//		let the user know the item was added successfully
//-----------------------------------------------------------------------------
void Backpack::addItem(string item) 
{
	BagList *newNode = new BagList;
	newNode->value = item;
	newNode->next = nullptr;

    if (head == NULL)
	{
		head = newNode;						//set the head and tail to the item entered if the backpack is empty
		tail = head;
	}

	else
	{
		BagList *ptr = new BagList;
		ptr = head;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;				//append the new node
		}
		
		tail = newNode;						//rename the tail to the newNode
		ptr->next = newNode;				//set the new pointer to the next node so you can continue to add to the backpack
		
		cout << item << " was put into your backpack successfully!" << endl;
	}
}	//end addItem(string item)

//=============================================================================
//	Function: findItem - searches the backpack for a specific item
//	Inputs:   user input of a string item
//	Outputs:  cout stream lets the user know if the item was found
//	Description:
//		Searches the backpack list for a specific item and uses the cout
//		stream to let the user know if the item was found
//-----------------------------------------------------------------------------
  
 void Backpack::findItem(string item)
 {
	BagList *newNode = new BagList;
	BagList *ptr = nullptr;
	BagList *b4 = nullptr;
    
	newNode->value = item;
	newNode->next = nullptr;
	
	int count = 1;

	if (head == NULL)		 //If the backpack is empty, let the user know
	{
		cout << "The bag is empty. Your " << item << " is not in there. Use the 'a' command to add it!" << endl;
		return;
	}


	else
	{
		ptr = head;			//ptr is the head of the list
		
		//skips all items that are not the item the user is looking for
		while(ptr != nullptr && ptr->value != item)
		{
			b4 = ptr;
			ptr = ptr->next;
		}

		if (ptr) 
		{
			cout << "Here's " << count << " " << item << "!";
			count++;
		}
		
		else
		{
			cout << "These are not the items you are looking for. "
				 << "Please add the item you are looking for to the backpack" << endl;
			return;
		}
		
	}
 } //end findItem(string item)
	
//=============================================================================
//	Function: removeItem - searches the backpack for a specific item 
//						   and removes it
//	Inputs:   user input of a string item
//	Outputs:  cout stream lets the user know if the item was found 
//			  and removed
//	Description:
//		Searches the backpack list for a specific item and removes it.
//		Then it uses the cout stream to let the user know if the item 
//		was found and removed
//-----------------------------------------------------------------------------
void Backpack::removeItem(string item) 
{

    BagList *ptr = new BagList;
	BagList *b4 = nullptr;

	if (head == NULL)
	{
		tail = nullptr;
		cout << "Your backpack is empty. Add an item first using the 'a' command!" << endl;		//if the list is empty, don't do anything
		return;
	}
   
	if (head->value == item)						//if it's the first item in the backpack
	{												//Get rid of it and let the user know
		ptr = head->next;							
		delete head;
		head = ptr;
		
		if  (head == NULL)							//if it's the only item, empty the backpack
		{
			tail = NULL;
		}
		
		cout << "I found your " << item << " and removed it for you." << endl;
		return;
	}

	else
	{
		ptr = head;			//ptr is the head of the list
		
		//skips all the items that are not the one user is looking for
		while(ptr != nullptr && ptr->value != item)
		{
			b4 = ptr;
			ptr = ptr->next;
		}

		//This bit of code checks to see if it finds the item and if it does, it deletes it
		if (ptr) 	
		{
			if (ptr->next != nullptr)
			{
				b4->next = ptr->next;
				delete ptr;
			}

			else if(ptr->next == nullptr)
			{
				b4->next = ptr->next;
				delete tail;
				tail = b4;
			}
			cout << "I found your " << item << " and removed it for you." << endl;
			return;
		}
		
		else		//Let the user know the app didn't find the item
		{
			cout << "These are not the items you are looking for. " 
				 << "Please add the item you are looking for to the backpack" << endl;
			return;
		}
	}
} // end removeItem(string item)

//=============================================================================
//	Function: itemList - prints a comprehensive list of all items in the 
//						 backpack
//	Inputs:   none
//	Outputs:  cout stream lists the items in the pack
//	Description: 
//			  Uses a for loop to run through all of the items in the backpack 
//			  and prints them out using the cout stream
//-----------------------------------------------------------------------------
void Backpack::itemList() 
{    
	cout << "The items that you have in your backpack are as follows:" << endl;
   for (BagList *ptr = head; ptr!= nullptr; ptr = ptr->next)			//goes through the backpack printing each item in the pack
   {
	   cout << ptr->value << endl;
   }
}	//end itemList()

//=============================================================================
//	Function: deleting - recursively empties the backpack
//	Inputs:   BagList *pn - pointer
//	Outputs:  none
//	Description: 
//			  Deletes all items in the backpack
//-----------------------------------------------------------------------------
void Backpack::deleting(BagList *pn)
{
	if (pn == NULL)
	{
		head = tail = NULL;
		return;
	}
	else
	{
		deleting(pn->next);
		delete pn;
		return;
	}
}
