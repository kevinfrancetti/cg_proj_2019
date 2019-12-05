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

void Node::render() {

}


void Node::loadModelMatrix(glm::mat4 m){
}

