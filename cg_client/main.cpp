/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kevin
 *
 * Created on October 8, 2019, 7:56 PM
 */

#include <iostream>
#include <typeinfo>
#include "engine.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	for(int i = 0; i < argc; i++){
		cout << argv[i] << endl;
	}


	//cout << typeid(First_engine).name() << endl;
	//cout << glm::to_string(glm::mat4{ 0.5f }) << endl;

	First_engine eng{};


	eng.run(&argc, argv);

	cout << "ola" << endl;
    return 0;
}

