#pragma once

#include "BlockPosition.h"
#include "ChunkPosition.h"
#include "ChunkMesh.h"

enum class BlockType { Air, Dirt, Stone };

class Block
{
public:
	struct NeighbourCollision
	{
		bool front, back, right, left, top, bottom;
	};

	Block(BlockType type, BlockPosition blockPos, ChunkPosition chunkPos):
		type(type), blockPos(blockPos), chunkPos(chunkPos) {}
	
	BlockType type;

	bool IsSolid() { return type != BlockType::Air; }
	
	void AddToMesh(ChunkMesh& mesh, NeighbourCollision colls) const;

	const BlockPosition blockPos;
	const ChunkPosition chunkPos;


};

