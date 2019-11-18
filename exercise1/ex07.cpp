#include <fstream>
#include <iostream>
#include <string>
#include "counter.h"
using namespace std;

class LimitedCounter {
	private:
		int limit;
		Counter counter;

	public:
		LimitedCounter(int n = 0, int newlimit = 0);
		int getCount() const;
		void setLimit(int const limit);
		void reset();
		LimitedCounter& operator++();
		LimitedCounter operator++(int);
		bool operator<(int const x) const;
		friend ostream& operator<<(ostream& out, const LimitedCounter& lc);
};

int main() {
	LimitedCounter lc(0, 5);  //initial value 0, upper limit 5
	cout << lc++ << endl;  //output should be 0       
	cout << ++lc << endl;  //output should be 2      
	lc.reset();
	for (int i = 0; i < 9; i++) {
		lc++;
		cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5       
	}
	cout << lc.getCount() << endl; //output is 5      
	cout << (lc < 7);//Testing the comparison operator //output is 1       
	cout << (lc < 1);//Testing the comparison operator //output is 0       
	return 0;
}

LimitedCounter::LimitedCounter(int n , int newlimit ) : counter(n) {
	limit = newlimit;
}
int LimitedCounter::getCount() const {
	return counter.getCount();
}
void LimitedCounter::setLimit(int const newlimit) {
	limit = newlimit;
}
void LimitedCounter::reset() {
	counter.reset();
}

LimitedCounter& LimitedCounter::operator++() {
	if (counter.getCount() < limit)
		counter++;
	return *this;
}

LimitedCounter LimitedCounter::operator++(int) {
	LimitedCounter old(*this);
	if (counter.getCount() < limit)
		counter++;
	return old;
}

bool LimitedCounter::operator<(int const x) const {
	return counter.getCount() < x;
}

 ostream& operator<<(ostream& out, const LimitedCounter& lc) {
	out << lc.counter.getCount();
	return out;
}

