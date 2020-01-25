/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   First_engine.cpp
 * Author: kevin
 * 
 * Created on November 12, 2019, 6:17 PM
 */
#include <iostream>
#include "engine.h"
#include <GL/freeglut.h>


//======GLOBALS=======//

//PROGECTIONS VARIABLES
float gNear = 1.0f;
float gFar = 100.0f;
float gFov = 45.0f;
glm::mat4 proj{ 1.0f };
glm::mat4 ortho{ 1.0f };


//GLOBAL CAMERA
glm::vec3 gCameraBackv3;
glm::vec3 gCameraFrontv3;
glm::vec3 gCameraUpv3{0.0f, 1.0f, 0.0f};

float yaw = 0;
float pitch = 0;

//MOUSE
int gMouseX;
int gMouseY;


//TEST
Cube gCube1{};
Cube gCube2{};
Node n1;
Node n2;
Node n3;
Node n4;
Cube c1;
Cube c2;
Scene s{ &n1 };
// Rotation angles:
float angleX = 0.0f, angleY = 0.0f;

using namespace std;


void string_to_unsigned_char(unsigned char*& text, string &str) {
	for (int i = 0; i < str.length(); i++) {
		text[i] = str.at(i);
	}
	text[str.length()] = '\0';
}

void print_info() {
	
	glDisable(GL_DEPTH_TEST);
	//INITIAL SET UP: PROJECTION MATRIX = ORTHO AND MODELVIEW = IDENTITY
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(ortho));
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(glm::mat4(1.0f)));
	//glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);

	//LOCAL VARIABLE
	string str;
	unsigned char message_buffer[40];
	unsigned char *pc = message_buffer;

	//LOGO
	glRasterPos2f(0.0f, 5.0f);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *) "LOCO ENGINE");
	
	//WIDTH + HEIGHT
	glRasterPos2f(0.0f, 20.0f);
	str = "WIDTH: " + to_string(glutGet(GLUT_WINDOW_WIDTH));
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	str = " - HEIGHT: " + to_string(glutGet(GLUT_WINDOW_HEIGHT));
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);

	//MOUSE POSITION
	glRasterPos2f(0.0f, 35.0f);
	str = "MOUSE: X: " + to_string(gMouseX);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	str = " Y: " + to_string(gMouseY);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);

	//CULLING OPTION
	glRasterPos2f(0.0f, 50.0f);
	if (glIsEnabled(GL_CULL_FACE))
		str = "[On]/Off culling [c]";
	else
		str = "On/[Off] culling [c]";
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);

	//WIREFRAME OPTION
	glRasterPos2f(0.0f, 65.0f);
	int poligon_mode[2];//This could become a pointer and then point it at position 1
	glGetIntegerv(GL_POLYGON_MODE, poligon_mode);
	if(poligon_mode[1] == GL_LINE)
		str = "[On]/Off wireframe [v]";
	else
		str = "On/[Off] wireframe [v]";
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	
	
	//PROJECTION OPTIONS
	glRasterPos2f(0.0f, 80.0f);
	str = "Near: " + to_string(gNear);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 95.0f);
	str = "Far: " + to_string(gFar);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 110.0f);
	str = "FOV: " + to_string(gFov);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);


	//GLOBAL CAMERA OPTIONS
	glRasterPos2f(0.0f, 125.0f);
	str = "CamBackX: " + to_string(gCameraBackv3.x);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 140.0f);
	str = "CamBackY: " + to_string(gCameraBackv3.y);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 155.0f);
	str = "CamBackZ: " + to_string(gCameraBackv3.z);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 170.0f);
	str = "CamFrontX: " + to_string(gCameraFrontv3.x);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 185.0f);
	str = "CamFrontY: " + to_string(gCameraFrontv3.y);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 200.0f);
	str = "CamFrontZ: " + to_string(gCameraFrontv3.z);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 215.0f);
	str = "YAW: " + to_string(yaw);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 230.0f);
	str = "PITCH: " + to_string(pitch);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_LIGHTING);
}

//SOME RANDOM TESTS MATRICES
glm::mat4 R = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
glm::mat4 L = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
glm::mat4 translate = glm::translate(glm::mat4(1.0f), gCameraBackv3);


void displayCallback() {
	// Clear the screen:         
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(proj));
	glMatrixMode(GL_MODELVIEW);


	glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(angleX), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(angleY), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 view = glm::lookAt(gCameraBackv3, gCameraBackv3 + gCameraFrontv3, gCameraUpv3);
	
	n1.setModelMatrix(n1.getModelMatrix() * rotationX * rotationY);
	s.setViewMatrix(view);
	s.renderSceneGraph();
	//gCube1.setModelMatrix( view * glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f)));
	
	//gCube1.render();

	
	print_info();
	glutSwapBuffers();   
	// Force another invocation of this rendering callback:
	glutPostWindowRedisplay(glutGetWindow());
}



