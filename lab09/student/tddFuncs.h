#ifndef TDDFUNCS_H
#define TDDFUNCS_H

#include <string>
using namespace std;

void assertEquals(string expected, 
		  string actual, 
		  string message="");

void assertEquals(int expected, 
		  int actual, 
		  string message="");


#define ASSERT_EQUALS(expected,actual) assertEquals(expected,actual,#actual)


void assertTrue(bool expression, string message="");

#define ASSERT_TRUE(expression) assertTrue(expression,#expression)

#endif // TDDFUNCS_H
