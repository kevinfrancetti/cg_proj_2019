/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   node.cpp
 * Author: kevin
 * 
 * Created on November 20, 2019, 4:16 PM
 */


#include "engine.h"
#include <iostream>

using namespace std;

Node::Node() : mModelMatrix {1.0f} {
	cout << "Constructor: " << debugStringClassName() << endl;
}


Node::Node(const Node& orig) : Object(orig) {
	cout << "Copy constructor: " << debugStringClassName() << endl;
}


Node::~Node() {
	cout << "Destructor: " << debugStringClassName() << endl;
}


void Node::setModelMatrix(glm::mat4 modelMatrix) {
	mModelMatrix = modelMatrix;
}

glm::mat4 Node::getModelMatrix() {
	return mModelMatrix;
}

void Node::render() const {
	//cout << "render() : "<<  debugStringClassName()  << " ID: " << mId << endl;
}

Node* Node::getParent() {
	return parent;
}

void Node::setParent(Node* node){
	
}

void Node::addChild(Node* node) {
	node->parent = this;
	childrens.push_back(node);
}

bool Node::hasChildren() const {
	return !childrens.empty();
}

int Node::numberOfChildrens() {
	return childrens.size();
}


void Node::printChilds() const {
	cout << "Node: " << mId  << " Chidlrens:" << endl;
	for (const Node* x : childrens) {
		cout << "\tChild ID: " << x->mId << endl;
	}

}