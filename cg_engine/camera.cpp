#include "engine.h"
#include <GL/freeglut.h>



Camera::Camera() {
}


Camera::~Camera() {
}





void Camera::activateMovingCamera() {

}



void Camera::mouse_passive_motion_cb(int x, int y) {
	//IF MOUSE IS ALREADY IN THE CENTER SKIP THIS FUNCTION
	if (x == glutGet(GLUT_WINDOW_WIDTH) / 2) {
		if (y == glutGet(GLUT_WINDOW_HEIGHT) / 2) {
			return;
		}
	}

	float sensitivity = 1.0f;

	//SPERIMENTAL
	if (x > glutGet(GLUT_WINDOW_WIDTH) / 2) {
		yaw += sensitivity;
	}
	else if (x < glutGet(GLUT_WINDOW_WIDTH) / 2)  yaw -= sensitivity;

	if (y > glutGet(GLUT_WINDOW_HEIGHT) / 2) {
		pitch -= sensitivity;
	}
	else if (y < glutGet(GLUT_WINDOW_HEIGHT) / 2) pitch += sensitivity;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	gCameraFrontv3 = glm::normalize(front);

	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
	glutPostWindowRedisplay(glutGetWindow());
}