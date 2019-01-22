#include "library.h"

int myMath::sum(int a, int b) {
	return a + b;
}

int myMath::min(int a, int b) {
	return a < b ? a : b;
}

int myMath::max(int a, int b) {
	return a > b ? a : b;
}

int myMath::clamp(int value, int min, int max) {
	return value < min | value > max ? value = min : value = max;
}

const double myMath::DEG_TO_RAD(const double degrees) {
	return degrees * PI / 180;
}

const double myMath::RAD_TO_DEG(const double radians) {
	return radians * 180 / PI;
}

// unsigned long long int
int myMath::pow(int base, int power) {
	// unsigned long long int
	int currentNumber = base;
	for (int i = 0; i < power - 1; i++) {
		currentNumber = currentNumber * base;
	}
	return currentNumber;
}