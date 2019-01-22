#include "vec3.h"
#pragma once

struct vec4 {
	  // ---------------------------------------- //
	 // -----***** Points and Vectors *****----- //
	// ---------------------------------------- //
	float x, y, z, w;

	vec4();
	vec4(float x, float y, float z, float w);

	// vec4 Unary addition operator overload (vec4 + vec4)
	vec4 operator+(const vec4 &rhs) const;

	// vec4 Unary subtraction operator overload (vec4 - vec4)
	vec4 operator-(const vec4 &rhs) const;

	// vec4 Compound addition assignment operator overload...
	// (vec4 += vec4) (Assigns the sum of the two values to the...
	// other.)
	vec4 &operator+=(const vec4 &rhs);

	// vec4 Compound subtraction assignment operator overload...
	// (vec4 -= vec4)
	vec4 &operator-=(const vec4 &rhs);

	// vec4 Equality operator overload (vec4 == vec4) 
	bool operator==(const vec4 &rhs) const;

	// vec4 Inequality operator overload (vec4 != vec4) 
	bool operator!=(const vec4 &rhs) const;

	// If a vector has a subtraction sign before it, would make that thing a negative
	vec4 operator-() const;

	// Converting a 4D vector as an array of floats
	operator float *();
	operator const float *() const;

	bool operator<(const float &rhs) const;
	bool operator>(const float &rhs) const;

	// Raylib Support
	// vec4 type definition
	#ifdef RAYLIB_H
	// constructor vec4 from Vector4
	vec4(Vector4 vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;
	}
	// convert from Vector4 to vec4
	vec4& operator =(const Vector4 &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;

		return  *this;
	}
	// convert from vec4 to Vector4
	operator Vector4() {
		return { x, y, z, w };
	}
	#endif // RAYLIB_H

	  // ------------------------------------------------- //
	 // -----***** Magnitude and Normalization *****----- //
	// ------------------------------------------------- //
	// Length of a Vector
	float magnitude() const;
	
	// Modify a Vector so that it's Magnitude is equal to One
	vec4 &normalize();
	vec4 getNormalized() const;

	// Multiplying a Vector by a Vector
	vec4 &scale(const vec4 &rhs);
	vec4 getScaled(const vec4 &rhs) const;

	// Multiplying a Vector by a Scalar
	vec4 operator*(const float rhs) const;

	// Dividing a Vector by a float
	vec4 operator/(const float rhs) const;

	// Float * Vector_Four
	friend vec4 operator*(const float lhs, const vec4 &rhs);

	// Vec3 multiplication assignment operator overload
	vec4 &operator*=(const float rhs);

	// Vec3 division assignment operator overload
	vec4 &operator/=(const float rhs);

	  // ------------------------------------------- //
	 // -----***** Dot and Cross Product *****----- //
	// ------------------------------------------- //
	float dot(const vec4 &rhs) const;

	// Cross Product
	vec4 cross(const vec4 &rhs) const;
};

  // ------------------------------ //
 // -----***** Matrices *****----- //
// ------------------------------ //
struct mat4 {
	union {
		// Implementation One
		struct {
			vec4 xAxis;
			vec4 yAxis;
			vec4 zAxis;
			vec4 wAxis;
		};
		vec4 axis[4];
		// Implementation Two
		struct {
			float m1, m2, m3, m4,
				  m5, m6, m7, m8,
				  m9, m10, m11, m12,
				  m13, m14, m15, m16;
		};
		// Implementation Three
		struct {
			float m[16];
		};
		// Implementation Four
		struct {
			float mm[4][4];
		};
	};
	// Initialize all members to zero
	mat4();

	// Pointer to an array that contains nine elements
	mat4(float *ptr);

	mat4(float m1, float m2, float m3, float m4, 
		 float m5, float m6, float m7, float m8, 
		 float m9, float m10, float m11, float m12,
		 float m13, float m14, float m15, float m16);

	// Implicit operator to convert mat4 into a float array
	operator float *();

	// Returns vec4 objects when accessing by subscript operator
	vec4 &operator[](const int index);
	const vec4 &operator[](const int index) const;

	// Concatenates two matrices together and returns the result
	mat4 operator*(const mat4 &rhs) const;

	// Concatenates and assigns the result to the matrix
	mat4 &operator *=(const mat4 &rhs);

	// Returns true if the matrices are equal
	bool operator==(const mat4 &rhs) const;

	// Returns true if the matrices are inequal
	bool operator!=(const mat4 &rhs) const;

	// Returns a 4x4 identity matrix
	static mat4 identity();

	// Updates the matrix elements with the given values
	void set(float m1, float m2, float m3, float m4,
			 float m5, float m6, float m7, float m8,
		     float m9, float m10, float m11, float m12,
		     float m13, float m14, float m15, float m16);

	// Updates the matrix elements with the given values from the given array
	void set(float *ptr);

	// Transposes the matrix
	void transpose();

	// Returns a transposed copy of the matrix
	mat4 getTranspose() const;

	// Reverses the matrix
	void reverse();

	// Returns a reversed copy of the matrix
	mat4 getReverse() const;

	  // --------------------------------------- //
	 // -----***** Matrix Transforms *****----- //
	// --------------------------------------- //
	// Returns a translation matrix with the given changes for each axis
	static mat4 translation(float x, float y, float z);
	
	// Returns a translation matrix with the given changes for each axis
	static mat4 translation(const vec3 &vec);
	
	// Returns a rotation matrix with the given rotation
	static mat4 rotationX(float xRotation);
	
	// Returns a rotation matrix with the given rotation
	static mat4 rotationY(float yRotation);
	
	// Returns a rotation matrix with the given rotation
	static mat4 rotationZ(float zRotation);
	
	// Returns a rotation matrix with the given rotation
	static mat4 rotation(float x, float y, float z);
	
	// Returns a translation matrix with the given changes for each axis
	static mat4 scale(float xScale, float yScale, float zScale);
	
	// Returns a translation matrix with the given changes for each axis
	static mat4 scale(const vec3 &vec);

	// Transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
	vec4 operator*(const vec4 &rhs) const;
	
	// Convenience function for transforming a 3D vector
	vec3 operator*(const vec3 &rhs) const;
};

// (Float * Vector_Four) When implementing binary operator overloads for...
// a type, we can only accept the right-hand side object as a...
// parameter. If we would instead like to overload the functionality in...
// the situation where our object is on the right-hand side, we need...
// to define it externally.
vec4 operator*(const float lhs, const vec4 &rhs);