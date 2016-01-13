#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <string>

class MyString 
{
	public:
		MyString(); //Default constructor
		~MyString() {}; // Destructor
		MyString(const char* ch);
		MyString(const MyString&); // Copy Constructor
		
		int length() const;
		MyString& operator=(const MyString& s); // Assignment operator
		MyString& operator=(const char* ch);
		MyString operator+(const MyString& s); // Concatenation operator
		MyString operator+=(const MyString& s);
		char& operator[](int pos); // Return character at a position
		bool operator<(const MyString& s);
		bool operator>(const MyString& s);
		bool operator==(const MyString& s);
		bool operator!=(const MyString& s);
		friend std::ostream& operator<<(std::ostream& os, const MyString& s);
	private:
		std::unique_ptr<char[]> mData;
};

#endif