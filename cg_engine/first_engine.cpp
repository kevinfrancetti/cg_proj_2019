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


//GLOBALS//
float gNear = 1.0f;
float gFar = 100.0f;
float red = 1.0f; 
float green = 1.0f; 
float blue = 1.0f; 
float z_cord = 0.0f;
GLfloat first_vertex[3];
GLfloat second_vertex[3];
GLfloat third_vertex[3];
GLfloat* selectet_vertex = first_vertex;
Cube* gpCube{};
Cube gCube1{};
Cube gCube2{};

// Rotation angles:
float angleX = 0.0f, angleY = 0.0f;

// Face colors:
unsigned char faceColor[6][3];

using namespace std;


void init_globals(){
	gpCube = &gCube1;
	first_vertex[0] = 15;
	first_vertex[1] = 0;
	first_vertex[2] = 0;
	second_vertex[0] = -15;
	second_vertex[1] = 0;
	second_vertex[2] = 0;
	third_vertex[0] = 0;
	third_vertex[1] = 15;
	third_vertex[2] = 0;
}

void displayTriangle(){
	glBegin(GL_TRIANGLES);
	glColor3f(red, 0.0f, 0.0f);
	glVertex3fv(first_vertex);
	glColor3f(0.0f, green, 0.0f);
	glVertex3fv(second_vertex);
	glColor3f(0.0f, 0.0f, blue);
	glVertex3fv(third_vertex);
	glEnd();
}


void displaySquare(float size){
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(red, 0.0f, 0.0f);
	glVertex3f(-size, -size, z_cord);
	glColor3f(0.0f, green, 0.0f);
	glVertex3f(-size, size, z_cord);
	glColor3f(0.0f, 0.0f, blue);
	glVertex3f(size, -size, z_cord);
	glVertex3f(size, size, z_cord);
	glEnd();
}


void displayCallback(){
	// Clear the screen:         
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);      

	glMatrixMode(GL_MODELVIEW);
	//glLoadMatrixf(glm::value_ptr(f));
	glLoadMatrixf(glm::value_ptr(gCube1.GetMatrixModelView()));
	gCube1.display(20);
	glLoadMatrixf(glm::value_ptr(gCube2.GetMatrixModelView()));
	gCube2.display(30);

	//displayTriangle();
	//displaySquare(20);
	//displayCube(20);
	//gpCube->display(50);
	//gCube2.display(30);
	// Swap this context's buffer:     
	glutSwapBuffers();   
	
	// Force another invocation of this rendering callback:
	glutPostWindowRedisplay(glutGetWindow());
}

void set_projection_matrix(){
	float width = (float) glutGet(GLUT_WINDOW_WIDTH);
	float height = (float) glutGet(GLUT_WINDOW_HEIGHT);
	glViewport(0, 0, width, height);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float) width / (float) height, gNear, gFar);
	glm::mat4 ortho = glm::ortho((float) -width / 2.0f, (float) width/2.0f, (float) -height/2.0f, (float) height / 2.0f, gNear, gFar);
	glMatrixMode(GL_PROJECTION);
	//glLoadMatrixf(glm::value_ptr(projection));
	glLoadMatrixf(glm::value_ptr(projection));
	glMatrixMode(GL_MODELVIEW);
}

void reshapeCallback(int width, int height){
	// For your information...:
	cout << "[reshape func invoked]" << endl;
	cout << "width: " << width << " height: " << height << endl;
	//cout << "widthByeGlut: " << glutGet(GLUT_WINDOW_WIDTH) << " heightByeGlut: " << glutGet(GLUT_WINDOW_HEIGHT) << endl;

	set_projection_matrix();
	
   	glutPostWindowRedisplay(glutGetWindow());
}

void specialCallback(int key, int mouse_x, int mouse_y){
	
	float step = 10.0f;
	switch(key){
		case GLUT_KEY_LEFT : gpCube->IncrementAngleY(-step); break;
		case GLUT_KEY_RIGHT: gpCube->IncrementAngleY(step); break;
		case GLUT_KEY_UP : gpCube->IncrementAngleX(step); break;
		case GLUT_KEY_DOWN : gpCube->IncrementAngleX(-step); break;
		
		/*
		case GLUT_KEY_LEFT : selectet_vertex[0] -= step; break;
		case GLUT_KEY_RIGHT: selectet_vertex[0] += step; break;
		case GLUT_KEY_UP: selectet_vertex[1] += step; break;
		case GLUT_KEY_DOWN : selectet_vertex[1] -= step; break;
		case GLUT_KEY_PAGE_UP: selectet_vertex[2] += step; break; // INVERTED FOR Z!!
		case GLUT_KEY_PAGE_DOWN: selectet_vertex[2] -= step; break;//INVERTED FOR Z!!
		*/ 
	}
	
	cout << "AngleX: " <<gpCube->mAngleX << endl;
	cout << "AngleY: " <<gpCube->mAngleY << endl;
	
	cout << "mouseX: " << mouse_x << "mouseY: " << mouse_y << endl;
	
	glutPostWindowRedisplay(glutGetWindow());
}

void keyboardCallback(unsigned char key, int mouse_x, int mouse_y){

	float step = 5.0f;
	switch(key){
		case 'n' : gNear -= step; set_projection_matrix(); break;
		case 'N' : gNear += step; set_projection_matrix(); break;
		case 'f' : gFar -= step; set_projection_matrix(); break;
		case 'F' : gFar += step; set_projection_matrix(); break;
		case 'R' : red += 0.01f; break;
		case 'r' : red -= 0.01f; break;
		case 'G' : green += 0.01f; break;
		case 'g' : green -= 0.01f; break;
		case 'B' : blue += 0.01f; break;
		case 'b' : blue -= 0.01f; break;
		case 'a' : angleX -= 1.0f; break;
		case 'A' : angleX += 1.0f; break;
		case 's' : angleY -= 1.0f; break;
		case 'S' : angleY += 1.0f; break;
		case 'z' : z_cord -= 1.0f; break;
		case 'Z' : z_cord += 1.0f; break;
		case '1' : selectet_vertex = first_vertex; break; 
		//case '2' : selectet_vertex = second_vertex; break;
		case '3' : selectet_vertex = third_vertex; break;

		case '4' : gpCube->IncrementCordX(-step); break;
		case '6' : gpCube->IncrementCordX(step); break;
		case '8' : gpCube->IncrementCordY(step); break;
		case '2' : gpCube->IncrementCordY(-step); break;
		case '7' : gpCube->IncrementCordZ(-step); break;
		case '9' : gpCube->IncrementCordZ(step); break;

		case 'x': gpCube = &gCube1; break;
		case 'X': gpCube = &gCube2; break;
	}
	cout << "near: " << gNear << endl;
	cout << "far: " << gFar << endl;
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
	
	/*
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);
	*/
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

	/*
	Object o1;
	Object o2 = o1;
	cout << o1.getId() << endl;
	cout << o2.getId() << endl;
	*/
	/*
	MeshCube m1;
	MeshCube m2;
	cout << m1.getId() << endl;
	cout << m2.getId() << endl;
	*/
	
	init_globals();
	init_glut(argc, argv);	
} 