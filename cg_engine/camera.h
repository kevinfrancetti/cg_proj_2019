#pragma once

class LIB_API Camera : public Node {
public:
	Camera();
	~Camera();
 
	void activateMovingCamera();
 
private:
	void mouse_passive_motion_cb(int x, int y);

	glm::vec3 gCameraBackv3;
	glm::vec3 gCameraFrontv3;
	glm::vec3 gCameraUpv3{ 0.0f, 1.0f, 0.0f };

	float yaw = 0;
	float pitch = 0;
};