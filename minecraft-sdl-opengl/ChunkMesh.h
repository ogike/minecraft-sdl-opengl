#pragma once

#include <GL/glew.h>

#include <vector>
#include <glm/glm.hpp>

#include <iostream>
#include "Block.h"

#include "Constants.h"


/// <summary>
/// Copied most of this from GLUtils/Mesh_OGL3
/// </summary>
class ChunkMesh
{
public:
	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texcoord;
	};

	ChunkMesh(void) : vertices(), indices(), 
		vertexArrayObject(), vertexBuffer(), indexBuffer() {}
	~ChunkMesh(void);

	void initBuffers();
	void draw();

	void addFace(glm::vec3 origoPos, 
		glm::vec3 facePosTopLeft, glm::vec3 facePosTopRight, 
		glm::vec3 facePosBtmLeft, glm::vec3 facePosBtmRight, 
		glm::vec3 normal, glm::vec2 texPos);

	/*void addVertex(const Vertex& vertex) {
		vertices.push_back(vertex);
	}
	void addIndex(unsigned int index) {
		indices.push_back(index);
	}*/
private:
	GLuint vertexArrayObject;
	GLuint vertexBuffer;
	GLuint indexBuffer;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	bool inited = false;
};
