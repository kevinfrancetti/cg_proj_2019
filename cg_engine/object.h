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

class LIB_API Object {
public:
    Object();
    Object(const Object& orig);
    virtual ~Object();

	//USED FOR DEBUG
	std::string debugStringClassName();
	
	virtual void render();
	int getId();

protected:
	int mId;
private:
	//static int NEXT_ID;
};

#endif /* OBJECT_H */

