/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cube.h
 * Author: kevin
 *
 * Created on November 15, 2019, 8:12 PM
 */

#ifndef CUBE_H
#define CUBE_H

#include "engine.h"

class LIB_API Cube {
public:
    Cube();
    Cube(const Cube& orig);
	void display(float edge);
    virtual ~Cube();
private:
	void randomize_colors();
	glm::mat4 m_model_view;
	glm::mat4 m_porjection;
	unsigned char m_face_colors[6][3];
};

#endif /* CUBE_H */

