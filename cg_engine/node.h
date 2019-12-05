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
    ~Node();

	void render() const;

	virtual Node* getParent();
	virtual void setParent(Node* node);
	virtual void addChild(Node* node);
	virtual bool hasChildren() const;
	virtual int numberOfChildrens();

	virtual void setModelMatrix(glm::mat4 modelMatrix);
	virtual glm::mat4 getModelMatrix();


	//FRIENDS
	friend void render(Node*);
	friend void render(const Node*, glm::mat4);

	//DEBUG METHODS:
	void printChilds();
	
protected:
	glm::mat4 mModelMatrix{ 1.0f };

private:
	glm::mat4 model{ 1.0f };
	Node* parent;
	std::vector<Node*> childrens;
};

#endif /* NODE_H */