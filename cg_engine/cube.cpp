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

#include "cube.h"
#include <iostream>
#include <GL/freeglut.h>

using namespace std;

void LIB_API Cube::randomize_colors(){
	int col = sizeof(m_face_colors[0]);
	int row = sizeof(m_face_colors)/col;
	srand(time(0));
	
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			m_face_colors[i][j] = rand() % 255;
	
}

Cube::Cube() {
	randomize_colors();
	glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -75.0f));
	//glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(angleX), glm::vec3(1.0f, 0.0f, 0.0f));
	//glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(angleY), glm::vec3(0.0f, 1.0f, 0.0f));
	m_model_view = translation;// *  rotationY * rotationX;	
}


void LIB_API Cube::display(float edge){
	float size = edge / 2.0f;
	
   // Back:
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(m_face_colors[0][0], m_face_colors[0][1], m_face_colors[0][2]);
         glVertex3f(size, -size, -size);
      glColor3ub(m_face_colors[1][0], m_face_colors[1][1], m_face_colors[1][2]);
         glVertex3f(-size, -size, -size);
      glColor3ub(m_face_colors[2][0], m_face_colors[2][1], m_face_colors[2][2]);
         glVertex3f(size, size, -size);
      glColor3ub(m_face_colors[3][0], m_face_colors[3][1], m_face_colors[3][2]);
         glVertex3f(-size, size, -size);
   glEnd();

   // Front:          
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(m_face_colors[1][0], m_face_colors[1][1], m_face_colors[1][2]);
         glVertex3f(-size, -size, size);
         glVertex3f(size, -size, size);
         glVertex3f(-size, size, size);
         glVertex3f(size, size, size);
   glEnd();

   // Left:       
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(m_face_colors[2][0], m_face_colors[2][1], m_face_colors[2][2]);
         glVertex3f(-size, size, -size);
         glVertex3f(-size, -size, -size);
         glVertex3f(-size, size, size);
         glVertex3f(-size, -size, size);
   glEnd();

   // Right:          
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(m_face_colors[3][0], m_face_colors[3][1], m_face_colors[3][2]);
         glVertex3f(size, -size, -size);
         glVertex3f(size, size, -size);
         glVertex3f(size, -size, size);
         glVertex3f(size, size, size);
   glEnd();

   // Bottom:         
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(m_face_colors[4][0], m_face_colors[4][1], m_face_colors[4][2]);
         glVertex3f(-size, -size, -size);
         glVertex3f(size, -size, -size);
         glVertex3f(-size, -size, size);
         glVertex3f(size, -size, size);
   glEnd();

   // Top:        
   glBegin(GL_TRIANGLE_STRIP);
      glColor3ub(m_face_colors[4][0], m_face_colors[4][1], m_face_colors[4][2]);
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
}

