#include <cfloat>
#include <iostream>
#include "library.h"
#include "vec4.h"

  // ---------------------------------------- //
 // -----***** Points and Vectors *****----- //
// ---------------------------------------- //
vec4::vec4() {
}

vec4::vec4(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

// vec4 Unary addition operator overload (vec4 + vec4)
vec4 vec4::operator+(const vec4 & rhs) const {
	return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w };
}

// vec4 Unary subtraction operator overload (vec4 - vec4)
vec4 vec4::operator-(const vec4 & rhs) const {
	return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };
}

// vec4 Compound addition assignment operator overload...
// (vec4 += vec4)
vec4 & vec4::operator+=(const vec4 & rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}

// vec4 Compound subtraction assignment operator overload...
// (vec4 += vec4)
vec4 & vec4::operator-=(const vec4 & rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}

// vec4 Equality operator overload (vec4 == vec4) 
bool vec4::operator==(const vec4 & rhs) const {
	// Take the differences between each member(temp) and compare it...
	// against a threshold. (FLT_EPSILON)
	vec4 temp;

	temp.x = x - rhs.x;
	temp.y = y - rhs.y;
	temp.z = z - rhs.z;
	temp.w = w - rhs.w;
	
	if (myMath::abs(temp.x) < FLT_EPSILON && myMath::abs(temp.y) < FLT_EPSILON && myMath::abs(temp.z) < FLT_EPSILON && myMath::abs(temp.w) < FLT_EPSILON) {
		return true;
	}
	return false;
}

// vec4 Inequality operator overload (vec4 != vec4) 
bool vec4::operator!=(const vec4 & rhs) const {
	return !(*this == rhs);
}

vec4 vec4::operator-() const {
	return { x * -1, y * -1, z * -1, w * -1 };
}

// Converting a 4D vector as an array of floats
vec4::operator float*() {
	return &x;
}

vec4::operator const float*() const {
	return &x;
}

bool vec4::operator<(const float & rhs) const {
	if (myMath::abs(x) < rhs && myMath::abs(y) < rhs && myMath::abs(z) < rhs && myMath::abs(w) < rhs) {
		return true;
	}
	return false;
}

bool vec4::operator>(const float & rhs) const {
	if (myMath::abs(x) > rhs && myMath::abs(y) > rhs && myMath::abs(z) > rhs && myMath::abs(w) > rhs) {
		return true;
	}
	return false;
}

  // ------------------------------------------------- //
 // -----***** Magnitude and Normalization *****----- //
// ------------------------------------------------- //
// Length of a Vector
float vec4::magnitude() const {
	return sqrt(x * x + y * y + z * z + w * w);
}

// Modify a Vector so that its Magnitude is equal to 1
vec4 & vec4::normalize() {
	float normalizeMagnitude = magnitude();
	x /= normalizeMagnitude;
	y /= normalizeMagnitude;
	z /= normalizeMagnitude;
	w /= normalizeMagnitude;
	return *this;
}

vec4 vec4::getNormalized() const {
	vec4 temp;
	float normalizeMagnitude = magnitude();
	temp.x = x / normalizeMagnitude;
	temp.y = y / normalizeMagnitude;
	temp.z = z / normalizeMagnitude;
	temp.w = w / normalizeMagnitude;
	std::cout << "Normalised Vector = x: " << temp.x << " y: " << temp.y << " z: " << temp.z << " w: " << temp.w << std::endl;
	return temp;
}

// Multiplying a Vector by a Vector
vec4 & vec4::scale(const vec4 & rhs) {
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}

vec4 vec4::getScaled(const vec4 & rhs) const {
	vec4 temp;
	temp.x = x * rhs.x;
	temp.y = y * rhs.y;
	temp.z = z * rhs.z;
	temp.w = w * rhs.w;
	std::cout << "Vector scale = x: " << temp.x << " y: " << temp.y << " z: " << temp.z << " w: " << temp.w << std::endl;
	return temp;
}

// Multiplying a Vector by a Scalar
vec4 vec4::operator*(const float rhs) const {
	return { x * rhs, y * rhs, z * rhs, w * rhs };
}

// Dividing a Vector by a float
vec4 vec4::operator/(const float rhs) const {
	return { x / rhs, y / rhs, z / rhs, w / rhs };
}

// Float * Vector_Four
vec4 operator*(const float lhs, const vec4 & rhs) {
	return { rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w * lhs };
}

