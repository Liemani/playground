#include <iostream>
#include "05_programming_exercise_9_1.hpp"

void	setgolf(golf& golf, const char* name, int handicap) {
	strcpy(golf.fullname, name);
	golf.handicap = handicap;
}

int		setgolf(golf& golf) {
	using std::cin;
	using std::cout;;

	cout << "Enter golf fullname: ";
	cin.get(golf.fullname, Len);
	if (!cin) {
		if (cin.eof())
			return 0;
		cin.clear();
		if (cin.get() == '\n')
			return 0;
	}
	while (cin.get() != '\n' and cin);
	if (!cin)
		return 0;
	cout << "Enter golf handicap: ";
	cin >> golf.handicap;
	if (!cin)
		return 0;
	cin.get();
	return 1;
}

void	handicap(golf& golf, int handicap) {
	golf.handicap = handicap;
}

void	showgolf(const golf& golf) {
	using std::cout;
	using std::endl;

	cout << "golf:" << endl;
	cout << "	fullname: " << golf.fullname << endl;
	cout << "	handicap: " << golf.handicap << endl;
}
