#pragma once

#include "BlockPosition.h"
#include "ChunkPosition.h"
#include "Block.h"
#include "TextureAtlasHandler.hpp"
#include "ChunkMesh.h"
#include "World.h"
#include <map>

class World;

class Chunk
{
public:
	Chunk(ChunkPosition pos, World* world) : myChunkPos(pos), myWorld(world) {
		//blocks = new Block[CHUNK_SIZE * CHUNK_SIZE * CHUNK_HEIGHT];
	}

	////world or in-chunk pos?
	//void AddBlock(Block * block, BlockPosition pos) {
	//	blocks[pos] = block;
	//}

	Block& GetBlockAt(int x, int y, int z);

	void SetBlock(int x, int y, int z, BlockType newType);

	void BuildMesh();
	void draw() { myMesh.draw(); }

	bool IsSolidAt(int x, int y, int z);

	const ChunkPosition myChunkPos;

private:

	//stored in rows: x->z->y
	Block blocks[CHUNK_SIZE * CHUNK_SIZE * CHUNK_HEIGHT];

	ChunkMesh myMesh;
	World* myWorld;
};

