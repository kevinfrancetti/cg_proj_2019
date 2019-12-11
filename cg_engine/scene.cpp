#include "engine.h"
#include <GL/freeglut.h>

Scene::Scene() {}
Scene::Scene(Node* root) : mRoot{root} {}
Scene::~Scene() {}

void Scene::setViewMatrix(glm::mat4 viewMatrix) {
	mView = viewMatrix;
}

void Scene::renderSceneGraph() {
	renderSceneGraph(mRoot, glm::mat4{ 1.0f });
}

void Scene::renderSceneGraph(const Node* node, glm::mat4 model) {
	glm::mat4 matrix_model = model * node->mModelMatrix;
	//node->printChilds();//DEBUG INFO
	if (node->hasChildren()) {
		for (const Node* n : node->childrens) {
			renderSceneGraph(n, matrix_model);
		}
	}
	else { // is a mesh
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(mView * matrix_model));
		node->render();
	}
}