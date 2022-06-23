#include <iostream>
#include "06_programming_exercise_9_4.hpp"

namespace SALES {
	void	setSales(Sales& s, const double ar[], int n) {
		int	i;

		s.average = 0;
		s.max = ar[0];
		s.min = ar[0];
		for (i = 0; i < QUARTERS and i < n; ++i) {
			s.sales[i] = ar[i];
			s.average += ar[i];
			if (ar[i] > s.max)
				s.max = ar[i];
			if (ar[i] < s.min)
				s.min = ar[i];
		}
		s.average /= i;
		while (i < QUARTERS) {
			s.sales[i] = 0;
			++i;
		}
	}

	void	setSales(Sales& s) {
		using std::cin;
		using std::cout;
		using std::endl;

		int		i;
		double	input;

		s.average = 0.0;
		s.max = 0.0;
		s.min = 0.0;
		cout << "Enter up to 4 quater sales:" << endl;
		for (i = 0; i < QUARTERS and cin >> input; ++i) {
			s.sales[i] = input;
			s.average += (input - s.average) / (i + 1);
			if (i == 0) {
				s.max = input;
				s.min = input;
			}
			if (input > s.max)
				s.max = input;
			if (input < s.min)
				s.min = input;
		}
		for (; i < QUARTERS; ++i)
			s.sales[i] = 0;
	}

	void	showSales(const Sales& s) {
		using std::cout;
		using std::endl;

		cout << "sales:" << endl;
		cout.setf(std::ios::fixed);
		cout << std::setprecision(1);
		for (int i = 0; i < QUARTERS; ++i)
			cout << s.sales[i] << endl;
		cout << "	average: " << s.average << endl;
		cout << "	max: " << s.max << endl;
		cout << "	min: " << s.min << endl;
	}
}
