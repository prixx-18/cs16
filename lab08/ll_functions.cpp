// Priyansh Nath

// Pre-condition: Input a pointer (by reference) to the first node in a linked list, and the name and number you want to input
// Post-condition: Initializes and inserts a LinkNode into the next available spot in a link list
void h_insert(LinkNodePtr& head, string nom, int num) {
    	LinkNodePtr tmp_ptr; 
    	tmp_ptr = new LinkNode;

	// Initialize new LinkNode member variables
	tmp_ptr->name = nom;
    	tmp_ptr->number = num;
    	tmp_ptr->link = nullptr; 

	// If the list is empty, the new node becomes the head
	if (head == nullptr)
		head = tmp_ptr;	


	// If the list is not empty, traverse to the last node
	else
	{
		LinkNodePtr cur_ptr = head; // Create a copy of head pointer to maintain reference to start of ll
		while (cur_ptr->link != nullptr)
			cur_ptr = cur_ptr->link;	
		cur_ptr->link = tmp_ptr; // Change the pointer of the last node to the new node
	}
}

// Pre-condition: Input a pointer (by reference) to the first node in a linked list
// Post-condition: Creates a linked list with user inputs until they terminate the function 
void createLL(LinkNodePtr& h) {
    	string nom = "";
    	int num;  

	// Prompt user until they terminate
    	while(true)
    	{
        	cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        	cin >> nom >> num;
		if (nom == "0" && num == 0)
			break;
		h_insert(h, nom, num); // Insert every node at the end of the linked list	
    	}
}

// Pre-condition: Input a pointer to the first node in a linked list
// Post-condition: Prints every element in the list if it is populated
void printLL(LinkNodePtr h) {
	// If the head is pointing to null the linked list is empty
	 if (h == nullptr)
        {
                cout << "This list is empty." << endl;
                return;
        }

	cout << "Printing the list:" << endl;

	// Prints node information
	int nodeCount = 0;
	while (h != nullptr)
	{
		cout << "Node #" << nodeCount << ": " << h->name << ", " << h->number << endl;
		h = h->link; // "Increment" the head pointer (not passed by reference so it won't change the connection to front of list)
		nodeCount++;
	}

	cout << "--------" << endl;
}

// Pre-condition: Input a pointer (by reference) to the first node in a linked list
// Post-condition: Inserts a node into an existing linked list (if position is valid)
void insertNodeAfter(LinkNodePtr& h) {
	// If head is pointing to null the list is empty and can't be inserted into
	if (h == nullptr)
	{
		cout << "Cannot insert in a non-existing link." << endl;
		return;
	}

	// Take user position (negative to exit)
	int pos;
        cout << "Enter node position to insert new node after (enter negative number to exit): ";
        cin >> pos;

	if (pos < 0)
		return;

	LinkNodePtr cur_ptr = h; // Copy headptr for safe iteration and retain connection to front of list
	for (int i = 0; i < pos && cur_ptr != nullptr; i++) // Asked AI if for loops can have multiple conditionals
	        cur_ptr = cur_ptr->link; // Increment current pointer according to user input
	
	// If user sent current pointer past linked list (null) it is an invalid position
	if (cur_ptr == nullptr)
	{
		cout << "Position entered is illegal. Nothing inserted." << endl;
		return;
	}

	// Takes user data for new node
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

// Pre-condition: Enter the head pointer to a linked list
// Post-condition: Finds and prints the largest number in the linked list
void findMax(LinkNodePtr h) {
    	if (h == nullptr)
	{
		cout << "This list is empty." << endl;
        	return;
	}

    	int max = h->number;
    	LinkNodePtr cur_ptr = h->link;

	// Iterate until we are at the end of the list
    	while (cur_ptr != nullptr)
    	{
		if(cur_ptr->number > max)
			max = cur_ptr->number;
		 cur_ptr = cur_ptr->link;
    	}
    	cout << "Largest number in the list is: " << max << endl;
}

// Pre-condition: Enter the head pointer to a linked list
// Post-condition: Finds and prints the smallest number in the linked list
void findMin(LinkNodePtr h) {
    	if (h == nullptr)
	{
		cout << "This list is empty." << endl;
                return;
	}

        int min = h->number;
        LinkNodePtr cur_ptr = h->link;
        
	// Iterate untilr we are at the end of the list
	while (cur_ptr != nullptr)
        {
                if(cur_ptr->number < min)
                        min = cur_ptr->number;
                 cur_ptr = cur_ptr->link;
        }
    	cout << "Smallest number in the list is: " << min << endl;
}
