#pragma once

#include "BlockPosition.h"
#include "ChunkPosition.h"
#include "Block.h"
#include "ChunkMesh.h"
#include "World.h"
#include <map>

class World;

class Chunk
{
public:
	Chunk(ChunkPosition pos, World* world) : myChunkPos(pos), myWorld(world) {}

	//world or in-chunk pos?
	void AddBlock(Block * block, BlockPosition pos) {
		blocks[pos] = block;
	}

	void BuildMesh();
	void draw() { myMesh.draw(); }

	Block::NeighbourCollision CheckNeighbours(Block* block);
	bool IsSolidAt(BlockPosition pos);

	const ChunkPosition myChunkPos;

private:

	std::map<BlockPosition, Block*> blocks;
	ChunkMesh myMesh;
	World* myWorld;
};

