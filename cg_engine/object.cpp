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
#include "object.h"

using namespace std;

int Object::mIdGenerator = 0;


Object::Object() {
	cout << "[Object constructor]" << endl;
	mId = mIdGenerator++;
}

Object::Object(const Object& orig) {
	cout << "[Object copy constructor]" << endl;
}

Object::~Object() {
	cout << "[Object destructor]" << endl;
}

void Object::render(){
	
}

int Object::getId(){
	return mId;
}