// Vec4 multiplication assignment operator overload
vec4 & vec4::operator*=(const float rhs) {
	x *= rhs;
	y *= rhs;
	z *= rhs;
	w *= rhs;
	return *this;
}

// Vec4 division assignment operator overload
vec4 & vec4::operator/=(const float rhs) {
	x /= rhs;
	y /= rhs;
	z /= rhs;
	w /= rhs;
	return *this;
}

  // ------------------------------------------- //
 // -----***** Dot and Cross Product *****----- //
// ------------------------------------------- //
// Dot Product
float vec4::dot(const vec4 & rhs) const {
	return { x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w };
}

// Cross Product
vec4 vec4::cross(const vec4 & rhs) const {
	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x, 0 };
}

  // ------------------------------ //
 // -----***** Matrices *****----- //
// ------------------------------ //
mat4::mat4() {
	// Initialize all members to zero
	xAxis.x = 0.0f;
	xAxis.y = 0.0f;
	xAxis.z = 0.0f;
	xAxis.w = 0.0f;

	yAxis.x = 0.0f;
	yAxis.y = 0.0f;
	yAxis.z = 0.0f;
	yAxis.w = 0.0f;

	zAxis.x = 0.0f;
	zAxis.y = 0.0f;
	zAxis.z = 0.0f;
	zAxis.w = 0.0f;

	wAxis.x = 0.0f;
	wAxis.y = 0.0f;
	wAxis.z = 0.0f;
	wAxis.w = 0.0f;

	axis[0] = xAxis;
	axis[1] = yAxis;
	axis[2] = zAxis;
	axis[3] = wAxis;
}

mat4::mat4(float * ptr) {
	// Pointer to an array that contains nine elements
	for (int i = 0; i < 16; i++) {
		m[i] = ptr[i];
	}
}

mat4::mat4(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16) {
	axis[0].x = m1;
	axis[0].y = m2;
	axis[0].z = m3;
	axis[0].w = m4;
	axis[1].x = m5;
	axis[1].y = m6;
	axis[1].z = m7;
	axis[1].w = m8;
	axis[2].x = m9;
	axis[2].y = m10;
	axis[2].z = m11;
	axis[2].w = m12;
	axis[3].x = m13;
	axis[3].y = m14;
	axis[3].z = m15;
	axis[3].w = m16;
}

// Implicit operator to convert mat4 into a float array
mat4::operator float*() {
	return m;
}

// Returns vec4 objects when accessing by subscript operator
vec4 & mat4::operator[](const int index) {
	std::cout << "x:" << axis[index].x << " y:" << axis[index].y << " z:" << axis[index].z << " w: " << axis[index].w << std::endl;
	return axis[index];
}

const vec4 & mat4::operator[](const int index) const {
	std::cout << "x:" << axis[index].x << " y:" << axis[index].y << " z:" << axis[index].z << " w: " << axis[index].w << std::endl;
	return axis[index];
}

// Concatenates two matrices together and returns the result
mat4 mat4::operator*(const mat4 & rhs) const {
	mat4 temp;
	for (int s = 0; s < 4; s++) {
		temp.axis[s].x = (axis[s].x * rhs.mm[0][0]) + (axis[s].y * rhs.mm[1][0]) + (axis[s].z * rhs.mm[2][0]) + (axis[s].w * rhs.mm[3][0]);
		temp.axis[s].y = (axis[s].x * rhs.mm[0][1]) + (axis[s].y * rhs.mm[1][1]) + (axis[s].z * rhs.mm[2][1]) + (axis[s].w * rhs.mm[3][1]);
		temp.axis[s].z = (axis[s].x * rhs.mm[0][2]) + (axis[s].y * rhs.mm[1][2]) + (axis[s].z * rhs.mm[2][2]) + (axis[s].w * rhs.mm[3][2]);
		temp.axis[s].w = (axis[s].x * rhs.mm[0][3]) + (axis[s].y * rhs.mm[1][3]) + (axis[s].z * rhs.mm[2][3]) + (axis[s].w * rhs.mm[3][3]);
		std::cout << "x: " << temp.axis[s].x << " y: " << temp.axis[s].y << " z: " << temp.axis[s].z << " w: " << temp.axis[s].w << std::endl;
	}
	return temp;
}

