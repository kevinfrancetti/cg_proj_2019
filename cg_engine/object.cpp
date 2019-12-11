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
#include <typeinfo>
#include "engine.h"

using namespace std;

static int NEXT_ID = 0;

string Object::debugStringClassName() const {
	return typeid(*this).name();
}

Object::Object() : mId {NEXT_ID++} {
	cout << "[Object constructor WITH ID: " << mId << "] :  " << debugStringClassName() <<  endl;
}

Object::Object(const Object& orig) : mId{NEXT_ID++} {
	cout << "[Object Copy constructor WITH ID: " << mId << " - " <<  debugStringClassName() << "]" << endl;
	test = orig.test;
}

Object::~Object() {
	cout << "[Object destructor WITH ID: " << mId << " - " << debugStringClassName() << "]" << endl;
}


int Object::getId(){
	return mId;
}

