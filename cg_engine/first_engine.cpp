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
#include <vector>


//======GLOBALS=======//

//PROGECTIONS VARIABLES
float gNear = 1.0f;
float gFar = 100.0f;
glm::mat4 proj{ 1.0f };
glm::mat4 ortho{ 1.0f };


// Position
float gX = 0.0f;
float gY = 0.0f;
float gZ = 0.0f;

float gCamX = 0.0f;
float gCamY = 0.0f;
float gCamZ = 0.0f;


//GLOBAL CAMERA
glm::mat4 gMatrixCamera{ 1.0f };

glm::vec3 gVectorCameraPosition{ 1.0f, 1.0f, 0.0f };
glm::vec3 gVectorCameraLook{ 0.0f, 0.0f, 0.0f };



int gMouseX;
int gMouseY;


Cube* gpCube{};
Cube gCube1{};
Cube gCube2{};

// Rotation angles:
float angleX = 0.0f, angleY = 0.0f;




using namespace std;


void init_globals(){
	gpCube = &gCube1;
}

void string_to_unsigned_char(unsigned char*& text, string &str) {
	for (int i = 0; i < str.length(); i++) {
		text[i] = str.at(i);
	}
	text[str.length()] = '\0';
}

void print_info() {

	//INITIAL SET UP: PROJECTION MATRIX = ORTHO AND MODELVIEW = IDENTITY
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(ortho));
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(glm::mat4(1.0f)));
	//glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);

	//LOCAL VARIABLE
	string str;
	unsigned char message_buffer[20];
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
	int poligon_mode;
	glGetIntegerv(GL_POLYGON_MODE, &poligon_mode);
	if(poligon_mode == GL_LINE)
		str = "[On]/Off wireframe [w]";
	else
		str = "On/[Off] wireframe [w]";
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


	//GLOBAL CAMERA OPTIONS
	glRasterPos2f(0.0f, 110.0f);
	str = "CamX: " + to_string(gCamX);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 125.0f);
	str = "CamY: " + to_string(gCamY);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);
	glRasterPos2f(0.0f, 140.0f);
	str = "CamZ: " + to_string(gCamZ);
	string_to_unsigned_char(pc, str);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (unsigned char *)message_buffer);


	//glEnable(GL_LIGHTING);
}



void displayCallback(){
	// Clear the screen:         
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);      

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(proj));
	glMatrixMode(GL_MODELVIEW);

	/*
	glm::mat4 trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(gX, gY, gZ));
	glm::mat4 trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(-gX, -gY, gZ));
	glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(angleX), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(angleY), glm::vec3(1.0f, 0.0f, 0.0f));
	*/

	//gMatrixCamera = glm::lookAt(glm::vec3{gCamX, gCamY, gCamZ}, glm::vec3{ 0.0f, 0.0f, -1.0f }, glm::vec3{ 0.0f, 1.0f, 0.0f });
	glm::mat4 camera = glm::inverse(glm::translate(glm::mat4(1.0f), glm::vec3(gCamX, gCamY, gCamZ)));

	gCube1.setModelMatrix(camera);
	//gCube2.setModelMatrix(gMatrixCamera);

	gCube1.render();
	//gCube2.render();
	


	//glm::mat4 camera = glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 0.0f, 0.0f));
	//gCube2.render();
	/*
	glLoadMatrixf(glm::value_ptr(glm::inverse(camera) * gCube1.getModelMatrix()));
	

	gCube1.display(1);
	glLoadMatrixf(glm::value_ptr(glm::inverse(camera) * gCube2.getModelMatrix()));
	gCube2.display(10);
	*/
	print_info();

	glutSwapBuffers();   
	
	// Force another invocation of this rendering callback:
	glutPostWindowRedisplay(glutGetWindow());
}


void set_projection_matrix(){
	float width = (float) glutGet(GLUT_WINDOW_WIDTH);
	float height = (float) glutGet(GLUT_WINDOW_HEIGHT);
	glViewport(0, 0, width, height);
	proj = glm::perspective(glm::radians(45.0f), (float) width / (float) height, gNear, gFar);
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
		case GLUT_KEY_LEFT :  break;
		case GLUT_KEY_RIGHT: break;
		case GLUT_KEY_UP : break;
		case GLUT_KEY_DOWN :break;
	}
	
	
	glutPostWindowRedisplay(glutGetWindow());
}


//When mouse a button is pressed down
void mouseCallback(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		gMouseX = x;
		gMouseY = y;
	}
}

void keyboardCallback(unsigned char key, int mouse_x, int mouse_y){

	float step = 0.1f;
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
			int poligon_mode;
			glGetIntegerv(GL_POLYGON_MODE, &poligon_mode);
			if (poligon_mode == GL_LINE) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			else glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}; break;

		case 'w': gCamZ -= 0.2f; break;
		case 's': gCamZ += 0.2f; break;
		case 'a': gCamX -= 0.2f; break;
		case 'd': gCamX += 0.2f; break;

		

		case 'q' : angleX -= 1.0f; break;
		case 'Q' : angleX += 1.0f; break;
		case 'e' : angleY -= 1.0f; break;
		case 'E' : angleY += 1.0f; break;

		case 'x': gpCube = &gCube1; break;
		case 'X': gpCube = &gCube2; break;

		case 'p': gZ -= 0.5f; break;
		case 'P': gZ += 0.5f; break;

		case 'o': gX -= 0.5f; break;
		case 'O': gX += 0.5f; break;

		case 'l': gY -= 0.5f; break;
		case 'L': gY += 0.5f; break;
	}


	//Debug info
	cout << "gX: " << gX << endl;
	cout << "gY: " << gY << endl;
	cout << "gZ: " << gZ << endl;

	glutPostWindowRedisplay(glutGetWindow());
}


void init_glut(int* argc, char** argv){
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
	glutMouseFunc(mouseCallback);
	
	//glEnable(GL_CULL_FACE);
//	glFrontFace(GL_CW);
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


void renderSceneGraph(const Node* node, glm::mat4 model) {
	glm::mat4 matrix_model = model * node->mModelMatrix;

	if (node->hasChildren()) {
		for (const Node* n : node->childrens) {
			renderSceneGraph(n, matrix_model);
		}
	}else { // is a mesh
		node->render();
	}
}

void renderSceneGraph(Node* node) {
	renderSceneGraph(node, glm::mat4{ 1.0f });
}


void First_engine::run(int* argc, char** argv){

	Node n1;
	Node n2;
	Node n3;

	n1.addChild(&n2);
	n1.addChild(&n2);
	n2.addChild(&n3);

	cout << "==============" << endl;
	n1.printChilds();
	n2.printChilds();
	cout << "==============" << endl;

	renderSceneGraph(&n1);

	init_globals();
	init_glut(argc, argv);	
} 