#include "Block.h"


void Block::AddToMesh(ChunkMesh& mesh, NeighbourCollision colls) const
{
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
			sideTexPos //tex
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
			sideTexPos //tex
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
			sideTexPos //tex
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
			sideTexPos //tex
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
			topTexPos //tex
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
			bottomTexPos //tex
		);
	
}

void Block::SetTextures()
{

	switch (type)
	{
		case BlockType::Dirt:

			topTexPos = glm::vec2(0, 0);;
			sideTexPos = glm::vec2(2 * TEX_SIZE, 0);
			bottomTexPos = glm::vec2(3 * TEX_SIZE, 0);
			break;
		case BlockType::Stone:
			topTexPos = glm::vec2(1 * TEX_SIZE, 0);
			sideTexPos = topTexPos;
			bottomTexPos = topTexPos;
			break;
		default: //invalid texture
			topTexPos = glm::vec2(6 * TEX_SIZE, 2 * TEX_SIZE);
			sideTexPos = topTexPos;
			bottomTexPos = topTexPos;
			break;
	}
	//topRight = topLeft +
}
