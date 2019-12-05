/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cube.cpp
 * Author: kevin
 * 
 * Created on November 15, 2019, 8:12 PM
 */

#include "engine.h"
#include <iostream>
#include <GL/freeglut.h>
#include <time.h>

using namespace std;

static float EDGE = 0.5f;




void Cube::randomize_colors(){
	int col = sizeof(mFaceColors[0]);
	int row = sizeof(mFaceColors)/col;
	srand(time(0));
	
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			mFaceColors[i][j] = rand() % 255;
}

void Cube::IncrementAngleX(float incrementValue){
	mAngleX += incrementValue;
}

void Cube::IncrementAngleY(float incrementValue){
	mAngleY += incrementValue;
}

void Cube::IncrementCordX(float incrementValue){
	mPosition.x += incrementValue;
}

void Cube::IncrementCordY(float incrementValue){
	mPosition.y += incrementValue;
}

void Cube::IncrementCordZ(float incrementValue){
	mPosition.z += incrementValue;
}

glm::mat4 Cube::getModelMatrix(){
	return mModelMatrix;
}

void Cube::setModelMatrix(glm::mat4 modelMatrix) {
	mModelMatrix = modelMatrix;
}


Cube::Cube() {
	cout << "Constructor: " << debugStringClassName() << endl;
	randomize_colors();
	mPosition = glm::vec3{0.0f, 0.0f, -95.0f};
	glm::mat4 translation = glm::translate(glm::mat4(1.0f), mPosition);
	glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(mAngleX+30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(mAngleY), glm::vec3(0.0f, 1.0f, 0.0f));
	mModelMatrix = translation *  rotationY * rotationX;	
}


void Cube::render() {

	glm::mat4 camera = glm::mat4{ 1.0f };
	glm::mat4 model_view = camera * mModelMatrix;

	//Save old matrix mode
	int old_matrix_mode;
	glGetIntegerv(GL_MATRIX_MODE, &old_matrix_mode);


	//Setup modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(model_view));

	glBegin(GL_TRIANGLES);
		glVertex3f(-EDGE, -EDGE, EDGE);
		glVertex3f(EDGE, -EDGE, EDGE);
		glVertex3f(EDGE, EDGE, EDGE);
	glEnd();


	//Restore previuos matrix mode
	glMatrixMode(old_matrix_mode);

}


void Cube::display(float edge){
	float size = edge / 2.0f;
	
   // Back:
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(mFaceColors[0][0], mFaceColors[0][1], mFaceColors[0][2]);
         glVertex3f(size, -size, -size);
      glColor3ub(mFaceColors[1][0], mFaceColors[1][1], mFaceColors[1][2]);
         glVertex3f(-size, -size, -size);
      glColor3ub(mFaceColors[2][0], mFaceColors[2][1], mFaceColors[2][2]);
         glVertex3f(size, size, -size);
      glColor3ub(mFaceColors[3][0], mFaceColors[3][1], mFaceColors[3][2]);
         glVertex3f(-size, size, -size);
   glEnd();

   // Front:          
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(mFaceColors[1][0], mFaceColors[1][1], mFaceColors[1][2]);
         glVertex3f(-size, -size, size);
         glVertex3f(size, -size, size);
         glVertex3f(-size, size, size);
         glVertex3f(size, size, size);
   glEnd();

   // Left:       
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(mFaceColors[2][0], mFaceColors[2][1], mFaceColors[2][2]);
         glVertex3f(-size, size, -size);
         glVertex3f(-size, -size, -size);
         glVertex3f(-size, size, size);
         glVertex3f(-size, -size, size);
   glEnd();

   // Right:          
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(mFaceColors[3][0], mFaceColors[3][1], mFaceColors[3][2]);
         glVertex3f(size, -size, -size);
         glVertex3f(size, size, -size);
         glVertex3f(size, -size, size);
         glVertex3f(size, size, size);
   glEnd();

   // Bottom:         
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(mFaceColors[4][0], mFaceColors[4][1], mFaceColors[4][2]);
         glVertex3f(-size, -size, -size);
         glVertex3f(size, -size, -size);
         glVertex3f(-size, -size, size);
         glVertex3f(size, -size, size);
   glEnd();

   // Top:        
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(mFaceColors[4][0], mFaceColors[4][1], mFaceColors[4][2]);
      glColor3f(1.0f, 0.0f, 0.0f);
         glVertex3f(size, size, -size);
      glColor3f(0.0f, 1.0f, 0.0f);
         glVertex3f(-size, size, -size);
      glColor3f(1.0f, 0.0f, 1.0f);
         glVertex3f(size, size, size);
      glColor3f(0.0f, 0.0f, 1.0f);
         glVertex3f(-size, size, size);
   glEnd();
}

Cube::Cube(const Cube& orig) {
}

Cube::~Cube() {
	cout << "Destructor: " << debugStringClassName() << endl;
}

