#pragma once

#include "BlockPosition.h"
#include "BlockPosition.h"
#include "ChunkMesh.h"

enum class BlockType { Air, Dirt, Stone };

class Block
{
public:
	struct NeighbourCollision
	{
		bool front, back, right, left, top, bottom;
	};

	Block(BlockType type, BlockPosition blockPos):
		type(type), blockPos(blockPos) {}
	
	BlockType type;

	bool IsSolid() { return type != BlockType::Air; }
	
	void AddToMesh(ChunkMesh& mesh, NeighbourCollision colls) const;

	const BlockPosition blockPos;

private:
	//const ChunkPosition chunkPos;


};

