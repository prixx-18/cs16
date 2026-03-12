/* file: Student.h for use with Student
 * 
 * DO NOT CHANGE ANYTHING IN THIS FILE!
 *  
 *  The class Student is defined for you here.
 *  Look this over carefully and then define the member functions in Student.cpp
 *
 */
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {

 public:
  Student(int perm, 
	   string lastName, 
	   string firstAndMiddleNames);

  int getPerm();

  string getLastName();
  string getFirstAndMiddleNames();
  string getFullName();
  string toString();

 private:
  int perm;
  string lastName;
  string firstAndMiddleNames;
};

#endif // STUDENT_H
