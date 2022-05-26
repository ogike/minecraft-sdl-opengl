#include "Block.h"

/*
void Block::AddToMesh(ChunkMesh& mesh, NeighbourCollision colls) const
{
	glm::vec3 origPos = blockPos.GetGlobalPos(chunkPos);

	//front
	if(!colls.front)
		mesh.addFace(
			origPos,
			//vertices
			glm::vec3(-0.5, -0.5, +0.5), //btm left
			glm::vec3(+0.5, -0.5, +0.5), //btm right
			glm::vec3(-0.5, +0.5, +0.5), //top left
			glm::vec3(+0.5, +0.5, +0.5), //top right
			glm::vec3(0, 0, 1), //normal
			sideTexPos //tex
		);
	
	//back
	if (!colls.back)
		mesh.addFace(
			origPos,
			//vertices
			glm::vec3(+0.5, -0.5, -0.5), 
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
			//vertices
			glm::vec3(+0.5, -0.5, +0.5), 
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
			//vertices
			glm::vec3(-0.5, -0.5, -0.5), 
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
			//vertices
			glm::vec3(-0.5, +0.5, +0.5), 
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
			//vertices
			glm::vec3(-0.5, -0.5, -0.5), 
			glm::vec3(+0.5, -0.5, -0.5),
			glm::vec3(-0.5, -0.5, +0.5),
			glm::vec3(+0.5, -0.5, +0.5),
			glm::vec3(0, -1, 0), //normal
			bottomTexPos //tex
		);
	
}
*/
/*
void Block::SetTextures()
{

	switch (type)
	{
		case BlockType::Dirt:
			topTexPos = getTexPos(2, 0);
			sideTexPos = getTexPos(2, 0);
			bottomTexPos = getTexPos(2, 0);
			break;
		case BlockType::Grass:
			topTexPos = getTexPos(0, 0);
			sideTexPos = getTexPos(3, 0);
			bottomTexPos = getTexPos(2, 0);
			break;
		case BlockType::Stone:
			topTexPos = getTexPos(1, 0);
			sideTexPos = getTexPos(1, 0);
			bottomTexPos = getTexPos(1, 0);
			break;
		case BlockType::Iron:
			topTexPos = getTexPos(1, 2);
			sideTexPos = getTexPos(1, 2);
			bottomTexPos = getTexPos(1, 2);
			break;
		case BlockType::Coal:
			topTexPos = getTexPos(2, 2);
			sideTexPos = getTexPos(2, 2);
			bottomTexPos = getTexPos(2, 2);
			break;
		default: //invalid texture
			topTexPos = getTexPos(6, 3);
			sideTexPos = getTexPos(6, 3);
			bottomTexPos = getTexPos(6, 3);
			break;
	}
}

//gives back the top left corner of the tile in the atlas
glm::vec2 Block::getTexPos(int col, int row)
{
	return glm::vec2(col * TEX_SIZE, 1 -  row * TEX_SIZE );
}
*/
