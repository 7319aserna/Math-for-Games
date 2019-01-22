#pragma once

struct vec2 {
	  // ---------------------------------------- //
	 // -----***** Points and Vectors *****----- //
	// ---------------------------------------- //
	float x, y;
	
	vec2();
	vec2(float x, float y);

	// Vec2 Unary addition operator overload (vec2 + vec2)
	vec2 operator+(const vec2 &rhs) const;

	// Vec2 Unary subtraction operator overload (vec2 - vec2)
	vec2 operator-(const vec2 &rhs) const;
	
	// Vec2 Compound addition assignment operator overload...
	// (vec2 += vec2) (Assigns the sum of the two values to the...
	// other.)
	vec2 &operator+=(const vec2 &rhs);
	
	// Vec2 Compound subtraction assignment operator overload...
	// (vec2 -= vec2)
	vec2 &operator-=(const vec2 &rhs);

	// Vec2 Equality operator overload (vec2 == vec2) 
	bool operator==(const vec2 &rhs) const;

	// Vec2 Inequality operator overload (vec2 != vec2) 
	bool operator!=(const vec2 &rhs) const;

	// If a vector has a subtraction sign before it, would make that thing a negative
	vec2 operator-() const;

	// Converting a 2D vector as an array of floats
	operator float *();
	operator const float *() const;

	bool operator<(const float &rhs) const;
	bool operator>(const float &rhs) const;

	vec2 getPerpCW() const;
	vec2 getPerpCCW() const;

	// Finding an angle between two vectors (If vectors are achored at origin?)
	float angleBetween(const vec2 &rhs) const;

	// Raylib Support
	// vec2 type definition
	#ifdef RAYLIB_H
	// constructor vec2 from Vector2
	vec2(Vector2 vec) {
		x = vec.x;
		y = vec.y;
	}
	// convert from Vector2 to vec2
	vec2& operator =(const Vector2 &rhs) {
		x = rhs.x;
		y = rhs.y;

		return  *this;
	}	
	// convert from ve2 to Vector2
	operator Vector2() {
		return { x, y };
	}
#endif // RAYLIB_H


	  // ------------------------------------------------- //
	 // -----***** Magnitude and Normalization *****----- //
	// ------------------------------------------------- //
	// Length of a Vector
	float magnitude() const;

	// Modify a Vector so that its Magnitude is equal to 1
	vec2 &normalize();
	vec2 getNormalized() const;

	// Multiplying a Vector by a Vector
	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	// Multiplying a Vector by a Scalar
	vec2 operator*(const float rhs) const;

	// Dividing a Vector by a float
	vec2 operator/(const float rhs) const;

	// Float * Vector_Two
	friend vec2 operator*(const float lhs, const vec2 &rhs);

	// Vec2 multiplication assignment operator overload
	vec2 &operator*=(const float rhs);

	// Vec2 division assignment operator overload
	vec2 &operator/=(const float rhs);

	  // ------------------------------------------- //
	 // -----***** Dot and Cross Product *****----- //
	// ------------------------------------------- //
	float dot(const vec2 &rhs) const;
};

// (Float * Vector_Two) When implementing binary operator overloads for...
// a type, we can only accept the right-hand side object as a...
// parameter. If we would instead like to overload the functionality in...
// the situation where our object is on the right-hand side, we need...
// to define it externally.
vec2 operator*(const float lhs, const vec2 &rhs);