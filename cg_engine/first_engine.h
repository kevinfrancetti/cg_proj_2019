/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   First_engine.h
 * Author: kevin
 *
 * Created on November 12, 2019, 6:17 PM
 */

#ifndef FIRST_ENGINE_H
#define FIRST_ENGINE_H

#include "engine.h"

class LIB_API First_engine {
public:
    First_engine();
    First_engine(const First_engine& orig);
    virtual ~First_engine();
	void run(int*, char**);
private:

};

#endif /* FIRST_ENGINE_H */

