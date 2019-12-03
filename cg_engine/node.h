/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   node.h
 * Author: kevin
 *
 * Created on November 20, 2019, 4:16 PM
 */

#ifndef NODE_H
#define NODE_H

#include "glm/fwd.hpp"

class Node : public Object{
public:
    Node();
    Node(const Node& orig);
    virtual ~Node();

	virtual void loadModelMatrix(glm::mat4);
	
private:
	Node* parent;
		
	glm::mat4 model{1.0f};
};

#endif /* NODE_H */