// Concatenates and assigns the result to the matrix
mat4 & mat4::operator*=(const mat4 & rhs) {
	mat4 temp;
	for (int s = 0; s < 4; s++) {
		temp.axis[s].x = (axis[s].x * rhs.mm[0][0]) + (axis[s].y * rhs.mm[1][0]) + (axis[s].z * rhs.mm[2][0]) + (axis[s].w * rhs.mm[3][0]);
		temp.axis[s].y = (axis[s].x * rhs.mm[0][1]) + (axis[s].y * rhs.mm[1][1]) + (axis[s].z * rhs.mm[2][1]) + (axis[s].w * rhs.mm[3][1]);
		temp.axis[s].z = (axis[s].x * rhs.mm[0][2]) + (axis[s].y * rhs.mm[1][2]) + (axis[s].z * rhs.mm[2][2]) + (axis[s].w * rhs.mm[3][2]);
		temp.axis[s].w = (axis[s].x * rhs.mm[0][3]) + (axis[s].y * rhs.mm[1][3]) + (axis[s].z * rhs.mm[2][3]) + (axis[s].w * rhs.mm[3][3]);
	}
	for (int j = 0; j < 4; j++) {
		axis[j].x = temp.axis[j].x;
		axis[j].y = temp.axis[j].y;
		axis[j].z = temp.axis[j].z;
		axis[j].w = temp.axis[j].w;
		std::cout << axis[j].x << " | " << axis[j].y << " | " << axis[j].z << " | " << axis[j].w << std::endl;
	}
	return *this;
}

// Returns true if the matrices are equal
bool mat4::operator==(const mat4 & rhs) const {
	float tolerance;
	for (int i = 0; i < 16; i++) {
		tolerance = m[i] - rhs.m[i];
		if (myMath::abs(tolerance) < 0.001f) {
			continue;
		}
		else {
			std::cout << "False" << std::endl;
			return false;
		}
	}
	std::cout << "True" << std::endl;
	return true;
}

// Returns true if the matrices are inequal
bool mat4::operator!=(const mat4 & rhs) const {
	float tolerance;
	for (int i = 0; i < 16; i++) {
		tolerance = m[i] - rhs.m[i];
		if (myMath::abs(tolerance) > 0.001f) {
			continue;
		}
		else {
			std::cout << "False" << std::endl;
			return false;
		}
	}
	std::cout << "True" << std::endl;
	return true;
}

// Returns a 3x3 identity matrix
mat4 mat4::identity() {
	return mat4(1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
}

// Updates the matrix elements with the given values
void mat4::set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16) {
	axis[0].x = m1;
	axis[0].y = m2;
	axis[0].z = m3;
	axis[0].w = m4;
	axis[1].x = m5;
	axis[1].y = m6;
	axis[1].z = m7;
	axis[1].w = m8;
	axis[2].x = m9;
	axis[2].y = m10;
	axis[2].z = m11;
	axis[2].w = m12;
	axis[3].x = m13;
	axis[3].y = m14;
	axis[3].z = m15;
	axis[3].w = m16;
}

// Updates the matrix elements with the given values from the given array
void mat4::set(float * ptr) {
	for (int i = 0; i < 16; i++) {
		m[i] = ptr[i];
	}
}

// Transposes the matrix
void mat4::transpose() {
	mat4 transposeMat4;
	transposeMat4.m1 = m1;
	transposeMat4.m2 = m5;
	transposeMat4.m3 = m9;
	transposeMat4.m4 = m13;
	
	transposeMat4.m5 = m2;
	transposeMat4.m6 = m6;
	transposeMat4.m7 = m10;
	transposeMat4.m8 = m14;
	
	transposeMat4.m9 = m3;
	transposeMat4.m10 = m7;
	transposeMat4.m11 = m11;
	transposeMat4.m12 = m15;

	transposeMat4.m13 = m4;
	transposeMat4.m14 = m8;
	transposeMat4.m15 = m12;
	transposeMat4.m16 = m16;


	for (int i = 0; i < 4; i++) {
		std::cout << "x: " << transposeMat4.axis[i].x << " y: " << transposeMat4.axis[i].y << " z: " << transposeMat4.axis[i].z << " w: " << transposeMat4.axis[i].w << std::endl;
	}
}

