#include "class01.h"

#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtx/string_cast.hpp"


using namespace std;

LIB_API Class01::Class01() {
	cout << "class constructor miao" << endl;
	glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
	glm::mat4 Model = glm::mat4(1.0);
	Model[4] = glm::vec4(1.0, 1.0, 0.0, 1.0);
	glm::vec4 Transformed = Model * Position;
	cout << glm::to_string(Transformed) << endl;
}


LIB_API Class01::~Class01() {
}
