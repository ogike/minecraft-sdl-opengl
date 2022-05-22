#pragma once

#include "BlockPosition.h"
#include "BlockPosition.h"
#include "ChunkMesh.h"

enum class BlockType { Air, Dirt, Stone };

class Block
{
public:
	Block(BlockType type, BlockPosition blockPos):
		type(type), blockPos(blockPos) {}
	
	BlockType type;

	bool IsSolid() { return type != BlockType::Air; }
	
	void AddToMesh(ChunkMesh& mesh) const;


private:
	//const ChunkPosition chunkPos;
	const BlockPosition blockPos;


};