mat4 mat4::getTranspose() const {
	mat4 transposeMat4;
	transposeMat4.m1 = m1;
	transposeMat4.m2 = m5;
	transposeMat4.m3 = m9;
	transposeMat4.m4 = m13;

	transposeMat4.m5 = m2;
	transposeMat4.m6 = m6;
	transposeMat4.m7 = m10;
	transposeMat4.m8 = m14;

	transposeMat4.m9 = m3;
	transposeMat4.m10 = m7;
	transposeMat4.m11 = m11;
	transposeMat4.m12 = m15;

	transposeMat4.m13 = m4;
	transposeMat4.m14 = m8;
	transposeMat4.m15 = m12;
	transposeMat4.m16 = m16;


	for (int i = 0; i < 4; i++) {
		std::cout << "x: " << transposeMat4.axis[i].x << " y: " << transposeMat4.axis[i].y << " z: " << transposeMat4.axis[i].z << " w: " << transposeMat4.axis[i].w << std::endl;
	}
	return transposeMat4;
}

// Reverses the matrix
void mat4::reverse() {
	mat4 reverseMat4;
	reverseMat4.m1 = m16;
	reverseMat4.m2 = m15;
	reverseMat4.m3 = m14;
	reverseMat4.m4 = m13;

	reverseMat4.m5 = m12;
	reverseMat4.m6 = m11;
	reverseMat4.m7 = m10;
	reverseMat4.m8 = m9;

	reverseMat4.m9 = m8;
	reverseMat4.m10 = m7;
	reverseMat4.m11 = m6;
	reverseMat4.m12 = m5;

	reverseMat4.m13 = m4;
	reverseMat4.m14 = m3;
	reverseMat4.m15 = m2;
	reverseMat4.m16 = m1;

	for (int i = 0; i < 4; i++) {
		std::cout << "x: " << reverseMat4.axis[i].x << " y: " << reverseMat4.axis[i].y << " z: " << reverseMat4.axis[i].z << " w: " << reverseMat4.axis[i].w << std::endl;
	}
	std::cout << std::endl;
}

// Returns a reversed copy of the matrix
mat4 mat4::getReverse() const {
	mat4 reverseMat4;
	reverseMat4.m1 = m16;
	reverseMat4.m2 = m15;
	reverseMat4.m3 = m14;
	reverseMat4.m4 = m13;

	reverseMat4.m5 = m12;
	reverseMat4.m6 = m11;
	reverseMat4.m7 = m10;
	reverseMat4.m8 = m9;

	reverseMat4.m9 = m8;
	reverseMat4.m10 = m7;
	reverseMat4.m11 = m6;
	reverseMat4.m12 = m5;

	reverseMat4.m13 = m4;
	reverseMat4.m14 = m3;
	reverseMat4.m15 = m2;
	reverseMat4.m16 = m1;

	for (int i = 0; i < 4; i++) {
		std::cout << "x: " << reverseMat4.axis[i].x << " y: " << reverseMat4.axis[i].y << " z: " << reverseMat4.axis[i].z << " w: " << reverseMat4.axis[i].w << std::endl;
	}
	std::cout << std::endl;

	return reverseMat4;
}

  // --------------------------------------- //
 // -----***** Matrix Transforms *****----- //
// --------------------------------------- //

// Returns a translation matrix with the given changes for each axis
mat4 mat4::translation(float x, float y, float z) {
	mat4 translationTemp(1.0f, 0.0f, 0.0f, x,
						 0.0f, 1.0f, 0.0f, y,
						 0.0f, 0.0f, 1.0f, z,
						 0.0f, 0.0f, 0.0f, 1.0f);
	return translationTemp;
}

// Returns a translation matrix with the given changes for each axis
mat4 mat4::translation(const vec3 & vec) {
	mat4 translationTemp(1.0f, 0.0f, 0.0f, vec.x,
						 0.0f, 1.0f, 0.0f, vec.y,
						 0.0f, 0.0f, 1.0f, vec.z,
						 0.0f, 0.0f, 0.0f, 1.0f);
	return translationTemp;
}

// Returns a rotation matrix with the given rotation
mat4 mat4::rotationX(float xRotation) {
	mat4 rotationTemp(1.0f, 0.0f,			0.0f,			 0.0f,
					  0.0f, cos(xRotation), -sin(xRotation), 0.0f,
					  0.0f, sin(xRotation), cos(xRotation),  0.0f,
					  0.0f, 0.0f,			0.0f,			 1.0f);
	return rotationTemp;
}

