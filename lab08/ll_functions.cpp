// file: ll_functions.cpp
#include <iostream> 
#include <string>  
using namespace std; 

#include "ll_headers.h"

// Used in the function createLL()
// This function is started for you correctly - you have to complete it.
//   Use the comments to help you figure out what to do.
void h_insert(LinkNodePtr& head, string nom, int num) {
    	LinkNodePtr tmp_ptr;
    	tmp_ptr = new LinkNode;

	tmp_ptr->name = nom;
    	tmp_ptr->number = num;
    	tmp_ptr->link = nullptr; 

	// If the list is empty, the new node becomes the head
	if (head == nullptr)
		head = tmp_ptr;	


	// If the list is not empty, traverse to the last node
	else
	{
		LinkNodePtr cur_ptr = head;
		while (cur_ptr->link != nullptr)
			cur_ptr = cur_ptr->link;	
		cur_ptr->link = tmp_ptr; // Change the pointer of the last node to the new node

	}
}

void createLL(LinkNodePtr& h) {
    	string nom = "";
    	int num;  
    	while(true)
    	{
        	cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        	cin >> nom >> num;
		if (nom == "0" && num == 0)
			break;
		h_insert(h, nom, num);		
    	}
}

void printLL(LinkNodePtr h) {
	 if (h == nullptr)
        {
                cout << "This list is empty." << endl;
                return;
        }

	cout << "Printing the list:" << endl;

	int nodeCount = 0;
	while (h != nullptr)
	{
		cout << "Node #" << nodeCount << ": " << h->name << ", " << h->number << endl;
		h = h->link;
		nodeCount++;
	}

	cout << "--------" << endl;
}
	
void insertNodeAfter(LinkNodePtr& h) {

	if (h == nullptr)
	{
		cout << "Cannot insert in a non-existing link." << endl;
		return;
	}

	int pos;
        cout << "Enter node position to insert new node after (enter negative number to exit): ";
        cin >> pos;

	if (pos < 0)
		return;

	LinkNodePtr cur_ptr = h; // Copy headptr for safer iteration
	for (int i = 0; i < pos && cur_ptr != nullptr; i++) // Asked AI if for loops can have multiple conditionals
	        cur_ptr = cur_ptr->link;
	
	if (cur_ptr == nullptr)
	{
		cout << "Position entered is illegal. Nothing inserted." << endl;
		return;
	}

	string name;
        int num;
	cout << "Enter data (name, then number): ";
        cin >> name >> num;

	LinkNodePtr tmp = new LinkNode;
    	tmp->name = name;
    	tmp->number = num;

    	tmp->link = cur_ptr->link; // Link new node to list to retain connection to rest of list 
    	cur_ptr->link = tmp; // Now safely overwrite cur_ptr memory address to the new node
	
}

void findMax(LinkNodePtr h) {
    	if (h == nullptr)
	{
		cout << "This list is empty." << endl;
        	return;
	}

    	int max = h->number;
    	LinkNodePtr cur_ptr = h->link;
    	while (cur_ptr != nullptr)
    	{
		if(cur_ptr->number > max)
			max = cur_ptr->number;
		 cur_ptr = cur_ptr->link;
    	}
    	cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    	if (h == nullptr)
	{
		cout << "This list is empty." << endl;
                return;
	}

        int min = h->number;
        LinkNodePtr cur_ptr = h->link;
        while (cur_ptr != nullptr)
        {
                if(cur_ptr->number < min)
                        min = cur_ptr->number;
                 cur_ptr = cur_ptr->link;
        }
    	cout << "Smallest number in the list is: " << min << endl;
}


