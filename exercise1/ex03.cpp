#include <iostream>
using namespace std;

//Phase 1
/*class String {
public:
	String(const char* string = "");
	void list();

private:
	char c_string[11];
};

void f(String s);

void main() {
	String s("abcdefg");
	s.list();
	f(s);
	s.list();
}

String::String(const char* string) {
	strcpy_s(c_string, 11, string);
}

void String::list() {
	cout <<c_string << endl;
}

void f(String s) {
	s.list();
}*/

//Phase 2
/*class String {
public:
	String(const char* string = "");
	~String();
	void list();

private:
	char *c_string;
};

void f(String s);//in Phase 3 void f(String &s);

void main() {
	String s("abcdefg");
	s.list();
	f(s);
	s.list();
}

String::String(const char* string) {
	c_string = new char[strlen(string) + 1];
	strcpy_s(c_string, strlen(string) + 1, string);
}

String::~String() {
	delete[] c_string;
	cout << "destructor done" << endl;
}

void String::list() {
	cout << c_string << endl;
}

void f(String s) { //in Phase 3 f(String &s)
	s.list();
}*/

//Phase 4

class String {
public:
	String(const char* string = "");
	String(const String &s);
	~String();
	void list();

private:
	char* c_string;
};

void f(String s);

void main() {
	String s("abcdefg");
	s.list();
	f(s);
	s.list();
}

String::String(const char* string) {
	c_string = new char[strlen(string) + 1];
	strcpy_s(c_string, strlen(string) + 1, string);
}

String::~String() {
	delete[] c_string;
	cout << "destructor done" << endl;
}

String::String(const String &s) {
	c_string = new char[strlen(s.c_string) + 1];
	strcpy_s(c_string, strlen(s.c_string) + 1, s.c_string);
}

void String::list() {
	cout << c_string << endl;
}

void f(String s) { 
	s.list();
}