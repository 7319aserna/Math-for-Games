#include "vec2.h"
#include <vector>
#pragma once

struct vec3 {
	  // ---------------------------------------- //
	 // -----***** Points and Vectors *****----- //
	// ---------------------------------------- //
	float x, y, z;

	vec3();
	vec3(float x, float y, float z);

	// vec3 Unary addition operator overload (vec3 + vec3)
	vec3 operator+(const vec3 &rhs) const;

	// vec3 Unary subtraction operator overload (vec3 - vec3)
	vec3 operator-(const vec3 &rhs) const;

	// vec3 Compound addition assignment operator overload...
	// (vec3 += vec3) (Assigns the sum of the two values to the...
	// other.)
	vec3 &operator+=(const vec3 &rhs);

	// vec3 Compound subtraction assignment operator overload...
	// (vec3 -= vec3)
	vec3 &operator-=(const vec3 &rhs);

	// vec3 Equality operator overload (vec3 == vec3) 
	bool operator==(const vec3 &rhs) const;

	// vec3 Inequality operator overload (vec3 != vec3) 
	bool operator!=(const vec3 &rhs) const;

	// If a vector has a subtraction sign before it, would make that thing a negative
	vec3 operator-() const;

	// Converting a 3D vector as an array of floats
	operator float *();
	operator const float *() const;

	bool operator<(const float &rhs) const;
	bool operator>(const float &rhs) const;

	// Raylib Support
	// vec3 type definition
	#ifdef RAYLIB_H
	// constructor vec3 from Vector3
	vec3(Vector3 vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}
	// convert from Vector3 to vec3
	vec3& operator =(const Vector3 &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;

		return  *this;
	}
	// convert from vec3 to Vector3
	operator Vector3() {
		return { x, y, z };
	}
	#endif // RAYLIB_H
	
	  // ------------------------------------------------- //
	 // -----***** Magnitude and Normalization *****----- //
	// ------------------------------------------------- //
	// Length of a Vector
	float magnitude() const;

	// Modify a Vector so that its Magnitude is equal to 1
	vec3 &normalize();
	vec3 getNormalized() const;

	// Multiplying a Vector by a Vector
	vec3 &scale(const vec3 &rhs);
	vec3 getScaled(const vec3 &rhs) const;

	// Multiplying a Vector by a Scalar
	vec3 operator*(const float rhs) const;

	// Dividing a Vector by a float
	vec3 operator/(const float rhs) const;

	// Float * Vector_Two
	friend vec3 operator*(const float lhs, const vec3 &rhs);

	// Vec3 multiplication assignment operator overload
	vec3 &operator*=(const float rhs);

	// Vec3 division assignment operator overload
	vec3 &operator/=(const float rhs);

	  // ------------------------------------------- //
	 // -----***** Dot and Cross Product *****----- //
	// ------------------------------------------- //
	float dot(const vec3 &rhs) const;

	// Cross Product
	vec3 cross(const vec3 &rhs) const;
};

  // ------------------------------ //
 // -----***** Matrices *****----- //
// ------------------------------ //
struct mat3 {
	union {
		// Implementation One
		struct {
			vec3 xAxis;
			vec3 yAxis;
			vec3 zAxis;
		};
		vec3 axis[3];
		// Implementation Two
		struct {
			float m1, m2, m3,
				  m4, m5, m6,
				  m7, m8, m9;
		};
		// Implementation Three
		struct {
			float m[9];
		};
		// Implementation Four
		struct {
			float mm[3][3]; 
		};
	};
	// Initialize all members to zero
	mat3();

	// Pointer to an array that contains nine elements
	mat3(float *ptr);

	mat3(float m1, float m2, float m3,
		 float m4, float m5, float m6,
		 float m7, float m8, float m9);

	// Implicit operator to convert mat3 into a float array
	operator float *();
	operator const float *() const;

	// Returns vec3 objects when accessing by subscript operator
	vec3 &operator[](const int index);
	const vec3 &operator[](const int index) const;

	// Concatenates two matrices together and returns the result
	mat3 operator*(const mat3 &rhs) const;

	// Concatenates and assigns the result to the matrix
	mat3 &operator *=(const mat3 &rhs);

	// Returns true if the matrices are equal
	bool operator==(const mat3 &rhs) const;

	// Returns true if the matrices are inequal
	bool operator!=(const mat3 &rhs) const;

	// Returns a 3x3 identity matrix
	static mat3 identity();

	// Updates the matrix elements with the given values
	void set(float m1, float m2, float m3,
			 float m4, float m5, float m6,
			 float m7, float m8, float m9);

	// Updates the matrix elements with the given values from the given array
	void set(float *ptr);

	// Transposes the matrix (A, B, C,		(A, D, G,
	//						  D, E, F,	->	 B, E, H,
	//						  G, H, I)       C, F, I)
	void transpose();

	// Returns a transposed copy of the matrix (A, B, C,		(A, D, G,
	//											D, E, F,	->	 B, E, H,
	//										    G, H, I)		 C, F, I)
	mat3 getTranspose() const;

	// Reverses the matrix
	void reverse();

	// Returns a reversed copy of the matrix
	mat3 getReverse() const;

	  // --------------------------------------- //
	 // -----***** Matrix Transforms *****----- //
	// --------------------------------------- //
	// Returns a translation matrix with the given changes for each axis
	static mat3 translation(float x, float y);
	
	// Returns a translation matrix with the given changes for each axis
	static mat3 translation(const vec2 &vec);
	
	// Returns a rotation matrix with the given rotation
	static mat3 rotation(float rot);
	
	// Returns a translation matrix with the given changes for each axis
	static mat3 scale(float xScale, float yScale);
	
	// Returns a translation matrix with the given changes for each axis
	static mat3 scale(const vec2 &vec);

	// Transforms a 3D vector by performing 3x3 x 3x1 matrix multiplication
	vec3 operator*(const vec3 &rhs) const;

	// Convenience function for transforming a 2D vector
	vec2 operator*(const vec2 &rhs) const;
};

struct transform2d {
	transform2d();

	vec2 localPos;
	float localRot;
	vec2 localScale;

	void translate(const vec2 &offset);	
	void translate(float x, float y);
	void rotate(const float angle);

	/*void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);*/

	mat3 getTRSMatix() const;

	  // ----------------------------------------- //
	 // -----***** Matrix Hierarchies *****------ //
	// ----------------------------------------- //
	vec2 worldPosition() const;               // World position of this object
	float worldRotation() const;              // World rotation of this object
	vec2 worldScale() const;                  // World scale of this object (lossy)

	void setParent(transform2d *parent);      // Assigns a parent to this object
	transform2d *getParent();                 // Returns a pointer to its parent
	transform2d const *getParent() const;     // Returns a pointer to its parent (const-qualified)

	transform2d **getChildren();              // Returns a pointer to the first child
	transform2d *const* getChildren() const;  // Returns a pointer to the first child (const-qualified)
	size_t getChildrenCount() const;          // Returns the number of children available

private:
	transform2d * parent;                     // Pointer to parent
	std::vector<transform2d *> children;      // Vector containing pointers to all children
};

// (Float * Vector_Three) When implementing binary operator overloads for...
// a type, we can only accept the right-hand side object as a...
// parameter. If we would instead like to overload the functionality in...
// the situation where our object is on the right-hand side, we need...
// to define it externally.
vec3 operator*(const float lhs, const vec3 &rhs);