all: vertical palindrome selectionSort

vertical: vertical.cpp
	g++ vertical.cpp -o vertical -std=c++17 -Wall

palindrome: palindrome.cpp pfunctions.cpp
	g++ palindrome.cpp pfunctions.cpp -o palindrome -std=c++17 -Wall

selectionSort: selectionSort.cpp sfunctions.cpp
	g++ selectionSort.cpp sfunctions.cpp -o selectionSort -std=c++17 -Wall

clean:
	rm -f *.o vertical palindrome selectionSort

