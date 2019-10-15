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
	
	glm::vec3 aplusb = a + b;
	glm::vec3 aminusb = a - b;
	glm::vec3 atimesb = a * b;
	int miao = glm::dot(a, b);
	
	cout << GLM_VERSION << endl;
	cout << miao << endl;
	cout << glm::to_string(aplusb) << endl;
	cout << glm::to_string(aminusb) << endl;
	cout << glm::to_string(atimesb) << endl;
}


LIB_API Class01::~Class01() {
}
