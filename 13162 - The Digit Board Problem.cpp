#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
	int numOfCases = 0;
	cin >> numOfCases;
	long long int* sumOfEachSlots;
	for (int i = 0; i < numOfCases; i++) {
		int numOfSlots = 0;
		int numOfRounds = 0;
		cin >> numOfSlots >> numOfRounds;
		sumOfEachSlots = new long long int[numOfSlots];
		for (int j = 0; j < numOfSlots; j++)sumOfEachSlots[j] = 0;
		for (int j = 0; j < numOfRounds; j++) {
			int slot = -1;
			cin >> slot;
			string s;
			getline(cin, s);
			stringstream ss;
			ss.str(s);
			int toBeInserted = 0;
			while (ss >> toBeInserted) {
				sumOfEachSlots[slot] += toBeInserted;
			}
		}
		long long int sum = 0;
		for (int j = 0; j < numOfSlots; j++) {
			sum += sumOfEachSlots[j] * (int)pow(10, numOfSlots - j - 1);
		}
		cout << sum << endl;
		delete[] sumOfEachSlots;
	}
}