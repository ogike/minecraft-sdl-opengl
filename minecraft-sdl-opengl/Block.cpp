#include "Block.h"

void Block::AddToMesh(ChunkMesh& mesh) const
{
	//TODO: air checks

	glm::vec3 origPos = glm::vec3(blockPos.GetX(), blockPos.GetY(), blockPos.GetZ());

	//front
	mesh.addFace(
		origPos,
		glm::vec3(-0.5, -0.5, +0.5), //vertices
		glm::vec3(+0.5, -0.5, +0.5),
		glm::vec3(-0.5, +0.5, +0.5),
		glm::vec3(+0.5, +0.5, +0.5),
		glm::vec3(0, 0, 1), //normal
		glm::vec2(0, 0) //tex
	);
	
	//back
	mesh.addFace(
		origPos,
		glm::vec3(+0.5, -0.5, -0.5), //vertices
		glm::vec3(-0.5, -0.5, -0.5),
		glm::vec3(+0.5, +0.5, -0.5),
		glm::vec3(-0.5, +0.5, -0.5),
		glm::vec3(0, 0, -1), //normal
		glm::vec2(0, 0) //tex
	);
	
	//right
	mesh.addFace(
		origPos,
		glm::vec3(+0.5, -0.5, +0.5), //vertices
		glm::vec3(+0.5, -0.5, -0.5),
		glm::vec3(+0.5, +0.5, +0.5),
		glm::vec3(+0.5, +0.5, -0.5),
		glm::vec3(1, 0, 0), //normal
		glm::vec2(0, 0) //tex
	);

	//left
	mesh.addFace(
		origPos,
		glm::vec3(-0.5, -0.5, -0.5), //vertices
		glm::vec3(-0.5, -0.5, +0.5),
		glm::vec3(-0.5, +0.5, -0.5),
		glm::vec3(-0.5, +0.5, +0.5),
		glm::vec3(-1, 0, 0), //normal
		glm::vec2(0, 0) //tex
	);

	//top
	mesh.addFace(
		origPos,
		glm::vec3(-0.5, +0.5, +0.5), //vertices
		glm::vec3(+0.5, +0.5, +0.5),
		glm::vec3(-0.5, +0.5, -0.5),
		glm::vec3(+0.5, +0.5, -0.5),
		glm::vec3(0, 1, 0), //normal
		glm::vec2(0, 0) //tex
	);

	//bottom
	mesh.addFace(
		origPos,
		glm::vec3(-0.5, -0.5, -0.5), //vertices
		glm::vec3(+0.5, -0.5, -0.5),
		glm::vec3(-0.5, -0.5, +0.5),
		glm::vec3(+0.5, -0.5, +0.5),
		glm::vec3(0, -1, 0), //normal
		glm::vec2(0, 0) //tex
	);
	
}