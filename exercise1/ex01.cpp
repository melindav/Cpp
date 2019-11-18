#include<iostream>
#include <stdlib.h> 
using namespace std;

float mean(int* array, int n);

int main()
{
	int numbers = 0;
	int* array;

	cout << "How many numbers you need(give an integer):" << endl;
	cin >> numbers;
	array = new int[numbers];

	for (int i = 0; i < numbers; i++) {
		array[i] = rand() % 100;
		cout << array[i] << endl;
	}
	
	cout << "The mean of the numbers is: " << mean(array, numbers) << endl;

	delete[] array;
	cin.get();
}
	
float mean(int* array, int n) {
		float sum = 0, average = 0;
		for (int i = 0; i < n; i++) {
			sum = sum + array[i];
		}
		average = sum / n;
		return average;
	}
	

	