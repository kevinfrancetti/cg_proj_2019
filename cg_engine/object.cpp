/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.cpp
 * Author: kevin
 * 
 * Created on November 19, 2019, 2:18 PM
 */

#include <iostream>
#include "engine.h"

using namespace std;

//int Object::NEXT_ID = 0;

string Object::debugStringClassName() {
	return typeid(*this).name();
}

Object::Object() {
	//cout << "[Object constructor WITH ID: " << NEXT_ID << "]" <<  endl;
	cout << "[Object constructor WITH ID: " << mId << "]  CLASS: " << debugStringClassName() <<  endl;

	//mId = NEXT_ID++;
}

Object::Object(const Object& orig) {
	//cout << "[Object Copy constructor WITH ID: " << NEXT_ID << "]" << endl;
	cout << "[Object Copy constructor WITH ID: " << mId << "]" << endl;

	//this->mId = NEXT_ID++;
}

Object::~Object() {
	//cout << "[Object destructor WITH ID: " << NEXT_ID << "]" << endl;
	cout << "[Object destructor WITH ID: " << mId << "]" << endl;
}

void Object::render(){
	
}

int Object::getId(){
	return mId;
}

