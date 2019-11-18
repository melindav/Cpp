#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string find_page(string const &page, string const text);

int main(void) {

	string page, line, location, temperature;
	ifstream inputFile("weather.xml");

	while (getline(inputFile, line)) {
		page.append(line);
		line.erase();
	}
	// Now page is a string that contains the whole xml page

	// Here you need to write something that finds and 
	// extracts location and temperature from the XML
	// data in the string page and stores them in 
	// the strings location and temperature respectively

	location = find_page(page, "location");
	temperature = find_page(page, "temp_c");

	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl;
	system("pause");
}

string find_page(string const& page, string const text) {

	
    auto pos1 = page.find("<" + text + ">") + text.length() +2;
	auto pos2 = page.find("</" + text + ">");
	if ((pos1 - text.length() -2) == pos2) {
		return "Not found.";
	}
	return page.substr(pos1, pos2 - pos1);
}