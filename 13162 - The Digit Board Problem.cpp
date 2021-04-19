#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
	int numOfCases = 0;
	cin >> numOfCases;
	int* sumOfEachSlots;
	for (int i = 0; i < numOfCases; i++) {
		int numOfSlots = 0;
		int numOfRounds = 0;
		cin >> numOfSlots >> numOfRounds;
		//Create a dynamic array, whose length is the number of slots, to store the sum of each slot.
		sumOfEachSlots = new int[numOfSlots];
		//Initialize the dynamic array.
		for (int j = 0; j < numOfSlots; j++)sumOfEachSlots[j] = 0;

		for (int j = 0; j < numOfRounds; j++) {
			int slot = 0;
			cin >> slot;
			string s;
			//By using getline, spaces can now be loaded into strings.
			getline(cin, s);
			//Initialize a stringstream using an existing string.
			stringstream ss;
			ss.str(s);
			int num = 0;
			//Separate the string into integers with spaces.
			while (ss >> num) {
				sumOfEachSlots[slot] += num;
			}
		}
		//Important!
		//The reason why we're using long long int here is because in the worst case,
		//the sum could be up to 9e12 at maximum.
		//The int datatype can only store 32 bits binary number, from -2^32 to 2^32,
		//that is, -2,147,483,648 to 2,147,483,647 ~ 2.1e9 in decimal.
		//Not enough for 9e12.
		//So we turn to long long int, this datatype can store 64 bits, 2^64 in decimal, approximately
		//9,223,372,036,854,775,807 ~ 9e18
		long long int sum = 0;
		for (int j = 0; j < numOfSlots; j++) {
			//Datatype of sumOfEachSlots is int,
			//and that of pow is double.
			//Don't forget to convert datatypes
			sum += (long long int)sumOfEachSlots[j] * (long long int)pow(10, numOfSlots - j - 1);
		}
		cout << sum << endl;
		//Free memory
		delete[] sumOfEachSlots;
	}
}
