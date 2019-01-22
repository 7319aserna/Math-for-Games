#pragma once

namespace myMath
{
	// Returns the sum of the two values
	int sum(int a, int b);

	// Returns the smaller of the two values
	int min(int a, int b);
		
	// Returns the larger of the two values
	int max(int a, int b);
		
	// Returns a value no smaller than min and no larger than max.
	int clamp(int value, int min, int max);

	// Defined as PI or π
	const double PI = 3.141592653589793238;

	// Multiply this with a angle measure expresses in degrees to...
	// get its equivilant in radians.
	const double DEG_TO_RAD(const double degrees);

	// Multiply this with a angle measure expressed in radians to...
	// get its equivalent in degrees.
	const double RAD_TO_DEG(const double radians);

	template <typename T>
	T abs(T val) {
		return val <= 0 ? val * -1 : val;
	}

	// Returns base to the power of exp (i.e. base^power).
	// unsigned long long int
	int pow(int base, int power);

	  // ----------------------------------- //
	 // -----***** Interpolation *****----- //
	// ----------------------------------- //
	// Linear Interpolation (lerp) (Implementation one)
	template <typename T>
	T lerp(const T& a, const T& b, float t) {
		return a * (1 - t) + b * t;
	}

	// Linear Interpolation (lerp) (Implementation two)
	/*template <typename T>
	T lerp(const T& a, const T& b, float t) {
		return a + (b - a) * t;
	}*/

	  // ---------------------------------------- //
	 // -----***** Curves and Splines *****----- //
	// ---------------------------------------- //
	template <typename T>
	T quadraticBezier(const T& a, const T& b, const T& c, float t) {
		T x = lerp(a, b, t);
		T y = lerp(b, c, t);
		return lerp(x, y, t);
	}

	template <typename T>
	T cubicBezier(const T& a, const T& b, const T& c, const T& d, float t) {
		T x = lerp(a, b, t);
		T y = lerp(b, c, t);
		T z = lerp(c, d, t);
		return quadraticBezier(x, y, z, t);
	}
}