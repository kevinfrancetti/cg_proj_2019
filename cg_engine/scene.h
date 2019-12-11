#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
	Scene();
	Scene(Node* root);
	~Scene();
	void renderSceneGraph();
	void renderSceneGraph(const Node* node, glm::mat4 model);
	void setViewMatrix(glm::mat4 viewMatrix);


private:
	Node* mRoot;
	glm::mat4 mView;
};

#endif /* SCENE_H */
