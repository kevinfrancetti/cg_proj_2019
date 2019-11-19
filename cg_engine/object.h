/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.h
 * Author: kevin
 *
 * Created on November 19, 2019, 2:18 PM
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "engine.h"

class LIB_API Object {
public:
    Object();
    Object(const Object& orig);
    virtual ~Object();
	
	virtual void render();
	int getId();
	static int mIdGenerator;
	int mId;
	
};

#endif /* OBJECT_H */

