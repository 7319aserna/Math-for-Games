#include <cfloat>
#include <iostream>
#include "library.h"
#include <stdlib.h>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

  // -------------------------------------------- //
 // -----***** Assessable - Unit matrixTest *****----- //
// -------------------------------------------- //
// Vector matrixTest
template<typename T>
T vectorTest(const char * matrixTestName, T actual, T expected, float threshold = 0.001f) {
	T tolerance = expected - actual;
	if (tolerance < myMath::abs(threshold)) {
		std::cout << "[PASS]" << matrixTestName << std::endl;
	}
	else {
		std::cout << "[FAIL]" << matrixTestName << std::endl;
	}
	return expected;
}

// Matrix matrixTest
template<typename T>
T matrixTest(const char * matrixTestName, T actual, T expected) {
	if (actual == expected) {
		std::cout << "[PASS]" << matrixTestName << std::endl;
	}
	else {
		std::cout << "[FAIL]" << matrixTestName << std::endl;
	}
	return expected;
}

int main() {
	  // -------------------------------------------- //
	 // -----***** Assessable - Unit matrixTest *****----- //
	// -------------------------------------------- //
	// Vector Addition
	std::cout << "\nVector Addition" << "\n---------------" << std::endl;
	vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	vec3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	vec4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	vectorTest("Vector2 addition", v2c, vec2(18.5f, -44.24f));
	vectorTest("Vector3 addition", v3c, vec3(18.5f, -44.24f, 850));
	vectorTest("Vector4 addition", v4c, vec4(18.5f, -44.24f, 850, 1));

	// Vector Subtraction
	std::cout << "\nVector Subtraction" << "\n------------------" << std::endl;
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	v2c = v2a - v2b;
	std::cout << "v2c x: " << v2c.x << " y: " << v2c.y << std::endl;
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	v3c = v3a - v3b;
	std::cout << "v3c x: " << v3c.x << " y: " << v3c.y << " z: " << v3c.z << std::endl;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;
	std::cout << "v4c x: " << v4c.x << " y: " << v4c.y << " z: " << v4c.z << " w: " << v4c.w << std::endl;
	std::cout << std::endl;

	vectorTest("Vector2 Subtraction", v2c, vec2(8.5f, -52.22f));
	vectorTest("Vector3 Subtraction", v3c, vec3(8.5f, -52.22f, 874));
	vectorTest("Vector4 Subtraction", v4c, vec4(8.5f, -52.22f, 874, -1));

	// Vector Post-Scale
	std::cout << "\nVector Post-Scale" << "\n-----------------" << std::endl;
	v2a = vec2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	std::cout << "v2c x: " << v2c.x << " y: " << v2c.y << std::endl;
	v3a = vec3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	std::cout << "v3c x: " << v3c.x << " y: " << v3c.y << " z: " << v3c.z << std::endl;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;
	std::cout << "v4c x: " << v4c.x << " y: " << v4c.y << " z: " << v4c.z << " w: " << v4c.w << std::endl;
	std::cout << std::endl;

	vectorTest("Vector2 Post-Scale", v2c, vec2(33.5069999695f, -119.706863403f));
	vectorTest("Vector3 Post-Scale", v3c, vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	vectorTest("Vector4 Post-Scale", v4c, vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// Vector Pre-Scale
	std::cout << "\nVector Pre-Scale" << "\n----------------" << std::endl;
	v2a = vec2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	std::cout << "v2c x: " << v2c.x << " y: " << v2c.y << std::endl;
	v3a = vec3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	std::cout << "v3c x: " << v3c.x << " y: " << v3c.y << " z: " << v3c.z << std::endl;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;
	std::cout << "v4c x: " << v4c.x << " y: " << v4c.y << " z: " << v4c.z << " w: " << v4c.w << std::endl;
	std::cout << std::endl;

	vectorTest("Vector2 Pre-Scale", v2c, vec2(33.5069999695f, -119.706863403f));
	vectorTest("Vector3 Pre-Scale", v3c, vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	vectorTest("Vector4 Pre-Scale", v4c, vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// Vector Dot Product
	std::cout << "\nVector Dot Product" << "\n------------------" << std::endl;
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	std::cout << "dot2: " << dot2 << std::endl;
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	std::cout << "dot3: " << dot3 << std::endl;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);
	std::cout << "dot4: " << dot4 << std::endl;
	std::cout << std::endl;

	vectorTest("Vector2 Dot", dot2, -124.937698364f);
	vectorTest("Vector3 Dot", dot3, -10468.9375f);
	vectorTest("Vector4 Dot", dot4, -10468.9375f);

	// Vector Cross Product
	std::cout << "\nVector Cross Product" << "\n--------------------" << std::endl;
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	std::cout << "v3c cross x: " << v3c.x << " y: " << v3c.y << " z: " << v3c.z << std::endl;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);
	std::cout << "v4c cross x: " << v4c.x << " y: " << v4c.y << " z: " << v4c.z << " w: " << v4c.w << std::endl;
	std::cout << std::endl;

	vectorTest("Vector3 Cross", v3c, vec3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	vectorTest("Vector4 Cross", v4c, vec4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// Vector Magnitude
	std::cout << "\nVector Magnitude" << "\n----------------" << std::endl;
	v2a = vec2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	std::cout << "mag2: " << mag2 << std::endl;
	v3a = vec3(13.5f, -48.23f, 862);
	float mag3 = v3a.magnitude();
	std::cout << "mag3: " << mag3 << std::endl;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.magnitude();
	std::cout << "mag4: " << mag4 << std::endl;
	std::cout << std::endl;

	vectorTest("Vector2 magnitude", mag2, 50.0837593079f);
	vectorTest("Vector3 magnitude", mag3, 863.453735352f);
	vectorTest("Vector4 magnitude", mag4, 863.453735352f);

	// Vector Normalize
	std::cout << "\nVector Normalize" << "\n----------------" << std::endl;
	v2a = vec2(-13.5f, -48.23f);
	v2a.normalize();
	std::cout << "v2a normalize x: " << v2a.x << " y: " << v2a.y << std::endl;
	v3a = vec3(13.5f, -48.23f, 862);
	v3a.normalize();
	std::cout << "v3a normalize x: " << v3a.x << " y: " << v3a.y << " z: " << v3a.z << std::endl;
	v4a = vec4(243, -48.23f, 862, 0);
	v4a.normalize();
	std::cout << "v4a normalize x: " << v4a.x << " y: " << v4a.y << " z: " << v4a.z << " w: " << v4a.w << std::endl;
	std::cout << std::endl;

	vectorTest("Vector2 normalize", v2a, vec2(-0.269548f, -0.962987f));
	vectorTest("Vector3 normalize", v3a, vec3(0.0156349f, -0.0558571f, 0.998316f));
	vectorTest("Vector4 normalize", v4a, vec4(0.270935f, -0.0537745f, 0.961094f, 0));

	  // ----------------------------------------- //
	 // -----***** Unit matrixTest: Matrices *****----- //
	// ----------------------------------------- //
	// Matrix Rotation
	std::cout << "\nMatrix Rotation" << "\n---------------" << std::endl;
	mat3 m3a, m3b, m3c, m3d;
	mat4 m4a, m4b, m4c, m4d;
	m3a = m3a.rotation(3.98f);
	m4a = m4a.rotationX(4.5f);
	m3b = m3b.rotation(1.76f);
		m3b.getReverse();
	m4b = m4b.rotationY(-2.6f);
		m4b.getReverse();
	m3c = m3c.rotation(9.62f);
		m3c.getReverse();
	m4c = m4c.rotationZ(0.72f);
		m4c.getReverse();
	// Note, since the matrixTest hasen't fully passed yet, m3a.getReverse()...
	// and m4a.getReverse() display the matrix before the matrixTest results...
	// appear.
	matrixTest("\nMatrix3 set rotate", m3a.getReverse(), mat3(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f));
	std::cout << std::endl;
	matrixTest("Matrix4 set rotate", m4a.getReverse(), mat4(1, 0, 0, 0, 0, -0.210796f, -0.97753f, 0, 0, 0.97753f, -0.210796f, 0, 0, 0, 0, 1));

	// Vector Transform
	std::cout << "\nVector Transform" << "\n----------------" << std::endl;
	v2a = vec2(13.5f, -48.23f);
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	std::cout << std::endl;

	matrixTest("Vector3 matrix transform", v3b, vec3(44.8302650f, 22.3300285f, 862.000000f));
	matrixTest("Vector3 matrix transform", v3c, vec3(-22.5994224548f, 44.6950683594f, 862));
	matrixTest("Vector4 matrix transform", v4b, vec4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
	matrixTest("Vector4 matrix transform", v4c, vec4(41.951499939f, -27.3578968048f, 862, 0));

	// Matrix Multiply
	std::cout << "\nMatrix Multiply" << "\n---------------" << std::endl;
	m3d = m3a * m3c;
	m4d = m4c * m4b;

	matrixTest("Matrix3 multiply", m3d, mat3(0.51170409934888498f, -0.85916177999804457f, 0, 0.85916177999804457f, 0.51170409934888498f, 0, 0, 0, 1));
	matrixTest("Matrix4 multiply", m4d, mat4(-0.644213855f, -0.659384668f, -0.387556940f, 0, -0.565019250f, 0.751805722713f, -0.339913756f, 0, 0.515501440f, 0, -0.856888711452f, 0, 0, 0, 0, 1));

	// Homogeneous Point Translation
	std::cout << "\nHomogeneous Point Translation" << "\n-----------------------------" << std::endl;
	m3b = mat3(1, 0, 0,
			   0, 1, 0,
			   0, 0, 1);
	// m3b[2] = vec3(55, 44, 1);
	m3b.m3 = 55;
	m3b.m6 = 44;
	m3b.m9 = 1;
	// m3b = (1,  0,  55,
	//		  0,  1,  44,
	//		  0,  0,  1)

	m3c.rotation(2.2f);
	// m3c[2] = vec3(55, 44, 1);
	m3c.m3 = 55;
	m3c.m6 = 44;
	m3c.m9 = 1;
	
	m4b = mat4(1, 0, 0, 0,
			   0, 1, 0, 0,
			   0, 0, 1, 0,
			   0, 0, 0, 1);
	// m4b[3] = vec4(55, 44, 99, 1);
	m4b.m4 = 55;
	m4b.m8 = 44;
	m4b.m12 = 99;
	m4b.m16 = 1;
	// m4b = (1, 0, 0, 55,
	//		  0, 1, 0, 44,
	//		  0, 0, 1, 99,
	//		  0, 0, 0, 1)
	
	m4c.rotationZ(2.2f);
	// m4c[3] = vec4(55, 44, 99, 1);
	m4c.m4 = 55;
	m4c.m8 = 44;
	m4c.m12 = 99;
	m4c.m16 = 1;

	v3a = vec3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, -54, 1);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	matrixTest("Vector3 matrix translation A", v3b, vec3(68.5f, -4.23f, 1));
	// Fix
	matrixTest("Vector3 matrix translation B", v3c, vec3(86.0490112305f, 83.2981109619f, 1));
	// Fix
	matrixTest("Vector4 matrix translation A", v4b, vec4(68.5f, -4.23f, 45, 1));
	// Fix
	matrixTest("Vector4 matrix translation B", v4c, vec4(86.0490112305f, 83.2981109619f, 45, 1));

	// Homogeneous vector translation
	std::cout << "\nHomogeneous Vector Translation" << "\n------------------------------" << std::endl;
	m3b = mat3(1, 0, 0,
			   0, 1, 0,
			   0, 0, 1);
	//m3b[2] = vec3(55, 44, 1);
	m3b.m3 = 55;
	m3b.m6 = 44;
	m3b.m9 = 1;
	m3c.rotation(2.2f);
	m3c[2] = vec3(55, 44, 1);
	m4b = mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = vec4(55, 44, 99, 1);
	m4c.rotationZ(2.2f);
	m4c[3] = vec4(55, 44, 99, 1);

	v3a = vec3(13.5f, -48.23f, 0);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, -54, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	matrixTest("Vector3 matrix translation C", v3b, vec3(13.5f, -48.23f, 0));
	// Fix
	matrixTest("Vector3 matrix translation D", v3c, vec3(31.0490131378f, 39.2981109619f, 0));
	// Fix
	matrixTest("Vector4 matrix translation C", v4b, vec4(13.5f, -48.23f, -54, 0));
	// Fix
	matrixTest("Vector4 matrix translation D", v4c, vec4(31.0490131378f, 39.2981109619f, -54, 0));
	return 0;
}

////			|--**axis[0]**--| |--**axis[1]**--| |--**axis[2]**--|
//mat3 theMatrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
//
////			   |----***axis[0]***----| |----***axis[1]***----| |-----****axis[2]****----| |-----****axis[3]****-----|
//mat4 theMatrixReloaded(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
//
//// Pointer to an array that contains nine elements(Matrix 3)
//std::cout << "// Pointer to an array that contains nine elements(Matrix 3)" << std::endl;
//float theMatrixArray[9] = { 1.5f, 3.0f, 4.5f, 6.0f, 7.5f, 9.0f, 10.5f, 12.0f, 13.5 };
//float* theMatrixPointer = theMatrixArray;
//mat3 theMatrixThreeMath = mat3(theMatrixPointer);
//
//// Pointer to an array that contains sixteen elements (Matrix 4)
//std::cout << "// Pointer to an array that contains sixteen elements(Matrix 4)" << std::endl;
//float theMatrixReloadedArray[16] = { 1.5f, 3.0f, 4.5f, 6.0f, 7.5f, 9.0f, 10.5f, 12.0f, 13.5, 15.0f, 16.5f, 18.0f, 19.5f, 21.0f, 22.5f, 24.0f };
//float* theMatrixReloadedPointer = theMatrixReloadedArray;
//mat4 theMatrixReloadedFourMath = mat4(theMatrixReloadedPointer);
//
//// Returns vec3 objects when accessing by subscript operator
//std::cout << std::endl;
//std::cout << "\n// Returns vec3 objects when accessing by subscript operator" << std::endl;
//theMatrix[0];
//
//// Returns vec4 objects when accessing by subscript operator
//std::cout << "\n// Returns vec4 objects when accessing by subscript operator" << std::endl;
//theMatrixReloaded[1];
//
//// Concatenates two matrices together and returns the result (Matrix 3)
//std::cout << "\n// Concatenates two matrices together and returns the result (Matrix 3)" << std::endl;
//mat3 theConcatenatedMatrix(10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f, 17.0f, 18.0f);
//theMatrix * theConcatenatedMatrix;
//
//// Concatenates two matrices together and returns the result (Matrix 4)
//std::cout << "\n// Concatenates two matrices together and returns the result (Matrix 4)" << std::endl;
//mat4 theConcatenatedMatrixReloaded(17.0f, 18.0f, 19.0f, 20.0f, 21.0f, 22.0f, 23.0f, 24.0f, 25.0f, 26.0f, 27.0f, 28.0f, 29.0f, 30.0f, 31.0f, 32.0f);
//theMatrixReloaded * theConcatenatedMatrixReloaded;
//
//// Concatenates and assigns the result to the matrix (Matrix 3)
//std::cout << "\n// Concatenates and assigns the result to the matrix (Matrix 3)" << std::endl;
//theMatrix *= theConcatenatedMatrix;
//
//// Concatenates and assigns the result to the matrix (Matrix 4)
//std::cout << "\n// Concatenates and assigns the result to the matrix (Matrix 4)" << std::endl;
//theMatrixReloaded *= theConcatenatedMatrixReloaded;
//
//// Transforms a 3D vector by performing 3x3 x 3x1 matrix 
//std::cout << "\nTransforms a 3D vector by performing 3x3 x 3x1 matrix" << std::endl;
//mat3 s(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
//vec3 j(1.0f, 2.0f, 3.0f);
//s * j;
//
//// Transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
//std::cout << "\nTransforms a 4D vector by performing 4x4 x 4x1 matrix" << std::endl;
//mat4 berenice(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
//vec4 marlohe(1.0f, 2.0f, 3.0f, 4.0f);
//berenice * marlohe;
//
//// Returns true if the matrices are equal (Matrix 3)
//std::cout << "\n// Returns true if the matrices are equal (Matrix 3)" << std::endl;
//mat3 theMatrix1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
//mat3 theMatrixReloaded1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
//theMatrix1 == theMatrixReloaded1;
//
//// Returns true if the matrices are equal (Matrix 4)
//std::cout << "\n// Returns true if the matrices are equal (Matrix 4)" << std::endl;
//mat4 theMatrix2(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
//mat4 theMatrixReloaded2(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
//theMatrix2 == theMatrixReloaded2;
//
//// Returns true if the matrices are inequal (Matrix 3)
//std::cout << "\n// Returns true if the matrices are inequal (Marix 3)" << std::endl;
//mat3 theMatrix3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
//mat3 theMatrixReloaded3(11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f, 17.0f, 18.0f, 19.0f);
//theMatrix3 != theMatrixReloaded3;
//
//// Returns true if the matrices are inequal (Matrix 4)
//std::cout << "\n// Returns true if the matrices are inequal (Marix 4)" << std::endl;
//mat4 theMatrix4(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
//mat4 theMatrixReloaded4(17.0f, 18.0f, 19.0f, 20.0f, 21.0f, 22.0f, 23.0f, 24.0f, 25.0f, 26.0f, 27.0f, 28.0f, 29.0f, 30.0f, 31.0f, 32.0f);
//theMatrix4 != theMatrixReloaded4;
//
//// Updates the matrix elements with the given values (Matrix 3)
//std::cout << "\n// Updates the matrix elements with the given values (Matrix 3)" << std::endl;
//theMatrix.set(3874.5f, 3984.5f, 8904.5f, 8569.5f, 86.5f, 37.5f, 64.5f, 3423.5f, 23.4f);
//float * theMatrixPointer2 = theMatrix;
//for (int i = 0; i < 9; i++) {
//	std::cout << theMatrixPointer2[i] << ", ";
//}
//
//// Updates the matrix elements with the given values (Matrix 4)
//std::cout << std::endl;
//std::cout << "\n// Updates the matrix elements with the given values (Matrix 4)" << std::endl;
//theMatrixReloaded.set(3874.5f, 3984.5f, 8904.5f, 8569.5f, 86.5f, 37.5f, 64.5f, 3423.5f, 23.4f, 3874.5f, 3984.5f, 8904.5f, 8569.5f, 86.5f, 37.5f, 64.5f);
//float * theMatrixReloadedPointer2 = theMatrixReloaded;
//for (int i = 0; i < 16; i++) {
//	std::cout << theMatrixReloadedPointer2[i] << ", ";
//}
//
//// Transposes the matrix (Matrix 3)
//std::cout << std::endl;
//std::cout << "\n// Transposes the matrix (Matrix 3)" << std::endl;
//mat3 theMatrixRevolutions(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
//theMatrixRevolutions.transpose();
//
//// Transposed the matrix (Matrix 4)
//std::cout << "\n// Transposes the matrix (Matrix 4)" << std::endl;
//mat4 theMatrixRevolutions1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
//theMatrixRevolutions1.transpose();