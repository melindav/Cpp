#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class String
{
	friend std::ostream& operator << (std::ostream& os, const String& string);

public:
	static const int max_string_length = 10;
	String(const char* string = "");
	String(const String& s);
	~String();
	void list();
	String operator+ (const String& string) const;
	String& operator++();
	String operator++(int);
	const String& operator = (const String& string);
	char& operator[](int i);
	const char& operator[](int i) const;
	operator const char* ()const;
	static int getN();
private:
	char* c_string;
	static int n;
};

void display(const String& p);


int main(void) {
	
	String s("abcdefgsxxxxxxx"); // MAX_STRING_LENGTH is 10 
	s[2] = 'Y';
	display(s); // outputs the string to the screen
	 
	cout<<String::getN()<<endl;
	{  
		String array[4]; 
		cout<<String::getN()<<endl;
	}    
	cout<<String::getN()<<endl;
	return 0; 
}
int String::n = 0;

void display(const String& p) {
	for (int i = 0; i < String::max_string_length; i++) {
		cout << p[i];
	}
	cout << endl;
	
}

String::String(const char* string) {
	c_string = new char[max_string_length + 1];
	strncpy_s(c_string, max_string_length + 1, string, max_string_length);
	n++;
}

String::String(String const& string) {
	c_string = new char[max_string_length + 1];
	strncpy_s(c_string, max_string_length + 1, string.c_string, max_string_length);
	n++;
}

const String& String::operator = (const String& string) {
	if (this != &string) {
		delete[] c_string;
		c_string = new char[max_string_length + 1];
		strcpy_s(c_string, max_string_length + 1, string.c_string);
	}
	return *this;
}

String String::operator + (String const& string) const {
	String temp;
	temp.c_string = new char[max_string_length + 1];
	strncpy_s(temp.c_string, max_string_length + 1, c_string, max_string_length);
	strncat_s(temp.c_string, max_string_length + 1, string.c_string, max_string_length - strlen(c_string));
	return temp;
}

String::~String() {
	n--;
	delete[] c_string;
}

void String::list() {
	cout << c_string << endl;
}

ostream& operator << (ostream& os, String const& string) {
	os << string.c_string;
	return os;
}

String& String::operator++() {
	char* temp = new char[max_string_length + 1];
	strcpy_s(temp, max_string_length + 1, c_string);
	strcat_s(temp, max_string_length + 1, "X");
	delete[] c_string;
	c_string = temp;
	return *this;
}

String String::operator++(int) {
	String temp(*this);
	delete temp.c_string;
	temp.c_string = new char[max_string_length + 1];
	strcpy_s(temp.c_string, max_string_length + 1, c_string);
	strcat_s(temp.c_string, max_string_length + 1, "X");
	swap(c_string, temp.c_string);
	return temp;
}

char& String::operator[](int i) {
	return c_string[i];
}
const char& String::operator[](int i) const {
	if (i > strlen(c_string)) {
		cout << "Array out of bounds" << endl;
		return c_string[0];
	}
	return c_string[i];
}

String::operator const char* ()const {
	return c_string;
}

int String::getN()
{
	return n;
}


