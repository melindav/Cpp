#include <iostream>
using namespace std;

class String {
	friend ostream& operator<<(ostream& out, const String& s);
public:
	String(const char* string = "");
	String(const String& s);
	~String();
	void list();
	const String& operator=(const String &s);
	String operator+(const String& s);
	String& operator++();    // pre-increment  
	String operator++(int);   //post-increment
	char& operator[](int i);

private:
	char* c_string;
};

void f(String s);

/*int main() {
	String s1("abcedf");
	String s2("ghijklmn");
	String sum;
	cout << "String 1 is:" << s1 << endl;
	cout << "String 2 is:" << s2 << endl;
	sum = s1 + s2;
	cout << "Sum is :" << sum; 
							      
	sum = sum; 
	cout << "Sum is still :" << sum; 

	return 0;
}*/

int main() {
	String s("abcdefg");
	cout << s++ << endl;
	cout << ++s << endl;
	return 0;
}

/*int main() {
	String s("abcdefg");
	for (int i = 0; i < 7; i++)
		cout << s[i] << " ";
	s[4] = 'X';
	for (int i = 0; i < 7; i++)
		cout << s[i] << " ";
	return 0;
}*/

String::String(const char* string) {
	c_string = new char[strlen(string) + 1];
	strcpy_s(c_string, strlen(string) + 1, string);
}

String::~String() {
	delete[] c_string;
	cout << "destructor done" << endl;
}

String::String(const String& s) {
	c_string = new char[strlen(s.c_string) + 1];
	strcpy_s(c_string, strlen(s.c_string) + 1, s.c_string);
}

void String::list() {
	cout << c_string << endl;
}

void f(String s) {
	s.list();
}

const String& String::operator=(const String& s) {
	if (this != &s) {//avoid damages in self assignment
		delete[] c_string;
		c_string = new char[strlen(s.c_string) + 1];
		strcpy_s(c_string, strlen(s.c_string) + 1, s.c_string);  
	}  
	return *this; 
}
ostream& operator<<(ostream& out, const String& s) { 
	out << s.c_string << endl;
	return out;
}
String String::operator+(const String& s) {
	String s3; 
	delete s3.c_string;
	s3.c_string = new char[strlen(c_string) + strlen(s.c_string) + 1];
	strcpy_s(s3.c_string, strlen(c_string) + strlen(s.c_string) + 1, c_string);
	strcat_s(s3.c_string, strlen(c_string) + strlen(s.c_string) + 1, s.c_string);
	return s3;
}
String& String::operator++() { 
	String s3;
	delete s3.c_string;

	s3.c_string = new char[strlen(c_string) + 2];
	strcpy_s(s3.c_string, strlen(c_string) + 2, c_string);
	strcat_s(s3.c_string, strlen(c_string) + 2, "X");
	swap(c_string, s3.c_string);
	return *this;
}
String String::operator++(int) {
	String s3 = *this;
	delete s3.c_string;

	s3.c_string = new char[strlen(c_string) + 2];
	strcpy_s(s3.c_string, strlen(c_string) + 2, c_string);
	strcat_s(s3.c_string, strlen(c_string) + 2, "X");
	swap(c_string, s3.c_string);
	return s3;
}
char& String::operator[](int i)
{
	if (i > strlen(c_string)) {
		cout << "Array out of bounds" << endl;
		return c_string[0];
	}
	return c_string[i];
}