//FUNCTION DECATIVATED
void mouse_passive_motion_callback(int x, int y) {

	//IF MOUSE IS ALREADY IN THE CENTER SKIP THIS FUNCTION
	if(x == glutGet(GLUT_WINDOW_WIDTH)/2){
		if(y == glutGet(GLUT_WINDOW_HEIGHT)/2){
			return;
		}
	}
	
	float sensitivity = 1.0f;

	//SPERIMENTAL
	if (x > glutGet(GLUT_WINDOW_WIDTH) / 2) {
		yaw += sensitivity;
	}
	else if(x < glutGet(GLUT_WINDOW_WIDTH) / 2)  yaw -= sensitivity;

	if (y > glutGet(GLUT_WINDOW_HEIGHT) / 2) {
		pitch -= sensitivity;
	}
	else if( y < glutGet(GLUT_WINDOW_HEIGHT) / 2) pitch += sensitivity;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	gCameraFrontv3 = glm::normalize(front);

	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
	glutPostWindowRedisplay(glutGetWindow());
}



void set_projection_matrix(){
	float width = (float) glutGet(GLUT_WINDOW_WIDTH);
	float height = (float) glutGet(GLUT_WINDOW_HEIGHT);
	glViewport(0, 0, width, height);
	proj = glm::perspective(glm::radians(gFov), (float) width / (float) height, gNear, gFar);
	//ortho = glm::ortho((float) -width / 2.0f, (float) width/2.0f, (float) -height/2.0f, (float) height / 2.0f, -1.0f, 1.0f);
	ortho = glm::ortho((float)0, (float)width, (float)0, (float)height, -1.0f, 1.0f);


	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(proj));
	glMatrixMode(GL_MODELVIEW);
}

void reshapeCallback(int width, int height){
	// For your information...:
	cout << "[reshape func invoked]" << endl;
	cout << "width: " << width << " height: " << height << endl;

	set_projection_matrix();
	
   	glutPostWindowRedisplay(glutGetWindow());
}

void specialCallback(int key, int mouse_x, int mouse_y){
	
	float step = 10.0f;
	switch(key){
		case GLUT_KEY_LEFT : angleX += 1.0f; break;
		case GLUT_KEY_RIGHT: angleX -= 1.0f; break;
		case GLUT_KEY_UP : angleY += 1.0f; break;
		case GLUT_KEY_DOWN : angleY -= 1.0f; break;
	}
	
	glutPostWindowRedisplay(glutGetWindow());
}


//USED FOR MODIFY FOV ( ZOOM )
void mouse_wheel_Callback(int wheel, int direction, int x, int y) {
	if (direction == 1) gFov += 1.0f;
	else gFov -= 1.0f;
	set_projection_matrix();
}

//When a mouse button is pressed down
void mouse_callback(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		gMouseX = x;
		gMouseY = y;
	}
}


void keyboardCallback(unsigned char key, int mouse_x, int mouse_y){

	float step = 0.5f;
	float camera_speed = 0.05f;
	switch(key){

		//MODIFY GLOBAL PROJECTION MATRIX
		case 'n' : gNear -= step; set_projection_matrix(); break;
		case 'N' : gNear += step; set_projection_matrix(); break;
		case 'f' : gFar -= step; set_projection_matrix(); break;
		case 'F' : gFar += step; set_projection_matrix(); break;

		//ENABLE/DISABLE CULLING
		case 'c': {
			if (glIsEnabled(GL_CULL_FACE)) glDisable(GL_CULL_FACE);
			else glEnable(GL_CULL_FACE);
		}; break;

		//ENABLE/DISABLE WIREFRAME MODE
		case 'v': {
			int poligon_mode[2];
			glGetIntegerv(GL_POLYGON_MODE, poligon_mode);
			if (poligon_mode[1] == GL_LINE) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			else glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}; break;

		//GLOBAL CAMERA MOVMENT
		case 'w': gCameraBackv3 += camera_speed * gCameraFrontv3; break;
		case 's': gCameraBackv3 -= camera_speed * gCameraFrontv3; break;
		case 'a': gCameraBackv3 -= glm::normalize(glm::cross(gCameraFrontv3, gCameraUpv3)) * camera_speed; break;
		case 'd': gCameraBackv3 += glm::normalize(glm::cross(gCameraFrontv3, gCameraUpv3)) * camera_speed; break;
	}

	glutPostWindowRedisplay(glutGetWindow());
}


void init(int* argc, char** argv){

	//=======GLUT INIT=========
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	
	glutInit(argc, argv);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	
	glutCreateWindow("Perro-Loco-Engine 1.0");
	glutDisplayFunc(displayCallback);  
	glutReshapeFunc(reshapeCallback); 
	glutKeyboardFunc(keyboardCallback);
	glutSpecialFunc(specialCallback);
	glutMouseFunc(mouse_callback);
	glutMouseWheelFunc(mouse_wheel_Callback);
	glutPassiveMotionFunc(mouse_passive_motion_callback);


	//=======OPENGL INIT=======
   	glClearColor(1.0f, 0.6f, 0.1f, 1.0f); // RGBA components
	glEnable(GL_DEPTH_TEST);
	
	/*
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	*/
	cout << glGetString(GL_VERSION) << endl;

	glutMainLoop();
	cout << "EXIT" << endl;
	
}

First_engine::First_engine() {
}

First_engine::First_engine(const First_engine& orig) {
}

First_engine::~First_engine() {
}


void First_engine::run(int* argc, char** argv){

	n1.addChild(&n2);
	n1.addChild(&n3);
	n2.addChild(&n4);

	n4.addChild(&c1);
	n3.addChild(&c2);
	n1.setModelMatrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));
	n3.setModelMatrix(glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 0.0f, 0.0f)));
	//s.renderSceneGraph();

	//renderSceneGraph(&n1);

	init(argc, argv);	
} 