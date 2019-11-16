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
#include "first_engine.h"
#include "engine.h"
#include "cube.h"
#include <GL/freeglut.h>


//GLOBALS//
float red = 1.0f; 
float green = 1.0f; 
float blue = 1.0f; 
float z_cord = 0.0f;
GLfloat first_vertex[3];
GLfloat second_vertex[3];
GLfloat third_vertex[3];
GLfloat* selectet_vertex = first_vertex;
Cube c{};

// Rotation angles:
float angleX = 0.0f, angleY = 0.0f;

// Face colors:
unsigned char faceColor[6][3];

using namespace std;

void displayCube(float edge)
{
   float size = edge / 2.0f;

   faceColor[0][0] = 255;
   faceColor[0][1] = 0;
   faceColor[0][2] = 255;
   
   // Back:
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(faceColor[0][0], faceColor[0][1], faceColor[0][2]);
	  //glColor3f(1.0f, 0.0f, 0.0f);
         glVertex3f(size, -size, -size);
         glVertex3f(-size, -size, -size);
         glVertex3f(size, size, -size);
         glVertex3f(-size, size, -size);
   glEnd();

   // Front:          
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(faceColor[1][0], faceColor[1][1], faceColor[1][2]);
         glVertex3f(-size, -size, size);
         glVertex3f(size, -size, size);
         glVertex3f(-size, size, size);
         glVertex3f(size, size, size);
   glEnd();

   // Left:       
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(faceColor[2][0], faceColor[2][1], faceColor[2][2]);
         glVertex3f(-size, size, -size);
         glVertex3f(-size, -size, -size);
         glVertex3f(-size, size, size);
         glVertex3f(-size, -size, size);
   glEnd();

   // Right:          
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(faceColor[3][0], faceColor[3][1], faceColor[3][2]);
         glVertex3f(size, -size, -size);
         glVertex3f(size, size, -size);
         glVertex3f(size, -size, size);
         glVertex3f(size, size, size);
   glEnd();

   // Bottom:         
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(faceColor[4][0], faceColor[4][1], faceColor[4][2]);
         glVertex3f(-size, -size, -size);
         glVertex3f(size, -size, -size);
         glVertex3f(-size, -size, size);
         glVertex3f(size, -size, size);
   glEnd();

   // Top:        
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(faceColor[4][0], faceColor[4][1], faceColor[4][2]);
         glVertex3f(size, size, -size);
         glVertex3f(-size, size, -size);
         glVertex3f(size, size, size);
         glVertex3f(-size, size, size);
   glEnd();
}

void init_globals(){
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
	
	glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -75.0f));
	glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(angleX), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(angleY), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 f = translation *  rotationY * rotationX;
	//f = glm::mat4{1.0f};

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(f));
	
	//displayTriangle();
	//displaySquare(20);
	//displayCube(20);
	c.display(20);
	// Swap this context's buffer:     
	glutSwapBuffers();   
	
	// Force another invocation of this rendering callback:
	glutPostWindowRedisplay(glutGetWindow());
}

void reshapeCallback(int width, int height){
	// For your information...:
	cout << "[reshape func invoked]" << endl;
	cout << "width: " << width << " height: " << height << endl;
	glViewport(0, 0, width, height);
	float left = 0.0f;
	float right = 0.0f;
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float) width / (float) height, 1.0f, 100.0f);
	glm::mat4 ortho = glm::ortho((float) -width / 2.0f, (float) width/2.0f, (float) -height/2.0f, (float) height / 2.0f, (float) 0, (float) 45);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(projection));
	glMatrixMode(GL_MODELVIEW);
   	glutPostWindowRedisplay(glutGetWindow());
}

void specialCallback(int key, int mouse_x, int mouse_y){
	
	float step = 4.0f;
	switch(key){
		case GLUT_KEY_LEFT : selectet_vertex[0] -= step; break;
		case GLUT_KEY_RIGHT: selectet_vertex[0] += step; break;
		case GLUT_KEY_UP: selectet_vertex[1] += step; break;
		case GLUT_KEY_DOWN : selectet_vertex[1] -= step; break;
		case GLUT_KEY_PAGE_UP: selectet_vertex[2] += step; break; // INVERTED FOR Z!!
		case GLUT_KEY_PAGE_DOWN: selectet_vertex[2] -= step; break;//INVERTED FOR Z!!
	}
	
	cout << "X: " << selectet_vertex[0] << endl;
	cout << "Y: " << selectet_vertex[1] << endl;
	cout << "Z: " << selectet_vertex[2] << endl;
	cout << "mouseX: " << mouse_x << "mouseY: " << mouse_y << endl;
	
	glutPostWindowRedisplay(glutGetWindow());
}

void keyboardCallback(unsigned char key, int mouse_x, int mouse_y){
	switch(key){
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
		case '2' : selectet_vertex = second_vertex; break;
		case '3' : selectet_vertex = third_vertex; break;
	}
	cout << "Z: " << z_cord << endl;
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
	
   	glClearColor(1.0f, 0.6f, 0.1f, 1.0f); // RGBA components
	glEnable(GL_DEPTH_TEST);
	
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
	init_globals();
	init_glut(argc, argv);	
} 