#pragma once

#include "BlockPosition.h"
#include "BlockPosition.h"
#include "Block.h"
#include "ChunkMesh.h"
#include <map>

class Chunk
{
public:
	Chunk(ChunkPosition pos) : myChunkPos(pos) {}

	//world or in-chunk pos?
	void AddBlock(Block * block, BlockPosition pos) {
		blocks[pos] = block;
	}

	void BuildMesh();
	void draw() { myMesh.draw(); }

	const ChunkPosition myChunkPos;

private:

	std::map<BlockPosition, Block*> blocks;
	ChunkMesh myMesh;

};

