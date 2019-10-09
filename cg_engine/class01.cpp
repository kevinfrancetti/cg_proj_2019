#include "class01.h"

#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtx/string_cast.hpp"


using namespace std;

LIB_API Class01::Class01() {
	cout << "class constructor miao" << endl;
	glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
	cout << "1" << endl;
	glm::mat4 Model = glm::mat4(1.0);
	cout << "2" << endl;
	cout << "3" << endl;
	cout << glm::to_string(Position) << endl;
}


LIB_API Class01::~Class01() {
}
