#include "MyString.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

MyString::MyString()
{
	mData = std::unique_ptr<char[]>(new char[1]);
	*(mData.get()) = '\0';
}

MyString::MyString(const char* ch)
{
	int len = std::strlen(ch);
	mData = std::unique_ptr<char[]>(new char[len+1]);
	std::strcpy(mData.get(), ch);
}

MyString::MyString(const MyString& s)
{
	int len = s.length();
	mData = std::unique_ptr<char[]>(new char[len+1]);
	std::strcpy(mData.get(), s.mData.get());
}

int MyString::length() const
{
	return strlen(mData.get());
}

MyString& MyString::operator=(const MyString& s)
{
	if (&s == this)
	{
		return *this;
	}
	int len = s.length();
	mData.reset(new char[len+1]);
	std::strcpy(mData.get(), s.mData.get());
	return *this;
}

MyString& MyString::operator=(const char* ch)
{
	int len = std::strlen(ch);
	mData.reset(new char[len+1]);
	std::strcpy(mData.get(), ch);
	return *this;	
}

MyString MyString::operator+(const MyString& s)
{
	MyString tmp;
	int len = s.length();
	tmp.mData = std::unique_ptr<char[]>(new char[length()+len+1]);
	strcpy(tmp.mData.get(), mData.get());
	strcat(tmp.mData.get(), s.mData.get());
	return tmp;

}

MyString MyString::operator+=(const MyString& s)
{
    const char* tmp = mData.get();
    int len = s.length();
	mData.reset(new char[length()+len+1]);
	strcpy(mData.get(), tmp);
	strcat(mData.get(), s.mData.get());
	return *this;
}

char& MyString::operator[](int pos)
{
	if (pos >= length())
	{
		std::cout << "Invalid string index!\n";
		exit(0);
	}
	return mData.get()[pos];
}

bool MyString::operator<(const MyString& s)
{
	return (strcmp(mData.get(), s.mData.get()) < 0);
}

bool MyString::operator>(const MyString& s)
{
	return (strcmp(mData.get(), s.mData.get()) > 0);
}

bool MyString::operator==(const MyString& s)
{
	return (strcmp(mData.get(), s.mData.get()) == 0);
}

bool MyString::operator!=(const MyString& s)
{
	return (strcmp(mData.get(), s.mData.get()) != 0);
}

std::ostream& operator<<(std::ostream& os, const MyString& s)
{
	return os << s.mData.get();
}

