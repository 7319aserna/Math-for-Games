#include <cfloat>
#include <iostream>
#include "library.h"
#include "vec2.h"

  // ---------------------------------------- //
 // -----***** Points and Vectors *****----- //
// ---------------------------------------- //
vec2::vec2() { }

vec2::vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

// Note: If it is asking for this ((const vec2 & rhs) const), make a temp...
// if not, you edit the x and y values.

// Vec2 Unary addition operator overload (vec2 + vec2)
vec2 vec2::operator+(const vec2 & rhs) const {
	return { x + rhs.x, y + rhs.y };
}

// Vec2 Unary subtraction operator overload (vec2 - vec2)
vec2 vec2::operator-(const vec2 & rhs) const {
	return { x - rhs.x, y - rhs.y };
}

// Vec2 Compound addition assignment operator overload...
// (vec2 += vec2)
vec2 & vec2::operator+=(const vec2 & rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

// Vec2 Compound subtraction assignment operator overload...
// (vec2 -= vec2)
vec2 & vec2::operator-=(const vec2 & rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

// Vec2 Equality operator overload (vec2 == vec2) 
bool vec2::operator==(const vec2 & rhs) const {
	// Take the differences between each member(temp) and compare it...
	// against a threshold. (FLT_EPSILON)
	vec2 temp;
	temp.x = x - rhs.x;
	temp.y = y - rhs.y;

	/*if ((myMath::abs(temp.x) < FLT_EPSILON - .5f) && (myMath::abs(temp.y) < FLT_EPSILON -.5f)) {
		return true;
	}*/
	if (myMath::abs(temp.x) < FLT_EPSILON && myMath::abs(temp.y) < FLT_EPSILON) {
	return true;
	}
	return false;
}

// Vec2 Inequality operator overload (vec2 != vec2) 
bool vec2::operator!=(const vec2 & rhs) const {
	return !(*this == rhs);
}

vec2 vec2::operator-() const {
	return {x * -1, y * -1};
}

// Converting a 2D vector as an array of floats
vec2::operator float*() {
	return &x;
}

vec2::operator const float*() const {
	return &x;
}

bool vec2::operator<(const float & rhs) const {
	if (myMath::abs(x) < rhs && myMath::abs(y) < rhs) {
		return true;
	}
	return false;
}

bool vec2::operator>(const float & rhs) const {
	if (myMath::abs(x) > rhs && myMath::abs(y) > rhs) {
		return true;
	}
	return false;
}

vec2 vec2::getPerpCW() const {
	vec2 perpCW;
	perpCW.x = y;
	perpCW.y = x * -1;
	return perpCW;
}

vec2 vec2::getPerpCCW() const {
	vec2 perpCCW;
	perpCCW.x = y * -1;
	perpCCW.y = x;
	return perpCCW;
}

// Finding an angle between two vectors (If vectors are achored at origin?)
float vec2::angleBetween(const vec2 & rhs) const {
	// Reference: Angle between two vectors (U & V)
	// Cosine? = (U * V (Dot product of U * V)) / ||U|| * ||V|| 
	float dotProductOfUTimesV = this->dot(rhs);
	float magnitudeOfU = this->magnitude();
	float magnitudeOfV = rhs.magnitude();
	float magnitudeOfUAndV = magnitudeOfU * magnitudeOfV;

	// Find inverse?
	float InverseOfUAndV = acos(dotProductOfUTimesV / magnitudeOfUAndV);
	return InverseOfUAndV;
}

  // ------------------------------------------------- //
 // -----***** Magnitude and Normalization *****----- //
// ------------------------------------------------- //
// Length of a Vector
float vec2::magnitude() const {
	// a^2
	float xSqr = x * x;
	// b^2
	float ySqr = y * y;
	// c^2
	float cSqr = xSqr + ySqr;
	// Square root of c
	return sqrtf(cSqr);
	// Or
	//return sqrt(x * x + y * y);
}

// Modify a Vector so that its Magnitude is equal to 1
vec2 & vec2::normalize() {
	// Make Magnitude a variable instead of calling it.
	float normalizeMagnitude = magnitude();
	x /= normalizeMagnitude;
	y /= normalizeMagnitude;
	return *this;
}

vec2 vec2::getNormalized() const {
	vec2 temp;
	float normalizeMagnitude = magnitude();
	temp.x = x / normalizeMagnitude;
	temp.y = y / normalizeMagnitude;
	std::cout << "Normalised Vector = x: " << temp.x << " y: " << temp.y << std::endl;
	return temp;
}

// Multiplying a Vector by a Vector
vec2 & vec2::scale(const vec2 & rhs) {
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

vec2 vec2::getScaled(const vec2 & rhs) const {
	vec2 temp;
	temp.x = x * rhs.x;
	temp.y = y * rhs.y;
	std::cout << "Vector scale = x: " << temp.x << " y: " << temp.y << std::endl;
	return temp;
}

// Multiplying a Vector by a Scalar
vec2 vec2::operator*(const float rhs) const {
	return { x * rhs, y * rhs };
}

// Dividing a Vector by a float
vec2 vec2::operator/(const float rhs) const {
	return { x / rhs, y / rhs };
}

// Float * Vector_Two
vec2 operator*(const float lhs, const vec2 & rhs) {
	// Example Below: 
	// float scalar = 3.5f;
	// vec2 dir = { 0, 1 };
	// vec2 newVelocity = scalar * dir;
	/*vec2 temp;
	temp.x = rhs.x * lhs;
	temp.y = rhs.y * lhs;
	std::cout << "x: " << temp.x << " y: " << temp.y << std::endl;
	return temp;*/
	return { rhs.x * lhs, rhs.y * lhs };
}

// Vec2 multiplication assignment operator overload
vec2 & vec2::operator*=(const float rhs) {
	x *= rhs;
	y *= rhs;
	return *this;
}

// Vec2 division assignment operator overload
vec2 & vec2::operator/=(const float rhs) {
	x /= rhs;
	y /= rhs;
	return *this;
}

  // ------------------------------------------- //
 // -----***** Dot and Cross Product *****----- //
// ------------------------------------------- //
float vec2::dot(const vec2 & rhs) const {
	/*vec2 temp;
	temp.x = x * rhs.x;
	temp.y = y * rhs.y;
	double dotProduct = temp.x + temp.y;
	return dotProduct;*/
	return { x * rhs.x + y * rhs.y };
}