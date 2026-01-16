#ifndef __MYSTRING__
#define __MYSTRING__

#include <iostream>

class MyString
{
private:
    char* data;
    unsigned int length;

    //static methods
    static void init_from(MyString* self, const char * const text);
    static void init_from(MyString* self, const MyString& other);

public:

    
    // constructors/destructors
    MyString();
    MyString(const char * const text);
    MyString(const MyString& other);
    ~MyString();

    // setgets
	unsigned int size() const;

    // operators
    MyString operator=(const MyString& other);
    MyString operator=(const char * const text);
    bool operator==(const MyString& other);
    bool operator==(const char * const text);
    bool operator!=(const MyString& other);
    bool operator!=(const char * const text);
    MyString operator+(const MyString& other);
    MyString operator+(const char * const text);
    MyString operator+=(const MyString& other);
    MyString operator+=(const char * const text);
    char operator[](const unsigned int i) const;
    operator char*() const;

	friend std::ostream& operator<<(std::ostream& stream, const MyString& mystr);
	friend std::istream& operator>>(std::istream& stream, MyString& mystr);
};


#endif