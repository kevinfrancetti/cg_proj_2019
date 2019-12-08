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

#define EDGE 0.5f


//VERTEX STRATS FROM 1 TO 8
#define VERTEX(x) &VERTEXES[3* ((x)-1)]
static float VERTEXES[8 * 3] = {
	//V1
	-EDGE, -EDGE, EDGE,
	//V2
	EDGE, -EDGE, EDGE,
	//V3
	EDGE, EDGE, EDGE,
	//V4
	-EDGE, EDGE, EDGE,


	//V5
	-EDGE, -EDGE, -EDGE,
	//V6
	EDGE, -EDGE, -EDGE,
	//V7
	EDGE, EDGE, -EDGE,
	//V8
	-EDGE, EDGE, -EDGE,
};


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
	//randomize_colors();
	mModelMatrix = glm::mat4(1.0f);
}




void Cube::render() {
	glm::mat4 fake_camera = glm::mat4{ 1.0f };
	glm::mat4 model_view = fake_camera * mModelMatrix;

	//Save old matrix mode
	int old_matrix_mode;
	glGetIntegerv(GL_MATRIX_MODE, &old_matrix_mode);


	//Setup modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(model_view));

	glBegin(GL_TRIANGLES);

		//FRONT
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3fv(VERTEX(1));
		glVertex3fv(VERTEX(2));
		glVertex3fv(VERTEX(3));

		glVertex3fv(VERTEX(1));
		glVertex3fv(VERTEX(3));
		glVertex3fv(VERTEX(4));

		//RIGHT
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3fv(VERTEX(2));
		glVertex3fv(VERTEX(6));
		glVertex3fv(VERTEX(3));

		glVertex3fv(VERTEX(3));
		glVertex3fv(VERTEX(6));
		glVertex3fv(VERTEX(7));

		//LEFT
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3fv(VERTEX(5));
		glVertex3fv(VERTEX(1));
		glVertex3fv(VERTEX(4));

		glVertex3fv(VERTEX(5));
		glVertex3fv(VERTEX(4));
		glVertex3fv(VERTEX(8));

		//TOP
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3fv(VERTEX(4));
		glVertex3fv(VERTEX(3));
		glVertex3fv(VERTEX(7));

		glVertex3fv(VERTEX(4));
		glVertex3fv(VERTEX(7));
		glVertex3fv(VERTEX(8));

		//BOT
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3fv(VERTEX(6));
		glVertex3fv(VERTEX(2));
		glVertex3fv(VERTEX(1));

		glVertex3fv(VERTEX(1));
		glVertex3fv(VERTEX(5));
		glVertex3fv(VERTEX(6));

		//BACK
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3fv(VERTEX(6));
		glVertex3fv(VERTEX(5));
		glVertex3fv(VERTEX(7));

		glVertex3fv(VERTEX(5));
		glVertex3fv(VERTEX(8));
		glVertex3fv(VERTEX(7));
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

