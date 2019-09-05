//==============================================================================
// Author: Kitiara See
// File:   BackPack.h: Creates and implements some functions in  
//					   the backpack class
//==============================================================================
 
#ifndef BACKPACK_H
#define	BACKPACK_H

#include <cstdlib>
#include <string>
using namespace std;

class Backpack 
{
	private:
	
		//Setting up the structure for the list
		struct BagList
		{
			string value;
			BagList *next;
		};
		
		BagList *head; 						// List head pointer 
		BagList *tail; 						// List tail pointer
		void deleting(BagList *pn);
		
	public:
	
		Backpack()							//constructor sets both head and tail of list to null
		{
			head = NULL;
			tail = NULL;
		}
		
		~Backpack();						//destructor

		void addItem(string item);			//adds an item to the backpack
		void removeItem(string item);		//removes an item from the backpack
		void findItem(string item);			//finds an item in the backpack
		void itemList();					//List the items inside the backpack
		
		void deleteAll()					//calls the private method to recursively delete all of the items in the backpack
		{
			cout << "Emptying your backpack..." << endl;
			deleting(head);
		}	

}; // end class

#endif	/* BACKPACK_H */