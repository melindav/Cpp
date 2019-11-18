#include <iostream>
#include <cstdlib>;
#include <ctime>;
using namespace std;


class  Dice {
	public:
		float roll();
		void initialize();
};

class  Counter {
	public:
		int getCount();
		void increment();
		void reset();
	private:
		int count;

};

class  Inspector {
	public:
		bool isInLimits(float number);
		void setLimits(float upperLimit, float lowerLimit);
	private:
		float max;
		float min;

};
int main() {
	Dice dice;
	Counter counter1, counter2, i;
	Inspector inspector;
	dice.initialize();
	counter1.reset();
	counter2.reset(), i.reset();
	inspector.setLimits(0.0, 0.5);
	while (i.getCount() < 100) {
		if (inspector.isInLimits(dice.roll()))
			counter1.increment(); 
		else     
			counter2.increment(); 
		i.increment(); 
	}   
	cout << counter1.getCount() << endl; 
	cout << counter2.getCount() << endl;
	return 0;
}

void Counter::reset() {
	count = 0; 
}
void Counter::increment() { 
	count++;
	/*if (count < 999999999)
		count++;
	else {
		reset();
		cout << "Counter roundup happened" << endl; 
	}*/
	
}
int Counter::getCount() {
	return count;
}
float Dice::roll() {
	return (float)rand()/RAND_MAX;
}
void Dice::initialize() {
	srand(time(NULL));
}
void Inspector::setLimits(float upperLimit, float lowerLimit) {
	max = upperLimit;
	min = lowerLimit;
}
bool Inspector::isInLimits(float number) {
	if (number < max && number > min)
		return true;
	else
		return false;
}
