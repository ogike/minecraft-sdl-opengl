#pragma once

#include "BlockPosition.h"
#include "ChunkPosition.h"
#include "ChunkMesh.h"
#include <GL/glew.h>

#include "Constants.h"

enum class BlockType { Air, Dirt, Grass, Stone };
enum class TextureSide { Top, Side, Bottom };

class ChunkMesh;

class Block
{
public:
	struct NeighbourCollision
	{
		bool front, back, right, left, top, bottom;
	};

	/*struct TexturePosition
	{
		int topLeft, topRight, btmLeft, btmRight;
	};*/

	Block::Block(BlockType type, BlockPosition blockPos, ChunkPosition chunkPos) :
		type(type), blockPos(blockPos), chunkPos(chunkPos){
		SetTextures();
	}
	
	BlockType type;

	bool IsSolid() { return type != BlockType::Air; }
	
	void AddToMesh(ChunkMesh& mesh, NeighbourCollision colls) const;

	const BlockPosition blockPos;
	const ChunkPosition chunkPos;

private:
	glm::vec2 topTexPos; //coordinates for the top-left corner in the tex atlas
	glm::vec2 sideTexPos;
	glm::vec2 bottomTexPos;
	void SetTextures(); 
	glm::vec2 getTexPos(int col, int row);
};

