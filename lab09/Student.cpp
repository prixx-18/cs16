#include "Student.h"
#include <sstream> // for ostringstream

// Overloaded constructor that initializes
Student::Student(int p, string lName, string fName) {
	perm = p; 
	lastName = lName;
	firstAndMiddleNames = fName;
	// Initializes all private member variables to user inputted parameters
}

int Student::getPerm() { 
  return perm; // Simply returns perm number (accessor)
}

string Student::getLastName() { 
  return lastName; // Simply returns lastName (accessor)
}

string Student::getFirstAndMiddleNames() { 
  return firstAndMiddleNames; // Simply returns first and middle names (accessor)
}

string Student::getFullName() { 
  return firstAndMiddleNames + " " + lastName; // Simply returns first, middle, and last name (accessor)
}

// THIS MEMBER FUNCTION IS DEFINED FOR YOU ALREADY:
// DO NOT CHANGE IT
string Student::toString()  { 
  // e.g. [12345,Smith,Malory Logan]
  ostringstream oss;
  
  oss << "[" 
      << getPerm() << ","
      << getLastName() << ","
      << getFirstAndMiddleNames() << "]";
  return oss.str();
} 


