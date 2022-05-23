#include "Block.h"

void Block::AddToMesh(ChunkMesh& mesh, NeighbourCollision colls) const
{
	//TODO: air checks

	glm::vec3 origPos = blockPos.GetGlobalPos(chunkPos);

	//front
	if(!colls.front)
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
	if (!colls.back)
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
	if (!colls.right)
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
	if (!colls.left)
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
	if (!colls.top)
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
	if (!colls.bottom)
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