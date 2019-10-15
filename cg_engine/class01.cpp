#include <iostream>
#include "engine.h"

using namespace std;

LIB_API Class01::Class01() {
	/*
	cout << "class constructor miao" << endl;
	glm::vec4 v1 = glm::vec4(glm::vec3(1.0, 0.5, 0.4), 1.0);
	glm::vec4 v2 = glm::vec4(glm::vec3(1.0, 0.5, 0.4), 1.0);
	glm::vec4 v3 = v1 + v2;
	glm::mat4 identity{1.0f};
	glm::mat4 myMatrix{1,0,0,0,
					   0,1,0,0,
					   0,0,1,0,
					   0,0,0,1};
	
	glm::vec4 transformedVector = identity * v1;
	cout << "1" << endl;
	glm::mat4 Model = glm::mat4(1.0);
	cout << "2" << endl;
	cout << "3" << endl;
	
	cout << glm::to_string(v1) << endl;
	cout << glm::to_string(transformedVector) << endl;
	cout << glm::to_string(v3) << endl;
	*/
}


void LIB_API Class01::exercise_01(){
	glm::vec3 a{1.0f, 0.0f, -1.0f};
	glm::vec3 b{-0.5f, 1.5f, 0.5f};
	glm::mat3 A {1.0f, -1.0f, 0.0f,
				-1.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 1.0f};
	glm::mat3 B {1.0f, 0.0f, 0.0f,
				 0.0f, 1.0f, 0.0f,
				 30.0f, 15.0f, 1.0f};
	
	glm::vec3 a_plus_b = a + b;
	glm::vec3 a_minus_b = a - b;
	glm::vec3 a_times_b = a * b;
	glm::vec3 a_cross_b = glm::cross(a, b);
	glm::vec3 b_normalized = glm::normalize(b);
	glm::vec3 a_transformed_A = A * a;
	glm::vec3 A_transformed_a = a * A;
	glm::mat3 AB = A*B;
	glm::mat3 BA = B*A;
	glm::mat3 A_t_B = glm::transpose(A)*B;
	glm::vec3 B_inv_b = glm::inverse(B)*b;
	
	float a_dot_b = glm::dot(a, b);
	
	cout << "GLM VERSION: " <<GLM_VERSION << endl;
	cout << "Vector a: " << glm::to_string(a) << endl;
	cout << "Vector b: " << glm::to_string(a) << endl;
	cout << "a+b: " << glm::to_string(a_plus_b) << endl;
	cout << "a-b: " << glm::to_string(a_minus_b) << endl;
	cout << "a*b (not dot): " << glm::to_string(a_times_b) << endl;
	cout << "dot(a,b): " << a_dot_b << endl;
	cout << "cross(a,b): " << glm::to_string(a_cross_b) << endl;
	cout << "a transformed by A: " << glm::to_string(a_transformed_A) << endl;
	cout << "A transformed by a: " << glm::to_string(A_transformed_a) << endl;//!!!
	cout << "AB: " << glm::to_string(AB) << endl;
	cout << "BA: " << glm::to_string(BA) << endl;
	cout << "A_trans B: " << glm::to_string(A_t_B) << endl;
	cout << "B_inverse_b: " << glm::to_string(B_inv_b) << endl;
	
	

	
}


LIB_API Class01::~Class01() {
}
