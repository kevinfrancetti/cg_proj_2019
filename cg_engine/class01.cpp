#include <iostream>
#include "engine.h"
#include <GL/freeglut.h>

using namespace std;

LIB_API Class01::Class01() {
}


LIB_API Class01::~Class01() {
}



void LIB_API Class01::exercise_01() {


	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glm::vec3 a{1.0f, 0.0f, -1.0f};
	glm::vec3 b{-0.5f, 1.5f, 0.5f};
	glm::mat3 A{1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f};
	glm::mat3 B{1.0f, 0.0f, 0.0f,
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
	glm::mat3 A_t_B = glm::transpose(A) * B;
	glm::vec3 B_inv_b = glm::inverse(B) * b;

	float a_dot_b = glm::dot(a, b);

	cout << "GLM VERSION: " << GLM_VERSION << endl;
	cout << "Vector a: " << glm::to_string(a) << endl;
	cout << "Vector b: " << glm::to_string(a) << endl;
	cout << "a+b: " << glm::to_string(a_plus_b) << endl;
	cout << "a-b: " << glm::to_string(a_minus_b) << endl;
	cout << "a*b (not dot): " << glm::to_string(a_times_b) << endl;
	cout << "dot(a,b): " << a_dot_b << endl;
	cout << "cross(a,b): " << glm::to_string(a_cross_b) << endl;
	cout << "a transformed by A: " << glm::to_string(a_transformed_A) << endl;
	cout << "A transformed by a: " << glm::to_string(A_transformed_a) << endl; //!!!
	cout << "AB: " << glm::to_string(AB) << endl;
	cout << "BA: " << glm::to_string(BA) << endl;
	cout << "A_trans B: " << glm::to_string(A_t_B) << endl;
	cout << "B_inverse_b: " << glm::to_string(B_inv_b) << endl;
}

void multitply(const glm::vec4* in, glm::vec4* out, int nbr_of_vertices){
	
}

void LIB_API Class01::exercise_02() {
	cout << "Exercise_2" << endl;

	glm::vec4 triangle[3];
	triangle[0] = glm::vec4(-15.0f, 0.0f, -50.0f, 1.0f);
	triangle[1] = glm::vec4{15.0f, 0.0f, -50.0f, 1.0f};
	triangle[2] = glm::vec4{0.0f, 15.0f, -50.0f, 1.0f};
	

	glm::mat4 T1 = glm::scale(glm::mat4{1.0f}, glm::vec3{0.5f});
	glm::mat4 T2 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3{0.0f, 0.0f, 1.0f});
	glm::mat4 T3 = glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 0.0f, 0.0f));   

	
	glm::vec4 vector{1.0f, 1.0f, 0.0f, 1.0f};
	cout << glm::to_string(T1*vector) << endl;
	cout << glm::to_string(T2*vector) << endl;
	cout << glm::to_string(T2*T2*vector) << endl;
	cout << glm::to_string(T2*T2*T2*vector) << endl;
	cout << glm::to_string(T2*T2*T2*T2*vector) << endl;
	cout << glm::to_string(T3*vector) << endl;
	cout << glm::to_string(T1) << endl;
	cout << glm::to_string(T2) << endl;
	cout << glm::to_string(T3) << endl;
	
	

}



/**
 * This callback is invoked each time the window gets resized (and once also when created).
 * @param width new window width
 * @param height new window height
 */

/*
void reshapeCallback(int width, int height)
{
   // For your information...:
   std::cout << "[reshape func invoked]" << std::endl;
}
*/

/**
 * This is the main rendering routine automatically invoked by FreeGLUT.
 */

/*
void displayCallback()
{
   // Clear the screen:
   glClearColor(1.0f, 0.6f, 0.1f, 1.0f); // RGBA components
   glClear(GL_COLOR_BUFFER_BIT);

   // Swap this context's buffer:
   glutSwapBuffers();

   // Force another invocation of this rendering callback:
   glutPostWindowRedisplay(glutGetWindow());
}



void LIB_API Class01::test_free_glut(int &argc, char** argv) {
	std::cout << "Simple FreeGLUT example, A. Peternier (C) SUPSI" << std::endl;
	std::cout << std::endl;

	// Init context:
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);

	// FreeGLUT can parse command-line params, in case:
	glutInit(&argc, argv);

	// Set some optional flags:
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// Create the window with a specific title:
	glutCreateWindow("FreeGLUT simple example");

	// The OpenGL context is now initialized...

	// Set callback functions:
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	// Check OpenGL version:
	std::cout << "OpenGL context" << std::endl;
	std::cout << "   version  . . : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "   vendor . . . : " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "   renderer . . : " << glGetString(GL_RENDERER) << std::endl;

	// Enter the main FreeGLUT processing loop:
	glutMainLoop();

	// Done:
	std::cout << "[application terminated]" << std::endl;
}
 */