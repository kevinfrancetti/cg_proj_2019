
#include <iostream>
#include "engine.h"

using namespace std;

MeshCube::MeshCube() {
	cout << "[MeshCube constructor WITH ID: " << mId << "]" << endl;
}


MeshCube::~MeshCube() {
	cout << "[MeshCube Destructor WITH ID: " << mId << "]" << endl;
}
