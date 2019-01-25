#include <cfloat>
#include <iostream>
#include "library.h"
#include "vec3.h"

  // ---------------------------------------- //
 // -----***** Points and Vectors *****----- //
// ---------------------------------------- //
vec3::vec3() {}

vec3::vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

// vec3 Unary addition operator overload (vec3 + vec3)
vec3 vec3::operator+(const vec3 & rhs) const {
	return { x + rhs.x, y + rhs.y, z + rhs.z };
}

// vec3 Unary subtraction operator overload (vec3 - vec3)
vec3 vec3::operator-(const vec3 & rhs) const {
	return { x - rhs.x, y - rhs.y, z - rhs.z };
}

// vec3 Compound addition assignment operator overload...
// (vec3 += vec3)
vec3 & vec3::operator+=(const vec3 & rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

// vec3 Compound subtraction assignment operator overload...
// (vec3 -= vec3)
vec3 & vec3::operator-=(const vec3 & rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

// vec3 Equality operator overload (vec3 == vec3) 
bool vec3::operator==(const vec3 & rhs) const {
	// Take the differences between each member(temp) and compare it...
	// against a threshold. (FLT_EPSILON)
	vec3 temp;
	temp.x = x - rhs.x;
	temp.y = y - rhs.y;
	temp.z = z - rhs.z;

	if (myMath::abs(temp.x) < FLT_EPSILON && myMath::abs(temp.y) < FLT_EPSILON && myMath::abs(temp.z) < FLT_EPSILON) {
		return true;
	}
	return false;
}

// vec3 Inequality operator overload (vec3 != vec3) 
bool vec3::operator!=(const vec3 & rhs) const {
	return !(*this == rhs);
}

vec3 vec3::operator-() const {
	return { x * -1, y * -1, z * -1 };
}

// Converting a 3D vector as an array of floats
vec3::operator float*() {
	return &x;
}

vec3::operator const float*() const {
	return &x;
}

bool vec3::operator<(const float & rhs) const {
	if (myMath::abs(x) < rhs && myMath::abs(y) < rhs && myMath::abs(z) < rhs) {
		return true;
	}
	return false;
}

bool vec3::operator>(const float & rhs) const {
	if (myMath::abs(x) > rhs && myMath::abs(y) > rhs && myMath::abs(z) > rhs) {
		return true;
	}
	return false;
}

  // ------------------------------------------------- //
 // -----***** Magnitude and Normalization *****----- //
// ------------------------------------------------- //
// Length of a Vector
float vec3::magnitude() const {
	// a^2
	float xSqr = x * x;
	// b^2
	float ySqr = y * y;
	// c^2
	float zSqr = z * z;
	// d^2
	float cSqr = xSqr + ySqr + zSqr;
	// Square root of c
	return sqrtf(cSqr);
	// Or
	//return sqrt(x * x + y * y + z * z);
}

// Modify a Vector so that its Magnitude is equal to 1
vec3 & vec3::normalize() {
	float normalizeMagnitude = magnitude();
	x /= normalizeMagnitude;
	y /= normalizeMagnitude;
	z /= normalizeMagnitude;
	return *this;
}

vec3 vec3::getNormalized() const {
	vec3 temp;
	float normalizeMagnitude = magnitude();
	temp.x = x / normalizeMagnitude;
	temp.y = y / normalizeMagnitude;
	temp.z = z / normalizeMagnitude;
	std::cout << "Normalised Vector = x: " << temp.x << " y: " << temp.y << " z: " << temp.z << std::endl;
	return temp;
}

// Multiplying a Vector by a Vector
vec3 & vec3::scale(const vec3 & rhs) {
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const {
	vec3 temp;
	temp.x = x * rhs.x;
	temp.y = y * rhs.y;
	temp.z = z * rhs.z;
	std::cout << "Vector scale = x: " << temp.x << " y: " << temp.y << " z: " << temp.z << std::endl;
	return temp;
}

// Multiplying a Vector by a Scalar
vec3 vec3::operator*(const float rhs) const {
	return { x * rhs, y * rhs, z * rhs };
}

// Dividing a Vector by a float
vec3 vec3::operator/(const float rhs) const {
	return { x / rhs, y / rhs, z / rhs };
}

// Float * Vector_Three
vec3 operator*(const float lhs, const vec3 & rhs) {
	return { rhs.x * lhs, rhs.y * lhs, rhs.z * lhs };
}

// Vec3 multiplication assignment operator overload
vec3 & vec3::operator*=(const float rhs) {
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

// Vec3 division assignment operator overload
vec3 & vec3::operator/=(const float rhs) {
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

  // ------------------------------------------- //
 // -----***** Dot and Cross Product *****----- //
// ------------------------------------------- //
// Dot Product
float vec3::dot(const vec3 & rhs) const {
	return { x * rhs.x + y * rhs.y + z * rhs.z};
}

// Cross Product
vec3 vec3::cross(const vec3 & rhs) const {
	//vec3 temp;
	//// ay * bz - az * by
	//temp.x = y * rhs.z - z * rhs.y;
	//// az * bx - ax * bz
	//temp.y = z * rhs.x - x * rhs.z;
	//// ax * by - ay * bx
	//temp.z = x * rhs.y - y * rhs.x;
	//std::cout << "Vector Cross Product = x: " << temp.x << " y: " << temp.y << " z: " << temp.z << std::endl;
	//return temp;
	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x };
}

  // ------------------------------ //
 // -----***** Matrices *****----- //
// ------------------------------ //
mat3::mat3() {
	// Initialize all members to zero
	xAxis.x = 0.0f;
	xAxis.y = 0.0f;
	xAxis.z = 0.0f;
	
	yAxis.x = 0.0f;
	yAxis.y = 0.0f;
	yAxis.z = 0.0f;

	zAxis.x = 0.0f;
	zAxis.y = 0.0f;
	zAxis.z = 0.0f;

	axis[0] = xAxis;
	axis[1] = yAxis;
	axis[2] = zAxis;
}

mat3::mat3(float * ptr) {
	// Pointer to an array that contains nine elements
	for (int i = 0; i < 9; i++) {
		m[i] = ptr[i];
	}
}

mat3::mat3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9) {
	axis[0].x = m1;
	axis[0].y = m2;
	axis[0].z = m3;
	axis[1].x = m4;
	axis[1].y = m5;
	axis[1].z = m6;
	axis[2].x = m7;
	axis[2].y = m8;
	axis[2].z = m9;
}

// Implicit operator to convert mat3 into a float array
mat3::operator float*() {
	return m;
}

mat3::operator const float*() const {
	return m;
}

// Returns vec3 objects when accessing by subscript operator
vec3 & mat3::operator[](const int index) {
	std::cout << "x:" << axis[index].x << " y:" << axis[index].y << " z:" << axis[index].z << std::endl;
	return axis[index];
}

const vec3 & mat3::operator[](const int index) const {
	std::cout << "x:" << axis[index].x << " y:" << axis[index].y << " z:" << axis[index].z << std::endl;
	return axis[index];
}

// Concatenates two matrices together and returns the result
mat3 mat3::operator*(const mat3 & rhs) const {
	mat3 temp;
	for (int s = 0; s < 3; s++) {
		temp.axis[s].x = (axis[s].x * rhs.mm[0][0]) + (axis[s].y * rhs.mm[1][0]) + (axis[s].z * rhs.mm[2][0]);
		temp.axis[s].y = (axis[s].x * rhs.mm[0][1]) + (axis[s].y * rhs.mm[1][1]) + (axis[s].z * rhs.mm[2][1]);
		temp.axis[s].z = (axis[s].x * rhs.mm[0][2]) + (axis[s].y * rhs.mm[1][2]) + (axis[s].z * rhs.mm[2][2]);
		std::cout << "x: " << temp.axis[s].x << " y: " << temp.axis[s].y << " z: " << temp.axis[s].z << std::endl;
	}
	return temp;
}

// Concatenates and assigns the result to the matrix
mat3 & mat3::operator*=(const mat3 & rhs) {
	mat3 temp;
	for (int s = 0; s < 3; s++) {
		temp.axis[s].x = (axis[s].x * rhs.mm[0][0]) + (axis[s].y * rhs.mm[1][0]) + (axis[s].z * rhs.mm[2][0]);
		temp.axis[s].y = (axis[s].x * rhs.mm[0][1]) + (axis[s].y * rhs.mm[1][1]) + (axis[s].z * rhs.mm[2][1]);
		temp.axis[s].z = (axis[s].x * rhs.mm[0][2]) + (axis[s].y * rhs.mm[1][2]) + (axis[s].z * rhs.mm[2][2]);
	}
	for (int j = 0; j < 3; j++) {
		axis[j].x = temp.axis[j].x;
		axis[j].y = temp.axis[j].y;
		axis[j].z = temp.axis[j].z;
		std::cout << axis[j].x << " | " << axis[j].y << " | " << axis[j].z << std::endl;
	}
	return *this;
}

// Returns true if the matrices are equal
bool mat3::operator==(const mat3 & rhs) const {
	float tolerance;
	for (int i = 0; i < 9; i++) {
		tolerance = m[i] - rhs.m[i];
		if (myMath::abs(tolerance) < 0.001f) {
			continue;
		}
		else {
			//std::cout << "False" << std::endl;
			return false;
		}
	}
	//std::cout << "True" << std::endl;
	return true;
}

// Returns true if the matrices are inequal
bool mat3::operator!=(const mat3 & rhs) const {
	float tolerance;
	for (int i = 0; i < 9; i++) {
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
mat3 mat3::identity() {
	return mat3(1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 1.0f);
}

// Updates the matrix elements with the given values
void mat3::set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9) {
	axis[0].x = m1;
	axis[0].y = m2;
	axis[0].z = m3;
	axis[1].x = m4;
	axis[1].y = m5;
	axis[1].z = m6;
	axis[2].x = m7;
	axis[2].y = m8;
	axis[2].z = m9;
}

// Updates the matrix elements with the given values from the given array
void mat3::set(float * ptr) {
	for (int i = 0; i < 9; i++) {
		m[i] = ptr[i];
	}
}

// Transposes the matrix
void mat3::transpose() {
	mat3 transposeMat3;
	transposeMat3.m1 = m1;
	transposeMat3.m2 = m4;
	transposeMat3.m3 = m7;

	transposeMat3.m4 = m2;
	transposeMat3.m5 = m5;
	transposeMat3.m6 = m8;

	transposeMat3.m7 = m3;
	transposeMat3.m8 = m6;
	transposeMat3.m9 = m9;

	for (int i = 0; i < 3; i++) {
		std::cout << "x: " << transposeMat3.axis[i].x << " y: " << transposeMat3.axis[i].y << " z: " << transposeMat3.axis[i].z << std::endl;
	}
}

mat3 mat3::getTranspose() const {
	mat3 transposeMat3;
	transposeMat3.m1 = m1;
	transposeMat3.m2 = m4;
	transposeMat3.m3 = m7;

	transposeMat3.m4 = m2;
	transposeMat3.m5 = m5;
	transposeMat3.m6 = m8;

	transposeMat3.m7 = m3;
	transposeMat3.m8 = m6;
	transposeMat3.m9 = m9;

	for (int i = 0; i < 3; i++) {
		std::cout << "x: " << transposeMat3.axis[i].x << " y: " << transposeMat3.axis[i].y << " z: " << transposeMat3.axis[i].z << std::endl;
	}
	return transposeMat3;
}

// Reverses the matrix
void mat3::reverse() {
	mat3 reverseMat3;
	reverseMat3.m1 = m9;
	reverseMat3.m2 = m8;
	reverseMat3.m3 = m7;

	reverseMat3.m4 = m6;
	reverseMat3.m5 = m5;
	reverseMat3.m6 = m4;

	reverseMat3.m7 = m3;
	reverseMat3.m8 = m2;
	reverseMat3.m9 = m1;

	for (int i = 0; i < 3; i++) {
		std::cout << "x: " << reverseMat3.axis[i].x << " y: " << reverseMat3.axis[i].y << " z: " << reverseMat3.axis[i].z << std::endl;
	}
	std::cout << std::endl;
}

// Returns a reversed copy of the 
mat3 mat3::getReverse() const {
	mat3 reverseMat3;
	reverseMat3.m1 = m9;
	reverseMat3.m2 = m8;
	reverseMat3.m3 = m7;

	reverseMat3.m4 = m6;
	reverseMat3.m5 = m5;
	reverseMat3.m6 = m4;

	reverseMat3.m7 = m3;
	reverseMat3.m8 = m2;
	reverseMat3.m9 = m1;

	for (int i = 0; i < 3; i++) {
		std::cout << "x: " << reverseMat3.axis[i].x << " y: " << reverseMat3.axis[i].y << " z: " << reverseMat3.axis[i].z << std::endl;
	}
	std::cout << std::endl;


	return reverseMat3;
}

  // --------------------------------------- //
 // -----***** Matrix Transforms *****----- //
// --------------------------------------- //
// Returns a translation matrix with the given changes for each axis
mat3 mat3::translation(float x, float y) {
	mat3 translationTemp(1.0f, 0.0f, x, 
						 0.0f, 1.0f, y, 
						 0.0f, 0.0f, 1.0f);
	return translationTemp;
}

// Returns a translation matrix with the given changes for each axis
mat3 mat3::translation(const vec2 & vec) {
	mat3 translationTemp(1.0f, 0.0f, vec.x,
						 0.0f, 1.0f, vec.y, 
						 0.0f, 0.0f, 1.0f);
	return translationTemp;
}

// Returns a rotation matrix with the given rotation
mat3 mat3::rotation(float rot) {
	rot = myMath::DEG_TO_RAD(rot);
	mat3 rotationTemp(cos(rot), -sin(rot), 0.0f,
					  sin(rot), cos(rot),  0.0f,
					  0.0f,		0.0f,	   1.0f);
	return rotationTemp;
}

// Returns a translation matrix with the given changes for each axis
mat3 mat3::scale(float xScale, float yScale) {
	mat3 scaleTemp(xScale, 0.0f, 0.0f,
				   0.0f, yScale, 0.0f,
				   0.0f, 0.0f, 1.0f);
	return scaleTemp;
}

// Returns a translation matrix with the given changes for each axis
mat3 mat3::scale(const vec2 & vec) {
	mat3 scaleTemp(vec.x, 0.0f, 0.0f,
				   0.0f, vec.y, 0.0f,
				   0.0f, 0.0f, 1.0f);
	return scaleTemp;
}

// Transforms a 3D vector by performing 3x3 x 3x1 matrix 
vec3 mat3::operator*(const vec3 & rhs) const {
	vec3 temp;
	temp.x = (mm[0][0] * rhs.x) + (mm[0][1] * rhs.y) + (mm[0][2] * rhs.z);
	temp.y = (mm[1][0] * rhs.x) + (mm[1][1] * rhs.y) + (mm[1][2] * rhs.z);
	temp.z = (mm[2][0] * rhs.x) + (mm[2][1] * rhs.y) + (mm[2][2] * rhs.z);
	std::cout << "x: " << temp.x << " y: " << temp.y << " z: " << temp.z << std::endl;
	return temp;
}

// Convenience function for transforming a 2D vector
vec2 mat3::operator*(const vec2 & rhs) const {
	vec2 temp;
	temp.x = (mm[0][0] * rhs.x) + (mm[0][1] * rhs.y) + (mm[0][2] * 1);
	temp.y = (mm[1][0] * rhs.x) + (mm[1][1] * rhs.y) + (mm[1][2] * 1);
	return temp;
}

  // --------------------------------------- //
 // -----***** Matrix Transforms *****----- //
// --------------------------------------- //
transform2d::transform2d() {
	parent = NULL;
	localPos = { 0.0f, 0.0f };
	localRot = 0.0f;
	localScale = { 0.0f, 0.0f };
}

void transform2d::translate(const vec2 & offset) {
	// Whatever the offset, move local position x and y by that offset.
	localPos.x += offset.x;
	localPos.y += offset.y;
}

void transform2d::translate(float x, float y) {
	localPos.x += x;
	localPos.y += y;
}

void transform2d::rotate(const float angle) {
	// Whatever the angle, the matrix will move by that angle.
	localRot += angle;
	std::cout << localRot;
}

mat3 transform2d::getTRSMatix() const {
	return mat3::translation(localPos) * mat3::rotation(localRot) * mat3::scale(localScale);
}

  // ----------------------------------------- //
 // -----***** Matrix Hierarchies *****------ //
// ----------------------------------------- //
// World position of this object
vec2 transform2d::worldPosition() const {
	if (parent != NULL) {
		mat3 wPMat3 = parent->getTRSMatix() * getTRSMatix();
		vec2 wPVec2({ wPMat3.m3, wPMat3.m6 });
		return wPVec2;
	}
	return localPos;
}

// World rotation of this object
float transform2d::worldRotation() const {
	if (parent != NULL) {
		mat3 wRMat3 = parent->getTRSMatix() * getTRSMatix();
		vec2 wRVec2({ wRMat3.m1, wRMat3.m4 });
		return myMath::RAD_TO_DEG(atan2f(wRVec2.y, wRVec2.x));
	}
	return localRot;
}

// World scale of this object (lossy)
vec2 transform2d::worldScale() const {
	if (parent != NULL) {
		mat3 wSMat3 = parent->getTRSMatix() * getTRSMatix();
		vec2 wSVec2({ wSMat3.m1, wSMat3.m5 });
		return wSVec2;
	}
	return localScale;
}

// Assigns a parent to this object
void transform2d::setParent(transform2d * parent) {
	this->parent = parent;
	parent->children = this->children;
}

// Returns a pointer to its parent
transform2d * transform2d::getParent() {
	return this->parent;
}

// Returns a pointer to its parent (const-qualified)
transform2d const * transform2d::getParent() const {
	return this->parent;
}

// Returns a pointer to the first child
transform2d ** transform2d::getChildren() {
	return this->children.data();
}

// Returns a pointer to the first child (const-qualified)
transform2d * const * transform2d::getChildren() const {
	return this->children.data();
}

// Returns the number of children available
size_t transform2d::getChildrenCount() const {
	return size_t(children.size());
}
