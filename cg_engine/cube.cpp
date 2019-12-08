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


Cube::Cube(glm::mat4 model) {
	mModelMatrix = model;
}


void Cube::render() {
	glm::mat4 model_view = mModelMatrix;

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


Cube::Cube(const Cube& orig) {
}

Cube::~Cube() {
	cout << "Destructor: " << debugStringClassName() << endl;
}