// Returns a rotation matrix with the given rotation
mat4 mat4::rotationY(float yRotation)
{
	mat4 rotationTemp(cos(yRotation),  0.0f, sin(yRotation), 0.0f,
					  0.0f,			   1.0f, 0.0f,			 0.0f,
					  -sin(yRotation), 0.0f, cos(yRotation), 0.0f,
					  0.0f,			   0.0f, 0.0f,			 1.0f);
	return rotationTemp;
}

// Returns a rotation matrix with the given rotation
mat4 mat4::rotationZ(float zRotation) {
	mat4 rotationTemp(cos(zRotation), -sin(zRotation), 0.0f, 0.0f,
					  sin(zRotation), cos(zRotation),  0.0f, 0.0f,
					  0.0f,			  0.0f,			   1.0f, 0.0f,
					  0.0f,			  0.0f,			   0.0f, 1.0f);
	return rotationTemp;
}

// Returns a rotation matrix with the given rotation
mat4 mat4::rotation(float x, float y, float z) {
	// Concatenate the rotation x, y and z and return that.
	mat4 rotationTempX(1.0f, 0.0f, 0.0f, 0.0f,
					   0.0f, cos(x), -sin(x), 0.0f,
					   0.0f, sin(x), cos(x), 0.0f,
					   0.0f, 0.0f, 0.0f, 1.0f);
	
	mat4 rotationTempY(cos(y),  0.0f, sin(y), 0.0f,
					   0.0f,    1.0f, 0.0f,   0.0f,
					   -sin(y), 0.0f, cos(y), 0.0f,
					   0.0f,    0.0f, 0.0f,   1.0f);

	mat4 rotationTempZ(cos(z), -sin(z), 0.0f, 0.0f,
					   sin(z), cos(z),  0.0f, 0.0f,
					   0.0f,   0.0f,    1.0f, 0.0f,
					   0.0f,   0.0f,    0.0f, 1.0f);

	mat4 rotationTempXY = rotationTempX * rotationTempY;
	mat4 rotationTempXYZ = rotationTempXY * rotationTempZ;
	return rotationTempXYZ;
}

// Returns a translation matrix with the given changes for each axis
mat4 mat4::scale(float xScale, float yScale, float zScale) {
	mat4 scaleTemp(xScale, 0.0f,   0.0f,   0.0f,
				   0.0f,   yScale, 0.0f,   0.0f,
				   0.0f,   0.0f,   zScale, 0.0f,
				   0.0f,   0.0f,   0.0f,   1.0f);
	return scaleTemp;
}

// Returns a translation matrix with the given changes for each axis
mat4 mat4::scale(const vec3 & vec) {
	mat4 scaleTemp(vec.x, 0.0f,  0.0f,  0.0f,
				   0.0f,  vec.y, 0.0f,  0.0f,
				   0.0f,  0.0f,  vec.z, 0.0f,
				   0.0f,  0.0f,  0.0f,  1.0f);
	return scaleTemp;
}

// Transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
vec4 mat4::operator*(const vec4 & rhs) const {
	vec4 temp;
	temp.x = (mm[0][0] * rhs.x) + (mm[0][1] * rhs.y) + (mm[0][2] * rhs.z) + (mm[0][3] * rhs.w);
	temp.y = (mm[1][0] * rhs.x) + (mm[1][1] * rhs.y) + (mm[1][2] * rhs.z) + (mm[1][3] * rhs.w);
	temp.z = (mm[2][0] * rhs.x) + (mm[2][1] * rhs.y) + (mm[2][2] * rhs.z) + (mm[2][3] * rhs.w);
	temp.w = (mm[3][0] * rhs.x) + (mm[3][1] * rhs.y) + (mm[3][2] * rhs.z) + (mm[3][3] * rhs.w);
	std::cout << "x: " << temp.x << " y: " << temp.y << " z: " << temp.z << " w: " << temp.w << std::endl;
	return temp;
}

// Convenience function for transforming a 3D vector
vec3 mat4::operator*(const vec3 & rhs) const {
	vec3 temp;
	temp.x = (mm[0][0] * rhs.x) + (mm[0][1] * rhs.y) + (mm[0][2] * rhs.z) + (mm[0][3] * 1);
	temp.y = (mm[1][0] * rhs.x) + (mm[1][1] * rhs.y) + (mm[1][2] * rhs.z) + (mm[1][3] * 1);
	temp.z = (mm[2][0] * rhs.x) + (mm[2][1] * rhs.y) + (mm[2][2] * rhs.z) + (mm[2][3] * 1);
	return temp;
}