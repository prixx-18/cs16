class AString {
	public:
		AString(); // Default constructor
		AString(string inputString); // Overloaded constructor that initializes StringValue
		string getStringValue(); // Accessor
		void cleanUp(); // Public member function that cleans strings
		void countLetters(int arr[]); // Public member function that counts letter occurances in an int array
		void getAString(); // Public member function that gets string from user
	private:
		string StringValue; // Private member variable
};

// DO NOTE CHANGE THESE AND DO NOT ADD TO THEM!
bool compareCounts(int a[], int b[]);
const int ARRAYSIZE = 26;

