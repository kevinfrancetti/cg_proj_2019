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


class LIB_API Cube : public Node {
public:
    Cube();
	Cube(glm::mat4 model);
    Cube(const Cube& orig);
    virtual ~Cube();
	
	
	void setModelMatrix(glm::mat4 modelMatrix);
	glm::mat4 getModelMatrix();

	void render() const;

	
private:
	void randomize_colors();
	glm::mat4 m_porjection;
	unsigned char mFaceColors[6][3];
};

#endif /* CUBE_H */
